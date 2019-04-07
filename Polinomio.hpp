/*!
   \file Polinomio.hpp
   \brief Definición de la clase Polinomio
*/

#ifndef _POLINOMIO_HPP_
#define _POLINOMIO_HPP_

// Control de asertos
#include <cassert>

// Vector de STL
#include <vector>

// Para usar la función abs
#include <cmath>
#include <algorithm>

#include "PolinomioInterfaz.hpp"
#include "Monomio.hpp"

  using namespace std;


// Se incluye la clase Polinomio dentro del espacio de nombre de la asigantura: ed
namespace ed {

//!  Definición de la clase Polinomio que hereda de PolinomioInterfaz
class Polinomio : public ed::PolinomioInterfaz
{

  //! \name Atributos privados de la clase Polinomio
   private:

 	vector<Monomio> polinomio_;


   //! \name Funciones o métodos públicos de la clase Polinomio
   public:

	//! \name Constructores de la clase Polinomio

		/**
		@fn Polinomio()
		@brief Constructor parametrizado de la clase Polinomio
		@post El polinomio creado es nulo
		*/
   	Polinomio(){
   		Monomio aux;
   		aux.setCoeficiente(0.0);
   		aux.setGrado(0);
   		polinomio_.push_back(aux);
   		#ifndef NDEBUG
			assert(this->esNulo()== true);
		#endif
   	};
	/**
		@fn Polinomio(Polinomio const &p)
		@brief Constructor de copia de la clase Polinomio
		@param Polinomio const &p
		@post El polinomio creado es igual al polinomio p
		*/
   	Polinomio(Polinomio const &p){

		for(int i=0 ; i < (int) p.polinomio_.size() ; i++){

			this->polinomio_.push_back(p.polinomio_[i]);
		}

   	};


  //! \name Observadores: funciones de consulta de la clase Polinomio

	/**
		@fn bool esNulo()const
		@brief Observador que comprueba si un monomio es nulo
		@return bool
		@param Polinomio const &p
		*/
	bool esNulo()const{
		bool aux;
		if(this->polinomio_[0].getCoeficiente() == 0.0 && this->polinomio_[0].getGrado() == 0 && (this->polinomio_.size() >= 1)){
			aux =true;
		}
		else{
			aux = false;
		}
		return aux;
	};
	/**
		@fn int getGrado()const
		@brief Observador que muestra el grado del polinomio
		@return int
		@pre Los monomio estan ordenados de mayor a menor grado
		*/
	int getGrado()const{

		return this->polinomio_[0].getGrado();
	};
	/**
		@fn int getNumeroMonomios()const
		@return int
		@brief Observador que muestra el numero de monomios del polinomio
		*/
	int getNumeroMonomios()const{
		return(this->polinomio_.size());
	};
	/**
		@fn bool existeMonomio(int g)const
		@return bool
		@brief Observador que muestra si existe el monomio de x grado existe
		@param int g
		*/
	bool existeMonomio(int g)const{
		#ifndef NDEBUG
			assert(getNumeroMonomios() > 0);
		#endif

			for(int i=0;i < (int) this->polinomio_.size() ; i++){
				if(this->polinomio_[i].getGrado() == g ){
					return true;
				}
			}

		return false;
	};
	/**
		@fn Monomio getMonomio(int g)const
		@return Monomio
		@brief Observador que muestrael monomio de x grado
		@pre El polinomio debe existir
		@param int g
		*/
	Monomio getMonomio(int g)const{
			#ifndef NDEBUG
			assert(getNumeroMonomios() > 0);
			#endif

			Monomio x;

			for(int i=0; i <(int)  this->polinomio_.size()  ; i++){
				if(this->polinomio_[i].getGrado() == g ){
					return this->polinomio_[i];
				}
			}

			return x;
	};

	inline vector<Monomio> getVector()const{return polinomio_;};

 	////////////////////////////////////////////////////////////////

   //! \name Operadores de la clase Polinomio
	/**
		@fn Polinomio & operator=(Polinomio const &p)
		@brief Operador que iguala el polinomio actual al polinomio pasado
		@pre El polinomio debe ser diferente al polinomio actual
		@post El polinomio debe ser igual al polinomio actual
		@param Polinomio const &p
		*/
	Polinomio & operator=(Polinomio const &p);

