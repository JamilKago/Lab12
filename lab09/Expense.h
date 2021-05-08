#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <functional> 

using namespace std;

/*klasa przechowujaca inforamcje w ydatkach danego dnia
@param dzien
@param lista wydatkow
*/
class Expense
{
  protected:
  string _name;
  vector<double> _data; 

  public:
  /*konstruktor
  @param dzien
  @param lista wydatkow
  */
  Expense(string name, vector<double> data);
  
  /*getter wydatków
  @return wydatki
  */
  vector<double>& data();
  
  /* srednia z dnia
  @return średnia z danego dnia
  */
  double mean() const;
  
  /*metoda wypisujaca
  */
  void print() const;

};

/*funkcja pomocnicza do wypisywania
 @param obiekt typu Expense
*/
void to_print(const Expense day);



