#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <math.h>


class Complex
{
public:
    Complex();
    Complex(double re_new, double im_new);
    Complex& operator=(Complex& a);
    double real();
    double imag();
    void real(const double re_new);
    void imag(const double im_new);
    Complex& operator+=(Complex& right);
    Complex& operator-=(Complex& right);
    Complex& operator*=(Complex& right);
    Complex& operator/=(Complex& right);

    double abs();
    double arg();
    double norm();
    Complex& conj();
    void polar(const double magnitude, const double angle);
    friend Complex& operator+ (Complex& a);
    friend Complex& operator- (Complex& a);

    friend Complex& operator+ (Complex& a, Complex& b);
    friend Complex& operator- (Complex& a, Complex& b);
    friend Complex& operator* (Complex& a, Complex& b);
    friend Complex& operator/ (Complex& a, Complex& b);
    friend bool operator== (Complex& a, Complex& b);
    friend bool operator!= (Complex& a, Complex& b);
    ///String to complex
    friend Complex& operator<< (Complex& a, std::string s);
    ///Complex to string
    friend std::string operator<< (std::string s, Complex& a);

private:
    double re;
    double im;
};

