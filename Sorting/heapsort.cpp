#include<iostream>
#include<array>

const unsigned N = 20;
int HEAPSIZE;


inline unsigned parent(unsigned);
inline unsigned left(unsigned);
inline unsigned right(unsigned);

template<typename T, unsigned SIZE>
void buildmaxheap(std::array<T, SIZE>);

template<typename T, unsigned SIZE>
void maxheapify(std::array<T, SIZE>, unsigned);
template<typename T, unsigned SIZE>
void heapsort(std::array<T, SIZE>);

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

template< typename T>
void maxheapify(std::array<T,SIZE> arr, unsigned i)
{
	int largest;
	int left = left(i);
	int right = right(i);
	if (left < HEAPSIZE && arr[left] > arr[i]) largest = left;
	else largest = i;

	if (right < HEAPSIZE && arr[right] > arr[largest]) largest = right;

	if (largest != i)
	{
		std::swap(arr[i],arr[largest]);
		maxHeapify(arr,largest);
	}
}

template<typename T, unsigned SIZE>
void buildmaxheap(std::array<T, SIZE> arr)
{
	HEAPSIZE = N;
	 for(unsigned i = (N>>1); i > 0;--i)
		 maxHeapify(arr,i - 1);
}


template<typename T, unsigned SIZE>
void heapsort(std::array<T, SIZE> arr)
{
	buildMaxHeap(arr);
	for(unsigned i= N - 1; i >= 1; --i)
	{
		std::swap(arr[0], arr[i]);
		--HEAPSIZE;
		maxHeapify(arr, 0);
	}
}
