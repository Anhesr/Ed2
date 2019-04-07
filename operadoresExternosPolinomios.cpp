/*!
   \file operadoresExternosPolinomios.cpp
   \brief Fichero que contiene el código de las funciones de la clase Polinomio
*/


// Ficheros de cabecera
#include <iostream>

#include "operadoresExternosPolinomios.hpp"

#include "operadoresExternosMonomios.hpp"

// Se incluyen los operadores sobrecargados dentro del espacio de nombres de ed

namespace ed
{

bool operator==(ed::Polinomio const & p1, ed::Polinomio const & p2){


		if(p1.getGrado()==p2.getGrado()){

			for(int i=0;i < (int) p1.getVector().size();i++ ){

				if(p1.getVector()[i].getCoeficiente() != p2.getVector()[i].getCoeficiente()){
					return false;
				}
			}
			return true;
		}
	
		return false;
}

bool operator==(ed::Polinomio const & p, ed::Monomio const & m){

	if((p.getGrado() == m.getGrado())&&(p.getNumeroMonomios() == 1)){


				if(p.getVector()[0].getCoeficiente() != m.getCoeficiente()){
					return false;
				}

			return true;
		}
	
		return false;
}

bool operator==(ed::Polinomio const & p, double const & x){

	if((p.getGrado() == 0)&&(p.getNumeroMonomios() == 1)){


				if(p.getVector()[0].getCoeficiente() != x){
					return false;
				}
				
			
			return true;
		}
	
		return false;
}

///////
bool operator==(ed::Monomio const & m, ed::Polinomio const & p){

	if((p.getGrado() == m.getGrado())&&(p.getNumeroMonomios() == 1)){


				if(p.getVector()[0].getCoeficiente() != m.getCoeficiente()){
					return false;
				}

			return true;
		}
	
		return false;
}

bool operator==(double const & x, ed::Polinomio const & p){

	if((p.getGrado() == 0)&&(p.getNumeroMonomios() == 1)){


				if(p.getVector()[0].getCoeficiente() != x){
					return false;
				}
				
			
			return true;
		}
	
		return false;
}



////////////////////////////////////////////////////////////////////////////////////
// Operadores de desigualdad

bool operator!=(ed::Polinomio const & p1, ed::Polinomio const & p2){


		if(p1.getGrado()==p2.getGrado()){

			for(int i=0;i < (int) p1.getVector().size();i++ ){

				if(p1.getVector()[i].getCoeficiente() == p2.getVector()[i].getCoeficiente()){
					return false;
				}
			}
			return true;
		}
	
		return true;
}

bool operator!=(ed::Polinomio const & p, ed::Monomio const & m){

	if((p.getGrado() == m.getGrado())&&(p.getNumeroMonomios() == 1)){


				if(p.getVector()[0].getCoeficiente() == m.getCoeficiente()){
					return false;
				}

			return true;
		}
	
		return true;
}

bool operator!=(ed::Polinomio const & p, double const & x){

	if((p.getGrado() == 0)&&(p.getNumeroMonomios() == 1)){


				if(p.getVector()[0].getCoeficiente() == x){
					return false;
				}
				
			
			return true;
		}
	
		return true;
}

bool operator!=(ed::Monomio const & m, ed::Polinomio const & p){

	if((p.getGrado() == m.getGrado())&&(p.getNumeroMonomios() == 1)){


				if(p.getVector()[0].getCoeficiente() == m.getCoeficiente()){
					return false;
				}

			return true;
		}
	
		return true;
}

bool operator!=(double const & x, ed::Polinomio const & p){

	if((p.getGrado() == 0)&&(p.getNumeroMonomios() == 1)){


				if(p.getVector()[0].getCoeficiente() == x){
					return false;
				}
				
			
			return true;
		}
	
		return true;
}


//////////////////////////////////////////////////////////////////////////////////////

// Operadores unarios

// COMPLETAR
ed::Polinomio & operator+(ed::Polinomio const & p)
{
	ed::Polinomio *nuevo = new ed::Polinomio(p);

	for(int i=0; i< (int) p.getVector().size();i++){
		if(i==0){
				nuevo->getVector()[i]=p.getVector()[i];
		}
		else{
			nuevo->getVector().push_back(p.getVector()[i]);
		}
	}

	#ifndef NDEBUG
			assert(*nuevo == p);
	#endif

	return *nuevo;
}


ed::Polinomio & operator-(ed::Polinomio const & p)
{

	ed::Polinomio *nuevo = new ed::Polinomio(p);

	for(int i=0; i< (int) p.getVector().size();i++){
		if(i==0){

				nuevo->getVector()[i].setCoeficiente(-1*(p.getVector()[i].getCoeficiente()));
		}
		else{
			nuevo->getVector().push_back(-p.getVector()[i].getCoeficiente());
		}
	}

	return *nuevo;
}


//////////////////////////////////////////////////////////////////////////////////////

// Operadores binarios de la suma
ed::Polinomio & operator+(ed::Polinomio const &p1,  ed::Polinomio const &p2)
{
	ed::Polinomio *nuevo = new ed::Polinomio;

	*nuevo =p1;

	*nuevo +=p2;
	return *nuevo;

}
ed::Polinomio & operator+(ed::Polinomio const &p,  ed::Monomio const &m)
{

	ed::Polinomio *nuevo = new ed::Polinomio;
	ed::Polinomio paux =p;
	paux +=m;

	*nuevo = paux;
	return *nuevo;

}
ed::Polinomio & operator+(ed::Monomio const &m,  ed::Polinomio const &p)
{

	ed::Polinomio *nuevo = new ed::Polinomio;
	ed::Polinomio paux =p;
	paux +=m;

	*nuevo = paux;
	return *nuevo;

}
ed::Polinomio & operator+(ed::Polinomio const &p,  double const &x)
{

	ed::Polinomio *nuevo = new ed::Polinomio;
	ed::Polinomio paux =p;
	paux +=x;

	*nuevo = paux;
	return *nuevo;
}
ed::Polinomio & operator+(double const &x,  ed::Polinomio const &p)
{

	ed::Polinomio *nuevo = new ed::Polinomio;
	ed::Polinomio paux =p;
	paux +=x;

	*nuevo = paux;
	return *nuevo;
}


