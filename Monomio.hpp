/*! 
	\file Monomio.hpp
	\brief Definición de la clase Monomio
*/

/*!
 \mainpage Implementación de un monomio
 \brief		\f$ coeficiente X^{grado}\f$
 \author   Angel Santos Ramírez
 \version  1.0
*/

#ifndef _MONOMIO_HPP_
#define _MONOMIO_HPP_

// Para usar la funciones pow y std::abs
#include <cmath>

// Para controlar las pre y post condiciones mediante asertos
#include <cassert>
#include <iostream>

#define COTA_ERROR 1.0e-6  //!< Cota de error para la comparación números reales

// Se incluye la clase Monomio dentro del espacio de nombre de la asigantura: ed
namespace ed
{
//!  Definición de la clase Monomio:  \f$ coeficiente \hspace{1ex} X^{grado} \f$ 
class Monomio
{
	//! \name Atributos privados de la clase Monomio
	private:
		double coeficiente_;
		int grado_;

	//! \name Funciones o métodos públicos de la clase Monomio
	public:

	//! \name Constructores de la clase Monomio

		/**
		@fn inline Monomio(double coeficiente=0.0,int grado=0)
		@brief Constructor parametrizado de la clase monomio
		@param coeficiente=0.0
		@param grado=0
		@return None
		@pre El parametro grado es mayor que 0
		@post El parametro coeficiente es igual que el coeficiente de la clase
		@post El parametro grado es igual que el grado de la clase
		*/

		inline Monomio(double coeficiente=0.0,int grado=0){
			#ifndef NDEBUG
				assert( grado >= 0);
			#endif
			coeficiente_=coeficiente;
			grado_=grado;
			#ifndef NDEBUG
				assert( std::abs(coeficiente_-coeficiente)< COTA_ERROR );
				assert(grado_ == grado);
			#endif
		};

		/**
		@fn inline Monomio(Monomio const  &m)
		@brief Constructor de copia de la clase monomio
		@param Monomio::Monomio
		@return None
		@post El coeficiente del monomio pasado es igual que el coeficiente de la clase
		@post El grado del monomio pasado es igual que el grado de la clase
		*/

		inline Monomio(Monomio const  &m){
			coeficiente_=m.coeficiente_;
			grado_=m.grado_;
			#ifndef NDEBUG
			assert(std::abs(coeficiente_ - m.coeficiente_) < COTA_ERROR);
			assert(grado_ == m.grado_);
			#endif
		};

	//! \name Observadores: funciones de consulta de la clase Monomio

		/**
		@fn inline double getCoeficiente()const		
		@brief Observador del ceficiente de la clase
		@param None
		@return Double coeficiente
		*/

		inline double getCoeficiente()const{return coeficiente_;};

		/**
		@fn inline int getGrado()const		
		@brief Observador del grado de la clase
		@param None
		@return Int grado
		*/

		inline int getGrado()const{return grado_;};

	//! \name Funciones de modificación de la clase Monomio

		/**
		@fn inline void setCoeficiente(double f)		
		@brief Modificador del coeficiente de la clase
		@param Double f
		@return None
		@post El coeficiente asignado debe ser igual al nuevo coeficiente de la clase
		*/

		inline void setCoeficiente(double f){
			coeficiente_=f;
			#ifndef NDEBUG
			assert(std::abs(coeficiente_-f) < COTA_ERROR);
			#endif
		};

		/**
		@fn inline void setGrado(int g)		
		@brief Modificador del grado de la clase
		@param Int g
		@return None
		@pre El parametro g deberá ser mayor o igual a 0
		@post El grado asignado debe ser igual al nuevo grado de la clase
		*/

		inline void setGrado(int g){
			#ifndef NDEBUG
			assert( g >= 0);
			#endif

			grado_=g;

			#ifndef NDEBUG
			assert(grado_ == g);
			#endif

		};


	/////////////////////////////////////////////////

	//! \name Operadores de la clase Monomio


		/**
		@fn Monomio & operator=(Monomio const &m)	
		@brief Operador de asignacion de la lase monomio
		@param Monomio::Monomio const &m
		@return *this
		@post El grado asignado del monomio debe ser igual al nuevo grado de la clase
		@post El coeficiente asignado del monomio debe ser igual al nuevo coeficiente de la clase
		*/
		Monomio & operator=(Monomio const &m);

		/**
		@fn Monomio & operator=(double const &x)
		@brief Operador de asignacion de la lase monomio
		@param double const &x
		@return *this
		@post El grado del monomio de la clase deberá ser igual a 0
		@post El coeficiente asignado por el parámetro debe ser igual al nuevo coeficiente de la clase
		*/
		Monomio & operator=(double const &x);

		/**
		@fn Monomio & operator+=(Monomio const &m)
		@brief Operador aritmético que modifica el monomio sumandole otro monomio
		@param Monomio const &m
		@return *this
		@pre Los grados de los dos monomios deben ser iguales
		@post El grado del monomio no varia
		@post El coeficiente del monomio es igual a la suma de coeficientes de los monomios
		*/
		Monomio & operator+=(Monomio const &m);

