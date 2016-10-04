#include<iostream>
#include<array>

template< typename T, unsigned SIZE>
void selectionsort(std::array<T, SIZE>& arr);

int main()
{
	std::array<int, 10> arr{9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	selectionsort(arr);
	for (auto item : arr) {
		std::cout << item << " ";
	}
	system("pause");
}

template< typename T, unsigned SIZE>
void selectionsort(std::array<T, SIZE>& arr)
{
	unsigned min,max, n,size;
	n = arr.size() - 1;
	size = n / 2;
	for (unsigned i = 0; i <= size; ++i)
	{
		min = i;
		max = n - i;
		for (unsigned j = i; j < n - i; ++j)
		{
			if (arr[j + 1] < arr[min]) 
				min = j + 1;
			if (arr[j] > arr[max]) 
				max = j;
		}
		if (arr[i] == arr[max])  
			max = min;
		std::swap(arr[i], arr[min]);
		if (arr[n - i] == arr[min])
			min = max;
		std::swap(arr[n - i], arr[max]);
	}
}