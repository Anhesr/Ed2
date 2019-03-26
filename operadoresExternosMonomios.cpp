/*! 
   \file  operadoresExternosMonomios.cpp
	\brief Ficheros con el código de los operadores externos de la clase Monomio
*/


//  Ficheros de cabecera
#include <iostream>

#include "operadoresExternosMonomios.hpp"


//  Se incluyen los operadores sobrecargados dentro del espacio de nombres ed
namespace ed 
{
	// Operadores de igualdad
	
	// COMPLETAR

	bool operator==(ed::Monomio const & m1, ed::Monomio const & m2)
	{
		bool aux;
		if( (std::abs(m1.getCoeficiente() - m2.getCoeficiente()) < COTA_ERROR)&&(m1.getGrado()==m2.getGrado())){
			aux=true;
		}
		else{
			aux=false;
		}
		#ifndef NDEBUG
			if( (std::abs(m1.getCoeficiente() - m2.getCoeficiente()) < COTA_ERROR)&&(m1.getGrado()==m2.getGrado())){
			assert(aux==true);
		}
		else{
			assert(aux==false);
		}
		#endif
		return aux;
	}

	// COMPLETAR LOS OTROS OPERADORES DE IGUALDAD


	bool operator==(ed::Monomio const & m1,double const & m2)
	{
		bool aux;
		if( (std::abs(m1.getCoeficiente() - m2) < COTA_ERROR)&&(m1.getGrado()==0)){
			aux=true;
		}
		else{
			aux=false;
		}
		#ifndef NDEBUG
			if( (std::abs(m1.getCoeficiente() - m2) < COTA_ERROR)&&(m1.getGrado()==0)){
			assert(aux==true);
		}
		else{
			assert(aux==false);
		}
		#endif
		return aux;
	}


	bool operator==(double const & m2,ed::Monomio const & m1)
	{
		bool aux;
		if( (std::abs(m1.getCoeficiente() - m2) < COTA_ERROR)&&(m1.getGrado()==0)){
			aux=true;
		}
		else{
			aux=false;
		}
		#ifndef NDEBUG
			if( (std::abs(m1.getCoeficiente() - m2) < COTA_ERROR)&&(m1.getGrado()==0)){
			assert(aux==true);
		}
		else{
			assert(aux==false);
		}
		#endif
		return aux;
	}

	// Operadores de desigualdad

