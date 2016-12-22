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

	for(int j = 1000; j < 0x3f3f3f; j *= 2) {

		std::cout << "The input scale is :" << j << std::endl;

		for(int i = 0; i < j; ++i) {
			a.push_back(dis(engine));
		}
		std::vector <int> b = a;

		int t = clock();
		merge_sort(b);
		int t2 = clock();
		std::cout << "merge sort  : "<<t2 - t << std::endl;

		b = a;

		t = clock();

		insertion_sort(b);
		t2 = clock();

		std::cout << "insert sort : " <<t2 - t << std::endl;

//		b = a;
//		t = clock();
//		bubble_sort(b);
//		t2 = clock();
//
//		std::cout <<"bubble sort : " <<  t2 - t << std::endl;

		b = a;
		t = clock();

		quick_sort(b, 0, b.size() - 1);

		t2 = clock();

		std::cout <<"quick sort  : " << t2 - t << std::endl;

		b = a;
		t = clock();

		std::sort(b.begin(), b.end());

		t2 = clock();

		std::cout <<"std   sort  : " << t2 - t << std::endl;

		std::cout << "------------"<< std::endl;
	}

    return 0;
}