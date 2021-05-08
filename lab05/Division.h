#pragma once
#include "Operation.h"

/*klasa dziedziczaca po klasie Operation sluzaca do
  oblicznia wartosci ulamka o zadaym mianowniku i liczniku
  *@param licznik ulamka
  *@param minaownik ulamka
*/
class Division : public Operation
{
  private:
  double _num;
  double _denum;

  public:
  /*konstruktor dwuargumentowy
  *@param licznik ulamka
  *@param minaownik ulamka 
  */
  Division(const double a, const double b):_num(a), _denum(b) {}

  /*funkcja wirtaualna wykonujaca liczenie dzialania 
  *@return wartosc dzialania (dzielenia)
  */
  double eval() const override
  { return  _num/_denum;}

  /*funkcja wirtaualna wypisaujaca dzilanie (dzielenie)
  */
  void print() const override
  { std::cout<< _num << " / " << _denum; }
};


  /*operator wypisania dzialania w ramce
  *@param ramka
  *@param obiekt przechowujacy dzialanie (dzielenie)
  */
  void operator>>=(const char* frame, const Division& op)
  {
    std::cout << frame <<" "; op.print(); 
    std::cout <<" "<< frame << std::endl; 
  }