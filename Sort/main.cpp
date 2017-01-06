#include <iostream>
#include "Sort_functions.hpp"
#include <random>
#include <string>
#include <functional>
#include <ctime>

void random_gen(std::vector<int>&_array, int _n){
	std::random_device rd;
	std::mt19937 engine(rd());
	std::uniform_int_distribution<> dis(1, 500);
	for(int i = 0; i < _n; ++i) {
		_array.push_back(dis(engine));
	}
}
int main() {

	int n = 0;
	int sort_type;
	std::vector<int> generated;
	std::vector<int> unsorted;
	std::vector<std::function<int (std::vector<int> &)>> functions = {merge_sort, quick_sort,
		heap_sort, bubble_sort, insertion_sort, radix_sort, shell_sort, select_sort};
	std::vector<std::string> function_name = {"merge_sort", "quick_sort",
		"heap_sort", "bubble_sort", "insertion_sort", "radix_sort", "shell_sort", "select_sort"};


	std::cout << "Input the data scale : ";
	std::cin >> n;
	random_gen(generated, n);


	std::cout << "Chose a sort method" << std::endl;

	for(int i = 0; i < 8; ++i){
		std::cout << i + 1 << " : " << function_name.at(i) << std::endl;
	}

	while(std::cin >> sort_type){
		unsorted = generated;
		auto time = clock();
		int count = functions.at(sort_type - 1)(unsorted);
		time = clock() - time;

		std::cout << function_name.at(sort_type - 1) << " cost " << (double)time / (double)CLOCKS_PER_SEC * (double)1000 << " ms, with "
			<< count << " swap."<< std::endl;
	}


    return 0;
}