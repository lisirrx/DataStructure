//
// Created by 李晗 on 2016/12/22.
//

#include <iostream>
#include "Sort_functions.hpp"


int left(int i){
	return 2 * i + 1;
}

int right(int i){
	return 2 * i + 2;
}

void min_heapify(std::vector<int> &_array, int i, int & cnt){
	auto l = left(i);
	auto r = right(i);
	auto temp = _array[i];
	if(i >= _array.size()){
		return;
	}

	auto min = i;

	if(l < _array.size() && _array[l] < temp){
		temp = _array[l];
		min = l;
	}

	if(r < _array.size() && _array[r] < temp){
		min = r;
	}

	if(min != i){
		cnt ++;
		std::swap(_array[min], _array[i]);
		min_heapify(_array, min, cnt);
	}
}


void build_min_heap(std::vector<int> &_array, int &cnt){
	for(int i = (_array.size() - 1) / 2 ; i >= 0; --i){
		min_heapify(_array, i, cnt);
	}

}

int heap_sort(std::vector<int> &_array){
	int cnt = 0;
	build_min_heap(_array, cnt);

	std::vector<int> temp;


	for(int i = _array.size() - 1; i >= 0; --i){
		std::swap(_array[0], _array[i]);
		temp.push_back(_array.back());
		_array.pop_back();
		min_heapify(_array, 0, cnt);
	}

	_array = temp;
	return cnt;

}