	// COMPLETAR
	bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2)
	{
		bool aux;
		if((std::abs(m1.getCoeficiente() - m2.getCoeficiente()) >= COTA_ERROR) || (m1.getGrado()!=m2.getGrado())){
			aux=true;
		}

		else{
			aux=false;
		}

		#ifndef NDEBUG
			if((std::abs(m1.getCoeficiente() - m2.getCoeficiente()) >= COTA_ERROR) || (m1.getGrado()!=m2.getGrado())){
			assert(aux==true);
		}

		else{
			assert(aux==false);
		}
		#endif
		return aux;

	}

	bool operator!=(ed::Monomio const & m1,double const & m2)
	{
		bool aux;
		if( (std::abs(m1.getCoeficiente() - m2) >= COTA_ERROR)||(m1.getGrado()!=0)){
			aux=true;
		}
		else{
			aux=false;
		}
		#ifndef NDEBUG
			if( (std::abs(m1.getCoeficiente() - m2) >= COTA_ERROR)||(m1.getGrado()!=0)){
			assert(aux==true);
		}
		else{
			assert(aux==false);
		}
		#endif
		return aux;
	}

	bool operator!=(double const & m2,ed::Monomio const & m1)
	{
		bool aux;
		if( (std::abs(m1.getCoeficiente() - m2) >= COTA_ERROR)||(m1.getGrado()!=0)){
			aux=true;
		}
		else{
			aux=false;
		}
		#ifndef NDEBUG
			if( (std::abs(m1.getCoeficiente() - m2) >= COTA_ERROR)||(m1.getGrado()!=0)){
			assert(aux==true);
		}
		else{
			assert(aux==false);
		}
		#endif
		return aux;
	}


	////////////////////////////////////////////////////////////

	// Operadores unarios prefijos 

	// COMPLETAR
	ed::Monomio & operator+(ed::Monomio const & m)
	{
		
		ed::Monomio *nuevo = new ed::Monomio();
		
		nuevo->setCoeficiente(m.getCoeficiente());
		nuevo->setGrado(m.getGrado());

		#ifndef NDEBUG
		assert(nuevo->getCoeficiente() == m.getCoeficiente());
		assert(nuevo->getGrado() == m.getGrado());
		#endif

		return *nuevo;
	}

	ed::Monomio & operator-(ed::Monomio const & m)
	{

		ed::Monomio *nuevo = new ed::Monomio();

		nuevo->setCoeficiente(-1 * m.getCoeficiente());
		nuevo->setGrado(m.getGrado());

		#ifndef NDEBUG
		assert(nuevo->getCoeficiente() == -1 * m.getCoeficiente());
		assert(nuevo->getGrado() == m.getGrado());
		#endif

		return *nuevo;
	}

	// COMPLETAR EL OTRO OPERADOR UNARIO PREFIJO: resta


	////////////////////////////////////////////////////////////
	// Operadores aritméticos binarios

	// Suma
	ed::Monomio & operator+ (ed::Monomio const &m1, ed::Monomio const &m2)
	{
		ed::Monomio *nuevo = new ed::Monomio();

		#ifndef NDEBUG
		assert(m1.getGrado() == m2.getGrado());
		#endif


		nuevo->setCoeficiente(m1.getCoeficiente()+m2.getCoeficiente());
		nuevo->setGrado(m1.getGrado());

		#ifndef NDEBUG
		assert(nuevo->getCoeficiente() == m1.getCoeficiente()+m2.getCoeficiente());
		assert(nuevo->getGrado() == m1.getGrado());
		#endif


		return *nuevo;
	}


	////////////
	// Resta
	ed::Monomio & operator- (ed::Monomio const &m1, ed::Monomio const &m2)
	{
		ed::Monomio *nuevo = new ed::Monomio();

		#ifndef NDEBUG
		assert(m1.getGrado() == m2.getGrado());
		#endif


		nuevo->setCoeficiente(m1.getCoeficiente()-m2.getCoeficiente());
		nuevo->setGrado(m1.getGrado());

		#ifndef NDEBUG
		assert(nuevo->getCoeficiente() == m1.getCoeficiente()-m2.getCoeficiente());
		assert(nuevo->getGrado() == m1.getGrado());
		#endif

		return *nuevo;
	}


	//////////////////
	// Multiplicación

	ed::Monomio & operator*(ed::Monomio const &m1, ed::Monomio const &m2)
	{

		ed::Monomio *nuevo = new ed::Monomio();

		nuevo->setCoeficiente(m1.getCoeficiente() * m2.getCoeficiente());
		nuevo->setGrado(m1.getGrado()+m2.getGrado());

		#ifndef NDEBUG
		assert(nuevo->getCoeficiente() == m1.getCoeficiente()*m2.getCoeficiente());
		assert(nuevo->getGrado() == m1.getGrado()+m2.getGrado());
		#endif

		return *nuevo;
	}


		ed::Monomio & operator*(ed::Monomio const &m1, double const & x)
	{
		ed::Monomio *nuevo = new ed::Monomio();

		nuevo->setCoeficiente(m1.getCoeficiente() * x);
		nuevo->setGrado(m1.getGrado());

		#ifndef NDEBUG
		assert(nuevo->getCoeficiente() == m1.getCoeficiente()*x);
		assert(nuevo->getGrado() == m1.getGrado());
		#endif

	
		return *nuevo;
	}

			ed::Monomio & operator*(double const & x,ed::Monomio const &m1)
	{

		ed::Monomio *nuevo = new ed::Monomio();

		nuevo->setCoeficiente(m1.getCoeficiente() * x);
		nuevo->setGrado(m1.getGrado());

		#ifndef NDEBUG
		assert(nuevo->getCoeficiente() == m1.getCoeficiente()*x);
		assert(nuevo->getGrado() == m1.getGrado());
		#endif


		return *nuevo;
	}

	////////////
	// División

	ed::Monomio & operator/(ed::Monomio const &m1, ed::Monomio const &m2)
	{
		#ifndef NDEBUG
		assert(m2.getGrado() <= m1.getGrado());
		assert(m2.getGrado()!= 0);
		#endif

		ed::Monomio *nuevo = new ed::Monomio();

		nuevo->setCoeficiente(m1.getCoeficiente() / m2.getCoeficiente());
		nuevo->setGrado(m1.getGrado() - m2.getGrado());

		#ifndef NDEBUG
		assert(nuevo->getCoeficiente() == m1.getCoeficiente()/m2.getCoeficiente());
		assert(nuevo->getGrado() == m1.getGrado()-m2.getGrado());
		#endif

		return *nuevo;
	}

		ed::Monomio & operator/(ed::Monomio const &m,double const & x)
	{
		#ifndef NDEBUG
		assert(x!= 0);
		#endif

		ed::Monomio *nuevo = new ed::Monomio();

		nuevo->setCoeficiente(m.getCoeficiente() / x);
		nuevo->setGrado(m.getGrado());

		#ifndef NDEBUG
		assert(nuevo->getCoeficiente() == m.getCoeficiente()/x);
		assert(nuevo->getGrado() == m.getGrado());
		#endif

		return *nuevo;
	}


			ed::Monomio & operator/(double const & x,ed::Monomio const &m)
	{
		#ifndef NDEBUG
		assert(x!= 0);
		#endif

		ed::Monomio *nuevo = new ed::Monomio();

		nuevo->setCoeficiente(m.getCoeficiente() / x);
		nuevo->setGrado(m.getGrado());

		#ifndef NDEBUG
		assert(nuevo->getCoeficiente() == m.getCoeficiente()/x);
		assert(nuevo->getGrado() == m.getGrado());
		#endif

		return *nuevo;
	}


	/////////////////////////////////////////////////////////////////////////////

	//  Sobrecarga del operador de entrada
	istream &operator>>(istream &stream, ed::Monomio &m) 
	{
		double c;
		int g;

		stream >> c;
		stream >> g;

		m.setCoeficiente(c);
		m.setGrado(g);
   		
		return stream;
	}


	//  Sobrecarga del operador de salida
	ostream &operator<<(ostream &stream, ed::Monomio const &m) 
	{
		stream << m.getCoeficiente();
		stream << " ";
		stream << m.getGrado();

		return stream;
	}


}  // namespace ed
