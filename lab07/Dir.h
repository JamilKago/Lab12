#pragma once
#include "Wrapper.h"
#include <vector>

using namespace std;

/* klasa pochodna, dziedziczy z klasy wrapper, symuluje katalog
  @param podkatalogi
*/
//slowo final blokuje mozliwosc dziedziczenia po tej klasie
class Dir final: public Wrapper
{

  protected:
  vector<Wrapper*> _sub;

  public:
  /* kostruktor nadajacy nazwe
  @param nazwa
  */
  Dir(const char* name):Wrapper(name)
  {}

  Dir(const Dir& org);

  /* destruktor glosny
  */
  ~Dir();


  //klasy virtualne nadpisywane
  ostream& print(ostream& out, int tabs) const override;
  Wrapper* get(const char* name) override;

  void copy(Wrapper* obj);

  /* getter na folder 
  @param nazwa folderu
  @preturn wskaznik na folder  
  */
  Dir* getDir(const char* name);

/* dodaeni obiektu
  @param obiekt
  @preturn referencja na folder  
  */
  Dir& operator+=(Wrapper* obj);

  /* usuniencie obiektu
  @param nazwa abiektu
  @preturn referencja na folder  
  */
  Dir& operator-=(const char* obj);

};