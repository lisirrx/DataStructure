//
// Created by 李晗 on 2016/11/6.
//

#include "Sort_functions.hpp"

int maxbit(std::vector<int> data, int n )
{
	int maxData = data[0];

	for (int i = 1; i < n; i++)
	{
		if (maxData < data[i])
			maxData = data[i];
	}
	int d = 1;
	int p = 10;

	while (maxData >= p)
	{
		maxData /= 10;
		++d;
	}

	return d;
}
int radix_sort(std::vector<int> &_array){
	int n = _array.size();
	int d = maxbit(_array, n);
	int *temp = new int[n];
	int *count = new int[10];

	int k;
	int radix = 1;

	for (int i = 1; i <= d; i++)
	{
		for (int j = 0; j < 10; j++)
			count[j] = 0;
		for (int j = 0; j < n; j++)
		{
			k = (_array[j] / radix) % 10;
			count[k]++;
		}
		for (int j = 1; j < 10; j++)
			count[j] = count[j - 1] + count[j];
		for (int j = n - 1; j >= 0; j--)
		{
			k = (_array[j] / radix) % 10;
			temp[count[k] - 1] = _array[j];
			count[k]--;
		}
		for (int j = 0; j < n; j++)
			_array[j] = temp[j];
		radix *= 10;

	}

	delete[] temp;
	delete[] count;

	return 0;

}
