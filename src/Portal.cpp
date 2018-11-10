#include "Portal.h"

Portal::Portal(bool esPortalDeOrigen, std::string tipoDelPortal,
		CoordenadaParcela * parcelaPareja) {
	this->portalOrigen = esPortalDeOrigen;
	this->tipoDePortal = tipoDelPortal;
	this->parcelaAsociada = parcelaPareja;
}

std::string Portal::getTipoDePortal() {
	return this->tipoDePortal;
}

void Portal::accionarPortal(bool nace, RGB* color, float factorNacimientoOrigen,
		float factorMuerteOrigen) {
	if (this->tipoDePortal == "activo") {
		if (this->portalOrigen) {
			if (nace) {
				this->nacer(color, factorNacimientoOrigen);
			} else {
				this->morir(factorMuerteOrigen);
			}
		} else if (!nace) {
			this->morir(factorMuerteOrigen);
		}
	} else if (this->tipoDePortal == "normal") {
		if (this->portalOrigen) {
			if (nace) {
				this->nacer(color, factorNacimientoOrigen);
			} else {
				this->morir(factorMuerteOrigen);
			}
		}
	} else if (this->portalOrigen && nace) { //Pasivo
		this->nacer(color, factorNacimientoOrigen);
	}
}

void Portal::nacer(RGB* color, float factorNacimientoOrigen) {
	int fila = this->parcelaAsociada->getCoordenadaX();
	int columna = this->parcelaAsociada->getCoordenadaY();
	Tablero * tableroAsociado = this->parcelaAsociada->getTablero();
	if (! tableroAsociado->getParcela(fila, columna).getCelula()->getEstado()){
		tableroAsociado->getParcela(fila, columna).getCelula()->nacer(
				factorNacimientoOrigen, color);
		tableroAsociado->getDatosTablero()->sumarCelulaViva();
		if (tableroAsociado->getDatosTablero()->estaCongelado()) {
			tableroAsociado->getDatosTablero()->setCongeladoTurnoActual(false);
		}
	}
}

void Portal::morir(float factorMuerteOrigen) {
	int fila = this->parcelaAsociada->getCoordenadaX();
	int columna = this->parcelaAsociada->getCoordenadaY();
	Tablero * tableroAsociado = this->parcelaAsociada->getTablero();
	if (tableroAsociado->getParcela(fila, columna).getCelula()->getEstado()){
		bool murio = tableroAsociado->getParcela(fila, columna).getCelula()->restarEnergia(
						factorMuerteOrigen);
		if (murio) {
			tableroAsociado->getDatosTablero()->sumarCelulaMuerta();
		}
		if (tableroAsociado->getDatosTablero()->estaCongelado()) {
			tableroAsociado->getDatosTablero()->setCongeladoTurnoActual(false);
		}
	}
}
