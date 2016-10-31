#include <iostream>
#include "Sort_functions.hpp"
#include <random>
#include <ctime>

int main() {
    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<> dis(1, 20000);

    std::cout << "Hello, World!" << std::endl;


    std::vector<int> a;
    for(int i = 0; i < 100000; ++ i){
        a.push_back(dis(engine));
    }
    std::vector<int> b = a;

    int t = clock();
    merge_sort(a);
    int t2 = clock();
    std::cout << t2 - t << std::endl;

    t = clock();
    insertion_sort(b);
    t2 = clock();

    std::cout << t2 - t << std::endl;

    t = clock();
    bubble_sort(b);
    t2 = clock();

    std::cout << t2 - t << std::endl;



    return 0;
}