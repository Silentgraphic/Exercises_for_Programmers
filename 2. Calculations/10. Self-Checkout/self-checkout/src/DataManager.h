#pragma once
#include<vector>
#include <utility>

#include "ICurrency.h"
#include "IItem.h"
#include "ITaxCal.h"

template <class C>
class DataManager {
public:
	DataManager();

	~DataManager();

	std::vector<IItem*> items;

	template<class T>
	void getItems();

private:
	//I feel like I should abstract the prices down a level but I can't think of a way how
	std::vector<ICurrency*> prices;
	void getUserIntput();
};

template<class C>
template<class T>
inline void DataManager<C>::getItems() {
	//Sanity checks just to make sure templates are correct
	static_assert(std::is_base_of<IItem, T>::value, "T not derived from IItem");

	for (size_t i = 0; i < 3; i++) {
		getUserIntput();
		//Shoult I switch to a smart pointer??
		items.push_back(new T(*prices[i]));
		items.at(i)->calculateTotal(1);
	};
}

template<class C>
DataManager<C>::DataManager() {
}

template<class C>
void DataManager<C>::getUserIntput() {
	static_assert(std::is_base_of<ICurrency, C>::value, "C not derived from ICurrency");
	long int userValue = 1000;
	prices.push_back(new C(userValue));
}

template<class C>
DataManager<C>::~DataManager() {
	for (ICurrency* i : prices) {
		delete i;
	};
	for (IItem* i : items) {
		delete i;
	};
	prices.clear();
	items.clear();
}