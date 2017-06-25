#include "Tinteger.h"
#include <locale.h>

 using namespace std;

int main() 
{
	setlocale(LC_ALL, "rus");
	TInteger a(3);
	TInteger b(9);

	cout << a << endl << b << endl;
	a += b;
	cout << "Сложение: " << a << endl;
	a -= b;
	cout << "Вычитание: " << a << endl;
	a *= b;
	cout << "Умножение: " << a << endl;
	a = a / b;
	cout << "Деление: " << a << endl;
	a /= b;
	cout << "Деление: " << a << endl;
	a = b;
	cout << "Приравнивание: " << a << endl;

	system("pause");
	return 0;
}
