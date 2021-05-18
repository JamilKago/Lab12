#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <functional> 

using namespace std;

//class representing list of expenses from definite day 
class Expense
{
  protected:
  string _name;
  vector<double> _data; 

  public:
  //constructors
  Expense(string name, vector<double> data);
  
  //getters
  vector<double>& data();
  
  //averege of expenses
  double mean() const;
  
  //printing info about day
  void print() const;

};

//additional function for printing
void to_print(const Expense day);



