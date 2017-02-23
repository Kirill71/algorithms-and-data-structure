#include<vector>
#include<algorithm>
#include<iostream>

template<typename T>
 int linerysearch(const std::vector<T>& vector, const T& value){
	if (vector.empty())
		throw std::logic_error("Sequence is empty");

	for (auto it{ vector.cbegin() }; it != vector.cend(); ++it) 
		if (*it == value) 
			return std::distance(vector.cbegin(), it) + 1;
	return -1;
}

int main() {
	std::vector<int>v{1, 3, 7, 9, 12, 19};
	std::cout << linerysearch(v, 17);
	system("pause");
	return 0;
}