#pragma once
#include <iostream>

using namespace std;

//kalsa wrapper na obiekty katalogow
class Wrapper
{
  /*
  @param nazawa obiektu
  */
  protected:
  string _name;

  public:
  /*konstruktor domyslny  ustawiajacy nazwe
  @param nazawa obiektu
  */
  Wrapper(const char* name): _name(name)
  {}

  /*wirtualny destrikor
  */
  virtual ~Wrapper()
  {}

  /* getter na nazwe
  @return nazawa obiektu
  */
  string name() {return _name;}

   /* wypisanie do strumienia
  @param strummien
  @param odstep
  @return strumien  
  */
  virtual ostream& print(ostream& out, int tabs) const = 0;

   /* getter na obiekt wrapper
  @param nazwa obiektu
  @return wskaznik na obiekt  
  */
  virtual Wrapper* get(const char* name) = 0;


  /* wypisanie do strumienia calej hierarch
  @param strummien
  @param obiekt
  @preturn strumien 
  */
  friend ostream& operator<<(ostream& out, const Wrapper& obj)
  {
    obj.print(out, 0);
    return out;
  }
};

