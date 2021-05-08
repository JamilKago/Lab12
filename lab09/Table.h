#pragma once
#include "Expense.h"
#include <iostream>
using namespace std;

/*klasa przechowujaca inforamcje o dniach
@param lista dni
*/
class Table
{
  protected:
  vector<Expense> _days;

  public:
  /*konstruktor domyslny
  */
  Table() = default;

  /*metoda sortujaca dni po kolumnach
  @param columna względem której sortujemy
  @return referencja na obiekt Table
  */
  Table& sort(int col);

  /*metoda sortujaca dni po średniej
  @return referencja na obiekt Table
  */
  Table& sortByMean();

  /*operator dodawania nowego dnia
  @param nowy dzień
  @return referencja na obiekt Table
  */
  Table& operator+=(Expense day);

  /*metoda wypisaujaca wszystkie dni
  @param columna względem której sortujemy
  */
  void print() const;

};

/*komperator po wartości kolumny
  @param dzienń 1
  @param dzienń 2
  @param koolumna względem której porównujemy
  @return prawda/falsz
*/
bool col_cmp( Expense day1, Expense day2, int col);

/*komperator po średniej
  @param dzienń 1
  @param dzienń 2
  @return prawda/falsz
*/
bool avg_cmp( Expense day1, Expense day2);

