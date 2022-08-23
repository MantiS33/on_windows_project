#pragma once

#include <iostream>
#include <ctime>



template<typename Ttype>
void BubbleSort(Ttype& array, int& size)
{
	for (int i = 0; i + 1 < size; ++i)
	{
		for (int j = 0; j + 1 < size - i; ++j)
		{
			if (array[j + 1] < array[j])
			{
				swap(array[j], array[j + 1]);
			}
		}
	}
}


template<typename Ttype>
void ShakerSort(Ttype& array, int& size)
{
	int left = 0;
	int right = size - 1;
	while (left <= right)
	{
		for (int i = left; i < right; ++i)
		{
			if (array[i] > array[i + 1])
			{
				swap(array[i], array[i + 1]);
			}
		}
		--right;
		for (int i = right; i > left; --i)
		{
			if (array[i - 1] > array[i])
			{
				swap(array[i - 1], array[i]);
			}
		}
		++left;
	}
}

template<typename Ttype>
void CombSort(Ttype& array, int& size)
{
	const double factor = 1.247;
	double step = static_cast<double>(size - 1);

	while (step >= 1)
	{
		for (int i = 0; i + step < size; ++i)
		{
			if (array[i] > array[i + step])
			{
				swap(array[i], array[i + step]);
			}
		}
		step /= factor;
	}
	BubbleSort(array, size);
}

template<typename Ttype>
void InsertionSort(Ttype& array, int& size)
{
	for (int i = 1; i < size; ++i)
	{
		Ttype x = array[i];
		int j = i;
		while (j > 0 && array[j - 1] > x)
		{
			array[j] = array[j - 1];
			--j;
		}
		array[j] = x;
	}
}