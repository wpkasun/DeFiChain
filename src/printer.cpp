#include "printer.h"

#include <iostream>

Printer::Printer()
{
}

Printer::~Printer()
{
}

void Printer::print(const MultiPrecFloat &value, const std::size_t &decPlaces) const
{
    const std::string str(value.str(numOfPrecision, std::ios_base::fixed));
    std::string finalValStr;
    std::size_t pos = str.find(".");
    if (pos == std::string::npos)
    {
        finalValStr = str;
    }
    else
    {
        finalValStr = str.substr(0, pos);
        finalValStr.append(".");
        finalValStr.append(str.substr(pos + 1, decPlaces));
    }
    std::cout << finalValStr << std::endl;
}
