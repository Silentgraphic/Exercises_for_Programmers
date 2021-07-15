#pragma once

class ITaxCal {
public:
	virtual unsigned long int calculateTotalExTax() = 0;
	virtual unsigned long int calculateTotalIncTax() = 0;
};