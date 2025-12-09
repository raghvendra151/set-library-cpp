
#include "Set.h"

void Set::insert(int x) {
    auto it = find_pos(x);
    if (it == elements.end() || *it != x) {
        elements.insert(it, x); // keep sorted order
    }
}

void Set::remove(int x) {
    auto it = find_pos(x);
    if (it != elements.end() && *it == x) {
        elements.erase(it);
    }
}

bool Set::belongsTo(int x) const {
    auto it = find_pos(x);
    return it != elements.end() && *it == x;
}

void Set::print(std::ostream& os) const {
    os << "{ ";
    for (size_t i = 0; i < elements.size(); ++i) {
        os << elements[i];
        if (i + 1 < elements.size()) os << ", ";
        os << " ";
    }
    os << "}";
}

Set Set::unionSet(const Set& other) const {
    std::vector<int> merged;
    merged.reserve(elements.size() + other.data().size());
    std::merge(elements.begin(), elements.end(),
               other.data().begin(), other.data().end(),
               std::back_inserter(merged));
    merged.erase(std::unique(merged.begin(), merged.end()), merged.end());
    return Set(merged);
}

Set Set::intersectionSet(const Set& other) const {
    std::vector<int> inter;
    inter.reserve(std::min(elements.size(), other.data().size()));
    std::set_intersection(elements.begin(), elements.end(),
                          other.data().begin(), other.data().end(),
                          std::back_inserter(inter));
    return Set(inter);
}

Set Set::differenceSet(const Set& other) const {
    std::vector<int> diff;
    diff.reserve(elements.size());
    std::set_difference(elements.begin(), elements.end(),
                        other.data().begin(), other.data().end(),
                        std::back_inserter(diff));
    return Set(diff);
}

Set Set::symmetricDifference(const Set& other) const {
    std::vector<int> sym;
    sym.reserve(elements.size() + other.data().size());
    std::set_symmetric_difference(elements.begin(), elements.end(),
                                  other.data().begin(), other.data().end(),
                                  std::back_inserter(sym));
    return Set(sym);
}
