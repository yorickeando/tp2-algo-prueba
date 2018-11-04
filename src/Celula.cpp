/*
 * Celula.cpp
 *
 *  Created on: Oct 18, 2018
 *      Author: german
 */
const int ENERGIA_MAX = 100;
const bool MUERTA = false;
const bool VIVA = true;

#include "Celula.h"

Celula::Celula() {
	this->estadoCelula = MUERTA;
	this->energiaCelula = 0;
	this->RGBCelula = 0;
}

bool Celula::morir(float factorMuerteParcela) {
	bool murio = true;
	int energiaAPerder = ENERGIA_MAX * factorMuerteParcela;
	if (this->energiaCelula > energiaAPerder){
		this->energiaCelula -= energiaAPerder;
		murio = false;
	}
	else{
		this->energiaCelula = 0;
		this->estadoCelula = MUERTA;
	}
	return murio;
}

void Celula::nacer(float factorNacimientoParcela, RGB* RGBParcela){
	this->estadoCelula = VIVA;
	this->energiaCelula = ENERGIA_MAX * factorNacimientoParcela;
	this->RGBCelula = RGBParcela;
}

RGB* Celula::getRGB() {
	return this->RGBCelula;
}

bool Celula::getEstado() {
	return this->estadoCelula;
}
