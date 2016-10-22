#include <iostream>
#include "Sort_functions.hpp"

int main() {
    std::cout << "Hello, World!" << std::endl;

    std::vector<int> a = {1, 4,5,3,5,6,635,9,7,0};

	bubble_sort(a);


    for(auto i : a){
        std::cout << i << std::endl;
    }
    return 0;
}