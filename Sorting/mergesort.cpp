#include<iostream>
#include<array>
#include<vector>
#include<limits>

template<typename T, unsigned SIZE>
void mergesort(std::array<T, SIZE>& arr, unsigned p, unsigned r);

template<typename T, unsigned SIZE>
void merge(std::array<T, SIZE>& arr, unsigned p, unsigned q, unsigned r);


unsigned main() {
	std::array<unsigned,10> arr{9,8,7,6,5,4,3,2,1,0};
	mergesort(arr, 0, arr.size() - 1);

	for (auto item : arr) {
		std::cout << item << " ";
	}
	system("pause");
}


template<typename T, unsigned SIZE>
void mergesort(std::array<T, SIZE>& arr, unsigned p, unsigned r) {
	if (p < r) {
		unsigned q = (p + r) / 2;
		mergesort(arr, p, q);
		mergesort(arr, q + 1, r);
		merge(arr, p, q + 1, r);
	}
}

template<typename T, unsigned SIZE>
void merge(std::array<T, SIZE>& arr, unsigned p, unsigned q, unsigned r) {

	unsigned n1 = q - p, n2 = r - q + 1;

	std::vector<T> L(n1 + 1), R(n2 + 1);

	for (unsigned i = 0; i < n1; ++i) 
		L[i] = arr[p + i];

	for (unsigned j = 0; j < n2; ++j)		
		R[j] = arr[q + j];
	
	L[n1] = R[n2] = UINT_MAX;
	
	for (unsigned k = p,i = 0, j = 0; k <= r; ++k) {
 		if (L[i] <= R[j])
			arr[k] = L[i++];
		else
			arr[k] = R[j++];
	}
}
