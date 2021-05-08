#pragma once
#include <iostream>


/*klasa obuektu-funkcji sprawdzjaca podzielnosc liczby
@param argument wzgledem ktorego porownujemy
*/
class DivisibleBy
{
  private:
  int _arg;

  public:
  /*kosntruktor domyslny
  */
  DivisibleBy() = default;
  /*kosntruktor jedoargumentowy
  @param argument porownujacy
  */
  DivisibleBy(int x): _arg(x) {};
  /*destruktor
  */
  ~DivisibleBy() = default;

  /*operator wywolania obiektu-funkcji
  @param argument do porownania
  @return wartosc logiczna tak/nie
  */
  bool operator() (int x) { return !( x%_arg ? true : false ); }

};


/*klasa obuektu-funkcji porownujacej liczby
@param argument wzgledem ktorego porownujemy
*/
class GreaterThan
{
  private:
  int _arg;


  public:
  
  /*kosntruktor domyslny
  */
  GreaterThan() = default;
  
  /*kosntruktor jedoargumentowy
  @param argument porownujacy
  */
  GreaterThan(int x): _arg(x) {};
  
  /*destruktor
  */
  ~GreaterThan() = default;


  /*operator wywolania obiektu-funkcji
  @param argument do porownania
  @return wartosc logiczna tak/nie
  */
  bool operator() (int x) { return  x>_arg ? true : false ; }


};