#include <iostream>

template <class T>
void swap(T& v1, T& v2)
{
	T temp = v1;
	v1 = v2;
	v2 = temp;
}

template <class T>
int partition(T* arr, const int low, const int high)
{
	T pivotVal = arr[high];

	int i = low-1;
	for (int j = low; j < high; j++)
	{
		if (arr[j] < pivotVal)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}

	swap(arr[i+1], arr[high]);
	return i+1;

}

template <class T>
void quickSort(T* arr, const int low, const int high)
{
	if (low < high)
	{
		int pivotIdx = partition(arr, low, high);

		quickSort(arr, low, pivotIdx - 1);
		quickSort(arr, pivotIdx + 1, high);
	}
}


int main()
{
	int n;
	std::cin >> n;

	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}

	quickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << std::endl;
	}

	std::cin.get();

	return 0;
}