#include<array>
#include<iostream>

template<typename T, unsigned SIZE>
void bublesort(std::array<T, SIZE>& arr);

int main() {
	std::array<int, 10> arr{ 4,3,4,54,6,5,76,7,5,8 };
	bublesort(arr);

	for (auto item : arr) {
		std::cout << item << " ";
	}
	system("pause");
}

template<typename T, unsigned SIZE>
void bublesort(std::array<T, SIZE>& arr) {

	for (unsigned i = 0; i < arr.size() - 1; ++i) {
		for (unsigned j = i + 1; j < arr.size(); ++j) {
			if (arr[i] > arr[j]) {
				std::swap(arr[i], arr[j]);
			}
		}
	}
}