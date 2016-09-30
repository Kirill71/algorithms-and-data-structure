#include<array>
#include<iostream>
template<typename T, unsigned SIZE>
void insertionsort(std::array<T, SIZE>& arr);

int main()
{
	std::array<int, 8> arr{ 2, 8, 7, 1, 3, 5, 6, 4 };
	insertionsort(arr);
	for (auto item : arr) {
		std::cout << item << " ";
	}
    system("pause");
 }
 template<typename T, unsigned SIZE>
  void insertionsort(std::array<T, SIZE>& arr)
  {
	  int  i,j,key;
	 for( j = 1; j < arr.size(); ++j)
	 {
	    key = arr[j];
		i = j - 1;
		while(i >= 0 && arr[i] > key)// descending sorting à[i]<key or ascending sorting à[i]>key
		{
		  arr[ i + 1] = arr[i];
		  --i;
		};
		arr[i + 1] = key;
	 }
  }

 