#pragma once
#include "Operation.h"

//--- class to exponentiation 
class Exponentiation : public Operation
{
private:
  double _base;
  double _pow;

public:
  //--- constructor
  Exponentiation(const double a, const double b): _base(a), _pow(b) {}


  //--- exponentiation
  double eval() const override
  { return  pow(_base, _pow);}

  //--- printing
  void print() const override
  { std::cout<< _base << " ^ " << _pow; }
};

