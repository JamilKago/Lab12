#pragma once
             
#include "base.h"
#include <iostream>
#include <cmath>
using namespace std;


class Point: public Transformable
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

  void pos() const
  {
    cout << "(" <<_x << ", " <<_y <<")"; 
  }

  void shift( double dx,  double dy )
  {
    _x += dx;
    _y += dy;
  }

  friend ostream& operator<<(ostream& out, const Point pkt)
  {
    return out << "(" << pkt.getX() << ", " << pkt.getY() <<")";
  }

};


class Section: public Drawable, public Transformable
{
  protected:
  Point _A;
  Point _B;
  

  public:
  Section(Point a, Point b): _A(a), _B(b)
  {}

  void to_draw() const override 
  {
    cout<<"Drowing section from ";
    _A.pos();
    cout << " to ";
    _B.pos();
    cout << endl;
  }

  void both_pos() const
  {
    _A.pos();
    cout << ", ";
    _B.pos();
  }


  double length() const override
  {
    double val = (_B.getX()-_A.getX()) * (_B.getX()-_A.getX());
    val += (_B.getY() - _A.getY()) * (_B.getY() - _A.getY());
    return sqrt( val );
  }

  void shift( double dx,  double dy ) override
  {
    _A.shift(dx, dy);
    _B.shift(dx, dy); 
  }

  Point getA() const
  {
    return _A;
  }

  Point getB() const
  {
    return _B;
  }


};


///---------------------------------------------

class Deltoid: public ClosedShape, public Transformable
{
  protected:
  Section _P;
  Section _Q;

  public:
  Deltoid(const Section a, const Section b): 
  _P(a), _Q(b)
  {}

  Deltoid(const Point a, const Point b, const Point c, const Point d ): 
  _P( Section(a,c)) , _Q(Section(b,d))
  {}


  void to_draw() const override 
  {
    cout << "Drawing a deltoid with vertices ";
    _P.getA().pos();
    cout << ", ";
    _Q.getA().pos();
    cout << ", ";
    _P.getB().pos();
    cout << ", ";
    _Q.getB().pos();
    cout << endl;
  }

  double area() const override
  {
    return  _P.length() * _Q.length();
  }

  double length() const override
  {
    double out = 0.0;
    out += 2 * Section(_P.getA(),_Q.getA()).length(); 
    out += 2 * Section(_P.getB(),_Q.getB()).length(); 
    return  out;
  }

  void shift( double dx,  double dy ) override
  {
    _P.shift(dx, dy);
    _Q.shift(dx, dy);
  }

};

///---------------------------------------------

class Circle: public ClosedShape, public Transformable
{
  protected:
  Point _S;
  double _R;

  public:
  Circle(const Point a, const double b): _S(a), _R(b)
  {}

  void to_draw() const override 
  {
    cout<<"Drowing a circle centered at ";
    _S.pos(); 
    cout << " with radius "<< _R <<endl;
  }

  double area() const override
  {
    return M_PI* _R *_R;
  }

  double length() const override
  {
    return 2.0 * M_PI * _R;
  }

  void shift( double dx,  double dy ) override
  {
    _S.shift(dx, dy);
  }

};