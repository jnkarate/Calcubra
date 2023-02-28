#ifndef FILEPARSER
#define FILEPARSER
#include <string>

struct problemData{
	bool isAlgebra;
	std::string problemText;
};

class fileParser{
	private:
		std::string InputFile;
	public:
		fileParser(std::string fileName) : InputFile(fileName) {}
		problemData parse();
};


#endif

