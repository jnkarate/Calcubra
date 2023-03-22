#ifndef _PROBLEM_
#define _PROBLEM_
#include <string>
#include <vector>
#include "fileParser.h"
#include "polynomial.h"

class problem{
	public:
		problem(problemData);
		void computeDerivative();
		friend std::ostream& operator<<(std::ostream& os, const problem& p);
		~problem();

	private:
		std::vector<polynomial*> polynomials;
};

#endif

