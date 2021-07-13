#pragma once
#include<string>

#include "ICurrency.h"

struct  USD : public ICurrency {
	USD(const long int& priceInCents) :ICurrency(priceInCents) {};

	std::string returnPresentableFormat();
};