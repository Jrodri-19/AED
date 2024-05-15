#include <iostream>
using namespace std;
struct Nodo {
	int dato; // Dato del nodo
	Nodo* siguiente; // Puntero al siguiente nodo
};
class ListaEnlazada {
private:
	Nodo* cabeza;
public:
	ListaEnlazada() : cabeza(nullptr) {} 
	void insertarAlInicio(int valor) {
		Nodo* nuevoNodo = new Nodo();
		nuevoNodo->dato = valor;
		nuevoNodo->siguiente = cabeza;
		cabeza = nuevoNodo;
	}
	void insertarAlFinal(int valor) {
		Nodo* nuevoNodo = new Nodo();
		nuevoNodo->dato = valor;
		nuevoNodo->siguiente = nullptr;
		if (cabeza == nullptr) {
			cabeza = nuevoNodo;
		} else {
			Nodo* actual = cabeza;
			while (actual->siguiente != nullptr) {
				actual = actual->siguiente;
			}
			actual->siguiente = nuevoNodo;
		}
		
	}
	
	void insertarEnPosicion(int valor, int posicion) {
		if (posicion < 0) {
			std::cout << "Posición no válida." << std::endl;
			return;
		}
		
		Nodo* nuevoNodo = new Nodo();
		nuevoNodo->dato = valor;
		
		if (posicion == 0) {
			nuevoNodo->siguiente = cabeza;
			cabeza = nuevoNodo;
			return;
		}
		
		Nodo* actual = cabeza;
		for (int i = 0; i < posicion - 1; ++i) {
			if (actual == nullptr) {
				std::cout << "Posición fuera de los límites de la lista." << std::endl;
				delete nuevoNodo;
				return;
			}
			actual = actual->siguiente;
		}
		
		nuevoNodo->siguiente = actual->siguiente;
		actual->siguiente = nuevoNodo;
	}
	void mostrar() {
		Nodo* actual = cabeza;
		while (actual != nullptr) {
			std::cout << actual->dato << " ";
			actual = actual->siguiente;
		}
		std::cout << "null" << std::endl;
	}
	
	// Destructor para liberar la memoria
	~ListaEnlazada() {
		Nodo* actual = cabeza;
		while (actual != nullptr) {
			Nodo* temp = actual;
			actual = actual->siguiente;
			delete temp;
		}
	}
};
int main(int argc, char *argv[]) {
	ListaEnlazada lista;
	
	lista.insertarAlInicio(3);
	lista.insertarAlInicio(2);
	lista.insertarAlInicio(1);
	
	/*
	lista.insertarAlFinal(3);
	lista.insertarAlFinal(2);
	lista.insertarAlFinal(1);
	*/
	lista.insertarEnPosicion(5, 2);
	lista.mostrar();
	return 0;
}
