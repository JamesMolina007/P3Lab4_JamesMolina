#include <string>
#include <iostream>
#include "libro.hpp"

#pragma once

class usuario{
	private: 
		string user;
		string contrasena;
		string nombre;
		int edad;
		double dinero;
		libro lista[10];
	public:
		usuario();
		usuario( string user_u, string contrasena_u, string nombre_u, int edad_u, double dinero_u );
		void setUser( string user_u );
		void setContrasena( string contrasena_u );
		void setNombre( string nombre_u );
		void setEdad( int edad_u );
		void setDinero( double dinero_u );
		void setLibro( libro librito_u, int pos_u );
		string getUser() { return user; };
		string getContrasena() { return contrasena; };
		string getNombre() { return nombre; };
		int getEdad() { return edad; };
		double getDinero() { return dinero; };
		libro* getLibro() { return lista; };
		//~usuario(){ delete libro };		
};
