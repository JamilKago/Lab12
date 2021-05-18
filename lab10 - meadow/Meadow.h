#pragma once
#include "Animals.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <memory>

//class representing meadow with animals
class Meadow
{
  protected:
  std::vector< std::unique_ptr<Animal> > _animals;

  public:
  //constructor
  Meadow() = default;

  //printing all animals in meadow with prefix 
  void print(std::string prefix) const;

  //adding naxt animal
  void add( std::unique_ptr<Animal> animal );

  //getting all sheeps
  std::vector< Sheep* > getSheepHerd();

  //countiong and printiong occuring of animals names
  void countNames();

};
