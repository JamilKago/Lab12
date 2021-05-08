#pragma once
#include "Operation.h"

/*klasa dziedziczaca po klasie Operation sluzaca do
  oblicznia  wybranej potegi dowolnej liczby rzeczywistej
  *@param podstawa potegi
  *@param wykladnik potegi
*/
class Exponentiation : public Operation
{
private:
  double _base;
  double _pow;

public:
  /*konstruktor dwuargumentowy 
  *@param podstawa potegi
  *@param wykladnik potegi
  */
  Exponentiation(const double a, const double b): _base(a), _pow(b) {}


  /*funkcja wirtaualna wykonujaca liczenie dzialania 
  *@return wartosc dzialania (potegowania)
  */
  double eval() const override
  { return  pow(_base, _pow);}

  /*funkcja wirtaualna wypisaujaca dzilanie (potegowanie)
  */
  void print() const override
  { std::cout<< _base << " ^ " << _pow; }
};

/*operator wypisania dzialania w ramce
*@param ramka
*@param obiekt przechowujacy dzialanie (potegowanie)
*/
void operator>>=(const char* frame, const Exponentiation& op)
{
  std::cout << frame <<" "; op.print(); 
  std::cout <<" "<< frame << std::endl; 
}