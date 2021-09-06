#pragma once 
#include<iostream>
#include<cmath>


//--- basic class
class Operation
{
private:
public:
  //--- calculating
  virtual double eval() const = 0;

  //--- printing
  virtual void print() const = 0;

  virtual ~Operation() {};

};

//--- printing in frame
void operator>>=(const char* frame, const Operation& op)
{
  std::cout << frame <<" "; op.print(); 
  std::cout <<" "<< frame << std::endl; 
}