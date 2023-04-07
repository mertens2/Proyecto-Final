#include "vista.h"

Vista::Vista()
{
	int opcion, tipoRopa, cantidad, calidad, precio;
	bool tieneCuello, esChupinOMangaCorta;
	presentador = new Presentador(this);
	do {
		system("CLS");
		do {
			continuar = false;
			try{
				std::cout << "====== AUTOSERVICIO ======\n=== Tienda " << presentador->NombreTienda() << " || " << presentador->DireccionTienda() << " ===\n==========================\n===== Datos del Vendedor =====\n==========================\n=== " << presentador->NombreVendedor() << " == ID: 000" << presentador->IDVendedor() << " ==\n==========================\n";
				std::cout << "Elija una opción :\n==========================\n1 - Comprar Prenda\n2 - Ver historial compras\n3 - Salir\n==========================\n\nEleccion: ";
				std::cin >> opcion;
			}
			catch (...){
				MensajeDeError()
			}
		}while (continuar);
		switch (opcion) {
		case 1:
			tipoRopa = QueTipo();
			if (tipoRopa == 1) {
				esChupinOMangaCorta = QuePantalon();
				calidad = Calidad();
				tieneCuello = false;
				if (calidad != 2) {
					cantidad = QueCantidad();
					precio = DarPrecio();
					presentador->ComprarPrenda(tipoRopa, esChupinOMangaCorta, tieneCuello, cantidad, calidad, precio);
				}
			}
			else if (tipoRopa == 2) {
				esChupinOMangaCorta = QueCamisa();
				tieneCuello = Cuello();
				calidad = Calidad();
				if (calidad != 2) {
					cantidad = QueCantidad();
					precio = DarPrecio();
					presentador->ComprarPrenda(tipoRopa, esChupinOMangaCorta, tieneCuello, cantidad, calidad, precio);
				}
			}
			else {
				std::cout << "Volviendo...";
				system("wait");
			}
			break;
		case 2:
			presentador->VerHistorial();
			break;
		case 3:
			Salir();
			break;
		}
		try {
			std::cout << "\n==========================\n¿Quieres continuar?\n==========================\n \n1-Si\n2-No\n==========================\n\nRespuesta: ";
			std::cin >> opcion;
		}
		catch (...){
			std::cout << "¡Error!\n¡El dato ingresado no es un numero entero! Volviendo al inicio.\n";
			system("wait");
			opcion = 2;
		}
		
	} while (opcion != 2);
	system("CLS");
	Salir();
}

int Vista::QueTipo() {
	int tipoRopa;
	continuar = false;
	system("CLS");
	do{
		continuar = false;
		try {
			std::cout << "\n\n=== ¿Desea comprar un pantalon o una camisa?\n==========================\n\n1-Pantalon\n2-Camisa\n3-Salir\n\n==========================\n\nEleccion: ";
			std::cin >> tipoRopa;
		}
		catch (...){
				MensajeDeError()
		}
	}while (continuar);
	if (tipoRopa != 1 && tipoRopa != 2) {
		Salir();
	}
	return tipoRopa;
}

bool Vista::QuePantalon() {
	int tipoPantalon;
	system("CLS");
	do {
		continuar = false;
		try {
			ImprimirTexto("====== SECCION DE COMPRAS ======\n\n === Tienda " + presentador->NombreTienda() + " ==========================\n");
			ImprimirTexto("=== ¿Desea comprar un pantalon chupin? ===\n=======================\n1-Si\n2-No\n=======================\nRespuesta: ");
			std::cin >> tipoPantalon;
		}
		catch (...){
				MensajeDeError()
		}	
	}while (continuar);
	if (tipoPantalon == 1) {
		return true;
	}
	return false;
}

int Vista::Calidad() {
	int eleccion;
	system("CLS");
	do {
		continuar = false;
		try {
			ImprimirTexto("====== ELECCION DE CALIDAD ======\n\n === Tienda " + presentador->NombreTienda() + " ===\n==========================\n=== ");
			ImprimirTexto("¿Desea calidad Premium (20% mas) o no? ===\n=======================\n1-No\n2-Si\n3-Volver\nRespuesta: ");
			std::cin >> eleccion;
		}
		catch (...){
				MensajeDeError()
		}
	}while (continuar);
	return eleccion-1;
}

int Vista::QueCantidad() {
	int cant;
	system("CLS");
	do {
		continuar = false;
		try {
			ImprimirTexto("====== ELECCION DE CANTIDAD ======\n\n === Tienda " + presentador->NombreTienda() + " ===\n==========================\n=== ");
			ImprimirTexto("¿Cuantas unidades desea comprar? ===\n=======================\nRespuesta: ");
			std::cin >> cant;
		}
		catch (...){
				MensajeDeError()
		}
	}while (continuar);
	
	return cant;
}

bool Vista::Cuello() {
	int cuello;
	
	system("CLS");
	continuar = false;
	do {
		continuar = false;
		try {
			ImprimirTexto("====== TIPO DE CUELLO ======\n\n === Tienda " + presentador->NombreTienda() + " ===\n==========================\n=== ");
			ImprimirTexto("¿Desea comprar una camisa cuello mao? ===\n=======================\n1-Si\n2-No\n=======================\nRespuesta: ");
			std::cin >> cuello;
		}
		catch (...){
				MensajeDeError()
		}
	}while (continuar);
	
	if (cuello == 1) {
		return true;
	}
	return false;
}

bool Vista::QueCamisa() {
	int tipoCamisa;
	system("CLS");
	do {
		continuar = false;
		try {
			ImprimirTexto("====== SECCION DE COMPRAS ======\n\n === Tienda " + presentador->NombreTienda() + " ==========================\n");
			ImprimirTexto("=== ¿Desea comprar una camisa manga corta? ===\n=======================\n1-Si\n2-No\n=======================\nRespuesta: ");
			std::cin >> tipoCamisa;
		}
		catch (...){
				MensajeDeError()
		}
	}while (continuar);
	
	if (tipoCamisa == 1) {
		return true;
	}
	return false;
}

void Vista::Salir() {
	std::cout << "\n==========================\nSaliendo...";
	std::cout.flush();
	exit(EXIT_SUCCESS);
}

void Vista::ImprimirTexto(std::string texto)
{
	std::cout << texto << "\n\n";
}

int Vista::DarPrecio() {
	int precio;
	system("CLS");
	do{
		continuar = false;
		try {
			ImprimirTexto("====== SELECCION DE PRECIO ======\n\n === Tienda " + presentador->NombreTienda() + " ==========================\n");
			ImprimirTexto("=== Ingrese el precio del producto ===\n=======================\n=======================\n\nRespuesta: ");
			std::cin >> precio;
		}
		catch (...){
				MensajeDeError()
		}
	}while (continuar);
	
	return precio;
}

void Vista::MensajeDeError(){
	std::cout << "¡Error!\n¡El dato ingresado no es un numero entero! Intentar nuevamente.\n";
	system("wait");
	continuar = true;
}

Vista::~Vista()
{
	presentador = nullptr;
}

int main() {
	Vista vista;
	return 0;
}