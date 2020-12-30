#include <iostream>

template <typename T>
void merge(T* arr, const int low, const int mid, const int high)
{
	T* tempArr1 = new T[mid - low + 1];
	T* tempArr2 = new T[high-mid];

	for (int i = low; i <= mid; i++)
		tempArr1[i-low] = arr[i];
	for (int i = mid + 1; i <= high; i++)
		tempArr2[i - (mid + 1)] = arr[i];

	int k = low; // index for arr
	int i = 0, j = 0; // i for tempArr1 , j for tempArr2
	while (i < mid-low+1 && j < high-mid)
	{
		if (tempArr1[i] < tempArr2[j])
		{
			arr[k++] = tempArr1[i++];
		}
		else
		{
			arr[k++] = tempArr2[j++];
		}

	}
	while (i < mid - low + 1)
	{
		arr[k++] = tempArr1[i++];
	}
	while (j < high - mid)
	{
		arr[k++] = tempArr2[j++];
	}

	delete[] tempArr1;
	delete[] tempArr2;
}


template <typename T>
void merge_sort(T* arr, const int low, const int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;

		merge_sort(arr, low, mid);
		merge_sort(arr, mid + 1, high);

		merge(arr, low, mid, high);
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

	merge_sort(arr, 0, n-1);

	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	std::cin.get();

	delete[] arr;

	return 0;
}