#ifndef DIRECT_ADDRESSING_TABLE_H
#define  DIRECT_ADDRESSING_TABLE_H
#include<vector>
#include<tuple>

template< typename T>
class direct_addressing_table {

public:
	explicit direct_addressing_table(unsigned size);

	direct_addressing_table(const direct_addressing_table& rhs);

	direct_addressing_table& operator= (const direct_addressing_table& rhs);

	virtual ~direct_addressing_table();
	
	inline const T& direct_address_search(unsigned index) const;

	void  direct_address_insert(const std::pair<unsigned, T>& x);

	void direction_address_delete(unsigned index);

	inline unsigned size() const { return table.size(); }

protected:
	std::vector<std::pair<unsigned, T>> table;

private:
	void copy(const direct_addressing_table& rhs);
	void is_out_of_range(unsigned index) const throw(std::out_of_range);
};

template<typename T>
 const T & direct_addressing_table<T>::direct_address_search(unsigned index) const {
	 is_out_of_range(index);
	return table[index].second;
}
 template<typename T>
 inline direct_addressing_table<T>::direct_addressing_table(unsigned size) : table(size) {}

 template<typename T>
 direct_addressing_table<T>::direct_addressing_table(const direct_addressing_table & rhs) : direct_addressing_table(rhs.size()) {
	 copy(rhs);
 }

 template<typename T>
 direct_addressing_table<T>& direct_addressing_table<T>::operator=(const direct_addressing_table & rhs) {
	 if (this != rhs) 
		 copy(rhs);
	 return *this;
 }

 template<typename T>
 direct_addressing_table<T>::~direct_addressing_table() {
	 table.~vector();
 }

 template<typename T>
 void direct_addressing_table<T>::direct_address_insert(const std::pair<unsigned,T>& x) {
	 is_out_of_range(x.first);
	 table[x.first] = x;
 }

 template<typename T>
 void direct_addressing_table<T>::direction_address_delete(unsigned index) {
	 is_out_of_range(index);
	 // may be bug
	 table[index] = std::pair<unsigned,T>(index,T());
 }

 template<typename T>
 void direct_addressing_table<T>::copy(const direct_addressing_table & rhs) {
	 for (unsigned i = 0; i < table.size(); ++i) {
		 std::pair<unsigned, T> val(i,rhs.table[i].second);
		 direct_address_insert(val);
	 }
		 
 }
 template<typename T>
 void direct_addressing_table<T>::is_out_of_range(unsigned index) const
 {
	 if (index < 0 || index > table.size())
		 throw std::out_of_range("index out of range in hash table");
 }
#endif // !DIRECT_ADDRESSING_TABLE_H

