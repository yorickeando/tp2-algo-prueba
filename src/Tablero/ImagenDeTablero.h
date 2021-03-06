#ifndef IMAGEN_DE_TABLERO_H_
#define IMAGEN_DE_TABLERO_H_

#include <string>
#include <sstream>
#include <iostream>

#include "../ProcesamientoDeStrings/StringHelper.h"
#include "../libreriaBMP/EasyBMP.h"
#include "../RGB/RGB.h"

class ImagenDeTablero {
private:
	std::string nombreTableroRepresentado;
	BMP archivoBmp;

public:
	/*
	 * pre: -
	 * post: crea un instancia de imagen de tablero con un archivo.bmp de resolucion alto x ancho y un nombre
	 de tablero igual que el nombre pasado por parametro (va a ser el mismo nombre que el del tablero que representa)
	 */
	ImagenDeTablero(int alto, int ancho, std::string nombre);

	/*
	 * pre: los valores de fila y columna que se pasan deben estar dentro de las dimensiones del tablero de origen
	 * post: se pinta el pixel que representa a la celula en cuestion con el color recibido
	 */
	void representarCelulaViva(int fila, int columna, RGB* color);

	/*
	 * pre: los valores de fila y columna que se pasan deben estar dentro de las dimensiones del tablero de origen
	 * post: pinta el pixel que representa a la celula en cuestion de blanco (el color por defecto para definir
	 * a la muerte)
	 */
	void representarCelulaMuerta(int fila, int columna);

	/*
	 * pre: -
	 * post: se guarda un archivo.bmp con la representacion de las celulas en el tablero
	 */
	void guardarImagenTablero(int NumeroDeTurno);
};

#endif /* IMAGEN_DE_TABLERO_H_ */
