#include <iostream>
#include "headers/JSONParser.h"
#include "JPage.h"
int main()
{
	JSONParser p("./exemple.piff");
	JSONEntity *o;
	o = p.parse();
	Page P;
	P.fromJson(o);
	std::cout << (*o)["data"][0]["type"] << std::endl;
	return 0;
}