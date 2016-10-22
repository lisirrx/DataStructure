//
// Created by lisirrx on 16-10-22.
//

#include "Sort_functions.hpp"

std::vector<int> merge(std::vector<int> _left, std::vector<int> _right){
	std::vector<int> array;

	size_t lenth_left = _left.size();
	size_t lenth_right = _right.size();

	_left.push_back(INT_MAX);
	_right.push_back(INT_MAX);

	for(auto i = _left.begin(), j = _right.begin(); i < _left.end() || j < _right.end();){
		if(*i < *j){
			array.push_back(*i);
			i++;
		} else{
			array.push_back(*j);
			j++;
		}
	}
	return array;
}

void merge_sort(std::vector<int> &_array){
    
}
