#include <iostream>
#include <fstream>
#include <string>
#include "fileParser.h"
#include "userInteraction.h"
#include "problem.h"

namespace{
	struct args{
		bool isHelp;
		std::string inputFileName;
	};

	args parseArgs(const int argc, char* argv[]){
		args ret;
		std::string arg;

		//assume to not be help
		ret.isHelp = false;

		for(int i = 1; i < argc; i = i+2){
			arg = std::string(argv[i]);
			if (arg == "--help"){
				ret.isHelp = true;
			}
			else if (arg == "--inputFile"){
				ret.inputFileName = std::string(argv[i+1]);
			}
		}
		return ret;
	}

}

int main(int argc, char* argv[]){
	// we require two arguments at minimum
	if (argc != 2){
		std::cerr << "Error, improper number of arguments supplied.\nAt least an input file or --help must be specified." << std::endl; 
		return EXIT_FAILURE;
	}

	auto args = parseArgs(argc, argv);
		
	// help case
	if (args.isHelp){
		userInteraction::printHelp();
		return EXIT_SUCCESS;
	}

	fileParser parser (args.inputFileName);
	problemData data = parser.parse();

	problem userSpecifiedProblem (data);
	userSpecifiedProblem.computeDerivative();
		
}
