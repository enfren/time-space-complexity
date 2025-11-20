/**
 * @file linear_scan_sum.cpp
 * @brief O(n) one-pass summation with O(1) auxiliary space
 * @details Classic linear-time algorithm.
 *          Processes each element exactly once — the foundation of streaming.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1) auxiliary (excluding input)
 */

#include <iostream>
#include <vector>

/// Returns the sum of all elements in data
long long computeSum(const std::vector<int>& data) {
    long long sum = 0;
    for (int value : data) {
        sum += value;
    }
    return sum;
}

int main() {
    const int n = 100'000'000;
    std::vector<int> numbers(n);

    // Fill with 1, 2, ..., n
    for (int i = 0; i < n; ++i) {
        numbers[i] = i + 1;
    }

    long long result = computeSum(numbers);

    // Expected: n*(n+1)/2
    long long expected = static_cast<long long>(n) * (n + 1) / 2;

    std::cout << "Sum of first " << n << " numbers = " << result << "\n";
    std::cout << "Correct? " << (result == expected ? "Yes!" : "No") << "\n";

    // Real-world: This is how log processors, real-time analytics,
    // and one-pass algorithms work in production systems.

    return 0;
}
