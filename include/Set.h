
#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

// Simple Set of ints with unique, ascending elements.
class Set {
private:
    std::vector<int> elements;

    // maintain sorted unique invariant
    void normalize() {
        std::sort(elements.begin(), elements.end());
        elements.erase(std::unique(elements.begin(), elements.end()), elements.end());
    }

    // find insertion/search position using lower_bound
    std::vector<int>::iterator find_pos(int x) {
        return std::lower_bound(elements.begin(), elements.end(), x);
    }
    std::vector<int>::const_iterator find_pos(int x) const {
        return std::lower_bound(elements.cbegin(), elements.cend(), x);
    }

public:
    Set() = default;
    explicit Set(const std::vector<int>& elems) : elements(elems) { normalize(); }

    // Insert if absent (O(log n) search + O(n) insert)
    void insert(int x);

    // Remove if present
    void remove(int x);

    // Membership
    bool belongsTo(int x) const;

    // Size
    int size() const { return static_cast<int>(elements.size()); }

    // Print to stream
    void print(std::ostream& os = std::cout) const;

    // Set operations
    Set unionSet(const Set& other) const;
    Set intersectionSet(const Set& other) const;
    Set differenceSet(const Set& other) const;
    Set symmetricDifference(const Set& other) const;

    // For tests
    const std::vector<int>& data() const { return elements; }
};
