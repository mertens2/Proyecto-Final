#ifndef TIENDA_H
#define TIENDA_H
#include "historial.h"
#include "prendas.h"
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <time.h>

class Vendedor;
class Cotizacion;
class Prendas;

class Tienda {
private:
	Vendedor* _vendedor;
public:
	std::string nombre, direccion;
	Tienda();
	~Tienda();
	int stockPantalon[2][2];
	int stockCamisa[2][4];
	int CalcularStock(int tipo, int cantidad, int calidad);
	void IniciarStock();
};


enum precio {
	PANTALON_PRECIO = 2000,
	CAMISA_PRECIO = 1000
};

#endif
