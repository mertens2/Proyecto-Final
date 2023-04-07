#ifndef VISTA_H
#define VISTA_H
#include "presentador.h"
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <time.h>

class Presentador;

class Vista {
	Presentador* presentador;
public:
	Vista();
	void ImprimirTexto(std::string texto);
	void Salir();
	int QueTipo();
	bool QuePantalon();
	bool QueCamisa();
	int Calidad();
	bool Cuello();
	int QueCantidad();
	int DarPrecio();
	~Vista();
};


#endif // !VISTA_H

