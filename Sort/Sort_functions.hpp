//
// Created by lisirrx on 16-10-21.
//

#ifndef SORT_SORT_FUNCTIONS_HPP
#define SORT_SORT_FUNCTIONS_HPP

#include <vector>

void bubble_sort(std::vector<int> &_array);
void insertion_sort(std::vector<int> &_array);
void merge_sort(std::vector<int> &_array);
void radix_sort(std::vector<int> &_array);
std::vector<int> merge(std::vector<int> _left, std::vector<int> _right);


#endif //SORT_SORT_FUNCTIONS_HPP
