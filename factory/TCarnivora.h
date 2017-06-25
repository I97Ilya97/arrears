#pragma once
#include "TAnimal.h"
class TCarnivora : public TAnimal
{
public:
	TCarnivora() : TAnimal()
	{}

	TCarnivora(const std::string & name, size_t age, TZoo & zoopark, const bool rod) : TAnimal(name, age, zoopark, rod)
	{}

	virtual ~TCarnivora() = default;

	
	
	
};

