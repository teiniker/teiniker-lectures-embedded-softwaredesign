# Claude Code 

## Prompt Processing

Here's a breakdown of how prompt processing works in Claude Code, from the 
moment you hit Enter to when Claude starts acting:

### Context Assembly (Before Claude Sees Your Prompt)

Your prompt doesn't go to Claude directly. When you type a prompt, Claude 
Code first assembles a system prompt (~2,900 base tokens), loads your 
`CLAUDE.md` instructions, injects 18+ tool definitions, and sends everything 
to the Claude API.

The full context stack looks like this, from top to bottom:

1. **System prompt**: Fixed behavioral instructions (same for all users, 
    enabling shared prompt caching).

2. **Tool definitions**: All 18+ built-in tools Claude can call (file
     read/write, bash, search, etc.).

3. **CLAUDE.md contents**: Injected as a `<system-reminder>` tag attached 
    to messages, not the system prompt itself.

4. **Conversation history**: Every prior turn in the session.

5. **Your new prompt**: Plus any `@file` mentions or other attachments.

The system prompt is the same for every Claude Code user on the same version,
that's what makes shared prompt caching work. `CLAUDE.md` can't go into the 
system prompt because every user has a different one; instead it gets injected 
via a `<system-reminder>` XML tag that the model treats as high-priority context.


### Input Modes (How You Can Write Prompts)

There are several ways to feed input:

- **Plain text**: Just type and hit Enter.
- **`\` + Enter**: Multiline input without submitting.
- **`Ctrl+G`**: Open your external editor (e.g. vim/nano) for long prompts.
- **`@filename`**: Attach a file with autocomplete; its contents are injected inline
- **`!command`**: Runs bash directly; output becomes part of conversation context
- **`#`**: Shortcut to add something to CLAUDE.md mid-session
- **`/btw`**: Ask a side question while Claude is mid-response, without touching 
    the conversation history

You can also **pipe input** from the shell:
```bash
cat error.log | claude -p "what caused this?"
git diff main | claude -p "any issues here?"
```
The `-p` flag handles piped input — it sends the prompt, prints output to stdout, and exits. It's strictly non-interactive, great for scripting.


### The Agentic Loop (What Happens After You Submit)

When you give Claude a task, it works through three phases: gather context, 
take action, and verify results. These phases blend together.

Each loop iteration ("turn") works like this:

1. Claude receives the full context (system prompt + history + your message)

2. It decides whether to respond directly or call a tool

3. If it calls a tool (read a file, run bash, search, etc.), the result is 
    appended to the conversation

4. Steps 2 and 3 repeat as a cycle. Claude continues calling tools and 
    processing results until it produces a response with no tool calls.

You can control loop behavior with:
- **`Shift+Tab`**: Toggle **plan mode**, so Claude proposes steps before executing
- **`--max-turns n`**: Cap how many agentic turns before it pauses for your input
- **`Escape`**: Interrupt Claude mid-generation
- **`Ctrl+F`**: Kill all background agents instantly


### Context Window & Caching

The model doesn't "remember" anything between API calls, every request 
includes the full conversation history, system prompt, and tool schemas. 

The full payload goes over the wire every time. But **prompt caching** means 
Claude Code pays only 10% for everything it's already seen, turning a 
fundamental constraint of stateless APIs into a cost advantage.

As sessions grow long, use `/compact` to summarize history and free up 
space. You can pass focus instructions: 
`/compact keep the authentication decisions` to control what survives 
the summary.

### Non-Interactive / Headless Mode

For scripting and CI/CD, you skip the interactive loop entirely:

```bash
# One-shot, exits after response
claude -p "summarize this file" < README.md

# Structured output for pipelines
claude -p "list issues" --output-format json

# Real-time streaming output
claude -p "run tests and explain failures" --output-format stream-json
```

Claude processes the prompt, outputs the result to stdout, and exits. 
No waiting for user input, no interactive terminal.

Our prompt is the *last* thing assembled into a rich context package. 
Claude sees our words surrounded by tools, project instructions, and 
history, all carefully managed to stay within the context window and 
maximize cache hits.


## Slash Commands

Once we launch Claude Code, we communicate using natural language and a suite of 
power-user slash commands.

### Navigation & Sessions

* `/resume`: Browse and resume a previous session

* `/ide`: Connect to your VS Code instance for better diff views

* `/exit`: Exit Claude Code

### Context Management

*  `/context`: Visualize current context usage as a colored grid

* `/compact`: Summarize conversation history to free up context (accepts focus 
    instructions, e.g. `/compact keep the auth layer decisions`)

* `/clear`: Reset the conversation entirely

* `/model`: Set the AI model for Claude Code (currently Sonnet 4.6)


### Workflow

* `/btw`: Ask a side question without polluting the main conversation context 
    (works even while Claude is mid-task)

* `/effort`: Control reasoning depth (turn up for architecture/debugging, down 
    for simple edits)


### Other Useful Commands

' `!command`: Run bash directly (as you know)

* `@filename`: Mention a file with autocomplete

* `Shift+Tab`: Toggle plan mode (Claude proposes before acting)

* `Ctrl+S`: Stash your current prompt to ask something else first, then it
    auto-restores

 * `/export session.md`: Writes a full conversation transcript as a plain-text 
    file directly to your current working directory.


## Interaction Modes

Claude Code provides multiple ways to interact with it, depending on our workflow and preferences:

* **Standard Mode**: To launch Claude Code in its default, 
interactive chat state, we simply navigate to our target project 
folder and run:

    ```bash
    $ claude
    ```
    - `-r`: Resume a previous conversation
    - `-c`: Continue most recent conversation in current directory


* **! Shortcut (Shell Mode)**: If we are inside an interactive Claude Code 
session but quickly need to run a standard, manual terminal command 
without exiting, type `!` at the start of our line (e.g., `!git status`). 
It bypasses the AI completely and triggers a direct shell pass-through.


## Custom Instructions (Priming Documents)

The custom instructions file in Claude Code is called **`CLAUDE.md`**, 
a plain Markdown file Claude automatically reads at the start of every 
session.

There are three scopes:
- `./CLAUDE.md`: Project root, committed to your repo (shared with your team)
- `./.claude/CLAUDE.md`: Also project-level but git-ignored friendly
- `~/.claude/CLAUDE.md`: Global, applies to every project on your machine

Run `/init` inside a project and Claude will generate a starter file for 
us based on our codebase. It's a good way to get oriented quickly, but the 
real value comes from iterating on it over time, using the `#` key to add 
instructions we find ourself repeating.

**What to put in it**

The file can document common bash commands, core utilities, code style 
guidelines, testing instructions, repository conventions, developer 
environment setup, and project-specific warnings. There's no required 
format.

A typical structure looks like this:

```markdown
## Architecture
- /app: Next.js App Router pages
- /lib: Shared utilities
- /prisma: DB schema

## Commands
- `npm run dev`: Start dev server
- `npm run test`: Run Jest tests
- `npm run db:migrate`: Run migrations

## Code Style
- TypeScript strict mode, no `any` types
- Named exports only, no default exports

## Important Rules
- NEVER commit .env files
- Always validate inputs in API handlers
```

## References

* [Claude Code Docs](https://code.claude.com/docs/en/overview)
* [Claude Code Docs: CLI reference](https://code.claude.com/docs/en/cli-reference)

* [YouTube (Net Ninja): Claude Code Tutorial](https://youtube.com/playlist?list=PL4cUxeGkcC9g4YJeBqChhFJwKQ9TRiivY&si=vFi4uc8KsxKJUIlN)
