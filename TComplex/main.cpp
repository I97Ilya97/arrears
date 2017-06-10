#include <iostream>
#include "Complex.h"
#include <string>

using namespace std;

int main()
{
    Complex c(10, 150.5),
    b(201.7988815, 4685.1354665), d;
    cout<<"b = "<<b.real()<<", "<<b.imag()<<"\n";
    cout<<"c = "<<c.real()<<", "<<c.imag()<<"\n";
   n"<<b<<"\n";
    d = b*c;
    cout<<"b*c = "<<d.real()<<", "<<d.imag()<<"\n";
    d = b/c;
    cout<<"b/c = "<<d.real()<<", "<<d.imag()<<"\n";
    d = b+c;
    cout<<"b+c = "<<d.real()<<", "<<d.imag()<<"\n";
    d+=c;
    cout<<"d+=c = "<<d.real()<<", "<<d.imag()<<"\n";
    d = -c;
    cout<<"-c = "<<d.real()<<", "<<d.imag()<<"\n";
    cout << "Hello world!" << endl;
    return 0;
}
