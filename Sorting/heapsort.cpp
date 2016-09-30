#include<iostream>
#include<array>

int HEAPSIZE;


inline unsigned parent(unsigned);
inline unsigned left(unsigned);
inline unsigned right(unsigned);

template<typename T, unsigned SIZE>
void buildmaxheap(std::array<T, SIZE>& arr);

template<typename T, unsigned SIZE>
void maxheapify(std::array<T, SIZE>& arr , unsigned i);
template<typename T, unsigned SIZE>
void heapsort(std::array<T, SIZE>& arr);

int main()
{
	std::array<int, 8> arr{2,8,7,1,3,5,6,4};
	heapsort(arr);

	for (auto item : arr) {
		std::cout << item << " ";
	}

	system("pause");
	return 0;
}




inline  unsigned parent (unsigned i)
{
	return (i-1)>>1;
}

inline unsigned left(unsigned i)
{
	return (i<<1)+1;
}

inline unsigned right (unsigned i)
{
	return (i<<1)+2;
}

template< typename T, unsigned SIZE>
void maxheapify(std::array<T,SIZE>& arr, unsigned i)
{
	int largest;
	int left_ = left(i);
	int right_ = right(i);
	if (left_ < HEAPSIZE && arr[left_] > arr[i]) largest = left_;
	else largest = i;

	if (right_ < HEAPSIZE && arr[right_] > arr[largest]) largest = right_;

	if (largest != i)
	{
		std::swap(arr[i],arr[largest]);
		maxheapify(arr,largest);
	}
}

template<typename T, unsigned SIZE>
void buildmaxheap(std::array<T, SIZE>& arr)
{
	
	HEAPSIZE = arr.size();
	 for(unsigned i = (arr.size()>>1); i > 0;--i)
		 maxheapify(arr,i - 1);
}


template<typename T, unsigned SIZE>
void heapsort(std::array<T, SIZE>& arr)
{
	buildmaxheap(arr);
	for(unsigned i= arr.size() - 1; i >= 1; --i)
	{
		std::swap(arr[0], arr[i]);
		--HEAPSIZE;
		maxheapify(arr, 0);
	}
}
