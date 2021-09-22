#pragma once
#include <iostream>

using namespace std;

class Drawable
{
  public:
  Drawable() = default;
  
  virtual ~Drawable() = default;

  virtual double length() const = 0;

  virtual void to_draw() const = 0;

  friend void draw( Drawable* shape)
  {
    shape -> to_draw();
  }

};

class Transformable
{
  protected:
  
  public:
  virtual void shift( double dx,  double dy ) = 0;
};


class ClosedShape: public Drawable 
{
  protected:

  public:
  virtual double area() const = 0;

};

