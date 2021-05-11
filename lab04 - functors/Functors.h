#pragma once
#include <iostream>


//--- class checking a divisibility
class DivisibleBy
{
  private:
  int _arg;

  public:
  //--- constructors and destructors
  DivisibleBy() = default;
  DivisibleBy(int x): _arg(x) {};
  ~DivisibleBy() = default;

  //--- calling a check 
  bool operator() (int x) { return !( x%_arg ? true : false ); }

};


//--- class comparising the numbers
class GreaterThan
{
  private:
  int _arg;

  public:
  //--- constructors and destructors
  GreaterThan() = default;
  GreaterThan(int x): _arg(x) {};
  ~GreaterThan() = default;

  //--- calling a check 
  bool operator() (int x) { return  x>_arg ? true : false ; }


};