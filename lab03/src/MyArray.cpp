 #include "MyArray.h"

  MyArray::MyArray(const int size) : _size(size)
  { 
    _data = new int[_size];
  }

  MyArray::MyArray(const MyArray& org): 
  _size(org._size), _next(org._next)
  {
    _data = new int[_size];
    for(int i=0;i<_size;i++)  _data[i] = org._data[i];
  }

  MyArray::MyArray (MyArray&& org):
  _size(std::exchange(org._size,0)), _data(std::exchange(org._data,nullptr)), 
  _next(std::exchange(org._next,nullptr))
  {}

  MyArray::~MyArray()
  {
    delete [] _data;
    _size = 0;
    delete _next;
  }

  int& MyArray::operator[](const int id)
  {
    return _data[id];
  }

  int MyArray::operator[](const int id) const
  {
    return _data[id];
  }
  
  MyArray MyArray::operator++(int)
  {
    MyArray copy = *this;
    for(int i=0;i<size();i++)
    {
      _data[i]++;
    }
    return copy;
  }

  MyArray& MyArray::operator--()
  {
    for(int i=0;i<size();i++)
    {
      _data[i]--;
    }
    return *this;
  }

  MyArray& MyArray::operator=(const MyArray& T)
  {
    if (this == &T) return *this;
    else
    {
      _size = T._size;
      _next = T._next;
      delete[] _data;
      _data = new int[_size];
      for(int i=0;i<_size;i++)  _data[i] = T._data[i];
      return *this;
    }
  }


  MyArray& MyArray::operator+=(MyArray& T)
  {
    MyArray* temp = this;
    while (temp->_next != nullptr)
    {
      temp = temp -> _next;
    }
    temp->_next = &T;
    return *this;
  }

  MyArray& MyArray::operator+=(MyArray&& T)
  {
    MyArray* temp = this;
    while (temp->_next != nullptr)
    {
      temp = temp -> _next;
    }
    temp->_next = new MyArray(T);
    return *this;
  }

  void MyArray::print(std::string prefix) const
  {
    std::cout<< prefix;
    const MyArray* temp = this;
    while (temp->_next != nullptr)
    {
      std::cout<<*temp<<" ";
      temp = temp->_next;
    } 
  }

  MyArray& MyArray::getNext()
  {
    return *_next;
  }

  int MyArray::size() const
  {
    return _size;
  }

  std::ostream& operator<<(std::ostream& out, const MyArray& T)
  {
    if(T.size()) 
    {
      std::cout<<"[";
      for(int i=0; i<T.size(); i++)
      {
        std::cout << T[i] <<", ";
      }
      std::cout<<"\b\b]";
      
    }
    return out;
  }