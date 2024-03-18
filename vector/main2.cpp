#include <iostream>
#include "vector.h"

int main(){
    nonstd::vector<int> v;
    for (int i: {1, 2, 3, 4, 5})
        v.push_back(i);
    v[2] = 10;
    std::cout << v;
}
