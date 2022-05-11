#include "input_reader.h"

#include <iostream>

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        const std::string inputFileName(argv[1]);
        InputReader inputReader;
        inputReader.readInputFile(inputFileName);
    }
    else
    {
        std::cout << "Please provide the input file as an argument." << std::endl;
    }
	return 0;
}