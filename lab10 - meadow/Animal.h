#pragma once
#include <iostream>


/*klasa reprezentujaca zmierzeta
*/
class Animal
{
  protected:
  std::string _name;

  public:

  /*konstruktor jednoargumentowy
  @param imie zwierzecia
  */
  explicit Animal(std::string name): _name(name)
  {}

  /*destrukotr
  */
  virtual ~Animal() = default;


  /*wypisanie imienia
  @return imie 
  */
  std::string name() const
  {
    return _name;
  }

  /*wypisanie inforamcji o zwierzeciu
  */
  virtual void print() const = 0; 

};