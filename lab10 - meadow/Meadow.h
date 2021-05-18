#pragma once
#include "Animals.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <memory>

//class representiong meadoaw of animals
class Meadow
{
  protected:
  std::vector< std::unique_ptr<Animal> > _animals;

  public:
  //constructor
  Meadow() = default;

  //printing all animals with prefix 
  void print(std::string prefix) const;

  //adding naxt animal
  void add( std::unique_ptr<Animal> animal );

  //getting all sheeps
  std::vector< Sheep* > getSheepHerd();

  //countiong and printiong occuring of animals names
  void countNames();

};
