#include<vector>
#include<algorithm>
#include<iostream>
template<typename T>
 int binarysearch(const std::vector<T>& vector, const T& value){
	if (!std::is_sorted(vector.cbegin(), vector.cend()) || vector.empty())
		throw std::logic_error("Sequence not sorted or vector is empty");
	int begin{}, end( vector.size()), middle{};
	while (begin < end) {
		middle = (begin + end)>>1;

		if (value == vector[middle])
			return middle + 1;
 
		if (value > vector[middle])
			begin = middle + 1;
		else
			end = middle;
	}
	return -1;
}
int main() {
	std::vector<int>v{1, 3, 7, 9, 12, 17};
	std::cout << binarysearch(v, 1);
	system("pause");
	return 0;
}