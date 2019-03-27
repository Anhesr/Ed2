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

   	Polinomio(){
   		Monomio aux;
   		aux.setCoeficiente(0.0);
   		aux.setGrado(0);
   		polinomio_.push_back(aux);
   	};

   	Polinomio(Polinomio const &p){

		for(int i=0 ; i < (int) p.polinomio_.size() ; i++){

			this->polinomio_.push_back(p.polinomio_[i]);
		}

		/*#ifndef NDEBUG
			assert(this == p);
		#endif*/
   	};


  //! \name Observadores: funciones de consulta de la clase Polinomio


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

	int getGrado()const{

		return this->polinomio_[0].getGrado();
	};

	int getNumeroMonomios()const{
		return(this->polinomio_.size());
	};

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

	Polinomio & operator=(Polinomio const &p);


	Polinomio & operator=(Monomio const &m);


	Polinomio & operator=(double const &x);

  // Operadores aritméticos y asignación

		// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator+=(Polinomio const &p);
	Polinomio & operator+=(Monomio const &m);
	Polinomio & operator+=(double const &x);
	Polinomio & operator-=(Polinomio const &p);
	Polinomio & operator-=(Monomio const &m);
	Polinomio & operator-=(double const &x);
	Polinomio & operator*=(Polinomio const &p);
	Polinomio & operator*=(Monomio const &m);
	Polinomio & operator*=(double const &x);
	Polinomio & operator/=(Polinomio const &p);
	Polinomio & operator/=(Monomio const &m);
	Polinomio & operator/=(double const &x);


	// COMPLETAR EL RESTO DE OPERADORES


  /////////////////////////////////////////////////////////////////////////////////////

	//! \name Funciones lectura y escritura de la clase Polinomio

	void leerPolinomio();

	void escribirPolinomio();

	//void monomiosSuma();


	///////////////////////////////////////////////////////////////////////

	//! \name Funciones auxiliares de la clase Polinomio

	double calcularValor(double x);

	// COMPLETAR


}; // Fin de la definición de la clase Polinomio




}
// \brief Fin de namespace ed.

//  _POLINOMIO_HPP_
#endif
