/*! 
	\file operadoresExternosMonomios.hpp
	\brief Ficheros con los prototipos de los operadores externos de la clase Monomio
*/

#ifndef _OperadoresExternosMonomios_HPP_
#define _OperadoresExternosMonomios_HPP_

// Facilita la entrada y salida
#include <iostream>

#include "Monomio.hpp"

// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

// Espacio de nombre de la asigantura: ed
namespace ed
{
//////////////////////////////////////////////////////////////////////////////////////

	//! \name Operadores de igualdad  
		/**
		@fn bool operator==(ed::Monomio const & m1, ed::Monomio const & m2)
		@brief Operador de igualdad que comprueba si dos monomios son iguales
		@param ed::Monomio const & m1
		@param ed::Monomio const & m2
		@return bool
		@post El valor devuelto es verdadero si son iguales(mismos coeficiente y grado)
		@post El valor devuelto es falso si son distintos
		*/
	bool operator==(ed::Monomio const & m1, ed::Monomio const & m2);

		/**
		@fn bool operator==(ed::Monomio const & m1, double const & m2)
		@brief Operador de igualdad que comprueba si el coeficiente de un monomio es igual a un Número
		@param ed::Monomio const & m1
		@param double const & m2
		@return bool
		@post El valor devuelto es verdadero si son iguales el coeficiente y el número, y el grado del monomio es 0
		@post El valor devuelto es falso si son distintos
		*/
	bool operator==(ed::Monomio const & m1, double const & m2);

		/**
		@fn bool operator==(double const & m2, ed::Monomio const & m1)
		@brief Operador de igualdad que comprueba si el coeficiente de un monomio es igual a un Número
		@param double const & m2
		@param ed::Monomio const & m1
		@return bool
		@post El valor devuelto es verdadero si son iguales el coeficiente y el número, y el grado del monomio es 0
		@post El valor devuelto es falso si son distintos
		*/
	bool operator==(double const & m2, ed::Monomio const & m1);


	//! \name Operadores de desigualdad 

