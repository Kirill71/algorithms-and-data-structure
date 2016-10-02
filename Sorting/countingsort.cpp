#include <iostream>
#include <array>
#include<vector>

template< typename T, unsigned SIZE>
void countingsort(std::array<T, SIZE> a, std::array<T, SIZE>& b);

int main() {
	std::array<int, 8> a{2,5,3,0,2,3,0,3};
	std::array<int, 8> b;
	countingsort(a, b);
	for (auto item : b) {
		std::cout << item << " ";
	}
	system("pause");
}

template< typename T, unsigned SIZE>
void countingsort(std::array<T, SIZE> a, std::array<T, SIZE>& b) {
	
	auto max = *std::max_element(a.cbegin(), a.cend());
	std::vector<T> c(++max , 0);
	for (unsigned j = 0; j < a.size(); ++j)
		++c[a[j]]; // counting elements

	for (unsigned i = 1; i < c.size(); ++i) {
		c[i] += c[i - 1]; // counting elemnts not more i
	}
	
	for (int j = a.size() - 1; j >= 0; --j) {
		b[c[a[j]] - 1] = a[j]; // write elemrnts to result array
		--c[a[j]];
	}

}