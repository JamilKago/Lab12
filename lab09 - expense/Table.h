#pragma once
#include "Expense.h"
#include <iostream>
using namespace std;

//class that holds informations about expenses from many days 
class Table
{
  protected:
  vector<Expense> _days;

  public:
  //constructor
  Table() = default;

  //sorting container according to values from particular column 
  Table& sort(int col);
  
  //sorting according to average expenses
  Table& sortByMean();

  
  //adding another day
  Table& operator+=(Expense day);

  //printing all container of all days
  void print() const;

};

//comparator for method sort 
bool col_cmp( Expense day1, Expense day2, int col);

//comparator for method sortByMean
bool avg_cmp( Expense day1, Expense day2);

