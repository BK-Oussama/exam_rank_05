#pragma once
#include "../searchable_bag.hpp"

class set {
	public:
		set(searchable_bag &);
		~set();
		void insert(int);
  		void insert(int *, int);
		void print() const;
		void clear();
		bool has(int item) const;
		const searchable_bag & get_bag() const;

	private:
		searchable_bag &bag;
};