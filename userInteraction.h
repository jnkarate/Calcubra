#include <string>
#include <iostream>
#include <string_view>

class userInteraction{
	public:
		static void printHelp() {std::cout << HelpText << std::endl;}
	private:
		static constexpr std::string_view HelpText = "Use --inputFile to specify an input and --outputFile to specify an output file"; 

};
