#pragma once
#include "TArtiodactyla.h"
class THippopotamus : public TArtiodactyla
{
public:

	THippopotamus() : TArtiodactyla()
	{}

	THippopotamus(const std::string & name, size_t age, TZoo & zoopark, const bool rod) : TArtiodactyla(name, age, zoopark, rod)
	{}

	virtual ~THippopotamus() = default;
	virtual void Live(float time) override
	{
		if (time >= 12.f && time <= 14.f)
			std::cout << "Hippopotamus  '" << GetName() << "'  is eating" << std::endl;
		else if (time >= 19.f && time <= 10.f)
			std::cout << "Hippopotamus  '" << GetName() << "'  is sleeping" << std::endl;
		else if (time >= 10.f && time <= 12.f)
			std::cout << "Hippopotamus  '" << GetName() << "'  is going" << std::endl;
		else if (time >= 14.f && time <= 17.f)
			std::cout << "Hippopotamus  '" << GetName() << "'  is swimming" << std::endl;
		else
			std::cout << "Hippopotamus  '" << GetName() << "'  is lying" << std::endl;
	}

	virtual int GetMark() const override
	{
		return 2;
	}

	virtual bool GetBirthAge() const override
	{
		return Age == 6 && NumChild < 3;
	}

	virtual bool Old() const override
	{
		if (Age > 16)
		{
			std::cout << std::endl << this->GetName() << " died, it's was 14 years old" << std::endl;
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

