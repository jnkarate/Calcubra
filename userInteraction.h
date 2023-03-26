#include <string>
#include <iostream>
#include <string_view>

//used for handling user interaction
class userInteraction{
	public:
		static void printHelp() {std::cout << HelpText << std::endl;}
	private:
		static constexpr std::string_view HelpText = "Use --inputFile to specify an input file"; 

};
