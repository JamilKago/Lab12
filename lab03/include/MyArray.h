#pragma once 
#include <iostream>
#include <utility>


/*
  *klasa przechowujaca tablice liczb int ktrore mozna laczyc
*/

class MyArray
{
  /*
  @param tablica liczb
  @param  rozmiar
  @param wskaznik na nastepna tablice
  */
  private:
  int* _data = nullptr;
  int _size = 0 ;
  MyArray* _next = nullptr;


  public:
  /* konstrukotr domyslny
   */
  MyArray() = default;

  /* konstruktor jednoargumentowy
  @param rozmiar tablicy
  */
  MyArray(const int size);


  /*konstruktor kopiujacy
  @param  elemnt kopiowany
  */
  MyArray(const MyArray& org);


   /*konstruktor przenoszacy
  @param  obiekt - zrodlo
  */
  MyArray(MyArray&& org);

   /*destruktor zwalniajacy pamiec
  */
  ~MyArray();

   /*operator zwracjacy elemnt o danym indeksie
  @param  indeks
  @return referencja na liczbe
  */
  int& operator[](int id);

  /*operator zwracjacy elemnt o danym indeksie
  @param  indeks
  @return liczba
  */
  int operator[](int id) const;

  /*operator postinkrementacji
  @param  int
  @return tablica o zinkremntowanym kazdym elemncie
  */
  MyArray operator++(int);


  /*operator predekrementacji
  @return referencja tablica o zdekrementowanym kazdym elemncie 
  */
  MyArray& operator--();

  /*operator przypisania
  @param  obiekt klasy MyArray
  @return referencja na obiekt na rzecz ktorego wywolano operator
  */
  MyArray& operator=(const MyArray& T);

  /*operator podlinkowania tablicy
  @param  MyArray ktory "podpinamy" pod obiekt na rzecz ktorego wywolano operator
  @return referencja na obiekt na rzecz ktorego wywolano operator
  */
  MyArray& operator+=( MyArray& T);

  /*operator podlinkowania tablicy dla elementu z konstrukora przenoszacego
  @param  MyArray ktory "podpinamy" pod obiekt na rzecz ktorego wywolano operator
  @return referencja na obiekt na rzecz ktorego wywolano operator
  */
  MyArray& operator+=(MyArray&& T);

  /*wypisanie clego lancucha z podlinkowanymi tablicami
  @param  prefix
  */
  void print(std::string prefix) const;

  /*zwrocenie kolejnej podpietej tablicy 
  @param  prefix
  */
  MyArray& getNext();

  /*zwrocenie rozmiaru 
  */
  int size() const;


  /*zwrocenie wypisanie tablicy do strumienia 
  @param  strumien
  @param  stala referncja na obiekt
  @return  wypisana jedna tablica bez podlinkowanych pod nia
  */
  friend std::ostream& operator<<(std::ostream& out, const MyArray& T);

};