#pragma once
#include <iostream>

class TAnimal;

const float STEP = 6;

typedef TAnimal *   TPtrAnimal;

class TZoo
{
	


	/// �����
	TPtrAnimal * Animals;

	/// ������������ ����������� ��������
	size_t Capacity;

	/// ���������� ������ � ��������
	size_t NumAnimals;

	/// ����� �����
	float Time;

	float Year;

public:

	TZoo();

	TZoo(size_t capacity);

	bool AddNewAnimal(TAnimal ** newAnimal);

	TZoo(const TZoo & other);

	TZoo & operator =(const TZoo & other);

	bool operator ==(const TZoo & other) const;

	void Work();

	~TZoo();

	size_t GetNumAnimals()  const;

	TPtrAnimal * GetAnimals() const;



};
