#include "problem.h"
#include <string>
#include <iostream>
#include <algorithm>

// build a problem from a text input
problem::problem(problemData problemInformation) {
	std::string currentValue = "";
	for(size_t i = 0; i < problemInformation.problemText.length(); i++){
		if (std::isspace(problemInformation.problemText[i])){
			// remove plus character from string
			if (currentValue[0] == '+'){
				currentValue = currentValue.substr(1,currentValue.length());
			}
			// create a polynomial from the current polynomial
			this->polynomials.push_back(new polynomial(currentValue));
			currentValue = "";
		}
		//omit the addition of the white space to the new value
		else{
			currentValue += problemInformation.problemText[i];
		}
	}

	//make polynomial from last string
	if (currentValue[0] == '+'){
		currentValue = currentValue.substr(1,currentValue.length());
	}
	this->polynomials.push_back(new polynomial(currentValue));
}

//copmute a derivative
void problem::computeDerivative(){
	std::cout << "Original problem: " << *this << std::endl;
	std::cout << "Power rule" << std::endl;
	std::vector<size_t> polynomialsToDelete;

	//find terms to eliminate
	for (size_t i = 0; i < polynomials.size(); i++){
		polynomial* currentPolynomial = polynomials[i];
		int degree = currentPolynomial->getDegree();
		//remove constants from vector as they are now zero after the derivative
		if (degree == 0){
			polynomialsToDelete.push_back(i);
			
		}
	}
	
	//erase polynomials that are eliminated from vector
	for (size_t i = 0; i < polynomialsToDelete.size(); i++){
		polynomial* polynomialToDelete = polynomials[polynomialsToDelete[i]];
		polynomials.erase(polynomials.begin()+polynomialsToDelete[i]);
		delete polynomialToDelete;
	}

	//update remaining polynomials
	for (size_t i = 0; i < polynomials.size(); i++){
		polynomial* currentPolynomial = polynomials[i];
		int oldDegree = currentPolynomial->getDegree();
		currentPolynomial->setDegree(oldDegree-1);
		currentPolynomial->setCoefficient(oldDegree*currentPolynomial->getCoefficient());
	}
	//write to stdandard out
	std::cout << *this << std::endl;
}

//display a problem
std::ostream& operator<<(std::ostream& os, const problem& p){
	//display each polynomial
	for (size_t i = 0; i < p.polynomials.size(); i++){
		os << *(p.polynomials[i]);
		if ( i != p.polynomials.size()-1){
			os << " + ";
		}
	}
	return os;
}

//delete the polynomials storede within the problem
problem::~problem(){
	for (size_t i = 0; i < polynomials.size(); i++){
		delete polynomials[i];
	}
}
