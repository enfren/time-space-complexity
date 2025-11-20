/**
 * @file fibonacci_recursive.cpp
 * @brief Naïve O(2ⁿ) recursive Fibonacci – exponential tree recursion
 * @details Pure textbook example of exponential time complexity.
 *          Each call branches into two more calls → ~2ⁿ total operations.
 *
 * Time Complexity: O(2ⁿ) — roughly doubles with each increment of n
 * Space Complexity: O(n) — maximum depth of recursion stack
 */

#include <iostream>
#include <chrono>

/// Naïve recursive Fibonacci – DO NOT USE in production
long long fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n = 45;  // 45 → ~2.8 seconds, 50 → ~45 seconds, 55 → 11+ minutes

    std::cout << "Computing fib(" << n << ") with naïve O(2ⁿ) recursion...\n";

    auto start = std::chrono::high_resolution_clock::now();
    long long result = fib(n);
    auto end = std::chrono::high_resolution_clock::now();

    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "fib(" << n << ") = " << result << "\n";
    std::cout << "Time taken: " << ms.count() << " ms\n";

    // Real-world lesson:
    // This is why we use memoization (O(n)), bottom-up DP (O(n)), or
    // matrix exponentiation (O(log n)) for Fibonacci in real systems.

    return 0;
}
