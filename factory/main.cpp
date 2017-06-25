#include <thread>
#include <iostream>
#include "TZoo.h"
#include "TAnimal.h"
#include "TArtiodactyla.h"
#include "TCarnivora.h"
#include "TProboscidea.h"
#include "TElephants.h"
#include "TGiraffa.h"
#include "THippopotamus.h"
#include "TLeo.h"
#include "TLoxodonta.h"
#include "TTigris.h"


int main()
{
	TZoo myZoo(100);

	TAnimal * giraffa_1 = new TGiraffa("Penelopa", 0, myZoo, false);
	TAnimal * tiger_2 = new TTigris("Jim", 0, myZoo, true);
	TAnimal * loxodonta_2 = new TLoxodonta("Water", 0, myZoo, true);
	TAnimal * elephant_1 = new TElephants("Fly", 0, myZoo, true);
	TAnimal * giraffa_2 = new TGiraffa("Ron", 0, myZoo, true);
	TAnimal * elephant_2 = new TElephants("Dina", 0, myZoo, false);
	TAnimal * tiger_1 = new TTigris("Luiza", 0, myZoo, false);
	TAnimal * loxodonta_1 = new TLoxodonta("Rima", 0, myZoo, false);

	TZoo myzoo_2(100);

	tiger_1->ChangeZoo(myzoo_2);
	tiger_2->ChangeZoo(myzoo_2);

	for (size_t i = 0; i < 100; ++i)
	{
		myZoo.Work();
		myzoo_2.Work();
		std::cout << "Work" << std::endl;
		
		std::this_thread::sleep_for(std::chrono::seconds(0));
	}
	system("pause");
}