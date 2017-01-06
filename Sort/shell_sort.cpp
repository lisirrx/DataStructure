//
// Created by 李晗 on 2017/1/6.
//

#include "Sort_functions.hpp"

int shell_sort(std::vector<int> &_array){
	int count = 0 ;
	int j;

	for (int gap = _array.size() >> 1; gap > 0; gap >>= 1)
	{
		for (int i = gap; i < _array.size(); i++)
		{
			int temp = _array[i];
			for (j = i - gap; j >= 0 && _array[j] > temp; j -= gap)
			{
				_array[j + gap] = _array[j];
				count++;
			}
			_array[j + gap] = temp;
		}
	}
	return count;
}

