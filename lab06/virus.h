#pragma once
// * Virus (virus.h) - klasa implemetuje wirus o następujących cechach:
//   - nazwa
//   - łańcuch RNA (dynamiczny obiekt RNA) 
//   - "wiek" wirusa - ilość wyprodukowanych pokoleń (bez mutacji)
//     Wiek wirusa zwiększa się o jeden, po każdej replikacji (skopiowaniu konstr. kopiującym).
//     Na przykład, jeśli wiek wirusa vir1 wynosi 1, to nowy wirus vir2 utworzony przez instrukcję 'Virus vir2(vir1)' bedzie miał wiek 0, zaś vir1 wiek 2.
#include <iostream>
#include "rna.h"

class Virus 
{
  protected:
  std::string _name;
  RNA* _rna;
  unsigned _age;

  public:
  Virus() = default;

  Virus(std::string name):_name(name) 
  {
    _age = 0;
  }

  Virus(std::string name, std::vector<Nukleotyp> rna ):_name(name) 
  {
    *_rna = rna;
    _age = 0;
  }

  Virus(const Virus& vir) 
  {
  }

  Virus(Virus&& vir) 
  {
  }

  std::string get_name()
  {
    return _name;
  }

  unsigned get_age()
  {
    return _age;
  }

  void set_RNA(std::vector<Nukleotyp> rna)
  {
    *_rna = rna;
  }

  RNA* get_RNA()
  {
    return _rna;
  }

  Virus& operator=(Virus vir)
  {
    return *this;
  }

  Virus* operator*()
  {
    return this;
  }


};