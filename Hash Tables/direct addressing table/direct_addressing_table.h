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

	void direction_address_delete(const std::pair<unsigned, T>& x);

	inline unsigned size() const { return table.size(); }

protected:
	std::vector<std::pair<unsigned, T>> table;
private:
	void copy(const direct_addressing_table& rhs);
};

#endif // !DIRECT_ADDRESSING_TABLE_H

