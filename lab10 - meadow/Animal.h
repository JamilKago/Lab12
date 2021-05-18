#pragma once
#include <iostream>


//class of aniamls
class Animal
{
  protected:
  std::string _name;

  public:

  //constructor and destructor
  explicit Animal(std::string name): _name(name)
  {}

  virtual ~Animal() = default;


  //printing name
  std::string name() const
  {
    return _name;
  }

  //printing info about animal
  virtual void print() const = 0; 

};
