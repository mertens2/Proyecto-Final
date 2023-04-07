#ifndef PRENDAS_H
#define PRENDAS_H
#include "tienda.h"
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <time.h>

class Tienda;

enum tipoPrenda {
	PANTALON = 1,
	CAMISA
};

enum tipoPantalon {
	CHUPIN = 0,
	NORMAL = 1
};

enum tipoCamisa {
	LARGA = 2,
	CORTA,
	LARGACUELLO,
	CORTACUELLO
};

class Prendas {
public:
	std::string nombre, calidad;
	int precio, tipo, stock;
};

class Pantalon : public Prendas {
public:
	Pantalon();
};

class Chupin : public Pantalon {
public:
	Chupin();
};

class Camisa : public Prendas {
public:
};

class Corta : public Camisa {
public:
};


#endif // !PRENDAS_H
