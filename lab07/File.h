#pragma once
#include "Wrapper.h"


using namespace std;


/* klasa pochodna, dziedziczy z klasy wrapper, symulje plik
  @param rozmiar pliku
*/
class File : public Wrapper
{
  protected:
  unsigned _size = 0;

  public:
  /* kostruktor nadajacy nazwe
  @param nazwa
  */
  File(const char* name):Wrapper(name)
  {}

  /* kostruktor nadajacy nazwe i rozmiar
  @param nazwa
  @param rozmiar
  */
  File(const char* name, unsigned size):Wrapper(name), _size(size)
  {}


  /* destruktor glosny
  */
  ~File(){
    cout<<"---Destruktor File "<<_name<<endl;
  }


  //klasy virtualne nadpisywane
  ostream& print(ostream& out, int tabs) const override
  {
    for(int i=0;i<tabs;i++) out<<"  ";
    return out<< _name <<" ("<< _size <<") "<< endl;
  }
  
  Wrapper* get(const char* name) override
  {
    if ( _name == name )  return this;
    return nullptr;
  }


};

