#include"direct_addressing_table.h"


template<typename T>
inline direct_addressing_table<T>::direct_addressing_table(unsigned size): table(size){}

template<typename T>
direct_addressing_table<T>::direct_addressing_table(const direct_addressing_table & rhs){
	copy(rhs);
}

template<typename T>
direct_addressing_table<T>& direct_addressing_table<T>::operator=(const direct_addressing_table & rhs){
	if (this != rhs) copy(rhs);
	return *this;
}

template<typename T>
direct_addressing_table<T>::~direct_addressing_table(){
	table.~vector();
}

template<typename T>
inline const T & direct_addressing_table<T>::direct_address_search(unsigned index) const{
	 return table[index].second;
}

template<typename T>
void direct_addressing_table<T>::direct_address_insert(const std::pair<unsigned, T>& x){
	table[x.first] = x;
}

template<typename T>
void direct_addressing_table<T>::direction_address_delete(const std::pair<unsigned, T>& x){
	table[x.first] = nullptr;
}

template<typename T>
void direct_addressing_table<T>::copy(const direct_addressing_table & rhs) {
	for (auto item : rhs) 
		table.push_back(item);
}
