#include "Table.h"

Table& Table::sort(int col)
{
  if ( find_if( _days.begin(), _days.end(), [&col](Expense x){return (int)(x.data().size()) <= col;}) == _days.end() )
  {  
    auto fun = bind(col_cmp, std::placeholders::_1, std::placeholders::_2, col);
    std::sort(_days.begin(), _days.end(), fun);  
  }
  else
  {
    cout <<" Indeks " << col << " nieprawidlowy!" << endl; 
  }
  return *this;
}

Table& Table::sortByMean()
{
  std::sort(_days.begin(), _days.end(), avg_cmp);
  return *this;
}

Table& Table::operator+=(Expense day)
{
  _days.push_back(day);
  return *this;
}


void Table::print() const
{
  for_each( _days.begin(), _days.end(), to_print);
  cout<<endl;
}


bool col_cmp( Expense day1, Expense day2, int col)
{
  return day1.data()[col] < day2.data()[col] ; 
}


bool avg_cmp( Expense day1, Expense day2)
{
  return day1.mean() < day2.mean() ; 
}
