#pragma once 
#include <iostream>
#include <utility>


/*
  *class of array 
*/

class MyArray
{
  
  private:
  int* _data;
  int _size;
  MyArray* _next;

  public:
  //--- constructors and desctructors ---//
  MyArray();

  MyArray(const int size);

  MyArray(const MyArray& org);

  MyArray(MyArray&& org);

  ~MyArray();

  //--- access methods and operators ---//
  int& operator[](int id);

  int operator[](int id) const;

  MyArray& getNext();

  int size() const;

  //--- increment and decrement ---//
  MyArray operator++(int);

  MyArray& operator--();

  //--- assaigment and adding operators ---//
  MyArray& operator=(const MyArray& T);

  MyArray& operator+=( MyArray& T);

  MyArray& operator+=(MyArray&& T);


  //--- printing arrays sequence ---//
  void print(std::string prefix) const;

};

//--- funcion printing single array ---//
std::ostream& operator<<(std::ostream& out, const MyArray& T);