#pragma once
#pragma once
#include <iostream>
#include "Animal.h"


/*klasa reprezentujaca krowa
*/
class Cow: public Animal
{
  protected:

  public:
   /*konstruktor jednoargumentowy
  @param imie krowy
  */
  Cow(std::string name);
  
  /*destrukotr
  */
  ~Cow();

  /*wypisanie inforamcji o krowie
  */
  void print() const override;


};


/*klasa reprezentujaca konia
*/
class Horse: public Animal
{
  protected:

  public:
   /*konstruktor jednoargumentowy
  @param imie konia
  */
  Horse(std::string name);
  
  /*destrukotr
  */
  ~Horse();

  /*wypisanie inforamcji o koniu
  */
  void print() const override;

};


/*klasa reprezentujaca owce ktora mozna ostrzyc
*/
class Sheep: public Animal
{
  protected:
  bool _sheared;

  public:
  /*konstruktor jednoargumentowy
  @param imie owcy
  */
  Sheep(std::string name);
  
  /*destrukotr
  */
  ~Sheep();

  /*wypisanie inforamcji o owcy
  */
  void print() const override;

  /*strzyzenie owcy
  */
  void shear();

};
