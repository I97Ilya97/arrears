#pragma once
#include "TCarnivora.h"
class TTigris : public TCarnivora
{

public:

	TTigris() : TCarnivora()
	{}

	TTigris(const std::string & name, size_t age, TZoo & zoopark, const bool rod) : TCarnivora(name, age, zoopark, rod)
	{}

	virtual ~TTigris() = default;

	virtual void Live(float time) override
	{
		if (time >= 13.f && time <= 17.f)
			std::cout << "Tigris  '" << GetName() << "'  is eating meat" << std::endl;
		else if (time >= 23.f && time <= 10.f)
			std::cout << "Tigris  '" << GetName() << "'  is sleeping" << std::endl;
		else if (time >= 19.f && time <= 23.f)
			std::cout << "Tigris  '" << GetName() << "'  is running" << std::endl;
		else if (time >= 17.f && time <= 19.f)
			std::cout << "Tigris  '" << GetName() << "'  is going" << std::endl;
		else
			std::cout << "Tigris  '" << GetName() << "'  is hunting" << std::endl;
	}

	virtual int GetMark() const  override
	{
		return 6;
	}

	virtual bool GetBirthAge() const override
	{
		return Age == 6 && NumChild < 3;
	}

	virtual bool Old() const override
	{
	if (Age > 13)
		{
		std::cout << std::endl << this->GetName() << " died, it's was 13 years old" << std::endl;
			return true;
		}
		else if (rand() % 100 > 71 && Zoopark.GetNumAnimals() > 15)
		{
			std::cout << std::endl << this->GetName() << " died because of illness" << std::endl;
			return true;
		}
		else if (rand() % 100 < 8 && Zoopark.GetNumAnimals() > 15)
		{
			std::cout << std::endl << this->GetName() << " died due to weather conditions" << std::endl;
			return true;
		}
		else return false;
	}	
};

