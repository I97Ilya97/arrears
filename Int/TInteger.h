#include <iostream>
#include <exception>

#define MAX_VALUE 2147483647
#define MIN_VALUE -2147483647

class excess:
	public std::exception
{
public:
	const char * what () const 
	{
		return "Error!";
	}
};

class TInteger
{
	int Sum;
public:
	TInteger();
	~TInteger();
	TInteger(long long int sum);
	bool Check(long long int sum1);
	TInteger& operator = (const TInteger &obj);
	TInteger& operator = (const long long int data);

	bool operator == (const TInteger &rhs);

	TInteger& operator += (const TInteger &obj);
	TInteger& operator -= (const TInteger &obj);
	TInteger& operator /= (const TInteger &obj);
	TInteger& operator *= (const TInteger &obj);
	TInteger& operator %= (const TInteger &obj);

	bool operator == (const long long int data);
	
	TInteger& operator += (const long long int sum);
	TInteger& operator -= (const long long int sum);
	TInteger& operator /= (const long long int sum);
	TInteger& operator *= (const long long int sum);
	TInteger& operator %= (const long long int sum);

	friend std::ostream & operator<<(std::ostream &, const TInteger &);

};

TInteger operator + (const TInteger &a, const TInteger &b);
TInteger operator - (const TInteger &a, const TInteger &b);
TInteger operator * (const TInteger &a, const TInteger &b);
TInteger operator / (const TInteger &a, const TInteger &b);
TInteger operator % (const TInteger &a, const TInteger &b);

TInteger operator + (const TInteger &a, const long long int sum);
TInteger operator - (const TInteger &a, const long long int sum);
TInteger operator * (const TInteger &a, const long long int sum);
TInteger operator / (const TInteger &a, const long long int sum);
TInteger operator % (const TInteger &a, const long long int sum);

TInteger operator + (const long long int sum, const TInteger &a);
TInteger operator - (const long long int sum, const TInteger &a);
TInteger operator * (const long long int sum, const TInteger &a);
TInteger operator / (const long long int sum, const TInteger &a);
TInteger operator % (const long long int sum, const TInteger &a);