		/**
		@fn Monomio & operator-=(Monomio const &m)
		@brief Operador aritmético que modifica el monomio restandole otro monomio
		@param Monomio const &m
		@return *this
		@pre Los grados de los dos monomios deben ser iguales
		@post El grado del monomio no varia
		@post El coeficiente del monomio es igual a la resta de coeficientes de los monomios
		*/
		Monomio & operator-=(Monomio const &m);

		/**
		@fn Monomio & operator*=(Monomio const &m)
		@brief Operador aritmético que modifica el monomio multiplicandole otro monomio
		@param Monomio const &m
		@return *this
		@post El grado del monomio actual es la suma del grado de los dos monomios
		@post El coeficiente del monomio es igual a la multiplicacion de coeficientes de los monomios
		*/
		Monomio & operator*=(Monomio const &m);

		/**
		@fn Monomio & operator/=(Monomio const &m)
		@brief Operador aritmético que modifica el monomio dividiendole otro monomio
		@param Monomio const &m
		@return *this
		@pre El grado del monomio de la clase es mayor o igual que el del pasado por parámetro
		@pre El grado es distinto de 0
		@post El grado del monomio actual es la resta del grado de los dos monomios
		@post El coeficiente del monomio es igual a la división de coeficientes de los monomios
		*/
		Monomio & operator/=(Monomio const &m);

		/**
		@fn Monomio & operator*=(double const &c)
		@brief Operador aritmético que modifica el monomio multiplicandole un número 
		@param double const &c
		@return *this
		@post El grado del monomio actual no se modifica
		@post El coeficiente del monomio es igual a la multiplicacion del coeficiente del monomio por el número
		*/
		Monomio & operator*=(double const &c);

		/**
		@fn Monomio & operator/=(double const &c)
		@brief Operador aritmético que modifica el monomio dividiendole un número 
		@param double const &c
		@return *this
		@pre El número pasado es diferente de 0
		@post El grado del monomio actual no se modifica
		@post El coeficiente del monomio es igual a la división del coeficiente del monomio entre el número
		*/
		Monomio & operator/=(double const &c);





	/////////////////////////////////////////////////////////////////////////////////////

	//! \name Funciones lectura y escritura de la clase Monomio

		/**
		@fn void leerMonomio()
		@brief Funcion que lee un monomio por teclado
		@param None
		@return None
		@post El grado es mayor o igual que 0
		*/

	void leerMonomio(){
		int g;
		double c;

		std::cout<<"Introduzca el coeficiente"<<std::endl;
		std::cin>>c;

		std::cout<<"Introduzca el grado"<<std::endl;
		std::cin>>g;

		grado_=g;
		coeficiente_=c;

		#ifndef NDEBUG
		assert(grado_ >= 0);
		#endif

	};
		/**
		@fn void escribirMonomio()
		@brief Escribe el monomio actual por pantalla
		@param None
		@return None
		*/
	void escribirMonomio(){

		if(this->getGrado()==0){
			std::cout<< this->getCoeficiente() ;
		}

		else{
			if(this->getGrado()==1){
				if(this->getCoeficiente() == 1 ){
				std::cout<<"x";
				}
				else{
					if(this->getCoeficiente() == -1 ){
					std::cout<<"-x";
					}
					else{
					std::cout<< this->getCoeficiente()<<"x";
					}
				}
			}
			else{
				if((this->getGrado() != 0)&&(this->getGrado()!=1)){

					if((this->getCoeficiente() != 1)&&(this->getCoeficiente()!=-1)){
					std::cout<< this->getCoeficiente()<<"x^"<<this->getGrado();
					}

					if(this->getCoeficiente() == 1 ){
					std::cout<<"x^"<<this->getGrado();
					}

					if(this->getCoeficiente() == -1 ){
					std::cout<<"-x^"<<this->getGrado();
					}
				}
			}
		}

	};


	///////////////////////////////////////////////////////////////////////

	//! \name Funciones auxiliares de la clase Monomio

		/**
		@fn double calcularValor(double x)
		@brief Calcula el valor del monomio asignandole a x un valor
		@param Double x
		@return None
		*/
	double calcularValor(double x){

		return coeficiente_ * ( pow(x,grado_)) ;
	};
		/**
		@fn void calcularIntegral()
		@brief Calcula el valor de la integral del monomio y lo imprime por pantalla
		@return None
		*/
	void calcularIntegral(){
		std::cout<<"La integral del monomio es : "<<std::endl;
		std::cout<< this->getCoeficiente() <<" * "<<"(x^"<< this->getGrado() + 1 <<"/"<< this->getGrado() + 1 <<")"<<std::endl;
	};

};  // Fin de la definición de la clase Monomio

}  //  Fin de namespace ed.

// _MONOMIO_HPP_
#endif
