#include "List.h"

  List::List(const List& org)
  {
    for(unsigned int i=0;i<org._data.size();i++)
    {
      _data.push_back( org._data[i] );
    }
  }

  List::~List()
  {
    _data.clear();
  }


  int& List::operator[](int id)
  {
    return _data[id];
  }

  int List::operator[](int id) const
  {
    return _data[id];
  }

  void List::insert(const int arg)
  {
    _data.push_back(arg);
  }

  void List::print(std::string pre) const
  {
    std::cout<< pre<<" [ ";
    for(unsigned int i=0;i<_data.size();i++)
    {
      std::cout<<_data[i]<<" ";
    }
    std::cout<<"]\n";

  }

  List List::filter( std::function <bool(int)> f)
  {
    List l_out;
    for(unsigned int i=0;i<_data.size();i++)
    {
      if( f(_data[i]) )   l_out.insert(_data[i]);
    }

    return l_out ;
  }




