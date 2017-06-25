#pragma once
#include "TCarnivora.h"
class TLeo : public TCarnivora
{

public:

	TLeo() : TCarnivora()
	{}

	TLeo(const std::string & name, size_t age, TZoo & zoopark, const bool rod) : TCarnivora(name, age, zoopark, rod)
	{}

	virtual ~TLeo() = default;

	virtual void Live(float time) override
	{
		if (time >= 14.f && time <= 17.f)
			std::cout << "Lion  '" << GetName() << "'  " << std::endl;
		else if (time >= 22.f && time <= 11.f)
			std::cout << "Lion  '" << GetName() << "'  is sleeping" << std::endl;
		else if (time >= 11.f && time <= 12.f)
			std::cout << "Lion  '" << GetName() << "'  is growling" << std::endl;
		else if (time >= 17.f && time <= 22.f)
			std::cout << "Lion  '" << GetName() << "'  is lying" << std::endl;
		else
			std::cout << "Lion  '" << GetName() << "'  is hunting" << std::endl;
	}


	virtual int GetMark() const  override
	{
		return 4;
	}

	virtual bool GetBirthAge() const override
	{
		return Age == 6 && NumChild < 3;
	}

	virtual bool Old() const override
	{
		if (Age > 10)
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

