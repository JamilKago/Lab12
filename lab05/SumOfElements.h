#pragma once
#include "Operation.h"

/*klasa dziedziczaca po klasie Operation sluzaca do
  oblicznia sumy dowolnej ilossc liczb rzeczywistych 
  *@param tablica liczb 
  *@param rozmiar tablicy
*/
class SumOfElements : public Operation
{
private:
  double* _nums;
  int _amount;

public:
  /*konstruktor dwuargumentowy
  *@param tablica liczb 
  *@param rozmiar tablicy
  */
  SumOfElements(double* n, const int a)
  {
    _amount = a;
    _nums = new double[_amount];
    for(int i=0;i<_amount;i++)  _nums[i] = n[i];
  }

  /*destruktor 
  */
  ~SumOfElements(){ delete []_nums;}

  /*funkcja wirtaualna wykonujaca liczenie dzialania 
  *@return wartosc dzialania (sumowania)
  */
  double eval() const override
  { 
    double sum = 0.0; 
    for(int i=0;i<_amount;i++)  sum += _nums[i];
    return sum;
  }

  /*funkcja wirtaualna wypisaujaca dzilanie (sumowanie)
  */
  void print() const override
  { 
    for(int i=0;i<_amount;i++)  std::cout<< _nums[i] << " + ";
    std::cout<<"\b\b\b";
  }

};

/*operator wypisania dzialania w ramce
*@param ramka
*@param obiekt przechowujacy dzialanie (sumowanie)
*/
void operator>>=(const char* frame, const SumOfElements& op)
{
  std::cout << frame <<" "; op.print(); 
  std::cout <<" "<< frame << std::endl; 
}