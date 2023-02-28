#include <iostream>
#include <fstream>
#include <string>
#include "fileParser.h"
#include "userInteraction.h"

namespace{
	struct args{
		bool isHelp;
		std::string inputFileName;
		std::string outputFileName;
	};

	args parseArgs(const int argc, char* argv[]){
		args ret;
		for(int i = 1; i < argc; i = i+2){
			if (argv[i] == "--help"){
				ret.isHelp = true;
			}
			else if (argv[i] == "--inputFile"){
				ret.inputFileName = std::string(argv[i+1]);
			}
			else if (argv[i] == "--outputFile"){
				ret.outputFileName = std::string(argv[i+1]);
			}
		}
		
		return std::move(ret);
	}

}

int main(int argc, char* argv[]){
	// we require two arguments at minimum
	if (argc < 2){
		std::cerr << "Error, inproper number of arguments supplied.\nAt least an input file or --help must be specified." << std::endl; 
		return EXIT_FAILURE;
	}

	auto args = parseArgs(argc, argv);
	
	// help case
	if (args.isHelp){
		userInteraction::printHelp();
		return EXIT_SUCCESS;
	}
	
		
}
