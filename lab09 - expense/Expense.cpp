#include "Expense.h"


Expense::Expense(string name, vector<double> data): _name(name), _data(data)
{
}

double Expense::mean() const
{
  double avg = accumulate( _data.begin(), _data.end(), 0.0);
  return avg/static_cast<double>(_data.size());
}

void Expense::print() const
{
  cout<< _name << setw(8);
  for_each( _data.begin(), _data.end(), [](double x){cout<< x << setw(6);});
  cout<<endl;
}

vector<double>& Expense::data()
{
  return _data;
}


void to_print(const Expense day)
{
  day.print();
}



