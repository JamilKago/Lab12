#pragma once
#pragma once
#include <iostream>
#include "Animal.h"


//class of cow
class Cow: public Animal
{
  protected:

  public:
  //constructor and destructors
  Cow(std::string name);

  ~Cow();

  //printing inforamtion about cow
  void print() const override;


};


//class of horse
class Horse: public Animal
{
  protected:

  public:
  //constructor and destructors
  Horse(std::string name);

  ~Horse();

  //printing inforamtion about horse
  void print() const override;

};


//class of sheep
class Sheep: public Animal
{
  protected:
  bool _sheared;

  public:
  //constructor and destructors
  Sheep(std::string name);
 
  ~Sheep();

  //printing inforamtion about horse
  void print() const override;

  //shearing sheep
  void shear();

};
