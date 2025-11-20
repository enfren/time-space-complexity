/**
 * @file binary_search.cpp
 * @brief O(log n) iterative binary search on sorted data
 * @details Classic divide-and-conquer algorithm.
 *          Halves the search space on every iteration.
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1) — iterative version (no recursion stack)
 */

#include <iostream>
#include <vector>

/// Returns true if target exists in the sorted vector arr
bool binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = static_cast<int>(arr.size()) - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;  // avoids overflow
        if (arr[mid] == target)  return true;
        if (arr[mid] < target)   left = mid + 1;
        else                     right = mid - 1;
    }
    return false;
}

int main() {
    std::vector<int> data;
    for (int i = 0; i < 100'000'000; i += 2)  // 50 M elements
        data.push_back(i);

    int target = 99'999'998;

    if (binarySearch(data, target))
        std::cout << "Found " << target << " in O(log n) time!\n";
    else
        std::cout << "Not found\n";

    // Real-world: This is the foundation of std::lower_bound,
    // database B-trees, and efficient game/AI decision systems.

    return 0;
}
