#include "Animals.h"

  Cow::Cow(std::string name): Animal(name) 
  {}
  
  Cow::~Cow()
  {
    std::cout<<"- Krowa "<< _name << "wraca do obory"<<std::endl;
  }    

  void Cow::print() const 
  {
    std::cout<<"- Krowa "<< _name <<std::endl;

  }





  Horse::Horse(std::string name): Animal(name)
  {}
  
  Horse::~Horse()
  {
    std::cout<<"- Koń "<< _name << "wraca do stajni"<<std::endl;
  }

  void Horse::print() const 
  {
    std::cout<<"- Koń "<< _name <<std::endl;
  }





  Sheep::Sheep(std::string name): Animal(name), _sheared(false)
  {}
  
  Sheep::~Sheep()
  {
    std::cout<<"- Owca "<< _name <<" "<<(_sheared?"":"nie") <<"ostrzyzona "<< "wraca do zagrody"<<std::endl;
  }

  void Sheep::print() const 
  {
    std::cout<<"- Owca "<< _name <<" "<<(_sheared?"":"nie") <<"ostrzyzona"<<std::endl;
  }

  void Sheep::shear()
  {
    _sheared = true;
  }
