#include <iostream>

int main()
{
	// ��� ���� ���� ��
	int n;
	std::cin >> n;

	// ���ڵ� �Է�
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}

	// bubble sort
	while (true)
	{
		bool is_sorted = true;

		for (int i = 1; i < n; i++)
		{
			// swap
			if (arr[i - 1] > arr[i])
			{
				is_sorted = false;

				int temp = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = temp;
			}
		}

		if (is_sorted) break;
	}


	// print result
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	std::cin.get();

	return 0;
}