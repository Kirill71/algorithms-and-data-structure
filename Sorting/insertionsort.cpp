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
		while(i >= 0 && arr[i] > key)// сортировка по убыванию а[i]<key если по возрастанию а[i]>key
		{
		  arr[ i + 1] = arr[i];
		  --i;
		};
		arr[i + 1] = key;
	 }
	
	//for(int i = 1; i < arr.size(); ++i)
	//{
	//	for(int j = i-1; j >= 0; --j)
	//	{	if( arr[i] < arr[j])// сортировка по возрастанию а[i]>a[j] сортировка по убыванию
	//	    {
	//	      std::swap(a[i],a[j]);
	//		  --i;
	//	    }
	//	else break;
		//}
	//}
  }

 