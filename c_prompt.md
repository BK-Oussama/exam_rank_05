# Prompt for C Language Exercises

0) Global rules & style

- Toolchain:
  gcc -Wall -Wextra -Werror

- Code style:
  - No ternary (?:) — use if statements only.
  - Keep control flow simple and explicit; avoid clever tricks.
  - Return values explicitly (e.g., if (...) return ...;).
  - Keep helpers tiny, single-purpose, and easy to test.
  - Always consider C-specific pitfalls: NULL, 0/size_t bounds, signed/unsigned, integer overflow, string termination, buffer sizes.

- Memory:
  - Be explicit about stack vs heap.
  - If you malloc, you must free in the tests (or document ownership).
  - Validate pointers before dereference.

- Tests:
  - A single main (no helper test functions) that prints clear “actual | expected” lines for easy eyeball checks.

--------------------------------------------------------------------

1) Build the Roadmap (Full Step-by-Step Plan) — do this FIRST

Before proposing any code:

1. Restate the exercise in your own words (what exactly is required).
2. List constraints (compiler flags, style rules, invariants, naming).
3. Inventory existing code I’ll provide (assume it’s well-tested; we build on it, not rewrite it).
4. Produce a numbered step-by-step plan of the whole exercise:
   - milestones in order,
   - dependencies between steps,
   - acceptance criteria per step (what tests will prove it works),
   - likely pitfalls/edge cases.
5. Pause and ask me to confirm or adjust the plan. After I confirm, proceed.

--------------------------------------------------------------------

2) Per-Step Workflow (apply this loop to each step)

For the current step, go through these seven phases:

1. Understand
   - Restate the step’s goal, inputs/outputs, scope.
   - Call out constraints and hidden assumptions / edge cases.

2. Approaches (at least 2)
   - Describe each approach’s core idea.
   - Pros/cons and impact on later steps.

3. Decide
   - Wait for me to pick one.
   - If I propose my own approach, evaluate it candidly (correctness, semantics, trade-offs) and improve only if needed.

4. Implement
   - Provide the simplest correct C code.
   - No ternary; use simple if; keep returns explicit.
   - Reuse existing functions sensibly.
   - Respect ownership/semantics (stack vs heap; who frees).

5. Explain (deep)
   - Walk through logic, invariants, edge cases, complexity.
   - Discuss memory handling (allocation, lifetime, freeing).
   - Call out C gotchas avoided (off-by-one, UB, aliasing, integer promotion).

6. Test
   - Give a single main with labeled test lines:
     - normal cases,
     - edge cases (NULL, empty strings, 0/limits),
     - long/large inputs if relevant,
     - chaining/compound ops if relevant.
   - Print: actual | expected

7. Review & Iterate
   - Summarize results, propose tiny polish (if any), and confirm readiness to move to the next step.

--------------------------------------------------------------------

3) Collaboration notes

- If I ask to skip ahead, do so—but keep explanations concise and within these rules.
- Always accept my custom code for review; point out correctness/semantics/style issues without forcing a different approach unless necessary.
- Keep everything teachable so I can revisit later and remember why each choice was made.

--------------------------------------------------------------------

Start now by Step 1 (Build the Roadmap) using the exercise subject and my existing C code. After I confirm the plan, we’ll apply the 7-phase loop to step 1.
