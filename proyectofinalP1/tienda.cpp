#include "tienda.h"
#include "historial.h"
#include "prendas.h"

Tienda::Tienda() {
	nombre = "Able Sisters";
	direccion = "Calle Falsa 123";
	IniciarStock();
}

Tienda::~Tienda() {
	_vendedor = nullptr;
}

void Tienda::IniciarStock() {
	//stockChupin, stockNormal 
// standard   750			250
// premium    750           250
	stockPantalon[0][0] = 750;
	stockPantalon[1][0] = 750;
	stockPantalon[0][1] = 250;
	stockPantalon[1][1] = 250;
	//stockLarga, stockCorta, LargaCuello, CortaCuello 
// standard   175			150			75			100
// premium    175           150			75			100
	stockCamisa[0][0] = 175;
	stockCamisa[1][0] = 175;
	stockCamisa[0][1] = 150;
	stockCamisa[1][1] = 150;
	stockCamisa[0][2] = 75;
	stockCamisa[1][2] = 75;
	stockCamisa[0][3] = 100;
	stockCamisa[1][3] = 100;
}

int Tienda::CalcularStock(int tipo, int cantidad, int calidad)
{
	if (tipo < 0 || calidad < 0 || tipo > 5 || calidad > 1)
	{
		return -2; // para separar el "no hay suficientes para comprar" del "datos no validos"
	}
	if (tipo >= 2)
	{
		tipo -= 2;
		if (cantidad > stockCamisa[calidad][tipo])
		{
			return -1;
		}
		stockCamisa[calidad][tipo] -= cantidad;
		return stockCamisa[calidad][tipo];
	}
	if (cantidad > stockPantalon[calidad][tipo])
	{
		return -1;
	}
	stockPantalon[calidad][tipo] -= cantidad;
	return stockPantalon[calidad][tipo];
}
