#include "ComplexNumber.h"

  ComplexNumber::ComplexNumber(double re, double im)
  {
    _re = re;
    _im = im;
  }

  ComplexNumber::ComplexNumber(double re)
  {
    _re = re;
    _im = 0;
  }

  
  ComplexNumber& ComplexNumber::operator *=(const double n)
  {
    _re *= n;
    _im *= n;
    return *this;
  }

  ComplexNumber& ComplexNumber::operator =(const ComplexNumber z)
  {
    _re = z._re;
    _im = z._im;
    return *this;
  }


  ComplexNumber ComplexNumber::operator+(const ComplexNumber z) const
  {
    return ComplexNumber( _re + z._re , _im + z._im );
  }

  ComplexNumber ComplexNumber::operator*(const ComplexNumber z) const
  {
    return ComplexNumber( (_re*z._re - _im*z._im) , (_re*z._im + _im*z._re) );
  }

  double& ComplexNumber::operator[](const int id)
  {
    return id ? _im : _re ;
  }

  double ComplexNumber::operator[](const int id) const
  {
    return id ? _im : _re ;
  }


  ComplexNumber& ComplexNumber::operator++()
  {
    _re += 1.0;
    return *this;
  }

  ComplexNumber ComplexNumber::operator++(int x)
  {
    ComplexNumber z = ComplexNumber(*this);
    _re += 1.0;
    return z;
  }

  ComplexNumber::operator double() const
  {
    return _re;
  }

  double ComplexNumber::modpow2() const
  {
    return _im * _im + _re * _re;
  }


  bool operator >(const ComplexNumber z1, const ComplexNumber z2)
  {
    return  z1.modpow2() > z2.modpow2() ;
  }

  ComplexNumber ComplexNumber::operator-(const ComplexNumber c2) const
  {
      return ComplexNumber(_re - c2._re, _im - c2._im);
  }


  ComplexNumber operator+(const double z1, const ComplexNumber z2)
  {
    return ComplexNumber( z1 + z2._re, z2._im );
  }

  ComplexNumber operator+(const int z1, const ComplexNumber z2)
  {
    return ComplexNumber( static_cast<double>(z1) + z2._re, z2._im );
  }

  std::ostream& operator<<(std::ostream& out, const ComplexNumber z)
  {
    return out<< z._re <<" + "<< z._im <<"i";
  }