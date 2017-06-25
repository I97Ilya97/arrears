#pragma once
#include <string>
#include <iostream>
#include "TZoo.h"


class TAnimal
{
protected:

	std::string Name;

	size_t Age;

	TZoo Zoopark;

	bool Rod;  //true - мужской, false - женский 

	int NumChild;

public:

	TAnimal();

	TAnimal(const std::string & name, size_t age, TZoo & zoopark, const bool rod);

	virtual ~TAnimal() = default;

	
	virtual void Live(float time) = 0;

	virtual int GetMark() const = 0;

	virtual bool GetBirthAge() const = 0;

	virtual void Grow();

	std::string GetName() const;

	size_t GetAge() const;

	bool GetRod() const;

	virtual bool Old() const = 0;

	bool operator !=(const TAnimal & other) const;

	void ChangeZoo(TZoo & other);

	void AddChild();
};

