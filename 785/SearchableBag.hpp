#ifndef SEARCHABLE_BAG_HPP
# define SEARCHABLE_BAG_HPP

#include "Bag.hpp"

class SearchableBag : virtual public Bag
{
	public:
		virtual bool has(int) const = 0;
};

#endif