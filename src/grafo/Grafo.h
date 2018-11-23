#include "../Listas/ListaEnlazada.h"
#include "Arista.h"
#include "../Tablero/Tablero.h"

class Grafo{
private:

	// Bastante simple, la cantidad de vertices del grafo (medio que sobra)
	int cantidadVertices;

	//Aca se crea un nodo de la lista de listas por cada vertice que se agrega y despues se ponen
	//los vertices adyacentes a dicho vertice en la lista. El orden de los nodos se puede obtener
	//a traves de la "listaDeVertices"

	ListaEnlazada<ListaEnlazada<Arista*>*>* verticesAdyacentes;

	//Aca se listan los vertices que tiene el grafo (tableros, en este caso)

	ListaEnlazada<Tablero*>* listaDeVertices;

public:

	/*
	 * pre: -
	 * post: se crea una iteracion de la clase grafo sin vertices ni aristas
	 */
	Grafo();

	/*
	 * pre: -
	 * post: se agrega un vertice al grafo
	 */
	void agregarVertice(Tablero* tableroAsociado);

	/*
	 * pre: los vertices emisor y receptor no pueden estar previamente conectados
	 * post: se crea una arista entre los vertices emisor y receptor
	 */
	void agregarArista(Tablero* verticeEmisor, Tablero* verticeReceptor);

	/*
	 * pre: solo se puede eliminar un vertice si no existen aristas que esten vinculadas con este
	 * post: se elimina un vertice del grafo
	 */
	void eliminarVertice(Tablero* tableroAsociado);

	/*
	 * pre: la arista en cuestion debe existir
	 * post: se elimina una arista entre los vertices emisor y receptor
	 */
	void elminimarArista(Tablero* verticeEmisor, Tablero* verticeReceptor);
};
