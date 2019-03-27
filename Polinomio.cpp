/*!
   \file Polinomio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Polinomio
*/


// Ficheros de cabecera
#include <iostream>
#include <vector>

#include "Polinomio.hpp"
#include "operadoresExternosPolinomios.hpp"

// Operadores de asignación

// COMPLETAR

bool wayToSort(ed::Monomio i, ed::Monomio j) { return i.getGrado() > j.getGrado(); }

/*void ed::Polinomio::monomiosSuma(){

	vector<Monomio> p;
	Monomio aux;
	for(int i=0;i< (int) this->polinomio_.size();i++){
		aux = this->polinomio_[i];
		for(int j=0;j < (int) this->polinomio_.size();j++){
			if((this->polinomio_[i] == this->polinomio_[j])&&(i!=j)){
				p[i].setCoeficiente(aux.getCoeficiente() + this->polinomio_[i].getCoeficiente() );
				this->polinomio_.erase(i);
			}
		}
	}
}*/



/////////////////////////////////////////////////////////////

ed::Polinomio & ed::Polinomio::operator=(ed::Polinomio const &p)
{
	Polinomio const paux1 = *this;

	/*#ifndef NDEBUG
	assert(paux1 != p);
	#endif*/

	this->polinomio_.resize(p.polinomio_.size());

	for(int i=0;i < (int) this->polinomio_.size() ; i++){

		this->polinomio_[i].setCoeficiente(p.polinomio_[i].getCoeficiente());
		this->polinomio_[i].setGrado(p.polinomio_[i].getGrado());

	}
	
	/*#ifndef NDEBUG
	assert(paux2 == p);
	#endif*/

	return *this ;
}


ed::Polinomio & ed::Polinomio::operator=(ed::Monomio const &m)
{

	//completar asertosSSSSSSSSSSSSSSSSSSSSS

	this->polinomio_.resize(1);

	this->polinomio_[0].setCoeficiente(m.getCoeficiente());
	this->polinomio_[0].setGrado(m.getGrado());



	return *this;
}


ed::Polinomio & ed::Polinomio::operator=(double const &x)
{
	this->polinomio_.resize(1);
	this->polinomio_[0].setCoeficiente(x);
	this->polinomio_[0].setGrado(0);

	return *this;
}


ed::Polinomio & ed::Polinomio::operator+=(ed::Polinomio const &p)
{
	int cont=0;
	Polinomio aux;
	for(int i=0;i < (int) (p.polinomio_.size()) ; i++){

		for(int j=0;j < (int) (this->polinomio_.size()) ; j++){

			if(this->polinomio_[j].getGrado() == p.polinomio_[i].getGrado()){

				this->polinomio_[j].setCoeficiente(this->polinomio_[j].getCoeficiente() + p.polinomio_[i].getCoeficiente());

				cont++;
			}
		}

		if(cont!=0){
			aux.polinomio_.push_back(p.polinomio_[i].getCoeficiente());
			cont = 0;
		}
	}

	for(int i=0;i < (int) aux.getVector().size() ;i++){
		this->polinomio_.push_back(aux.polinomio_[i]);
	}

	sort(this->polinomio_.begin(),this->polinomio_.end(),wayToSort);

	return *this;
}


ed::Polinomio & ed::Polinomio::operator+=(ed::Monomio const &m)
{
	int cont=0;
	for(int i=0;i < (int) (this->polinomio_.size()) ; i++){

			if(this->polinomio_[i].getGrado() == m.getGrado()){

				this->polinomio_[i].setCoeficiente(this->polinomio_[i].getCoeficiente() + m.getCoeficiente());
				cont++;			
			}
	}
	if(cont == 0){this->polinomio_.push_back(m);}

	return *this;
}

ed::Polinomio & ed::Polinomio::operator+=(double const &x)
{
	int cont=0;
	Monomio aux;
	for(int i=0;i < (int) (this->polinomio_.size()) ; i++){

			if(this->polinomio_[i].getGrado() == 0){

				this->polinomio_[i].setCoeficiente(this->polinomio_[i].getCoeficiente() + x);
				cont++;
			}
	}
	if(cont == 0){
	aux.setCoeficiente(x);
	aux.setGrado(0);
	this->polinomio_.push_back(aux);}

	return *this;
}

////////////////////////////////////////////////////////
ed::Polinomio & ed::Polinomio::operator-=(ed::Polinomio const &p)
{
	for(int i=0;i < (int) ((this->polinomio_.size())-1) ; i++){

		for(int j=0;j < (int) (p.polinomio_.size()) ; j++){

			if(this->polinomio_[i].getGrado() == p.polinomio_[j].getGrado()){

				this->polinomio_[i].setCoeficiente(this->polinomio_[i].getCoeficiente() - p.polinomio_[j].getCoeficiente());

			}
		}
	}

	return *this;
}

ed::Polinomio & ed::Polinomio::operator-=(ed::Monomio const &m)
{
	int cont=0;
	Monomio aux;
	for(int i=0;i < (int) (this->polinomio_.size()) ; i++){

			if(this->polinomio_[i].getGrado() == m.getGrado()){

				this->polinomio_[i].setCoeficiente(this->polinomio_[i].getCoeficiente() - m.getCoeficiente());
				cont++;
		}
	}

	if(cont == 0){
	aux.setCoeficiente(m.getCoeficiente()*-1);
	aux.setGrado(m.getGrado());
	this->polinomio_.push_back(aux);}

	return *this;
}

