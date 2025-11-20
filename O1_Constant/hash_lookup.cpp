/**
 * @file hash_lookup.cpp
 * @brief O(1) average-case lookup using unordered_map
 * @details Demonstrates constant-time access regardless of container size.
 *          Real-world use: caching, symbol tables, memoization.
 * 
 * Time Complexity: O(1) average
 * Space Complexity: O(n) for the map, O(1) per lookup
 */

#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::unordered_map<std::string, int> cache;
    // Fill cache (happens once)
    cache["apple"] = 50;
    cache["fig"] = 75;
    cache["cherry"] = 90;
    
    // O(1) lookup — no matter how big the map gets
    std::string key = "fig";
    auto it = cache.find(key);
    
    if (it != cache.end()) {
        std::cout << key << " costs " << it->second << " cents\n";
    } else {
        std::cout << key << " not found\n";
    }
    
    // Real-world note: This is why caching, memoization, and hash maps
    // are used everywhere in high-performance systems.
    
    return 0;
}