		/**
		@fn bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2)
		@brief Operador de igualdad que comprueba si dos monomios son distintos
		@param ed::Monomio const & m1
		@param ed::Monomio const & m2
		@return bool
		@post El valor devuelto es verdadero si son distintos(mismos coeficiente o grado)
		@post El valor devuelto es falso si son iguales
		*/
	bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2);

		/**
		@fn bool operator!=(ed::Monomio const & m1, double const & m2)
		@brief Operador de igualdad que comprueba si dos monomios son distintos
		@param ed::Monomio const & m1
		@param double const & m2
		@return bool
		@post El valor devuelto es verdadero si el coeficiente del monimio y el numero son diferentes o el grado del monomio es distinto de 0
		@post El valor devuelto es falso si son iguales
		*/
	bool operator!=(ed::Monomio const & m1, double const & m2);

		/**
		@fn bool operator!=(double const & m2, ed::Monomio const & m1)
		@brief Operador de igualdad que comprueba si dos monomios son distintos
		@param double const & m2
		@param ed::Monomio const & m1
		@return bool
		@post El valor devuelto es verdadero si el coeficiente del monimio y el numero son diferentes o el grado del monomio es distinto de 0
		@post El valor devuelto es falso si son iguales
		*/
	bool operator!=(double const & m2, ed::Monomio const & m1);


	///////////////////////////////////////////////////

	//! \name Operadores unarios prefijos

		/**
		@fn ed::Monomio & operator+(ed::Monomio const & m)
		@brief Devuelve una copia del monomio m
		@param ed::Monomio const & m
		@return ed::Monomio
		@post El monomio devuelto es igual al monomio pasado
		*/
	ed::Monomio & operator+(ed::Monomio const & m);

		/**
		@fn ed::Monomio & operator-(ed::Monomio const & m)
		@brief Devuelve una copia del monomio m con signo opuesto
		@param ed::Monomio const & m
		@return ed::Monomio
		@post El monomio devuelto es igual al monomio pasado pero con signo opuesto
		*/
	ed::Monomio & operator-(ed::Monomio const & m);


	//////////////////////////////////////////////////////////

	//! \name Operador binario de la suma 

		/**
		@fn ed::Monomio & operator+ (ed::Monomio const &m1, ed::Monomio const &m2)
		@brief Devuelve un monomio que es la suma de otros dos monomios
		@param ed::Monomio const & m
		@return ed::Monomio
		@pre los dos monomios pasados tienen igual grado
		@post El coeficiente del monomio es igual a la suma de los dos coeficientes
		@post El grado debe ser igual al de los dos monomios
		*/
	 ed::Monomio & operator+ (ed::Monomio const &m1, ed::Monomio const &m2);



	//////////////////////////////////////////////////////////
	//! \name Operador binario de la resta 

		/**
		@fn ed::Monomio & operator- (ed::Monomio const &m1, ed::Monomio const &m2)
		@brief Devuelve un monomio que es la resta de otros dos monomios
		@param ed::Monomio const & m
		@return ed::Monomio
		@pre los dos monomios pasados tienen igual grado
		@post El coeficiente del monomio es igual a la resta de los dos coeficientes
		@post El grado debe ser igual al de los dos monomios
		*/
	ed::Monomio & operator- (ed::Monomio const &m1, ed::Monomio const &m2);


	///////////////////////////////////////////////////////////////////////////
	//! \name Operadores binarios de la multiplicación 

		/**
		@fn ed::Monomio & operator*(ed::Monomio const &m1, ed::Monomio const &m2)
		@brief Devuelve un monomio que es la multiplicacion de otros dos monomios
		@param ed::Monomio const & m1
		@param ed::Monomio const & m2
		@return ed::Monomio
		@post El coeficiente del monomio devuelto es igual a la multiplicacion de los dos coeficientes
		@post El grado del monomio devuelo es la suma del grado de los dos monomios
		*/
	ed::Monomio & operator*(ed::Monomio const &m1, ed::Monomio const &m2);

		/**
		@fn ed::Monomio & operator*(ed::Monomio const &m1, double const & x)
		@brief Devuelve un monomio que es la multiplicacion de un monomio por un real
		@param ed::Monomio const & m1
		@param double const & x
		@return ed::Monomio
		@post El coeficiente del monomio devuelto es igual a la multiplicacion del coeficiente por el numero
		@post El grado del monomio devuelo es igual al del monomio pasado
		*/
	ed::Monomio & operator*(ed::Monomio const &m1, double const & x);

		/**
		@fn ed::Monomio & operator*(double const & x,ed::Monomio const &m1)
		@brief Devuelve un monomio que es la multiplicacion de un monomio por un real
		@param double const & x
		@param ed::Monomio const & m1
		@return ed::Monomio
		@post El coeficiente del monomio devuelto es igual a la multiplicacion del coeficiente por el numero
		@post El grado del monomio devuelo es igual al del monomio pasado
		*/
	ed::Monomio & operator*(double const & x,ed::Monomio const &m1);

	///////////////////////////////////////////////////////////////////////////

	//! \name Operadores binarios de la división 

		/**
		@fn ed::Monomio & operator/(ed::Monomio const &m1, ed::Monomio const &m2)
		@brief Devuelve un monomio que es la división de otros dos monomios
		@param ed::Monomio const & m1
		@param ed::Monomio const & m2
		@return ed::Monomio
		@post El coeficiente del monomio devuelto es igual a la division de los dos coeficientes
		@post El grado del monomio devuelo es la resta del grado de los dos monomios
		*/
	ed::Monomio & operator/(ed::Monomio const &m1, ed::Monomio const &m2);

		/**
		@fn ed::Monomio & operator/(ed::Monomio const &m1, double const & x)
		@brief Devuelve un monomio que es la division de un monomio entre un real
		@param ed::Monomio const & m1
		@param double const & x
		@return ed::Monomio
		@post El coeficiente del monomio devuelto es igual a la division del coeficiente entre el numero
		@post El grado del monomio devuelo es igual al del monomio pasado
		*/
	ed::Monomio & operator/(ed::Monomio const &m1, double const & x);

		/**
		@fn ed::Monomio & operator/(double const & x,ed::Monomio const &m1)
		@brief Devuelve un monomio que es la division de un monomio entre un real
		@param double const & x
		@param ed::Monomio const & m1
		@return ed::Monomio
		@post El coeficiente del monomio devuelto es igual a la division del coeficiente entre el numero
		@post El grado del monomio devuelo es igual al del monomio pasado
		*/
	ed::Monomio & operator/(double const & x,ed::Monomio const &m1);


	/////////////////////////////////////////////////////////////////////////////

	//! \name Sobrecarga de los operadores de entrada y salida 

		/**
		@fn ed::Monomio & operator/(double const & x,ed::Monomio const &m1)
		@brief Lee desde el flujo de entrada los atributos del monomio separados por espacios
		@param istream &stream
		@param ed::Monomio &m
		@return istream
		*/
	 istream &operator>>(istream &stream, ed::Monomio &m);

		/**
		@fn ed::Monomio & operator/(double const & x,ed::Monomio const &m1)
		@brief Escribe en el flujo de salida los atributos del monomio separados por espacios
		@param istream &stream
		@param ed::Monomio const &m
		@return ostream
		*/
	 ostream &operator<<(ostream &stream, ed::Monomio const &m);

}  // Fin de namespace ed.

#endif // _OperadoresExternosMonomios_HPP_


