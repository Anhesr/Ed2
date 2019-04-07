/*!
	\file operadoresExternosPolinomios.hpp
	\brief Ficheros con operadores de monomios y polinomios
*/

#ifndef _OperadoresPolinomios_HPP_
#define _OperadoresPolinomios_HPP_

// Facilita la entrada y salida
#include <iostream>

#include "Polinomio.hpp"

using std::istream;
using std::ostream;

// Espacio de nombre de la asigantura: ed
namespace ed
{

////////////////////////////////////////////////////////////////////////////
	// Funciones y operadores que no pertenecen a la clase Polinomio


	////////////////////////////////////////////////////////////
	//! \name Operadores de igualdad

	/**
		@fn bool operator==(ed::Polinomio const & p1, ed::Polinomio const & p2)	
		@brief Operador que comprueba si dos polinomios son iguales
		@param ed::Polinomio const & p1, ed::Polinomio const & p2
		@return bool
		*/
	bool operator==(ed::Polinomio const & p1, ed::Polinomio const & p2);
	/**
		@fn bool operator==(ed::Polinomio const & p, ed::Monomio const & m)	
		@brief Operador que comprueba si un polinomio y un monomio son iguales
		@param ed::Monomio const & m, ed::Polinomio const & p
		@return bool
		*/
	bool operator==(ed::Polinomio const & p, ed::Monomio const & m);
	/**
		@fn bool operator==(ed::Monomio const & m, ed::Polinomio const & p)
		@brief Operador que comprueba si un polinomio y un monomio son iguales
		@param ed::Monomio const & m, ed::Polinomio const & p
		@return bool
		*/
	bool operator==(ed::Monomio const & m, ed::Polinomio const & p);
	/**
		@fn bool operator==(ed::Polinomio const & p, double const & x)
		@brief Operador que comprueba si un polinomio y un numero son iguales
		@param ed::Polinomio const & p, double const & x
		@return bool
		*/

	bool operator==(ed::Polinomio const & p, double const & x);
	/**
		@fn bool operator==(double const & x, ed::Polinomio const & p)
		@brief Operador que comprueba si un polinomio y un numero son iguales
		@param double const & x, ed::Polinomio const & p
		@return bool
		*/
	bool operator==(double const & x, ed::Polinomio const & p);


	////////////////////////////////////////////////////////////////////////////////////
	//! \name Operadores de desigualdad

	/**
		@fn bool operator!=(ed::Polinomio const & p1, ed::Polinomio const & p2)	
		@brief Operador que comprueba si dos polinomios son distintos
		@param ed::Polinomio const & p1, ed::Polinomio const & p2
		@return bool
		*/
	bool operator!=(ed::Polinomio const & p1, ed::Polinomio const & p2);
	/**
		@fn bool operator!=(ed::Polinomio const & p, ed::Monomio const & m)	
		@brief Operador que comprueba si un polinomio y un monomio son distintos
		@param ed::Monomio const & m, ed::Polinomio const & p
		@return bool
		*/
	bool operator!=(ed::Polinomio const & p, ed::Monomio const & m);
	/**
		@fn bool operator!=(ed::Monomio const & m, ed::Polinomio const & p)
		@brief Operador que comprueba si un polinomio y un monomio son distintos
		@param ed::Monomio const & m, ed::Polinomio const & p
		@return bool
		*/
	bool operator!=(ed::Monomio const & m, ed::Polinomio const & p);
	/**
		@fn bool operator!=(ed::Polinomio const & p, double const & x)
		@brief Operador que comprueba si un polinomio y un numero son distintos
		@param ed::Polinomio const & p, double const & x
		@return bool
		*/
	bool operator!=(ed::Polinomio const & p, double const & x);
		/**
		@fn bool operator!=(double const & x, ed::Polinomio const & p)
		@brief Operador que comprueba si un polinomio y un numero son distintos
		@param double const & x, ed::Polinomio const & p
		@return bool
		*/
	bool operator!=(double const & x, ed::Polinomio const & p);



//////////////////////////////////////////////////////////////////////////////////////

