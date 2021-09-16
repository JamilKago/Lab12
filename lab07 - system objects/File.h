#pragma once
#include "Wrapper.h"

using namespace std;

//--- class of simple file
class File : public Wrapper
{
  protected:
  unsigned _size = 0;

  public:

  //--- constructors and destructor
  File(const string name);
  File(const string name, unsigned size);
  File(const File& other);
  ~File();

  //--- printing to output
  ostream& print(ostream& out, int tabs) const override;

  //--- creating copy of file
  Wrapper* makeCopy() const override;

};

