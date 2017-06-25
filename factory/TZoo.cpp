#include "TZoo.h"
#include "TFactoryMethod.h"
#include "TAnimal.h"



TZoo::TZoo(){};


TZoo::TZoo(size_t capacity) : Capacity(capacity), NumAnimals(0), Time(0)
{
	Animals = new TPtrAnimal[Capacity];
	memset(Animals, 0, sizeof(TPtrAnimal)* Capacity);
}

TZoo::TZoo(const TZoo & other)
{
	Capacity = other.Capacity;
	Animals = new TPtrAnimal[Capacity];
	NumAnimals = other.NumAnimals;
	for (size_t i = 0; i < NumAnimals; ++i)
	{
		Animals[i] = other.Animals[i];
	}
	Time = other.Time;
}

TZoo & TZoo::operator =(const TZoo & other)
{
	if (this == &other) return *this;
	Capacity = other.Capacity;
	Animals = new TPtrAnimal[Capacity];
	NumAnimals = other.NumAnimals;
	for (size_t i = 0; i < NumAnimals; ++i)
	{
		Animals[i] = other.Animals[i];
	}
	Time = other.Time;
	return *this;
}

bool TZoo::operator ==(const TZoo & other) const
{
	for (size_t i = 0; i < NumAnimals; ++i)
	{
		if (Animals[i] != other.Animals[i]) return false;
	}
	return (Capacity == other.Capacity && NumAnimals == other.NumAnimals && Time == other.Time);
}

bool TZoo::AddNewAnimal(TAnimal ** newAnimal)
{
	// Проверяем корректность входного параметра
	if (newAnimal == nullptr) return false;

	// Зоопарк полон, нельзя добавить нового зверя
	if (NumAnimals == Capacity) return false;

	// Добавляем зверя в массив
	Animals[NumAnimals] = *newAnimal;

	// Забираем зверя у старого владельца, чтобы не удалить зверя дважды
	//*newAnimal = nullptr;

	// Увеличиваем счетчик
	++NumAnimals;

	return true;
}

void TZoo::Work()
{
	for (size_t i = 0; i < NumAnimals; ++i)
	{
		if (Animals[i] != nullptr)
		{
			// Демонстрация работы динамического полиморфизма
			Animals[i]->Live(Time);
			if(rand() % 2)  TFactoryMethod::NewAnimal(*this);   
			if (Animals[i]->Old())
			{
				Animals[i] = nullptr;
				--NumAnimals;
			}

		}
	}
	Time += STEP;
	if (Time >= 24.f)
	{
		Time -= 24.f;
		Year += 0.5;
	}
	if ((int)Year == Year && Year)
	{
		for (int i = 0; i < NumAnimals; ++i) Animals[i]->Grow();
	}
}


TZoo::~TZoo()
{
	for (size_t i = 0; i < NumAnimals; ++i)
	{
		delete Animals[i];
	}
	delete[] Animals;
}



size_t TZoo::GetNumAnimals()  const
{
	return NumAnimals;
}

TPtrAnimal * TZoo::GetAnimals() const
{
	return Animals;
}