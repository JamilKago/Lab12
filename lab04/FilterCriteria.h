#pragma once 
#include <iostream>
#include <vector>
#include <functional>


/*klasa przetrzymujaca funkcje porownujace
@param wektor funkckji
  */
class FilterCriteria
{
  private:
  std::vector< std::function<bool(int)>> _fun;

  public:
  /*kosntruktor domyslny
  */
  FilterCriteria() = default;

  /*destruktor
  */
  ~FilterCriteria();

  /*operator zasiegu do funkckji
  @param indeks funkckji
  @return funkcja 
  */
  std::function<bool(int)> get(const int id);

  /*dodanie obiektu funkcyjnego do wektora
  */
  void add( std::function <bool(int)> f);

  /*fukcja zwracajaca rozmiar wektora
  @return rozmiar wektora
  */
  int size() const;

};