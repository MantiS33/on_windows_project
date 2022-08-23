// sorting-vs.cpp: определяет точку входа для приложения.
//

#include "sorting-vs.h"
using namespace std;

template<typename Ttype>
void Output(Ttype& array, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << array[i] << endl;
	}
}

int main(void)
{
	int main_array[100000];
	int size = 100000;
	int* temp_array = new int[size];
	
	srand(time(0));
	for (int i = 0; i < size; ++i)
	{
		main_array[i] = rand();
	}

	for (int i = 0; i < size; ++i)
	{
		temp_array[i] = main_array[i];
	}

	cout << time(0) << endl;
	BubbleSort(temp_array, size);
	cout << time(0) << endl;
	delete[] temp_array;
	cout << time(0) << endl;
	return 0;
}
