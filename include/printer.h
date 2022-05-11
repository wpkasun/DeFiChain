#ifndef PRINTER_H
#define PRINTER_H

#include "app_consts.h"

class Printer
{
public:
	Printer();
	~Printer();
	void print(const MultiPrecFloat &value, const std::size_t &decPlaces) const;

private:

};

#endif