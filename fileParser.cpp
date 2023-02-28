#include "fileParser.h"
#include <string>
#include <fstream>

problemData fileParser::parse(){
	problemData ret;
	
	// open file
	std::ifstream problemFile {this->InputFile};

	std::string line;
	int counter = 0;
	//read from file line by line
	while (problemFile){
		std::getline(problemFile, line);
		//if first lien check if problem is algebra or calculus
		if (counter == 0){
			ret.isAlgebra = (line == "algebra");
		}
		//in all other cases get the problem text
		else{
			ret.problemText = line;
		}
	}
	problemFile.close();
	
	return std::move(ret);
}

