#ifndef PRESENTADOR_H
#define PRESENTADOR_H
#include "vista.h"
#include "historial.h"
#include "tienda.h"

class Vista;
class Vendedor;
class Tienda;

class Presentador {
	Vista* _vista;
	Vendedor* vendedor;
	Tienda* tienda;
public:
	Presentador(Vista* vista);
	void ActualizarVista(std::string texto, bool borrar);
	void ComprarPrenda(int tipoRopa, bool esChupinOMangaCorta, bool tieneCuello, int cantidad, int calidad, int precio);
	void VerHistorial();
	std::string NombreVendedor();
	int IDVendedor();
	std::string NombreTienda();
	std::string DireccionTienda();
	~Presentador();
};



#endif // !PRESENTADOR_H

