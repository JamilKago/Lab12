#pragma once 
#include <iostream>
#include <vector>
#include <functional>


//--- class that gets comparison functions 
class FilterCriteria
{
  private:
  std::vector< std::function<bool(int)>> _fun;

  public:
  //--- constructors and destructors
  FilterCriteria() = default;
  ~FilterCriteria();

  //--- access operator 
  std::function<bool(int)> get(const int id);

  //--- method adding a function
  void add( std::function <bool(int)> f);

  //--- method returning amount of functions
  int size() const;

};