	////////////
	// Resta

ed::Polinomio & operator-(ed::Polinomio const &p1,  ed::Polinomio const &p2)
{

	ed::Polinomio *nuevo = new ed::Polinomio;
	ed::Polinomio paux =p1;
	paux -=p2;

	*nuevo = paux;
	return *nuevo;

}
ed::Polinomio & operator-(ed::Polinomio const &p,  ed::Monomio const &m)
{

	ed::Polinomio *nuevo = new ed::Polinomio;
	ed::Polinomio paux =p;
	paux -=m;

	*nuevo = paux;
	return *nuevo;

}
ed::Polinomio & operator-(ed::Monomio const &m,  ed::Polinomio const &p)
{

	ed::Polinomio *nuevo = new ed::Polinomio;
	ed::Polinomio paux =p;
	paux -=m;

	*nuevo = paux;
	return *nuevo;

}
ed::Polinomio & operator-(ed::Polinomio const &p,  double const &x)
{

	ed::Polinomio *nuevo = new ed::Polinomio;
	ed::Polinomio paux =p;
	paux -=x;

	*nuevo = paux;
	return *nuevo;
}
ed::Polinomio & operator-(double const &x,  ed::Polinomio const &p)
{

	ed::Polinomio *nuevo = new ed::Polinomio;
	ed::Polinomio paux =p;
	paux -=x;

	*nuevo = paux;
	return *nuevo;
}


