#include "virus.h"

Virus::Virus(std::string name):
_name(name),
_rna(nullptr),
_age(0) 
{}

Virus::Virus(std::string name, std::vector<Nukleotyp> rna ):
_name(name),
_rna(new RNA(rna)),
_age(0)
{}

Virus::Virus(Virus& vir):
_name(vir._name),
_rna(new RNA(*vir._rna)),
_age(0)
{
	vir._age++;
}

Virus::Virus(Virus&& vir):
_name(std::move(vir._name)),
_rna( std::__exchange(vir._rna, nullptr) ),
_age(std::move(vir._age))
{
	_rna->mutate();
}

Virus::~Virus()
{
    if(_rna != nullptr) 
	{
        delete _rna;
    }
}

std::string Virus::get_name() const
{
    return _name;
}

unsigned Virus::get_age() const
{
    return _age;
}

RNA* Virus::get_RNA() const
{
	return _rna;
}

void Virus::set_RNA(std::vector<Nukleotyp> rna)
{
    if(_rna != nullptr)
    {
		delete _rna;
    }
    _rna = new RNA(rna);
}


Virus& Virus::operator=(const Virus& vir)
{
	if(&vir != this)
    {
        delete _rna;
        _rna = new RNA( *vir.get_RNA() );
        _rna->mutate();
        _name = vir.get_name();
        _age = 0;
    }
	return *this;
}

Virus& Virus::operator=(Virus&& vir)
{
	if(&vir != this)
	{
		_rna = std::__exchange(vir._rna, nullptr);
		_name = std::move(vir._name);
		_age = std::move(vir._age);
	}
	return *this;
}