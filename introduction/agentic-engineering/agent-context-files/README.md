# Agent Context Files

A coding agent starts every session with no memory of the project.
An **Agent Context File** (`CLAUDE.md`, `AGENT.md`, `AGENTS.md`) is a
plain Markdown file, checked into the repository, that is read into
the model's context at the start of a session (and after compaction).
It gives the agent the background a new team member would otherwise
have to ask for or discover by exploring the code: how to build and
test the project, which conventions to follow, and which behaviors
are expected or forbidden.

Technically the file's content is folded into the **system prompt**,
so it applies to every turn of the session without the user having
to repeat it. That also means it is not free: it consumes tokens on
every request, so it should stay short and only contain what the
agent cannot reliably infer from the code itself.


## Anatomy of a Context File

There is no fixed schema, but most Context Files converge on a
similar structure:

* **Project Overview**: A one- or two-sentence description of what
    the repository is and how it is organized.

* **Build & Test Commands**: The exact commands to build, run, and
    test the project, including how to run a single test. Agents
    waste many turns rediscovering these by trial and error if they
    are missing.

* **Conventions**: Naming schemes, package layout, coding standard
    (indentation, line width, brace style, ...), and any other
    project-specific rules that are not obvious from reading a
    single file.

* **Do / Don't Rules**: Explicit constraints, e.g. "never commit
    directly to `main`", "always use JUnit 4, not JUnit 5".

* **References**: Pointers to further documentation, architecture
    diagrams, or related Context Files, instead of duplicating their
    content.

Well-written Context Files favor **short, declarative rules** over
long prose, and avoid restating information that is already
derivable from the code (file structure, dependencies, git history).


## Consequences

**Benefits**

* Removes the need to repeat the same instructions in every prompt.
* Encodes tacit project knowledge (conventions, pitfalls) that would
    otherwise live only in a senior developer's head.
* Makes agent behavior more consistent across sessions and users.


**Drawbacks**

* Consumes context window and tokens on every request, so an overly
    long file has a real, recurring cost.
* Can go stale: if the file is not updated alongside the code, the
    agent may follow outdated instructions.
* Is a hint, not a hard constraint: the agent may still deviate from
    it, especially in a long session or after context compaction.
* Requires the same maintenance discipline as code; an unowned
    Context File tends to rot faster than the code it documents.


## References

* [Claude Code: Manage Claude's memory](https://code.claude.com/docs/en/memory)

*Egon Teiniker, 2026, GPL v3.0*
