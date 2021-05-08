#include "FilterCriteria.h"


  FilterCriteria::~FilterCriteria()
  {
    _fun.clear();
  }

  std::function<bool(int)> FilterCriteria::get( int id)
  {
    return _fun[id];
  }

  void FilterCriteria::add( std::function <bool(int)> f)
  {
    _fun.push_back(f);
  }

  int FilterCriteria::size() const
  {
    return _fun.size();
  }

