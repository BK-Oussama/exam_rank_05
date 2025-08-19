
I want you to help me solve a C++98 exercise step by step. Follow this exact workflow and style.

0) Global rules & style

    - Toolchain: compile with -Wall -Wextra -Werror -std=c++98.

    - Code style: no ternary (?:) — use simple if statements only; simplify return values (explicit if + return is fine).

    - Simplicity-first: keep helpers tiny; use clear control flow; avoid clever tricks.

    - Tests: a single main (no helpers) printing actual vs expected lines, easy to read by eye.

1) Build the Roadmap (Full Step-by-Step Plan) — do this FIRST

Before proposing approaches or code:

    1. Restate the exercise in your own words (what exactly is required).

    2. List constraints (flags, style rules, invariants, naming).

    3. Inventory existing code I’ll provide (assume it’s “well-tested and solid”; we are not starting from scratch).

    4. Produce a numbered step-by-step plan of the whole exercise:

        - milestones in order,
    
        - dependencies between steps,

        - acceptance criteria per step (what tests will prove it works),

        - likely pitfalls/edge cases.

    5. Ask me to confirm or adjust the plan. After I confirm, we proceed.


2) Per-Step Workflow (apply this loop to each step in the plan)

For the current step, do these seven phases:

    1. Understand
    
        - Restate the specific step’s goal, inputs/outputs, and scope.
    
        - Call out constraints and hidden assumptions / edge cases.
    
    2. Approaches (2 at least)
    
        - Describe the core idea of each, with pros/cons and impact on later steps.
    
    3. Decide
    
        - Wait for me to pick one.
    
        - If I provide my own approach, evaluate it candidly (correctness, semantics, trade-offs) and improve it if needed.
    
    4. Implement
    
        - Provide the simplest correct code in C++98.
    
        - No ternary; use simple if; keep returns explicit.
    
        - Reuse existing operators where sensible.
    
        - Respect semantics (e.g., prefix returns &, postfix returns value).
    
    5. Explain (deep)
    
        - Walk through logic, invariants, edge cases, complexity, ownership/semantics (by-ref vs by-value), and any gotchas avoided.
    
    6. Test
    
        - Give a single main (no helpers) with clear, labeled test lines:
    
            - normal cases, edge cases, long/large inputs as relevant,
    
            - chaining where it matters (e.g., a += b += c, (x <<= 2) >>= 1).
    
        - Print actual | expected for easy eyeball checks.
    
    7. Review & Iterate
    
        - Summarize results, propose tiny polish (if any), and confirm readiness to move to the next step.

3) Collaboration notes

If I ask to skip ahead, do so—but keep explanations concise and aligned with these rules.

Always accept my custom code for review; point out fixes (correctness/semantics/style) without forcing a different approach unless necessary.

Keep everything teachable; I should be able to review this later and remember why each choice was made.

Start now by Step 1 (Build the Roadmap) using the subject and my existing code. After I confirm the plan, we’ll apply the 7-phase loop to step 1.

