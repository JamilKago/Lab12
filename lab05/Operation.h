#pragma once 
#include<iostream>
#include<cmath>


/*klasa bazowa bedaca wrpperem na obiekty klas z niej dziedzicacych
*/
class Operation
{
private:
public:
  /*funkcja wirtaualna wykonujaca liczenie dzialania 
  *@return wartosc dzialania
  */
  virtual double eval() const = 0;

  /*funkcja wirtaualna wypisaujaca dzilanie 
  */
  virtual void print() const = 0;
};



/*operator wypisania dzialania w ramce
*@param ramka
*@param obiekt przechowujacy dzialanie
*/
void operator>>=(const char* frame, const Operation& op)
{
  std::cout << frame <<" "; op.print(); 
  std::cout <<" "<< frame << std::endl; 
}