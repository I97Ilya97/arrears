#pragma once
#include "TProboscidea.h"
class TLoxodonta : public TProboscidea
{
public:

	TLoxodonta() : TProboscidea()
	{}

	TLoxodonta(const std::string & name, size_t age, TZoo & zoopark, const bool rod) : TProboscidea(name, age, zoopark, rod)
	{}

	virtual ~TLoxodonta() = default;
	virtual void Live(float time) override
	{
		if (time >= 7.f && time <= 11.f)
			std::cout << "Loxodonta  '" << GetName() << "'   eating" << std::endl;
		else if (time >= 20.f && time <= 6.f)
			std::cout << "Loxodonta  '" << GetName() << "'   sleeping" << std::endl;
		else if (time >= 11.f && time <= 16.f)
			std::cout << "Loxodonta  '" << GetName() << "'  walking" << std::endl;
		else if (time >= 16.f && time <= 17.f)
			std::cout << "Loxodonta  '" << GetName() << "'   swimming" << std::endl;
		else
			std::cout << "Loxodonta  '" << GetName() << "'   lying" << std::endl;
	}

	virtual int GetMark() const  override
	{
		return 5;
	}

	virtual bool GetBirthAge() const override
	{
		return Age == 9 && NumChild < 3;
	}

	virtual bool Old() const override
	{
		if (Age > 10)
		{
			std::cout << std::endl << this->GetName() << " died, it's was 10 years old" << std::endl;
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

