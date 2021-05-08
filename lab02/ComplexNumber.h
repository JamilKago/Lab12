#pragma once
#include <iostream>


/*klasa reprezentujaca liczbe zespolona
*/
class ComplexNumber
{
  private:
  double _re;
  double _im;

  public:
 /*konstruktor domyslny
*/
  ComplexNumber() = default;

  /*konstruktor dwuargumentowt ustalajacy wartosci czesci rzeczywistej i urojonej
  *@param czesc rzeczywista
  *@param czesc urojona
*/
  ComplexNumber(double re, double im);
  
  /*konstrukor jednoargumetowy ustaljacy wartrosc czesci rzeczywstej
  *@param czesc rzeczywista
*/
  explicit ComplexNumber(double re) ;
  
  /*destrukor
*/
  ~ComplexNumber() = default;
  
  /*opeator mnozenia z przypisaniem 
  *@param loczyn
  *@return referencja na obekt
*/
  ComplexNumber& operator *=(const double n);
  
  /*operator przypisania
  *@param liczb zespolona
  *@return referencja na obekt
*/
  ComplexNumber& operator =(const ComplexNumber z);
  
  /*dodawnie liczb zespolonych
  *@param liczb zespolona
  *@return liczba zespolona
*/
  ComplexNumber operator+(const ComplexNumber z) const;
  
  /*mnozenie liczb zespolonych
  *@param liczb zespolona
  *@return liczba zespolona
*/
  ComplexNumber operator*(const ComplexNumber z) const;
  
  /*operator odwolnia do wartosci _re i _im
  *@param indeks
  *@return double
*/
  double& operator[](const int id);
  
  /*operator odwolnia do wartosci _re i _im
  *@param indeks
  *@return referencja na double
*/
  double operator[](const int id) const;
  
  /* preinkrementacja
  *@return referencja na obiekt
*/
  ComplexNumber& operator++();
  
  /* postinkrementacja
  *@param liczba int
  *@return lcizba zepolona
*/
  ComplexNumber operator++(int x);
  
  /*rzutowanie na double
  *@return czesc _re liczby
*/
  operator double() const;
  
  /*modul liczby do kwadratu
  *@return liczby do kwadratu
*/
  double modpow2() const;

  /* porownie liczb
  *@param liczba zespolona
  *@param liczba zespolona
  *@return wartosc logiczna
*/
  friend bool operator>(const ComplexNumber z1, const ComplexNumber z2);
  
 
 /* operator minusa przed liczba
  *@param lcizba zespolona
  *@return -liczba zespolona
*/
  friend ComplexNumber operator-(const ComplexNumber z);
  
  
 /*dodawnie zwyklej liczby re i liczby zespolonej
  *@param liczba re
  *@param liczba zespolona
  *@return wynik dodawania
*/
  friend ComplexNumber operator+(const double z1, const ComplexNumber z2);
  
  /*dodawnie zwyklej liczby calkowitej i liczby zespolonej
  *@param liczba calkowita
  *@param liczba zespolona
  *@return wynik dodawania
*/
  friend ComplexNumber operator+(const int z1, const ComplexNumber z2);
  
  /*wypisanie liczbyb zepolonej do strumienia
  *@param strumien
  *@param liczba zepolona
  *@return wypisanie liczby w strumieniu
*/
  friend std::ostream& operator<<(std::ostream& out, const ComplexNumber z);
};