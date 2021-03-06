#ifndef SRC_DATOSTABLERO_H_
#define SRC_DATOSTABLERO_H_

#include "../Tablero/Tablero.h"

class Tablero;

class DatosTablero {
private:
	unsigned int cantidadCelulasVivas;
	unsigned int nacidasTotal;
	unsigned int muertasTotal;
	float promedioNacidas;
	float promedioMuertas;
	unsigned int turnosCongelado;
	bool congeladoTurnoActual;
	unsigned int numeroTurno;
	unsigned int nacidasEnUltimoTurno;
	unsigned int muertasEnUltimoTurno;
	Tablero* tableroAsociado;

public:
	/*
	 * pre: turnosCongelado se setea a true por defecto porque se parte de la hipotesis de que todo tablero se
	 * considera congelado hasta que se pruebe lo contrario, lease, alguna celula nazca o muera
	 * post: inicializa una instancia de DatosPartida con los valores en 0
	 */
	DatosTablero(Tablero* tableroAsociado);

	/*
	 * pre: -
	 * post: devuelve el valor de la cantidadCelulasVivas
	 */
	unsigned int getCantidadCelulasVivas();

	/*
	 * pre: -
	 * post: contabiliza un nacimiento de celula
	 */
	void sumarCelulaViva();

	/*
	 * pre: -
	 * post: contabiliza una muerte de celula
	 */
	void sumarCelulaMuerta();

	/*
	 * pre: -
	 * post: devuelve el valor de nacidasTotal
	 */
	int getNacidasTotal();

	/*
	 * pre: -
	 * post: devuelve el valor de muertasTotal
	 */
	unsigned int getMuertasTotal();

	/*
	 * pre: -
	 * post: devuelve el valor de promedioNacidas
	 */
	float getPromedioNacidas();

	/*
	 * pre: -
	 * post: devuelve el valor de promedioMuertas
	 */
	float getPromedioMuertas();

	/*
	 * pre: -
	 * post: si el tablero se encuentra congelado (no hay nuuevas muertes ni nacimientos)
	 * suma uno a la cantidad de turnos que el tablero lleva congelado
	 */
	void setCantidadTurnosCongeladosTablero();

	/*
	 * pre: -
	 * post: se setea el atributo congeladoTurnoActual al valor pasado por parametro
	 */
	void setCongeladoTurnoActual(bool estadoDeCongelamiento);

	/*
	 * pre: -
	 * post: si el tablero lleva dos o mas turnos congelado se devuelve true, en caso
	 * contrario se devuelve false
	 */
	bool estaCongelado();

	/*
	 * pre: -
	 * post: devuelve el numero de turno actual
	 */
	unsigned int getTurno();

	/*
	 * pre: -
	 * post: se suma uno al numero de turnos
	 */
	void avanzarUnTurno();

	/*
	 * pre: -
	 * post: devuelve el numero de celulas que han nacido en el ultimo turno
	 */
	unsigned int getNacidasEnUltimoTurno();

	/*
	 * pre: -
	 * post: devuelve el numero de celulas han muerto en el ultimo turno
	 */
	unsigned int getMuertasEnUltimoTurno();

	/*
	 * pre: cada vez que se itera un turno en la clase Datostablero se almacena la informacion de las celulas nacidas y muertas en
	 * el turno, por eso hace falta un metodo que las resetee a cero cada vez que se comienza un nuevo turno
	 * post: Reinicia el contador de nacidasEnUltimoTurno y muertesEnUltimoTurno
	 */
	void reiniciarContadorDeNacidasYMuertasEnUltimoTurno();

	/*
	 * pre: -
	 * post: muestran por pantalla los datos del tablero en cuestion
	 */
	void mostrarDatosTablero();
};
#endif /* SRC_DATOSTABLERO_H_ */
