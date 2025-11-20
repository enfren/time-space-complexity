# Time & Space Complexity Showcase  
Modern C++23 – Measured on real hardware

All examples written and benchmarked by me to truly internalize how each class feels.

| Complexity | Folder                  | Example                          | Runtime (my machine) | Notes                                           |
|------------|-------------------------|----------------------------------|----------------------|-------------------------------------------------|
| O(1)       | `O1_Constant`           | Hash map lookup                  | < 1 µs               | Instant, independent of input size              |
| O(log n)   | `Ologn_Logarithmic`     | Binary search (50 M elements)    | ~30 µs               | Halves search space on every step               |
| O(n)       | `On_Linear`             | Sum 100 M numbers                | ~180 ms              | Linear pass – predictable and fast              |
| O(n log n) | `OnlogN_Linearithmic`   | Merge sort 10 M numbers          | ~1.4 s               | Gold standard for comparison-based sorting      |
| O(n²)      | `On2_Quadratic`         | Bubble sort 10 000 elements      | ~12 s                | You feel every single comparison                |
| O(2ⁿ)      | `O2n_Exponential`       | fib(45) naïve recursion          | 2.839 s              | Exponential growth is brutal                    |
| O(n!)      | `OnFact_Factorial`      | All 3 628 800 permutations (n=10)| **17 ms**            | Theory says impossible – optimized STL laughs   |

Why only 17 ms for 10!?
`std::next_permutation` is written in hand-tuned assembly-like C++, branch prediction loves the pattern, and modern CPUs execute the tight inner loop at ~200–300 million iterations per second. Asymptotic notation hides constant factors — sometimes by orders of magnitude.

Built slowly and deliberately so I actually understand, not just memorize.
