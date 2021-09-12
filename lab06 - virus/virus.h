#pragma once
#include <iostream>
#include "rna.h"

//--- class representing objets of the virus type
class Virus 
{

  protected:

    std::string _name;
    RNA* _rna;
    unsigned _age;

  public:

    //--- constructors and destructors
    Virus() = default;
    Virus(std::string name);
    Virus(std::string name, std::vector<Nukleotyp> rna);
    Virus(Virus& vir);
    Virus(Virus&& vir);
    virtual ~Virus();

    //--- getters
    std::string get_name() const;
    unsigned get_age() const;
    RNA* get_RNA() const;

    //--- setters
    void set_RNA(std::vector<Nukleotyp> rna);

    //--- two overloaded of operator '='
    Virus& operator=(const Virus& vir);
    Virus& operator=(Virus&& vir);

};