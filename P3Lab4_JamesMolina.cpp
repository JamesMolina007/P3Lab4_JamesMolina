#include <iostream>
#include <string>
#include "libro.hpp"
#include "usuario.hpp"

using namespace std;

usuario users[10];
bool verificar(){
		
}


int main(){
	usuario u( "n.duron", "sybase", "Nicolle Duron", 20, 1000 );
	users[0] = u;
	int opcion1, edad;
	double dinero;
	string usuario, contrasena, nombre;
	do{
		cout << "0- Salir" << "1- Ingresar" << endl << "2- Registrarse" << "Ingrese la opcion: ";
		cin >> opcion1;
		switch( opcion1 ){
			case 1:{
				cout << "Usuario: ";
				cin >> usuario;
				cout << "Contraseña: ";
				cin >> contrasena;
				if( verificar() )
				break;
			       }
			case 2: {
				cout << "Usuario: ";
				cin >> usuario;
				cout << "Contraseña: ";
				cin >> contrasena;
				cout << "Nombre: ";
				cin >> nombre;
				cout << "Edad: ";
				cin >> edad;
				cout << "Dinero: ";
				cin >> dinero;
				break;
				}
		}
	}while( opcion1 );
}
