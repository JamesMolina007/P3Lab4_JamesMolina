#include <string>
#include <iostream>
#pragma once

using namespace std;

class libro{
	private:
		string titulo;
		string autor;
		int anio;
		double precio;
		bool vendido;
	public:
		libro();
		libro( string titulo_l, string autor_l, int anio_l, double precio_l, bool vendido_l );
		void setTitulo( string titulo_l );
		void setAutor( string autor_l );
		void setAnio( int anio_l );
		void setPrecio( double precio_l );
		void setVendido( bool vendido_l );
		string getTitulo(){ return titulo; };
		string getAutor(){ return autor; };
		int getAnio(){ return anio; };
		double getPrecio(){ return precio; };
		bool getVendido(){ return vendido; };
};
