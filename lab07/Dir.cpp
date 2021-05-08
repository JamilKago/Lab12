#include "Dir.h"


using namespace std;
  

  Dir::~Dir()
  {
    cout<<"Destruktor Dir "<<_name<<endl;
    for (unsigned int i=0;i<_sub.size();i++)
	  {
	    delete _sub[i];
	  }
    _sub.clear();
  }

  Dir::Dir(const Dir& org) : Wrapper( org.name() )
  {
  	for (unsigned i = 0; i < org._sub.size(); ++i)
  	{
  		Dir* add = new Dir( _sub[i]->name() );
  		_sub.push_back(	add );
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

  Wrapper* Dir::get(const char* name) 
  {
    if(_name == name) return this;

    for(unsigned i=0;i<_sub.size();i++)
      if ( _sub[i]->get(name) ) return  _sub[i]->get(name);
    
    return nullptr;
  }

  void Dir::copy(Wrapper* obj)
  {
    *this += obj;
  }

  Dir* Dir::getDir(const char* name)
  {
    if ( get(name))
      if ( dynamic_cast<Dir*>( get(name) )  == dynamic_cast<Dir*>(this) ) // po odkomentowaniu brak wypisania ale program przestaje dzialac  
        return dynamic_cast<Dir*>(get(name));
    return nullptr;
  }

  Dir& Dir::operator+=(Wrapper* obj){
    _sub.push_back(obj);
    return *this;
  }

  Dir& Dir::operator-=(const char* obj){
    int a = 0;
    for(auto it = _sub.begin(); it <= _sub.end(); )
    {
      if (_sub[a]->name() == obj)
      { 
        cout<<"-----------Znalezniono "<< _sub[a]->name() <<endl; 
        it = _sub.erase( it );
        return *this;
      } 
      a++;
    }
    return *this;
  }
