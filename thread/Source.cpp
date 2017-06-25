#include <iostream>

#include <future>

#include "InfInt.h"




InfInt factorial(InfInt &n)

{

	InfInt result = 1;

	for (InfInt i = 1; i <= n; ++i)

	{

		result *= i;

	}

	return  result;

}



int main()

{

	std::cout << "Enter n and k. C(n, k)" << std::endl;



	InfInt n = 0;

	InfInt k = 0;



	std::cin >> n;

	std::cin >> k;



	if (k > n || k < 0 || n < 0)

	{

		std::cout << "error" << std::endl;

		system("pause");

		return -1;

	}



	auto fact_n = std::async(factorial, n);

	auto fact_k = std::async(factorial, k);

	auto fact_n_k = std::async(factorial, n - k);



	auto num = fact_n.get();

	auto den1 = fact_n_k.get();

	auto den2 = fact_k.get();



	InfInt result = num / (den1 * den2);



	std::cout << result << std::endl;



	system("pause");



	return 0;

}
