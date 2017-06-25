#include "TGiraffa.h"
#include "TElephants.h"
#include "THippopotamus.h"
#include "TLeo.h"
#include "TLoxodonta.h"
#include "TTigris.h"
#include "TZoo.h"
#include "TAnimal.h"
#include <iostream>

class TFactoryMethod
{
public:

	static void NewAnimal(TZoo & zoo)
	{
		for (int i = 0; i < zoo.GetNumAnimals(); ++i)
		{
			if (!zoo.GetAnimals()[i]) continue;
			for (int j = i; j < zoo.GetNumAnimals(); ++j)
			{
				if (!zoo.GetAnimals()[j]) continue;
				if (zoo.GetAnimals()[i]->GetMark() == zoo.GetAnimals()[j]->GetMark() && zoo.GetAnimals()[i]->GetBirthAge() \
					&& zoo.GetAnimals()[j]->GetBirthAge() && zoo.GetAnimals()[i]->GetRod() != zoo.GetAnimals()[j]->GetRod())
				{ 
					zoo.GetAnimals()[i]->AddChild();
					zoo.GetAnimals()[j]->AddChild();
					std::string name;
					std::cout << zoo.GetAnimals()[i]->GetName() << "  and  " << zoo.GetAnimals()[j]->GetName() << "  want to have a baby, please, enter the name of child : ";
					while(name == "") std::cin >> name;
					std::cout << std::endl;
					TAnimal * child = nullptr;
					switch (zoo.GetAnimals()[i]->GetMark())
					{
					case(1) : 
						child = new TGiraffa(name, 0, zoo, rand() % 2); 
						break;
					case(2) :
						child = new THippopotamus(name, 0, zoo, rand() % 2); 
						break;
					case(3) : 
						child = new TElephants(name, 0, zoo, rand() & 2); 		
						break;
					case(4) :
						child = new TLeo(name, 0, zoo, rand() % 2);
						break;
					case(5) : 
						child = new TLoxodonta(name, 0, zoo, rand() % 2);			
						break;
					case(6) :
						child = new TTigris(name, 0, zoo, rand() % 2);
						break;
					}
					std::cout << std::endl << zoo.GetAnimals()[i]->GetName() << " and " << zoo.GetAnimals()[j]->GetName() << " have a child  '" << name << "'  \n";
				}
			}
		}
	}
};