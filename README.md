
# Set Library — C++17

A clean, interview-ready **Set** class implemented from scratch using `std::vector<int>` with elements kept **unique** and **ascending**. Includes classic operations (insert, remove, union, intersection, difference, symmetric difference), membership, size, and print — plus tests and CI.

## Features
- Unique, sorted storage using `std::vector<int>`
- `insert`, `remove`, `belongsTo`, `size`, `print`
- `unionSet`, `intersectionSet`, `differenceSet`, `symmetricDifference`
- CMake project with tests and GitHub Actions CI

## Build & Run (local)
```bash
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . -j

# demo
./set_demo

# tests
ctest --output-on-failure
# or
./set_tests
```
