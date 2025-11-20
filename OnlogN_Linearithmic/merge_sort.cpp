/**
 * @file merge_sort.cpp
 * @brief Guaranteed O(n log n) stable sorting via divide-and-conquer
 * @details Classic merge sort implementation.
 *          Worst-case O(n log n) — used as fallback in many standard libraries.
 *
 * Time Complexity: O(n log n) — always
 * Space Complexity: O(n) — temporary merge buffer
 */

#include <iostream>
#include <vector>
#include <algorithm>

void merge(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)  temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (int p = 0; p < k; ++p)
        arr[left + p] = temp[p];
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    std::vector<int> data(10'000'000);
    for (size_t i = 0; i < data.size(); ++i)
        data[i] = data.size() - i;  // reverse order

    std::cout << "Sorting 10 million numbers with merge sort...\n";

    mergeSort(data, 0, data.size() - 1);

    std::cout << "First 10: ";
    for (int i = 0; i < 10; ++i) std::cout << data[i] << " ";
    std::cout << "\n";

    std::cout << "Sorted? " << (std::is_sorted(data.begin(), data.end()) ? "Yes!\n" : "No\n");

    // Real-world: This is why Timsort (Python), Introsort (C++), and most
    // high-performance databases rely on O(n log n) algorithms.

    return 0;
}
