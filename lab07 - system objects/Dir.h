#pragma once
#include "Wrapper.h"
#include <vector>

using namespace std;

//--- class of dir in which we can put other dirs or files
class Dir final: public Wrapper
{

  protected:
  vector<Wrapper*> _sub;

  public:
  //--- constructors and destructor
  Dir(string name);
  Dir(const Dir& org);
  ~Dir();

  //--- printing to output
  ostream& print(ostream& out, int tabs) const override;
  
  //--- searching for file by name
  Wrapper* get(const string name);

  //--- creating copy of dir
  Wrapper* makeCopy() const override; 

  //--- adding copy of object
  void copy(Wrapper* obj);

  //--- searching for dir by name
  Dir* getDir(const string name) const;
  
  //--- adding new object
  Dir& operator+=(Wrapper* obj);
  
  //--- deleting object from dir
  Dir& operator-= (const string obj); 

};