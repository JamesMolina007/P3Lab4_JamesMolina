#include <iostream>
#include <string>
#include "usuario.hpp"

using namespace std;

usuario :: usuario(){
}

usuario :: usuario( string user_u, string contrasena_u, string nombre_u, int edad_u, double dinero_u){
	user = user_u;
	contrasena = contrasena_u;
	nombre = nombre_u;
	edad = edad_u;
	dinero = dinero_u;
}

void usuario :: setUser( string user_u ){
	user = user_u;
}

void usuario :: setContrasena( string contrasena_u ){
	contrasena = contrasena_u;
}

void usuario :: setNombre( string nombre_u ){
	nombre = nombre_u;
}

void usuario :: setEdad( int edad_u ){
	edad = edad_u;
}

void usuario :: setDinero( double dinero_u ){
	dinero = dinero_u;
}

void usuario :: setLibro( libro librito, int pos ){
	lista[ pos ] = librito;
}	