	//////////////////
	// Multiplicación

ed::Polinomio & operator*(ed::Polinomio const &p1,  ed::Polinomio const &p2)
{

	ed::Polinomio *nuevo = new ed::Polinomio;
	ed::Polinomio paux =p1;
	paux *=p2;

	*nuevo = paux;
	return *nuevo;

}
ed::Polinomio & operator*(ed::Polinomio const &p,  ed::Monomio const &m)
{

	ed::Polinomio *nuevo = new ed::Polinomio;
	ed::Polinomio paux =p;
	paux *=m;

	*nuevo = paux;
	return *nuevo;

}
ed::Polinomio & operator*(ed::Monomio const &m,  ed::Polinomio const &p)
{

	ed::Polinomio *nuevo = new ed::Polinomio;
	ed::Polinomio paux =p;
	paux *=m;

	*nuevo = paux;
	return *nuevo;

}
ed::Polinomio & operator*(ed::Polinomio const &p,  double const &x)
{

	ed::Polinomio *nuevo = new ed::Polinomio;
	ed::Polinomio paux =p;
	paux *=x;

	*nuevo = paux;
	return *nuevo;
}
ed::Polinomio & operator*(double const &x,  ed::Polinomio const &p)
{

	ed::Polinomio *nuevo = new ed::Polinomio;
	ed::Polinomio paux =p;
	paux *=x;

	*nuevo = paux;
	return *nuevo;
}

	////////////
	// División

ed::Polinomio & operator/(ed::Polinomio const &p1,  ed::Polinomio const &p2)
{

	ed::Polinomio *nuevo = new ed::Polinomio;
	ed::Polinomio paux =p1;
	paux /=p2;

	*nuevo = paux;
	return *nuevo;

}
ed::Polinomio & operator/(ed::Polinomio const &p,  ed::Monomio const &m)
{

	ed::Polinomio *nuevo = new ed::Polinomio;
	ed::Polinomio paux =p;
	paux /=m;

	*nuevo = paux;
	return *nuevo;

}
ed::Polinomio & operator/(ed::Monomio const &m,  ed::Polinomio const &p)
{

	ed::Polinomio *nuevo = new ed::Polinomio;
	ed::Polinomio paux =p;

	paux /=m;

	*nuevo = paux;
	return *nuevo;

}
ed::Polinomio & operator/(ed::Polinomio const &p,  double const &x)
{

	ed::Polinomio *nuevo = new ed::Polinomio;
	ed::Polinomio paux =p;
	paux /=x;

	*nuevo = paux;
	return *nuevo;
}
ed::Polinomio & operator/(double const &x,  ed::Polinomio const &p)
{

	ed::Polinomio *nuevo = new ed::Polinomio;
	ed::Polinomio paux =p;
	paux /=x;

	*nuevo = paux;
	return *nuevo;
}


////////////////////////////////////////////////////////////////////////////

// Sobrecarga del operador de entrada
istream &operator>>(istream &stream, Polinomio &p)
{
	int n;
	ed::Monomio aux;
	std::cout<<"Introduzca el numero de monomios del polinomio"<<std::endl;
	std::cin >> n;
	for(int i=0;i<n;i++){
		std::cin >> aux;
		if(i==0){
			p.getVector()[i] = aux;
		}
		else{
			p.getVector().push_back(aux);
		}
	}

  return stream;
}



// Sobrecarga del operador de salida
ostream &operator<<(ostream &stream, Polinomio const &p)
{
	for(int i=0;i < (int) p.getVector().size();i++){
		if((p.getVector()[i].getCoeficiente()==0)&&(p.getNumeroMonomios()!= 1)){
			p.getVector().erase(p.getVector().begin()+i);
			i=0;
		}
	}

	for(int i=0;i < (int) p.getVector().size() ;i++){
		stream << p.getVector()[i].getCoeficiente();
		stream << " ";
		stream << p.getVector()[i].getGrado();
		if(i+1 != (int) p.getVector().size()){
		stream << " + ";
		}
	}
  return stream;
}


} // Fin del espacio de nombres ed
