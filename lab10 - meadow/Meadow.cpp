#include "Meadow.h"

void Meadow::print(std::string prefix) const
{
  std::cout<< prefix << std::endl;
  for(auto& animal : _animals )
  {
    animal->print();
  }
}

void Meadow::add( std::unique_ptr<Animal> animal )
{
  _animals.push_back( std::move(animal) );
}

std::vector< Sheep* > Meadow::getSheepHerd()
{
  std::vector< Sheep* > sheeps;
  for(auto &animal: _animals)
  {
    if( dynamic_cast<Sheep*>(animal.get()) )
    {
      sheeps.push_back( dynamic_cast<Sheep*>(animal.get()) );
    }
  }

  return sheeps;
}

void Meadow::countNames()
{
  std::map<std::string, int> temp;
  for(auto &animal: _animals)
  {
    if( temp.find(animal->name()) == temp.end() )
    {
      temp[ animal->name() ] = 1;
    }
    else
    {
      temp[ animal->name() ] += 1;
    }
  }

  for(auto &animal: temp)
  {
    std::cout<< animal.first <<": " << animal.second << std::endl;
  }

}