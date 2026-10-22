# Patterns for Reducing Friction in AI-Assisted Development
	
## Introduction

When I do pair programming with a colleague, certain rituals happen naturally: 
- I walk them through the codebase before asking them to contribute. 
- We sketch on a whiteboard before diving into implementation. 
- I explain our conventions, our constraints, the reasoning behind past decisions. 
- We review the work against team standards.

With AI coding assistants we type a prompt, expect aligned output, and then 
wonder why the result doesn't fit.
The time saved by AI-generated code is often consumed by the effort required 
to correct it.

### The Frustration Loop

> **Frustration Loop**: generate code, review it, find it doesn't fit the codebase, 
> regenerate with corrections, review again, and eventually either accept heavily-
> modified output or abandon the attempt entirely.

The friction arises from how we collaborate with these systems.

AI Agents produce what might be called “the average of the internet” rather 
than code that fits a specific team's architecture and conventions.

Common symptoms include:
- AI generates solutions that don't align with existing architecture
- Developers spend significant time on post-generation editing
- Context established early in a conversation is lost as the session lengthens
- Quality varies depending on which team member is prompting

#### The Speed Trap
If an AI generates 200 lines of code in seconds, but a developer spends 30 
minutes reviewing, debugging, and refactoring to fit team patterns, the net 
productivity gain is questionable.
The work has shifted from writing to fixing, but the total effort may not 
have decreased.
When I pair with a human colleague, I don't measure success by how fast they 
type. I care about whether their contribution fits the codebase, whether it 
solves the right problem, whether it will hold up in review. The same should 
apply to AI collaboration.

#### The Tool-to-Teammate Shift
A useful reframe is to stop treating AI as a tool and start treating it 
as a teammate.
AI assistants are like junior developers with infinite energy but zero context.
They can work faster than any human, they never tire, and they never complain. 
But they know nothing about a specific project's conventions, constraints, or 
history.
The AI needs the same things a human pair needs:
- Onboarding: Context about the codebase before contributing
- Whiteboarding: Structured design discussion before implementation
- Guardrails: Standards and quality checks consistently applied

#### Proposed Patterns for AI Collaboration:

- [Knowledge Priming](https://martinfowler.com/articles/reduce-friction-ai/knowledge-priming.html): 
    Proactively sharing curated project context (architectural choices, 
    tech stacks, naming conventions) with the AI before generating code, 
    effectively acting as manual Retrieval-Augmented Generation (RAG). 
    This anchors the model's output to specific codebase constraints 
    rather than generic training data.

- [Design-First Collaboration](https://martinfowler.com/articles/reduce-friction-ai/design-first-collaboration.html): 
    Structuring the AI interaction like a whiteboard session with a human 
    peer, stepping through progressive levels of design before any 
    implementation begins. This prevents the cognitive overload of untangling 
    implicit architectural decisions buried within prematurely generated code.

- [Encoding Team Standards](https://martinfowler.com/articles/reduce-friction-ai/encoding-team-standards.html): 
    Transforming tacit senior developer knowledge into explicit, version-
    controlled instructions that the AI executes during code generation, 
    refactoring, and security reviews.

- [Context Anchoring](https://martinfowler.com/articles/reduce-friction-ai/context-anchoring.html): 
    Treating feature-level decision context as external state by maintaining 
    a persistent, living document of architectural choices, open questions, 
    and rejected alternatives. This external memory prevents the AI from 
    forgetting crucial reasoning as context windows fill up or ephemeral 
    sessions restart.

- [Feedback Flywheel](https://martinfowler.com/articles/reduce-friction-ai/feedback-flywheel.html): 
    A systematic, lightweight practice for harvesting insights from daily 
    AI interactions and feeding those insights back into the team's shared 
    priming documents and instruction files. This active feedback loop 
    ensures the AI collaboration infrastructure compounds in value over time.

## References

* [Patterns for Reducing Friction in AI-Assisted Development](https://martinfowler.com/articles/reduce-friction-ai/)

*Egon Teiniker, 2026, GPL v3.0*