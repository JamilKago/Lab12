#include "Dir.h"

using namespace std;

  Dir::Dir(string name):
  Wrapper(name) 
  {}
  
  Dir::Dir(const Dir& org): 
  Wrapper(org.name())
  {
  	for (unsigned i = 0; i < org._sub.size(); ++i)
  	{
      *this += org._sub[i]->makeCopy();
  	}
  }

  Dir::~Dir()
  {
    cout<< "Destructor Dir: " <<_name<<endl;
    for (unsigned int i=0;i<_sub.size();i++)
    {
      delete _sub[i];
    }
  }



  ostream& Dir::print(ostream& out, int tabs)  const
  {
    for(int i=0;i<tabs;i++) out<<"  ";
    out<< _name <<" (dir) "<< endl;
    
    for(auto& it : _sub)
      it->print(out, tabs+1);

    return out;
  }

  Wrapper* Dir::get(const string name) 
  {
    for(auto sub : _sub)
    {
      if(sub->name() == name)
      {
        return sub;
      }

      else if(dynamic_cast<Dir*>(sub))
      {
        return dynamic_cast<Dir*>(sub)->get(name);
      }
    }
    return nullptr;
  }


  Wrapper* Dir::makeCopy() const  
  { 
    return new Dir(*this);
  }

  void Dir::copy(Wrapper* obj)
  {
    (*this) += obj->makeCopy();
  }
    


  Dir* Dir::getDir(const string name) const
  {
    for(auto sub : _sub)
    {
      if( dynamic_cast<Dir*>(sub) )
      {
        if(sub->name() == name)
        {
          return dynamic_cast<Dir*>(sub);
        }
        return dynamic_cast<Dir*>(sub)->getDir(name);
      }
    }
    return nullptr;
  }


  Dir& Dir::operator+=(Wrapper* obj)
  {
    _sub.push_back(obj);
    return *this;
  }


  Dir& Dir::operator-= (std::string obj) 
  {
    for (int i = 0; i < static_cast<int>(_sub.size()); i++) 
    {
      if (_sub[i]->name() == obj) 
      {
        delete _sub[i];
        _sub.erase(_sub.begin() + i);
      }
    }
    return *this;
  }

