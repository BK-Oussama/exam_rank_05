#include "set.hpp"

set::set(searchable_bag &bg) : bag(bg){}

set::~set(){}

void set::insert(int value){
	if (!bag.has(value))	
		bag.insert(value);
}

void set::insert(int *items, int size){
	for (int i = 0; i < size; i++){
		if (!bag.has(items[i]))	
			bag.insert(items[i]);	
	}
}

void set::print() const{
	bag.print();
}

void set::clear(){
	bag.clear();
}

bool set::has(int item) const{
	return bag.has(item);
}

const searchable_bag & set::get_bag() const{
	return bag;
}