# Lessons Learned from Using Agents

## Environment & Tooling

* A Linux VM can act as a **sandbox** for the coding agent.

* The integration of a **Linux shell** (many small tools) and coding
    agents works very well.

    - For CLI-based coding agents, using a Linux shell provides 
        a significant advantage over a native Windows
        environment. The "Linux philosophy" is essentially the native
        language of these agents.

    - The agent "knows" grep, sed, awk, find, and xargs by heart.
        It can pipe these together flawlessly.

* A **Git Repo** is important to manage changes.
    - Undo changes (compared to the repo).
    - Use a feature branch to work with an agent.

* **IDE** features are less important.
    - Agents can do most refactoring and boilerplate code generation.
    - Debugging is still a topic where IDEs help.
    - Copilot is perfect for small changes in a file.


## Agent Configuration & Communication

* A **CLAUDE.md** (AGENTS.md) file is needed, but should be short
    (save tokens).

* **Design and Architectural Patterns** help to communicate with
    agents. One name replaces a lot of description about the
    implementation structure. It increases abstraction and makes
    communication more efficient.

* **Fotos of UML diagrams** are also a good way to communicate design ideas.    
    In the other directon **Mermaide diagrams** (text based) can be 
    generated to abstract from the concrete implementation.

* **Planning** (create a `plan.md` file) is very usefull to discuss 
    the implementation design without code.
    We can review and change the plan.md file if we want.

* From text-based requirements **generate user story templates**.
    These templates are well structures and easy to review.


## Process & Workflow

* **Test Automation** is important to validate the generated code.

* Break down tasks into **small (vertical) tasks** or user stories.
    Use **Kanban** for organizing these tasks and work on them in
    parallel.

*Egon Teiniker, 2026, GPL v3.0*