ed::Polinomio & ed::Polinomio::operator-=(double const &x)
{
	int cont=0;
	Monomio aux;
	for(int i=0;i < (int) (this->polinomio_.size()) ; i++){

			if(this->polinomio_[i].getGrado() == 0){

				this->polinomio_[i].setCoeficiente(this->polinomio_[i].getCoeficiente() - x);
				cont++;
		}
	}
	if(cont == 0){
	aux.setCoeficiente(x*-1);
	aux.setGrado(0);
	this->polinomio_.push_back(aux);}


	return *this;
}

/////////////////////////////////////////////////////////////////
ed::Polinomio & ed::Polinomio::operator*=(ed::Polinomio const &p)
{
	Polinomio paux;
	Monomio aux;

	for(int i=0;i < (int) (this->polinomio_.size()) ; i++){

		for(int j=0;j < (int) (p.polinomio_.size()) ; j++){

				aux.setCoeficiente(this->polinomio_[i].getCoeficiente() * p.polinomio_[j].getCoeficiente());
				aux.setGrado(this->polinomio_[i].getGrado() + p.polinomio_[j].getGrado());
				paux.polinomio_.push_back(aux);	
		}
	}

	sort(paux.polinomio_.begin(),paux.polinomio_.end(),wayToSort);

	this->polinomio_.resize(paux.polinomio_.size());

	for(int i=0;i < (int) (this->polinomio_.size()) ; i++){
		this->polinomio_[i] = paux.polinomio_[i];
	}

	return *this;
}

ed::Polinomio & ed::Polinomio::operator*=(ed::Monomio const &m)
{
	for(int i=0;i < (int) (this->polinomio_.size()) ; i++){

				this->polinomio_[i].setCoeficiente(this->polinomio_[i].getCoeficiente() * m.getCoeficiente());
				this->polinomio_[i].setGrado(this->polinomio_[i].getGrado() + m.getGrado());		

	}

	return *this;
}

ed::Polinomio & ed::Polinomio::operator*=(double const &x)
{
	for(int i=0;i < (int) (this->polinomio_.size()) ; i++){

				this->polinomio_[i].setCoeficiente(this->polinomio_[i].getCoeficiente() * x);	

	}

	return *this;
}
////////////////////////////////////////////////////////////////////////

ed::Polinomio & ed::Polinomio::operator/=(ed::Polinomio const &p)
{
	#ifndef NDEBUG
		assert(this->getGrado() >= p.getGrado());
	#endif

	for(int i=0;i < (int) (this->polinomio_.size()) ; i++){

		for(int j=0;j < (int) (p.polinomio_.size()) ; j++){

				this->polinomio_[i].setCoeficiente(this->polinomio_[i].getCoeficiente() / p.polinomio_[j].getCoeficiente());
				this->polinomio_[i].setGrado(this->polinomio_[i].getGrado() - p.polinomio_[j].getGrado());		
		}
	}

	return *this;
}

ed::Polinomio & ed::Polinomio::operator/=(ed::Monomio const &m)
{
	#ifndef NDEBUG
		assert(this->getGrado() >= m.getGrado());
	#endif

	for(int i=0;i < (int) (this->polinomio_.size()) ; i++){

				this->polinomio_[i].setCoeficiente(this->polinomio_[i].getCoeficiente() / m.getCoeficiente());
				this->polinomio_[i].setGrado(this->polinomio_[i].getGrado() - m.getGrado());		

	}

	return *this;
}

ed::Polinomio & ed::Polinomio::operator/=(double const &x)
{
	for(int i=0;i < (int) (this->polinomio_.size()) ; i++){

				this->polinomio_[i].setCoeficiente(this->polinomio_[i].getCoeficiente() / x);	

	}

	return *this;
}


///////////////////////////////////////////////////////////////////////

// Funciones lectura y escritura de la clase Polinomio

void ed::Polinomio::leerPolinomio(){
		int grado=0;
		std::cout<<"Cuantos monomios tiene el polinomio?"<<std::endl;
		std::cin >> grado;

		ed::Monomio aux;
		//ed::Polinomio paux;
		vector<ed::Monomio> p;

		for(int i=0;i<grado;i++){
			aux.leerMonomio();
			p.push_back(aux);
		}

		sort(p.begin(),p.end(),wayToSort);


		for(int i=0;i<grado;i++){
			if(i==0){
				this->polinomio_[i]=p[i];
			}
			else{
			this->polinomio_.push_back(p[i]);
			}
		}

}

void ed::Polinomio::escribirPolinomio(){
	for(int i=0;i < (int) this->polinomio_.size();i++){
		if((this->polinomio_[i].getCoeficiente()==0)&&(getNumeroMonomios()!= 1)){
			this->polinomio_.erase(this->polinomio_.begin()+i);
			i=0;
		}
	}



	for(int i=0; i < (int) this->polinomio_.size();i++){

			this->polinomio_[i].escribirMonomio();

			if(i!=(int) (this->polinomio_.size()-1)){
				std::cout<<" + ";
			}

	}
	std::cout<<"\n";

}

///////////////////////////////////////////////////////////////////////

// Funciones auxiliares de la clase Polinomio

double ed::Polinomio::calcularValor(double x){

	double aux=0;

	for(int i=0;i< (int) this->polinomio_.size() ; i++){
		aux= aux + this->polinomio_[i].getCoeficiente() * pow(x,this->polinomio_[i].getGrado());
	}

	return aux;
}