#pragma once
#include "virus.h"
#include "rna.h"

//--- class representing objets of the Animalvirus type
class AnimalVirus : public Virus
{
  protected:
  std::string _host;

  public:
  //--- constructors and destructors
  AnimalVirus() = default;

  AnimalVirus(std::string name, std::string host, std::vector<Nukleotyp> rna):
  Virus(name, rna), 
  _host(host)
  {
  }

  //--- getter
  std::string get_animal_host()
  {
    return _host;
  }
  
};
