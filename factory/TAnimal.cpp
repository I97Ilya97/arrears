#include "TAnimal.h"


TAnimal::TAnimal() : Name(), Age(0)
{}

TAnimal::TAnimal(const std::string & name, size_t age, TZoo & zoopark, const bool rod)
{
	Name = name;
	Age = age;
	Rod = rod;
	TAnimal * p = this;
	if (!zoopark.AddNewAnimal(&p)) delete[] this;  
	Zoopark = zoopark;
}

std::string TAnimal::GetName() const
{
	return Name;
}

void TAnimal::AddChild()
{
	++NumChild;
}

void TAnimal::ChangeZoo(TZoo & other)
{
	if (other == Zoopark) return;
	TAnimal * p = this; 
	if (other.AddNewAnimal(&p)) Zoopark = other;
	return;
}

void TAnimal::Grow()
{
	Age++;
}

bool TAnimal::operator !=(const TAnimal & other) const
{
	return (Age != other.Age && Rod != other.Rod && Name != other.Name && !(Zoopark == other.Zoopark));
}

bool TAnimal::GetRod() const
{
	return Rod;
}



