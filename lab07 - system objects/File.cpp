#include "File.h"

using namespace std;


  File::File(const string name):
  Wrapper(name)
  {}


  File::File(const string name, unsigned size):
  Wrapper(name),
   _size(size)
  {}

  File::File(const File& other):
  Wrapper(other.name()),
  _size(other._size)
  {}

  File::~File(){
    cout<<"---Destructor File "<<_name<<endl;
  }


  ostream& File::print(ostream& out, int tabs) const 
  {
    for(int i=0;i<tabs;i++) out<<"  ";
    return out<< _name <<" ("<< _size <<") "<< endl;
  }

  Wrapper* File::makeCopy() const  
  { 
    return new File(*this);
  }