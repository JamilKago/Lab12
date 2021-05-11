#pragma once
#include <iostream>
#include <vector>
#include <functional>



//--- class working with list of function arguments
class List 
{
  private:
  std::vector <int> _data;


  public:
  //--- constructors and destructors
  List() = default;
  List(const List& org);
  ~List();

  //--- access operators
  int& operator[](int id);
  int operator[](int id) const;
  
  //--- method adding new function arguments
  void insert(const int arg);

  //--- method printiong class data
  void print(std::string pre = "") const;

  //--- method returning list of numbers accepted key (function)
  List filter( std::function <bool(int)> f) ;

};