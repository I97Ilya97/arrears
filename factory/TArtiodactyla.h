#pragma once
#include <iostream>
#include "TAnimal.h"

class TArtiodactyla : public TAnimal
{
public:

	TArtiodactyla() : TAnimal()
	{}

	TArtiodactyla(const std::string & name, size_t age, TZoo & zoopark, const bool rod) : TAnimal(name, age, zoopark, rod)
	{}

	virtual ~TArtiodactyla() = default;

	
	
};

