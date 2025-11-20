/**
 * @file bubble_sort.cpp
 * @brief O(n²) comparison-based sort – educational / anti-pattern
 * @details Repeatedly "bubbles" largest unsorted element to its final position.
 *          Optimized early exit when no swaps occur.
 *
 * Time Complexity: O(n²) worst and average, O(n) best (already sorted)
 * Space Complexity: O(1) — fully in-place
 */

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    int comparisons = 0;
    bool swapped;

    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            ++comparisons;
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;  // Already sorted — early exit
    }
    std::cout << "Total comparisons: " << comparisons << " ≈ n²/2\n";
}

int main() {
    std::vector<int> data;
    const int n = 10'000;
    for (int i = n; i >= 1; --i) data.push_back(i);  // reverse sorted

    std::cout << "Running O(n²) bubble sort on " << n << " elements...\n";
    bubbleSort(data);

    std::cout << "First 20 sorted: ";
    for (int i = 0; i < 20 && i < data.size(); ++i)
        std::cout << std::setw(5) << data[i];
    std::cout << "\n";

    std::cout << "Correctly sorted? "
              << (std::is_sorted(data.begin(), data.end()) ? "Yes!\n" : "No\n");

    // Real-world lesson: Never use bubble sort on large data.
    // This is exactly why std::sort exists.

    return 0;
}
