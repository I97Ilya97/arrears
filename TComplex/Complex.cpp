#include "Complex.h"

Complex::Complex(){}
Complex::Complex(double re_new, double im_new){
    re = re_new;
    im = im_new;
}

Complex& Complex::operator=(Complex& a){
    if(this==(&a)){
        return *this;
    }
    real(a.real());
    imag(a.imag());
    return *this;
}
double Complex::real(){
    return re;
}
double Complex::imag(){
    return im;
}
void Complex::real(const double re_new){
    re = re_new;
}
void Complex::imag(const double im_new){
    im = im_new;
}
Complex& Complex::operator+=(Complex& right){

    im = im + right.imag();
    re = re + right.real();
    return *this;
}
Complex& Complex::operator-=(Complex& right){
    im = im - right.imag();
    re = re - right.real();
    return *this;
}
Complex& Complex::operator*=(Complex& right){
    double l_re = re, l_im = im;
    re = (l_re * right.real()) - (l_im * right.imag());
    im = (l_re * right.imag()) + (l_im * right.real());
    return *this;
}
Complex& Complex::operator/=(Complex& right){
    double l_re = re, l_im = im;
    double divider = ((right.real()*right.real()) + (right.imag() * right.imag()));
    re = ((l_re*right.real()) + (l_im*right.imag()))/divider;
    im = ((l_im*right.real()) - (l_re*right.imag()))/divider;
    return *this;

}

double Complex::abs(){
    return sqrt((re * re)+(im * im));
}
double Complex::arg(){
    return atan(re/im);
}
double Complex::norm(){
    return ((re*re)+(im*im));
}
Complex Complex::conj(){
    Complex retval (re, -im);
    return retval;
}
void Complex::polar(const double magnitude, const double angle){
    re = magnitude * cos(angle);
    im = magnitude * sin(angle);
}

Complex operator+ (Complex& a){
    Complex retval(a.real(), a.imag());
    return retval;
}
Complex operator- (Complex& a){
    Complex retval(-a.real(), -a.imag());
    return retval;

}

Complex operator+ (Complex& a, Complex& b){
    Complex retval(a.real() + b.real(), a.imag() + b.imag())
    return retval;
}
Complex operator- (Complex& a, Complex& b){
    Complex retval(a.real() - b.real(), a.imag() - b.imag());
    return retval;
}
Complex operator* (Complex& a, Complex& b){
    double ret_re, ret_im;

    ret_re = (a.real() * b.real()) - (a.imag() * b.imag());
    ret_im = (a.real() * b.imag()) + (a.imag() * b.real());
    Complex retval(ret_re, ret_im);
    return retval;
}
Complex operator/ (Complex& a, Complex& b){
    double ret_re, ret_im;
    double divider = ((b.real()*b.real()) + (b.imag() * b.imag()));
    ret_re = (a.real() * b.real()) - (a.imag() * b.imag())/divider;
    ret_im = (a.real() * b.imag()) + (a.imag() * b.real())/divider;
    Complex retval(ret_re, ret_im);
    return retval;
}
bool operator== (Complex& a, Complex& b){
    return (a.real()==b.real())&&(a.imag()==b.imag());
}
bool operator!= (Complex& a, Complex& b){
    return (a.real()!=b.real())||(a.imag()!=b.imag());
}
///String to complex
Complex& operator<< (Complex& a, std::string s){
        int pos = s.find(",");
        std::string real = s.substr(0, pos);
        std::string imag = s.substr(pos+1);
        a.real(atof(real.data()));
        a.imag(atof(imag.data()));
        std::cout<<real<<";"<<imag<<"\n";
        return a;
}
///Complex to string
std::string operator<< (std::string s, Complex& a){
    
    std::ostringstream ost;
    ost << a.real();
    ost << ", ";
    ost << a.imag();
    std::cout<<ost.str();
    return ost.str();
}
