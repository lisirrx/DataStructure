//
// Created by lisirrx on 16-10-22.
//

#include "Sort_functions.hpp"

std::vector <int> merge(std::vector <int> &_left, std::vector <int> &_right) {
	std::vector <int> array;

	_left.push_back(INT_MAX);
	_right.push_back(INT_MAX);

	for(auto i = _left.begin(), j = _right.begin(); i < _left.end() - 1 || j < _right.end() - 1;) {
		if(*i < *j) {
			array.push_back(*i);
			i++;
		} else {
			array.push_back(*j);
			j++;
		}
	}
	return array;
}

void m_sort(std::vector<int> &_array) {

	std::vector<int> left(_array.begin(), _array.begin() + (_array.end() - _array.begin()) / 2);
	std::vector<int> right(_array.begin() + (_array.end() - _array.begin()) / 2, _array.end());

	if(left.size() > 1) {
		merge_sort(left);
	}
	if(right.size() > 1) {
		merge_sort(right);
	}

	_array = merge(left, right);
}

int merge_sort(std::vector<int> &_array) {

	m_sort(_array);

	return 0;
}