	//! \name Operadores unarios

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
		/**
		@fn ed::Polinomio & operator+(ed::Polinomio const & p)
		@brief Operador que devuelve una copia del polinomio p
		@param ed::Polinomio const & p
		*/
		ed::Polinomio & operator+(ed::Polinomio const & p);
		/**
		@fn ed::Polinomio & operator-(ed::Polinomio const & p)
		@brief Operador que devuelve una copia opuesta del polinomio p
		@param ed::Polinomio const & p
		*/
		ed::Polinomio & operator-(ed::Polinomio const & p);

	// COMPLETAR EL OTRO OPERADOR UNARIO PREFIJO: resta


//////////////////////////////////////////////////////////////////////////////////////

	//! \name Operadores binarios de la suma

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
		/**
		@fn ed::Polinomio & operator+(ed::Polinomio const &p1,  ed::Polinomio const &p2)
		@brief Operador que devuelve la suma de dos polinomios
		@param ed::Polinomio const & p1 ,ed::Polinomio const &p2
		*/
		ed::Polinomio & operator+(ed::Polinomio const &p1,  ed::Polinomio const &p2);
		/**
		@fn ed::Polinomio & operator+(ed::Polinomio const &p,  ed::Monomio const &m)
		@brief Operador que devuelve la suma de un polinomio y un monomio
		@param ed::Polinomio const &p,  ed::Monomio const &m
		*/
		ed::Polinomio & operator+(ed::Polinomio const &p,  ed::Monomio const &m);
		/**
		@fn ed::Polinomio & operator+(ed::Monomio const &m,  ed::Polinomio const &p)
		@brief Operador que devuelve la suma de un polinomio y un monomio
		@param ed::Monomio const &m,  ed::Polinomio const &p
		*/
		ed::Polinomio & operator+(ed::Monomio const &m,  ed::Polinomio const &p);
		/**
		@fn ed::Polinomio & operator+(ed::Polinomio const &p,  double const &x)
		@brief Operador que devuelve la suma de un polinomio y un real
		@param ed::Polinomio const &p,  double const &x
		*/
		ed::Polinomio & operator+(ed::Polinomio const &p,  double const &x);
		/**
		@fn ed::Polinomio & operator+(double const &x,  ed::Polinomio const &p)
		@brief Operador que devuelve la suma de un polinomio y un real
		@param double const &x,  ed::Polinomio const &p
		*/
		ed::Polinomio & operator+(double const &x,  ed::Polinomio const &p);



		//////////////////////////////////////////////////////////
		//! \name Operador binario de la resta

		ed::Polinomio & operator-(ed::Polinomio const &p1,  ed::Polinomio const &p2);
		/**
		@fn ed::Polinomio & operator-(ed::Polinomio const &p1,  ed::Polinomio const &p2)
		@brief Operador que devuelve la resta de dos polinomios
		@param ed::Polinomio const & p1 ,ed::Polinomio const &p2
		*/
		ed::Polinomio & operator-(ed::Polinomio const &p,  ed::Monomio const &m);
		/**
		@fn ed::Polinomio & operator-(ed::Polinomio const &p,  ed::Monomio const &m)
		@brief Operador que devuelve la resta de un polinomio y un monomio
		@param ed::Polinomio const &p,  ed::Monomio const &m
		*/
		ed::Polinomio & operator-(ed::Monomio const &m,  ed::Polinomio const &p);
		/**
		@fn ed::Polinomio & operator-(ed::Monomio const &m,  ed::Polinomio const &p)
		@brief Operador que devuelve la resta de un polinomio y un monomio
		@param ed::Monomio const &m,  ed::Polinomio const &p
		*/
		ed::Polinomio & operator-(ed::Polinomio const &p,  double const &x);
		/**
		@fn ed::Polinomio & operator-(ed::Polinomio const &p,  double const &x)
		@brief Operador que devuelve la resta de un polinomio y un real
		@param ed::Polinomio const &p,  double const &x
		*/
		ed::Polinomio & operator-(double const &x,  ed::Polinomio const &p);
		/**
		@fn ed::Polinomio & operator-(double const &x,  ed::Polinomio const &p)
		@brief Operador que devuelve la resta de un polinomio y un real
		@param double const &x,  ed::Polinomio const &p
		*/


		///////////////////////////////////////////////////////////////////////////
		//! \name Operadores binarios de la multiplicación

