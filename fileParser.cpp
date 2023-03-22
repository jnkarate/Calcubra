#include "fileParser.h"
#include <string>
#include <fstream>

namespace{
	enum class currentlyReading{
		typeOfProblem,
		problemText,
		done
	};
}

problemData fileParser::parse(){
	problemData ret;
	
	// open file
	std::ifstream problemFile {this->InputFile};

	std::string line;
	currentlyReading currentItemToRead = currentlyReading::typeOfProblem;
	//read from file line by line
	while (problemFile){
		std::getline(problemFile, line);
		//if first lien check if problem is algebra or calculus
		if (currentItemToRead == currentlyReading::typeOfProblem){
			ret.isAlgebra = (line == "algebra");
			currentItemToRead = currentlyReading::problemText;
		}
		//in all other cases get the problem text
		else if (currentItemToRead == currentlyReading::problemText){
			ret.problemText = line;
			currentItemToRead = currentlyReading::done;
		}
	}
	problemFile.close();
	
	return ret;
}

