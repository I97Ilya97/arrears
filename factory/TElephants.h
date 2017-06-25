#pragma once
#include "TProboscidea.h"
class TElephants : public TProboscidea
{
public:

	TElephants() : TProboscidea()
	{}

	TElephants(const std::string & name, size_t age, TZoo & zoopark, const bool rod) : TProboscidea(name, age, zoopark, rod)
	{}

	virtual ~TElephants() = default;
	virtual void Live(float time) override
	{
		if (time >= 10.f && time <= 12.f)
			std::cout << "Elephant  '" << GetName() << "'  is eating" << std::endl;
		else if (time >= 22.f && time <= 9.f)
			std::cout << "Elephant  '" << GetName() << "'  is sleeping" << std::endl;
		else if (time >= 9.f && time <= 10.f)
			std::cout << "Elephant  '" << GetName() << "'  is going" << std::endl;
		else if (time >= 12.f && time <= 13.f)
			std::cout << "Elephant  '" << GetName() << "'  is swimming" << std::endl;
		else
			std::cout << "Elephant  '" << GetName() << "'  is walking" << std::endl;
	}

	virtual int GetMark() const
	{
		return 3;
	}

	virtual bool GetBirthAge() const override
	{
		return Age == 6 && NumChild < 4;
	}

	virtual bool Old() const override
	{
		if (Age > 8)
		{
			std::cout << std::endl << this->GetName() << " died, it's was 8 years old" << std::endl;
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

