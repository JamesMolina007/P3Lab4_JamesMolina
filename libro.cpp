#include "libro.hpp"
#include <iostream>
#include <string>

using namespace std;

libro :: libro(){
}

libro :: libro( string titulo_l, string autor_l, int anio_l, double precio_l, bool vendido_l){
	titulo = titulo_l;
	autor = autor_l;
	anio = anio_l;
	precio = precio_l;
	vendido = vendido_l;
}

void libro :: setTitulo( string titulo_l ){
	titulo = titulo_l;
}

void libro :: setAutor( string autor_l ){
	autor = autor_l;
}

void libro :: setAnio( int anio_l ){
	anio = anio_l;
}

void libro :: setPrecio( double precio_l ){
	precio = precio_l;
}

void libro :: setVendido( bool vendido_l ){
	vendido = vendido_l;
}
