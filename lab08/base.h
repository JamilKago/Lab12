#pragma once
#include <iostream>

using namespace std;

///---------------------------------------------

class Point
{
  protected:
  double _x;
  double _y;

  public:
  Point() = default;
  Point(const double x, const double y): _x(x), _y(y)
  {}

  double getX() const{
    return _x;}  

  double getY() const{
    return _y;}

  string pos() const
  {
    string position = "(";
    position += to_string(_x);
    position +=", "; 
    position += to_string(_y);
    position +=") ";
    return position; 
  }

  friend ostream& operator<<(ostream& out, const Point pkt)
  {
    return out << pkt.pos();
  }

};


///--------------------------------------------- 


class Drawable
{

  protected:
  


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

///---------------------------------------------
class Transformable: virtual public Drawable 
{
  protected:
  
  public:
  virtual void shift( double dx,  double dy ) = 0;


};



///---------------------------------------------

class ClosedShape: public Transformable 
{
  protected:

  public:
  virtual double area() const = 0;
  


};

