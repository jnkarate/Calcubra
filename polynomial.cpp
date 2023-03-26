#include "polynomial.h"
#include <iostream>

namespace {
	//enum to determine what value is currently being read
	enum class readingFrom {
		coeff,
		exponent
	};
}

polynomial::polynomial(std::string polyText) {
	readingFrom currentlyReading = readingFrom::coeff;
	std::string currentValue = "";
	//loop over the entire polynomial
	for (size_t i = 0; i < polyText.length(); i++) {
		if (!std::isdigit(polyText[i])) {
			//save coefficient
			if (currentlyReading == readingFrom::coeff) {
				this->coefficient = std::atoi(currentValue.c_str());
				currentlyReading = readingFrom::exponent;
				currentValue = "";
			}
			//save exponent
			else if (currentValue != ""){
				this->degree = std::atoi(currentValue.c_str());
			}
		}
		else {
			currentValue += polyText[i];
		}
	}
	this->degree = std::atoi(currentValue.c_str());
}

//display a polynomial
std::ostream& operator<<(std::ostream& os, const polynomial& p){
	os << p.coefficient << "X^" << p.degree;
	return os;
}