		ed::Polinomio & operator*(ed::Polinomio const &p1,  ed::Polinomio const &p2);
		/**
		@fn ed::Polinomio & operator*(ed::Polinomio const &p1,  ed::Polinomio const &p2)
		@brief Operador que devuelve la multiplicación de dos polinomios
		@param ed::Polinomio const & p1 ,ed::Polinomio const &p2
		*/
		ed::Polinomio & operator*(ed::Polinomio const &p,  ed::Monomio const &m);
		/**
		@fn ed::Polinomio & operator*(ed::Polinomio const &p,  ed::Monomio const &m)
		@brief Operador que devuelve la multiplicación de un polinomio y un monomio
		@param ed::Polinomio const &p,  ed::Monomio const &m
		*/
		ed::Polinomio & operator*(ed::Monomio const &m,  ed::Polinomio const &p);
		/**
		@fn ed::Polinomio & operator*(ed::Monomio const &m,  ed::Polinomio const &p)
		@brief Operador que devuelve la multiplicación de un polinomio y un monomio
		@param ed::Monomio const &m,  ed::Polinomio const &p
		*/
		ed::Polinomio & operator*(ed::Polinomio const &p,  double const &x);
		/**
		@fn ed::Polinomio & operator*(ed::Polinomio const &p,  double const &x)
		@brief Operador que devuelve la multiplicación de un polinomio y un real
		@param ed::Polinomio const &p,  double const &x
		*/
		ed::Polinomio & operator*(double const &x,  ed::Polinomio const &p);
		/**
		@fn ed::Polinomio & operator*(double const &x,  ed::Polinomio const &p)
		@brief Operador que devuelve la multiplicación de un polinomio y un real
		@param double const &x,  ed::Polinomio const &p
		*/

		///////////////////////////////////////////////////////////////////////////

		//! \name Operadores binarios de la división

		ed::Polinomio & operator/(ed::Polinomio const &p1,  ed::Polinomio const &p2);
		/**
		@fn ed::Polinomio & operator/(ed::Polinomio const &p1,  ed::Polinomio const &p2)
		@brief Operador que devuelve la división de dos polinomios
		@param ed::Polinomio const & p1 ,ed::Polinomio const &p2
		*/
		ed::Polinomio & operator/(ed::Polinomio const &p,  ed::Monomio const &m);
		/**
		@fn ed::Polinomio & operator/(ed::Polinomio const &p,  ed::Monomio const &m)
		@brief Operador que devuelve la división de un polinomio y un monomio
		@param ed::Polinomio const &p,  ed::Monomio const &m
		*/
		ed::Polinomio & operator/(ed::Monomio const &m,  ed::Polinomio const &p);
		/**
		@fn ed::Polinomio & operator/(ed::Monomio const &m,  ed::Polinomio const &p)
		@brief Operador que devuelve la división de un polinomio y un monomio
		@param ed::Monomio const &m,  ed::Polinomio const &p
		*/
		ed::Polinomio & operator/(ed::Polinomio const &p,  double const &x);
		/**
		@fn ed::Polinomio & operator/(ed::Polinomio const &p,  double const &x)
		@brief Operador que devuelve la división de un polinomio y un real
		@param ed::Polinomio const &p,  double const &x
		*/
		ed::Polinomio & operator/(double const &x,  ed::Polinomio const &p);
		/**
		@fn ed::Polinomio & operator/(double const &x,  ed::Polinomio const &p)
		@brief Operador que devuelve la división de un polinomio y un real
		@param double const &x,  ed::Polinomio const &p
		*/

	/////////////////////////////////////////////////////////////////////////////

   //! \name Sobrecarga de los operadores de flujo de la clase Polinomio.

		/**
		@fn ostream &operator<<(ostream &stream, ed::Polinomio const &p)
		@brief Operador que lee un polinomio desde el flujo de entrada
		@param ostream &stream, ed::Polinomio const &p
		*/

    ostream &operator<<(ostream &stream, ed::Polinomio const &p);
    /**
		@fn istream &operator>>(istream &stream, ed::Polinomio &p)
		@brief Operador que escribe en el flujo del polinomio
		@param istream &stream, ed::Polinomio &p
		*/
    istream &operator>>(istream &stream, ed::Polinomio &p);

}  // Fin de namespace ed.

#endif // _OperadoresPolinomios_HPP_
