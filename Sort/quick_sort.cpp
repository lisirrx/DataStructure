//
// Created by 李晗 on 2016/12/15.
//

#include <vector>
#include <iostream>


auto divide(std::vector<int> &array, std::vector<int>::size_type left, std::vector<int>::size_type right, int &_cnt) -> decltype(left){
	auto temp = array.at(right);

	auto i = left;
	for(auto j = left; j < right - 1; ++j){
		if(array.at(j) <= temp){
			i++;
			std::swap(array.at(i), array.at(j));
			_cnt ++;
		}
	}
	std::swap(array.at(i + 1), array.at(right));
	return i + 1;
}

void q_sort(std::vector<int> &_array, std::vector<int>::size_type left, std::vector<int>::size_type right, int&_cnt){

	if(left >= right)
		return;
	auto t = divide(_array, left, right, _cnt);
	q_sort(_array, left, t - 1, _cnt);
	q_sort(_array, t + 1, right, _cnt);
}


int quick_sort(std::vector<int> &array){
	static int cnt = 0;
	q_sort(array, 0, array.size() - 1, cnt);
	return cnt;
}
