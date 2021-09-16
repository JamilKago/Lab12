#pragma once
#include <iostream>

using namespace std;

//--- base class of all system object
class Wrapper
{ 
  protected:
  string _name;

  public:
  //--- constructor
  Wrapper(string name): 
  _name(name)
  {}
 
  //--- virtual destructor
  virtual ~Wrapper() = default;

  //--- getter of name 
  string name() const 
  {
    return _name;
  }

  //--- creating copy of system object
  virtual Wrapper* makeCopy() const = 0;

  //--- printing of system object 
  virtual ostream& print(ostream& out, int tabs) const = 0;

  //--- printing whoel tree of system object  
  friend ostream& operator<<(ostream& out, const Wrapper& obj)
  {
    obj.print(out, 0);
    return out;
  }
};

