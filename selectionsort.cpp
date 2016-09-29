#include<iostream>
#include<array>

template< typename T, unsigned SIZE>
void selectionsort(std::array<T, SIZE>& arr);

int main()
{
	std::array<int, 8> arr{ 2,8,7,1,3,5,6,4 };
	selectionsort(arr);
	for (auto item : arr) {
		std::cout << item << " ";
	}
 
	system("pause");
}

template< typename T, unsigned SIZE>
void selectionsort(std::array<T,SIZE>& arr)
{
	unsigned min;
	for (unsigned i = 0; i < arr.size() - 1 ; ++i)
	{
		min = i;
		for (unsigned j = i + 1; j < arr.size(); ++j)
		{
			if (arr[j] < arr[min]) min = j;
			
		}
		std::swap(arr[i], arr[min]);
	}
}