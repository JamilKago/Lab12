#pragma once
#include "Operation.h"

//--- class to sum numbers
class SumOfElements : public Operation
{
private:
  double* _nums;
  int _amount;

public:
  //--- constructor
  SumOfElements(double* n, const int a)
  {
    _amount = a; 
    _nums = new double[_amount];
    for(int i=0;i<_amount;i++)  _nums[i] = n[i];
  }

  //--- destructor
  ~SumOfElements(){ delete []_nums;}

  //--- summing
  double eval() const override
  { 
    double sum = 0.0; 
    for(int i=0;i<_amount;i++)  sum += _nums[i];
    return sum;
  }

  //--- printing
  void print() const override
  { 
    for(int i=0;i<_amount;i++)  
      std::cout<< _nums[i] << " + ";
    
    std::cout<<"\b\b\b";
  }

};

