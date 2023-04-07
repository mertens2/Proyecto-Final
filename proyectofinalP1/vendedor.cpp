#define _CRT_SECURE_NO_WARNINGS
#include "historial.h"
#include "tienda.h"

Vendedor::Vendedor() {
	codigo = 2010;
	nombre = "Susan";
	apellido = "Strong";
}

Vendedor::~Vendedor() {
	historial.clear();
}

bool Vendedor::ExisteID(int id) {
	for (Cotizacion item : historial) {
		if (id == item.id) {
			return true;
		}
	}
	return false;
}

void Vendedor::ComprarAlgo(Prendas prenda, int cant) {
	Cotizacion* compra = new Cotizacion{};
	int id;
	do {
		id = rand() % 100;
	} while (ExisteID(id) && id != 0);
	compra->id = id;
	compra->prenda = prenda.nombre;
	compra->cantRopa = cant;
	if (prenda.calidad == "Premium") {
		compra->prenda.append(" calidad Premium");
		prenda.precio += (30 * prenda.precio / 100);
	}
	else {
		compra->prenda.append(" calidad Standard");
	}
	compra->stock = prenda.stock;
	compra->precioUnidad = prenda.precio;
	compra->precioFinal = prenda.precio * cant;
	auto now = std::chrono::system_clock::now();
	std::time_t end_time = std::chrono::system_clock::to_time_t(now);
	compra->fechaYHora = std::ctime(&end_time);
	historial.push_back(*compra);
}

void Vendedor::ImprimirHistorial() {
	for (Cotizacion actual : historial) {
		std::cout << "\n=======================\nID de la compra: " << actual.id << "\nArtículo comprado: " << actual.prenda << "\nCantidad comprada: " << actual.cantRopa << "\nFecha y hora que fue comprada: " << actual.fechaYHora << "\nPrecio por unidad: " << actual.precioUnidad << "\nPrecio final: " << actual.precioFinal << "\nCantidad en stock: " << actual.stock << "\n=======================\n\n\n";
	}
}