	/**
		@fn Polinomio & operator=(Monomio const &m)
		@brief Operador que iguala el polinomio actual al monomio pasado
		@post El monomio debe ser igual al polinomio actual
		@param Monomio const &m
		*/
	Polinomio & operator=(Monomio const &m);

	/**
		@fn Polinomio & operator=(double const &x)
		@brief Operador que iguala el polinomio actual al número pasado
		@post El real debe ser igual al polinomio actual
		@param double const &m
		*/
	Polinomio & operator=(double const &x);

  // Operadores aritméticos y asignación
	/**
		@fn Polinomio & operator+=(Polinomio const &p)
		@brief Operador de incremento y asignacion con otro polinomio
		@param Polinomio const &p
		*/
	Polinomio & operator+=(Polinomio const &p);
	/**
		@fn Polinomio & operator+=(Monomio const &m)
		@brief Operador de incremento y asignacion con un monomio
		@param monomio const &p
		*/
	Polinomio & operator+=(Monomio const &m);
	/**
		@fn Polinomio & operator+=(double const &x)
		@brief Operador de incremento y asignacion con un numero
		@param double const &p
		*/
	Polinomio & operator+=(double const &x);

	/**
		@fn Polinomio & operator-=(Polinomio const &p)
		@brief Operador de decremento y asignacion con otro polinomio
		@param Polinomio const &p
		*/
	Polinomio & operator-=(Polinomio const &p);
	/**
		@fn Polinomio & operator-=(Monomio const &m)
		@brief Operador de decremento y asignacion con un monomio
		@param monomio const &p
		*/
	Polinomio & operator-=(Monomio const &m);
	/**
		@fn Polinomio & operator-=(double const &x)
		@brief Operador de decremento y asignacion con un numero
		@param double const &p
		*/
	Polinomio & operator-=(double const &x);
	/**
		@fn Polinomio & operator*=(Polinomio const &p)
		@brief Operador de multiplicacion y asignacion con otro polinomio
		@param Polinomio const &p
		*/
	Polinomio & operator*=(Polinomio const &p);
	/**
		@fn Polinomio & operator*=(Monomio const &m)
		@brief Operador de multiplicacion y asignacion con un monomio
		@param monomio const &p
		*/
	Polinomio & operator*=(Monomio const &m);
	/**
		@fn Polinomio & operator*=(double const &x)
		@brief Operador de multiplicacion y asignacion con un numero
		@param double const &p
		*/
	Polinomio & operator*=(double const &x);
	/**
		@fn Polinomio & operator/=(Polinomio const &p)
		@brief Operador de division y asignacion con otro polinomio
		@param Polinomio const &p
		*/
	Polinomio & operator/=(Polinomio const &p);
	/**
		@fn Polinomio & operator/=(Monomio const &m)
		@brief Operador de division y asignacion con un monomio
		@param monomio const &p
		*/
	Polinomio & operator/=(Monomio const &m);
	/**
		@fn Polinomio & operator/=(double const &x)
		@brief Operador de division y asignacion con un numero
		@param double const &p
		*/
	Polinomio & operator/=(double const &x);




  /////////////////////////////////////////////////////////////////////////////////////

	//! \name Funciones lectura y escritura de la clase Polinomio
	/**
		@fn void leerPolinomio()
		@brief Funcion que lee un polinomio desde teclado
		*/
	void leerPolinomio();
	/**
		@fn void void escribirPolinomio()
		@brief Funcion que escribe un polinomio en pantalla
		*/
	void escribirPolinomio();

	//void monomiosSuma();


	///////////////////////////////////////////////////////////////////////

	//! \name Funciones auxiliares de la clase Polinomio
	/**
		@fn void double calcularValor(double x)
		@brief Funcion que calcula el valor de un polinomio con un x pasado
		@param double x
		*/
	double calcularValor(double x);

	// COMPLETAR


}; // Fin de la definición de la clase Polinomio




}
// \brief Fin de namespace ed.

//  _POLINOMIO_HPP_
#endif
