#pragma once
/* hierarchia

             class Drawable          <<<-----      class Point - klsa zewnetrzna uzywana prez reszte 
                  ||
              Transformable
          /                   \
    ClosedShape             Section
        ||                     
        ||                     
  Circle + Deltoid             
                             
               


*/
#include "base.h"
#include <iostream>
#include <cmath>
using namespace std;

///---------------------------------------------

class Section: public Transformable
{
  protected:
  Point _A;
  Point _B;
  

  public:
  Section(Point a, Point b): _A(a), _B(b)
  {}

  void to_draw() const override 
  {
    cout<<"Rysujemy odcinek od " << _A.pos() << " do " << _B.pos() <<endl;
  }

  string both_pos() const
  {
    string both = _A.pos() + ", " + _B.pos();
    return both;
  }


  double length() const override
  {
    double val = (_B.getX() - _A.getX()) * (_B.getX() - _A.getX());
    val += (_B.getY() - _A.getY()) * (_B.getY() - _A.getY());
    return sqrt( val );
  }

  void shift( double dx,  double dy ) override
  {
    
  }


};


///---------------------------------------------

class Deltoid: public ClosedShape
{
  protected:
  Section _P;
  Section _Q;

  public:
  Deltoid(const Section a, const Section b ): _P(a), _Q(b)
  {}

  Deltoid(const Point a, const Point b, const Point c, const Point d ): _P( Section(a,b)) , _Q(Section(c,d))
  {}


  void to_draw() const override 
  {
    cout<<"Rysujemy deltoid o wierzcholkach " << _P.both_pos() << ", " << _Q.both_pos() <<endl;
  }

  double area() const override
  {
    return 0.0;

  }

  double length() const override
  {
    return 0.0;
    
  }

  void shift( double dx,  double dy ) override
  {

  }

};

///---------------------------------------------

class Circle: public ClosedShape
{
  protected:
  Point _S;
  double _R;

  public:
  Circle(const Point a, const double b): _S(a), _R(b)
  {}

  void to_draw() const override 
  {
    cout<<"Rysujemy kolo o srodku " << _S.pos() << " i promieniu " << _R <<endl;
  }

  double area() const override
  {
    return M_PI * _R *_R;

  }

  double length() const override
  {
    return 2.0 * M_PI * _R;
    
  }

  void shift( double dx,  double dy ) override
  {
    
  }

};