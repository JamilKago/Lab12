#pragma once
#include "virus.h"
#include "rna.h"

class AnimalVirus : public Virus
{
  protected:
  std::string _host;

  public:
  AnimalVirus() = default;

  AnimalVirus(std::string name, std::string host, std::vector<Nukleotyp> rna):
  Virus(name, rna), _host(host)
  {
  }

  std::string get_animal_host()
  {
    return _host;
  }



};
