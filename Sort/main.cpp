#include <iostream>
#include "Sort_functions.hpp"

int main() {
    std::cout << "Hello, World!" << std::endl;

    std::vector<int> a = {1,4,5,2,3,7,9,10};

    insertion_sort(a);

    for(auto i : a){
        std::cout << i << std::endl;
    }

    return 0;
}