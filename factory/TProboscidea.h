#pragma once
#include "TAnimal.h"
class TProboscidea : public TAnimal
{
public:

	TProboscidea() : TAnimal()
	{}

	TProboscidea(const std::string & name, size_t age, TZoo & zoopark, const bool rod) : TAnimal(name, age, zoopark, rod)
	{}

	virtual ~TProboscidea() = default;
};

