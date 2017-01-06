//
// Created by 李晗 on 2017/1/6.
//
#include "Sort_functions.hpp"



int select_sort(std::vector<int>& data)
{
	int count = 0;
	int max = 0;

	for (int i = 0; i < data.size(); i++)
	{
		for (int j = i; j < data.size(); j++)
		{

			if (data[max] < data[j])
			{
				max = j;
			}
		}
		count++;
		std::swap(data[i], data[max]);
	}

	return count;

}

