#pragma once
#include "Operation.h"

//--- class to division numbers
class Division : public Operation
{
  private:
  double _num;
  double _denum;

  public:
  //--- constructor
  Division(const double a, const double b):_num(a), _denum(b) {}

  //--- division
  double eval() const override
  { return  _num/_denum;}

  //--- printing
  void print() const override
  { std::cout<< _num << " / " << _denum; }
};
