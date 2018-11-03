/*
 * DatosTablero.h
 *
 *  Created on: 1 nov. 2018
 *      Author: nazareno
 */

#ifndef SRC_DATOSTABLERO_H_
#define SRC_DATOSTABLERO_H_

class DatosTablero {
private:
	unsigned int cantidadCelulasVivas;
	unsigned int nacidasTotal;
	unsigned int muertasTotal;
	float promedioNacidas;
	float promedioMuertas;
	unsigned int turnosCongelado;
	bool congeladoTurnoActual;

public:
	/*
	 * pre: -
	 * post:inicializa una instancia de DatosPartida con los valores en 0
	 */
	DatosTablero();
	/*
	 *pre: -
	 *post: devueleve el valor de la cantidadCelulasVivas
	 */
	unsigned int getCantidadCelulasVivas();
	/*
	*pre: -
	*post: contabiliza un nacimiento de celula
	*/
	void sumarCelulaViva();
	/*
	*pre: -
	*post: contabiliza una muerte de celula
	*/
	void sumarCelulaMuerta();
	/*
	*pre: -
	*post: devueleve el valor de nacidasTotal
	*/
	int getNacidasTotal();
	/*
	*pre: -
	*post: devueleve el valor de muertasTotal
	*/
	unsigned int getMuertasTotal();
	/*
	*pre: -
	*post: devueleve el valor de promedioNacidas
	*/
	float getPromedioNacidas();
	/*
	 *pre: -
	*post: devueleve el valor de promedioMuertas
	*/
	float getPromedioMuertas();

	/*
	 * pre: -
	 * post: si el tablero se encuentra congelado (no hay nuuevas muertes ni nacimientos)
	 * suma uno a la cantidad de turnos que el tablero lleva congelado
	 */
	void analizarCongelamientoDelTablero();

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
	bool getCongelamiento();
};
#endif /* SRC_DATOSTABLERO_H_ */
