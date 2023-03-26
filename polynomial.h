#ifndef POLYNOMIAL
#define POLYNOMIAL
#include <string>

class polynomial
{
private:
	// represent a polynomial in the form:
	// (coefficient)(X)^(degree)
	int degree;
	int coefficient;

public:
	polynomial(std::string polynomialText);

	//getters and setters
	void setDegree(int degree) {this->degree = degree;}
	int getDegree() {return degree;}
	void setCoefficient(int coefficient) {this->coefficient = coefficient;}
	int getCoefficient(){return coefficient;}

	//used for displaying the polynomial
	friend std::ostream& operator<<(std::ostream& os, const polynomial& p);
};

#endif

