#pragma once

#include "TArtiodactyla.h"
class TGiraffa : public TArtiodactyla
{
public:

	

	TGiraffa() : TArtiodactyla()
	{}

	TGiraffa(const std::string & name, size_t age, TZoo & zoopark, const bool rod) : TArtiodactyla(name, age, zoopark, rod)
	{}

	virtual ~TGiraffa() = default;

	virtual void Live(float time) override
	{
		if (time >= 9.f && time <= 13.f)
			std::cout << "Giraffa  '" << GetName() <<  "'  is walking"  << std::endl;
		else if (time >= 23.f && time <= 8.f)
			std::cout << "Giraffa  '" << GetName() << "'  is sleeping" << std::endl;
		else if (time >= 13.f && time <= 14.f)
			std::cout << "Giraffa  '" << GetName() << "'  is swimming it the river" << std::endl;
		else if (time >= 8.f && time <= 9.f)
			std::cout << "Giraffa  '" << GetName() << "'  is lying" << std::endl;
		else if (time >= 0.f && time <= 0.5)
			std::cout << "Giraffa  '" << GetName() << "'  is running" << std::endl;
		else if (time >= 0.5 && time <= 1.f)
			std::cout << "Giraffa  '" << GetName() << "'  is smilling" << std::endl;
		else 
			std::cout << "Giraffa  '" << GetName() <<"'  is eating leaves" << std::endl;
	}

	virtual int GetMark() const override
	{
		return 1;
	}

	virtual bool GetBirthAge() const override
	{
		return Age == 9 && NumChild < 4;
	}

	virtual bool Old() const override
	{
		if (Age > 18)
		{
			std::cout << std::endl << this->GetName() << "  died, it's was 14 years old" << std::endl;
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

