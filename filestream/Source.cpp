#define _CRT_SECURE_NO_WARNINGS



#include "Filestream.h"

#include <iostream>

#include <string>





int main()

{

	TFilestream fl;

	fl.open("./Text.txt");



	std::string s;



	fl >> s;



	std::cout << s;



	fl.close();
	
}
