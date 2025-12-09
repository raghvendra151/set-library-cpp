
#include "Set.h"
#include <cassert>
#include <iostream>

static void assert_vec(const std::vector<int>& got, const std::vector<int>& want) {
    assert(got.size() == want.size());
    for (size_t i=0;i<want.size();++i) assert(got[i] == want[i]);
}

int main(){
    Set s1({1,2,3});
    Set s2({3,4,5});

    // insert / remove / belongsTo
    s1.insert(4); assert(s1.belongsTo(4));
    s1.remove(2); assert(!s1.belongsTo(2));

    // operations
    auto u = s1.unionSet(s2);            // {1,3,4,5}
    auto i = s1.intersectionSet(s2);     // {3,4}
    auto d = s1.differenceSet(s2);       // {1}
    auto sd = s1.symmetricDifference(s2);// {1,5}

    assert_vec(u.data(),  std::vector<int>({1,3,4,5}));
    assert_vec(i.data(),  std::vector<int>({3,4}));
    assert_vec(d.data(),  std::vector<int>({1}));
    assert_vec(sd.data(), std::vector<int>({1,5}));

    std::cout << "✅ All tests passed\n";
    return 0;
}
