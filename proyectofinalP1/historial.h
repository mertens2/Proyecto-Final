#ifndef HISTORIAL_H
#define HISTORIAL_H
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <time.h>
#include <chrono>

class Vendedor;
class Prendas;

class Cotizacion {
private:
	Vendedor* codVendedor;
public:
	int id;
	std::string fechaYHora, prenda;
	int cantRopa, precioFinal, stock, precioUnidad;
};

class Vendedor {
private:
	time_t now;
	std::vector<Cotizacion> historial;
public:
	std::string nombre, apellido;
	int codigo;
	Vendedor();
	~Vendedor();
	void ComprarAlgo(Prendas prenda, int cant);
	void ImprimirHistorial();
	bool ExisteID(int id);
};



#endif // !HEADER
