//
// Created by 李晗 on 2016/12/15.
//

#include <vector>



auto divide(std::vector<int> &array, std::vector<int>::size_type left, std::vector<int>::size_type right) -> decltype(left){
	auto temp = array.at(right);

	auto j = left;
	for(auto i = left; i < right; ++i){
		if(array.at(i) < temp){
			j++;
			std::swap(array.at(i), array.at(j));
		}
	}
	std::swap(array.at(j), array.at(right));

	return j + 1;

}


void quick_sort(std::vector<int> &array, std::vector<int>::size_type left, std::vector<int>::size_type right){

	if(left >= right)
		return;
	auto t = divide(array, left, right);
	quick_sort(array, left, t - 1);
	quick_sort(array, t + 1, right);
}
