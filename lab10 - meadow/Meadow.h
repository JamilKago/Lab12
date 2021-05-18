#pragma once
#include "Animals.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <memory>

/*klasa stado zwierzat
*/
class Meadow
{
  protected:
  std::vector< std::unique_ptr<Animal> > _animals;

  public:
  /*konstruktor domyslny
  */
  Meadow() = default;

  /*wypisanie inforamcji o stadzie
  @param prefix
  */
  void print(std::string prefix) const;

  /*dodanie zwierzecia do stada
  @param unique_ptr wskazujacy na zwierze
  */
  void add( std::unique_ptr<Animal> animal );

  /*zebranie wszytkich owiec ze stada
  @return wekotr owiec ze statda
  */
  std::vector< Sheep* > getSheepHerd();

  /*zliczenie i wypisanei imion zwierzat alfabetycznie
  */
  void countNames();

};