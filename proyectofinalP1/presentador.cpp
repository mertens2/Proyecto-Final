#include "presentador.h"

Presentador::Presentador(Vista* vista)
{
	_vista = vista;
	vendedor = new Vendedor;
	tienda = new Tienda;
}

void Presentador::ActualizarVista(std::string texto, bool borrar)
{
	if (borrar) {
		system("CLS");
	}
	_vista->ImprimirTexto(texto);
}

void Presentador::ComprarPrenda(int tipoRopa, bool esChupinOMangaCorta, bool tieneCuello, int cantidad, int calidad, int precio) {
		if (tipoRopa == PANTALON) {
			if (esChupinOMangaCorta) 
			{
				Chupin* chupin = new Chupin;
				chupin->nombre = "Pantalon chupin";
				chupin->precio = (precio - (12 * precio / 100));
				tipoRopa = 0;
				if (calidad == 1) 
				{
					chupin->calidad = "Premium";
				}
				else 
				{
					chupin->calidad = "Standard";
				}
				chupin->stock = tienda->CalcularStock(tipoRopa, cantidad, calidad);
				if (chupin->stock == -1) 
				{
					ActualizarVista("Error. Cantidad pedida excede cantidad de prendas en stock. Volviendo...", false);
					system("pause");
				}
				else if (chupin->stock == -2) 
				{
					ActualizarVista("Error. El codigo fallo porque los datos del 'calcularStock' no fueron validos. Volviendo...", false);
					system("pause");
				}
				else 
				{
					vendedor->ComprarAlgo(*chupin, cantidad);
				}
			}
			else {
				Pantalon* pantalon = new Pantalon;
				pantalon->nombre = "Pantalon largo";
				pantalon->precio = precio;
				tipoRopa = 1;
				if (calidad == 1) 
				{
					pantalon->calidad = "Premium";
				}
				else 
				{
					pantalon->calidad = "Standard";
				}
				pantalon->stock = tienda->CalcularStock(tipoRopa, cantidad, calidad);
				if (pantalon->stock == -1) 
				{
					ActualizarVista("Error. Cantidad pedida excede cantidad de prendas en stock. Volviendo...", false);
					system("pause");
				}
				else if (pantalon->stock == -2)
				{
					ActualizarVista("Error. El codigo fallo porque los datos del 'calcularStock' no fueron validos. Volviendo...", false);
					system("pause");
				}
				else
				{
					vendedor->ComprarAlgo(*pantalon, cantidad);
				}
			}
		}
		else if (tipoRopa == CAMISA) 
		{

			if (esChupinOMangaCorta) 
			{
				Corta* cCorta = new Corta;
				cCorta->nombre = "Camisa manga corta";
				cCorta->precio = (precio - (10 * precio / 100));
				tipoRopa = 3;
				if (tieneCuello) 
				{
					cCorta->precio += (3 * precio / 100);
					cCorta->nombre.append(" con cuello mao");
					tipoRopa += 2;
				}
				if (calidad == 1) 
				{
					cCorta->calidad = "Premium";
				}
				else 
				{
					cCorta->calidad = "Standard";
				}
				cCorta->stock = tienda->CalcularStock(tipoRopa, cantidad, calidad);
				if (cCorta->stock == -1) 
				{
					ActualizarVista("Error. Cantidad pedida excede cantidad de prendas en stock. Volviendo...", false);
					system("pause");
				}
				else if (cCorta->stock == -2) 
				{
					ActualizarVista("Error. El codigo fallo porque los datos del 'calcularStock' no fueron validos. Volviendo...", false);
					system("pause");
				}
				else 
				{
					vendedor->ComprarAlgo(*cCorta, cantidad);
				}
			}
			else
			{
				Camisa* camisa = new Camisa;
				camisa->nombre = "Camisa manga larga";
				camisa->precio = precio;
				tipoRopa = 2;
				if (tieneCuello)
				{
					camisa->precio += (3 * precio / 100);
					camisa->nombre.append(" con cuello mao");
					tipoRopa += 2;
				}
				if (calidad == 1)
				{
					camisa->calidad = "Premium";
				}
				else
				{
					camisa->calidad = "Standard";
				}
				camisa->stock = tienda->CalcularStock(tipoRopa, cantidad, calidad);
				if (camisa->stock == -1)
				{
					ActualizarVista("Error. Cantidad pedida excede cantidad de prendas en stock. Volviendo...", false);
					system("pause");
				}
				else if (camisa->stock == -2)
				{
					ActualizarVista("Error. El codigo fallo porque los datos del 'calcularStock' no fueron validos. Volviendo...", false);
					system("pause");
				}
				else
				{
					vendedor->ComprarAlgo(*camisa, cantidad);
				}
			}
		}
}

void Presentador::VerHistorial() {
	ActualizarVista("====== HISTORIAL DE COMPRAS ======\n\n == = Tienda " + NombreTienda() + " \n=======================\n\n", true);
	vendedor->ImprimirHistorial();
}

std::string Presentador::NombreVendedor()
{
	std::string nombreYApellido = vendedor->nombre;
	nombreYApellido.append(" ");
	nombreYApellido.append(vendedor->apellido);
	return nombreYApellido;
}

int Presentador::IDVendedor()
{
	return vendedor->codigo;
}

std::string Presentador::NombreTienda()
{
	return std::string(tienda->nombre);
}

std::string Presentador::DireccionTienda()
{
	return std::string(tienda->direccion);
}

Presentador::~Presentador()
{
	_vista = nullptr;
	vendedor = nullptr;
	tienda = nullptr;
}