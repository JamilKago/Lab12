#pragma once
#include <iostream>
#include <vector>
#include <functional>



/*klasa obslugujaca liste argumentow
  @param wektor argumentow
*/
class List 
{
  private:
  std::vector <int> _data;


  public:

  /*kosntruktor domyslny
  */
  List() = default;

  /*kosntruktor kopiujacy
  */
  List(const List& org);

  /*destruktor
  */
  ~List();

  /*operator dostepu do danych
  @param int indeks argumentu
  @return referencja na wartosc spod indeksu
  */
  int& operator[](int id);

  /*operator dostepu do danych
  @param int indeks argumentu
  @return wartosc spod indeksu
  */
  int operator[](int id) const;
  
  /*dodanie argumentu
  @param wartosc argumentu
  */
  void insert(const int arg);

  /*wypisanie listy z prefiksem
  @param prefiks
  */
  void print(std::string pre) const;
  
  /*wypisanie listy 
  */
  void print() const;

  /*filtrowanie zgodnie z kluczem - funkcja
  @param klucz - funkcja
  @return obiekt wynikow
  */
  List& filter( std::function <bool(int)> f) ;

};