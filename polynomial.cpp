#include "polynomial.h"
#include <iostream>

namespace {
	enum class readingFrom {
		coeff,
		exponent
	};
}

polynomial::polynomial(std::string polyText) {
	readingFrom currentlyReading = readingFrom::coeff;
	std::string currentValue = "";
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

std::ostream& operator<<(std::ostream& os, const polynomial& p){
	os << p.coefficient << "X^" << p.degree;
	return os;
}

