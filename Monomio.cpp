/*! 
   \file  Monomio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Monomio
*/


//  Ficheros de cabecera
#include <iostream>

#include "Monomio.hpp"

// Operadores de asignación

ed::Monomio & ed::Monomio::operator=(ed::Monomio const &m)
{
	this->setCoeficiente(m.coeficiente_);
	this->setGrado(m.grado_);

	#ifndef NDEBUG
	assert(std::abs(this->getCoeficiente() - m.coeficiente_) < COTA_ERROR);
	assert(this->getGrado() == m.grado_);
	#endif

	// Se devuelve el objeto actual
	return *this;
}


ed::Monomio & ed::Monomio::operator=(double const &x)
{
	this->setCoeficiente(x);
	this->setGrado(0);
	#ifndef NDEBUG
	assert(std::abs(this->getCoeficiente() - x) < COTA_ERROR);
	assert(this->getGrado() == 0);
	#endif
	// Se devuelve el objeto actual
	return *this;
}



//////////////////////////////////////////////////////////////

// Operadores aritméticos y asignación


ed::Monomio & ed::Monomio::operator+=(ed::Monomio const &m)
{
	double aux=this->getCoeficiente();
	int auxg=this->getGrado();

	#ifndef NDEBUG
	assert(this->getGrado() == m.grado_);
	#endif

	this->setCoeficiente(m.coeficiente_+this->getCoeficiente());

	#ifndef NDEBUG
	assert(std::abs(this->getCoeficiente() - m.coeficiente_) == aux);
	assert(this->getGrado() == auxg);
	#endif

	// Se devuelve el objeto actual
	return *this;
}

ed::Monomio & ed::Monomio::operator-=(ed::Monomio const &m)
{
	double aux=this->getCoeficiente();
	int auxg=this->getGrado();

	#ifndef NDEBUG
	assert(this->getGrado() == m.grado_);
	#endif

	this->setCoeficiente(this->getCoeficiente() - m.coeficiente_);

	#ifndef NDEBUG
	assert(std::abs(this->getCoeficiente() + m.coeficiente_) == aux);
	assert(this->getGrado() == auxg);
	#endif
	// Se devuelve el objeto actual
	return *this;

}

ed::Monomio & ed::Monomio::operator*=(ed::Monomio const &m)
{
	double aux=this->getCoeficiente();
	int auxg=this->getGrado();

	this->setCoeficiente(this->getCoeficiente() * m.coeficiente_);
	this->setGrado(this->getGrado() + m.grado_);

	#ifndef NDEBUG
	assert(std::abs(this->getCoeficiente() / m.coeficiente_) == aux);
	assert(this->getGrado() == auxg + m.grado_);
	#endif

	// Se devuelve el objeto actual
	return *this;

}

ed::Monomio & ed::Monomio::operator/=(ed::Monomio const &m)
{
	double aux=this->getCoeficiente();
	int auxg=this->getGrado();

	#ifndef NDEBUG
	assert(this->getGrado() >= m.grado_);
	assert(m.grado_ != 0);
	#endif

	this->setGrado(this->getGrado() - m.grado_);
	this->setCoeficiente(this->getCoeficiente() / m.coeficiente_);

	#ifndef NDEBUG
	assert(std::abs(this->getCoeficiente() * m.coeficiente_) == aux);
	assert(auxg == this->getGrado() + m.grado_ );
	#endif

	// Se devuelve el objeto actual
	return *this;

}

ed::Monomio & ed::Monomio::operator*=(double const &m)
{ 
	double aux= this->getCoeficiente();
	int auxg=this->getGrado();

	this->setCoeficiente(this->getCoeficiente() * m);

	#ifndef NDEBUG
	assert(std::abs(this->getCoeficiente() / m) == aux);
	assert(this->getGrado() == auxg);
	#endif
	
	// Se devuelve el objeto actual
	return *this;

}

ed::Monomio & ed::Monomio::operator/=(double const &m)
{ 
	double aux= this->getCoeficiente();
	int auxg=this->getGrado();

	#ifndef NDEBUG
	assert(m != 0);
	#endif

	this->setCoeficiente(this->getCoeficiente() / m);

	#ifndef NDEBUG
	assert(std::abs(this->getCoeficiente() * m) == aux);
	assert(this->getGrado() == auxg);
	#endif
	
	// Se devuelve el objeto actual
	return *this;

}

