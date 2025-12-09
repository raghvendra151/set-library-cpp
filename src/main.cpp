
#include "Set.h"
#include <iostream>

int main() {
    Set A({1,2,3,4});
    Set B({3,4,5,6});

    std::cout << "A = "; A.print(); std::cout << "\n";
    std::cout << "B = "; B.print(); std::cout << "\n\n";

    std::cout << "A ∪ B = "; A.unionSet(B).print(); std::cout << "\n";
    std::cout << "A ∩ B = "; A.intersectionSet(B).print(); std::cout << "\n";
    std::cout << "A \\ B = "; A.differenceSet(B).print(); std::cout << "\n";
    std::cout << "A Δ B = "; A.symmetricDifference(B).print(); std::cout << "\n\n";

    std::cout << "belongsTo(3) in A? " << (A.belongsTo(3) ? "Yes" : "No") << "\n";
    std::cout << "size(A) = " << A.size() << "\n";

    A.insert(10);
    A.remove(2);
    std::cout << "After insert(10) & remove(2), A = "; A.print(); std::cout << "\n";
    return 0;
}
