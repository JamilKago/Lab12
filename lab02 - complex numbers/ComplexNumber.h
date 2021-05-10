#pragma once
#include <iostream>


/* class representing a comlex number
*/
class ComplexNumber
{
  private:
  double _re;
  double _im;

  public:
 /* default constructor
*/
  ComplexNumber() = default;

  /* two-param constructor
  *@param real part of number
  *@param complex part of number
*/
  ComplexNumber(double re, double im);
  
  /* one-param constructor
  *@param real part of number
*/
  explicit ComplexNumber(double re) ;
  
  /* destructor
*/
  ~ComplexNumber() = default;
  
  /* multiplication operator
  *@param real number
  *@return reference to an object
*/
  ComplexNumber& operator *=(const double n);
  
  /* assigment operator 
  *@param object of class complex number
  *@return reference to an object
*/
  ComplexNumber& operator =(const ComplexNumber z);
  
  /* adding complex numbers
  *@param complex number
  *@return result
*/
  ComplexNumber operator+(const ComplexNumber z) const;

  /* substraction of complex number
  *@param complex number
  *@return result
*/
  ComplexNumber operator-(const ComplexNumber z) const;
  
  /*mnozenie multiply 
  *@param complex number
  *@return result
*/
  ComplexNumber operator*(const ComplexNumber z) const;
  
  /*operator appeal to part od complex number
  *@param index [0] real, [1] complex
  *@return reference to real or complex part
*/
  double& operator[](const int id);
  
  /*operator appeal to part od complex number
  *@param index [0] real, [1] complex
  *@return value of part
*/
  double operator[](const int id) const;
  
  /* pre-incrementation
  *@return reference to an object
*/
  ComplexNumber& operator++();
  
  /* post-incrementation
  *@param int
  *@return complex number
*/
  ComplexNumber operator++(int x);
  
  /* cast to double 
  *@return real part
*/
  operator double() const;
  
  /*modulo pf complex number
  *@return modulo pf complex number
*/
  double modpow2() const;

  /* comparison of complex number
  *@param first complex number
  *@param second complex number
  *@return true/false
*/
  friend bool operator>(const ComplexNumber z1, const ComplexNumber z2);
  
 /*adding real and complex numbers
  *@param real number
  *@param complex number
  *@return result
*/
  friend ComplexNumber operator+(const double z1, const ComplexNumber z2);
  
  /*adding intiger and complex numbers
  *@param real number
  *@param complex number
  *@return result
*/
  friend ComplexNumber operator+(const int z1, const ComplexNumber z2);
  
  /*unsubscribing to stream
  *@param stream
  *@param complex number
  *@return stream with unsubscribed vumplex number 
*/
  friend std::ostream& operator<<(std::ostream& out, const ComplexNumber z);
};