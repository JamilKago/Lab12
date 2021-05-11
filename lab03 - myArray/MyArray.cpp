 #include "MyArray.h"

  MyArray::MyArray(): _data(nullptr), _size(0), _next(nullptr)
  {}


  MyArray::MyArray(const int size): _data(nullptr), _size(size), _next(nullptr)
  {
    if (_size ) 
    {
        _data = new int[_size];
        for (int i = 0; i < _size; i++) _data[i] = 0;
    } 
  }

  MyArray::MyArray(const MyArray& org): 
  _data(nullptr), _size(org._size), _next(org._next)
  {
	if (_size ) 
	{
	    _data = new int[_size];
	    for (int i = 0; i < _size; i++) _data[i] = org._data[i];
	} 
  }

  MyArray::MyArray (MyArray&& org)
  {
  	_size = std::__exchange(org._size,0);
  	_data = std::__exchange(org._data,nullptr);
  	_next = std::__exchange(org._next,nullptr);
  }

  MyArray::~MyArray()
  {
  	if( _data )
    	delete [] _data; 
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
    MyArray copy = MyArray(*this);
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
    if (this == &T) 
    	return *this;
    else
    {
      _size = T._size;
      _next = T._next;
      delete[] _data;
      _data = new int[_size];
      for(int i=0;i<_size;i++)  
      	_data[i] = T._data[i];
      return *this;
    }
  }


  MyArray& MyArray::operator+=(MyArray& T)
  {
    if (_next == nullptr) 
    {
        _next = &T;
    } 
    else 
    {
        *_next += T;
    }
    return *this;
  }
  

  MyArray& MyArray::operator+=(MyArray&& T)
  {
   	int* temp = new int[ _size + T._size ];
   	for (int i = 0; i < _size; ++i)	
   		temp[i] = _data[i];

   	for (int i = 0; i < T._size; ++i)	
   		temp[_size + i] = T._data[i];

   	_size = _size + T._size;
   	delete [] _data;
   	_data = temp;
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
    std::cout<<*temp<<" ";

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
    if( T.size() != 0 ) 
    {
      out<<"[";
      for(int i=0; i<T.size(); i++)
      {
        out << T[i] <<", ";
      }
      out<<"\b\b]";
      
    }
    return out;
  }