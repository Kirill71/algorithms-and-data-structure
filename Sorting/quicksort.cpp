#include <iostream>
#include<array>

template<typename T, unsigned SIZE>
void quicksort(std::array<T, SIZE>& arr, int p, int r);

template<typename T, unsigned SIZE>
int partition(std::array<T, SIZE>& arr, int p, int r);

int main() {
	std::array<int, 8> arr{ 2,8,7,1,3,5,6,4 };
	quicksort(arr, 0, arr.size() - 1);

	for (auto item : arr) {
		std::cout << item << "  ";
	}
	system("pause");
	return 0;
}

template<typename T, unsigned SIZE>
void quicksort(std::array<T, SIZE>& arr, int p, int r) {
	if (p < r) {
		int q = partition(arr, p, r);
		quicksort(arr, p, q - 1);
		quicksort(arr, q + 1, r);
	}
}

template<typename T, unsigned SIZE>
int partition(std::array<T, SIZE>& arr, int p, int r) {
	T x = arr[r];
	int i = p - 1;
	for (unsigned j = p; j <= r - 1; ++j) {
		if (arr[j] >= x) {
			++i;
			std::swap(arr[i], arr[j]);
		}
	}
	std::swap(arr[i + 1], arr[r]);
	return i + 1;
}