#include <iostream>
#include <string>
#include "libro.hpp"
#include "usuario.hpp"
#include <array>
#include <cstring>

using namespace std;

int contlibros, contusers = 1, entro;
array< libro, 10 > lista_libros;
usuario users[10];


void usuarioscreados(){
	for( int i = 0; i < 10; i++ ){
		cout << endl << endl;
		cout << "Usuario: "<< users[i].getUser() << endl;
		cout << "Nombre: "<< users[i].getNombre() << endl;
		cout << "Contraseña: "<< users[i].getContrasena() << endl;
		cout << "Edad: " << users[i].getEdad() << endl;
		cout << "Dinero: " << users[i].getDinero() << endl;
	}

}



void desaparecer(){
	for( int i = 0; i < 10; i++ ){
                if( i == entro ){
                        while( i < 9 ){
                                users[i] = users[i+1];
                                i++;
                        }
                }
        }

        usuarioscreados();
        cout << "Se ha borrado exitosamente" << endl;

}

void busqueda( string busca ){
	for( int i = 0; i < 10; i++ ){
		if( lista_libros[i].getAutor() == busca || lista_libros[i].getTitulo() == busca ){
			cout << endl;
			cout << "Libro #" << ( i + 1 ) << endl;
			cout << "Titulo: " << lista_libros[i].getTitulo() << endl;
			cout << "Autor: " << lista_libros[i].getAutor() << endl;
			cout << "Precio: " << lista_libros[i].getPrecio() << endl;
			cout << "Vendido: " << lista_libros[i].getVendido() << endl;
			cout << endl;
		}
	}
}

void libritos(  ){
      cout << endl << endl;
      for( int i = 0; i < 10; i++ ){
            if(lista_libros[i].getTitulo() != ""){
		  cout << endl << endl;
                  cout << "Libro #" << ( i + 1 ) << endl;
                  cout << "Titulo: " << lista_libros[i].getTitulo() << endl;
                  cout << "Autor: " << lista_libros[i].getAutor() << endl;
                  cout << "Precio: " << lista_libros[i].getPrecio() << endl;
                  cout << "Vendido: " << lista_libros[i].getVendido() << endl;
            }
      }
}


void compra(){
	int numero;
	libritos();
	cout << "Ingrese el libro que desea comprar: ";
	cin >> numero;
	numero--;
	if( numero >= 0 && numero < 10 ){
		double dinero = users[entro].getDinero();
		double costo = lista_libros[numero].getPrecio();
		if( dinero >= costo ){
			users[entro].setDinero( dinero - costo );
			cout << "Se ha comprado el libro exitosamente" << endl;
			lista_libros[numero].setVendido( true );
		}else{
			cout << "No tiene suficiente dinero para comprar" << endl;
		}
	}	
}

void interfazUsuario(){
	int opcion;
	string autor, titulo;
	do{
		cout << endl << endl;
		cout << "0- Salir" << endl;
		cout << "1- Comprar Libro" << endl;
		cout << "2- Buscar por autor" << endl;
		cout << "3- Buscar por titulo" << endl;
		cout << "4- Agregar dinero a mi cuenta" << endl;
		cout << "5- Restablecer contraseña" << endl;
		cout << "6- Borrar cuenta" << endl;
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		switch( opcion ){
			case 1:{
				 compra();
				 break;
			       }
			case 2:{
				cout << "Ingrese el nombre del autor: ";
				cin >> autor;
				busqueda( autor );
				break;
			       }
			case 3:{
				cout << "Ingrese el titulo del libro: ";
				cin >> titulo;
				busqueda( titulo );
				break;
			       }
			case 4:{
				double dinero;
				cout << "Ingrese le dinero que tiene: ";
				cin >> dinero;
				users[entro].setDinero( dinero );
				cout << "Se ha modificado el dinero" << endl;
				break;
			       }
			case 5:{
				string contrasena;
				cout << "Ingrese la nueva contraseña: ";
				cin >> contrasena;
				users[entro].setContrasena( contrasena );
				cout << "La contraseña de ha modificado" << endl;
				break;
			       }
			case 6:{
				int borrar;
				cout << "Seguro que desea borrar su cuenta[ 1- SI / 0 - NO ]: ";
				cin >> borrar;
				if( borrar == 1 ){
					opcion = 0;       
					desaparecer();
				}
				break;
			       }
		}
	}while( opcion );
}


void crear(int pos){
	string autor, titulo;
        int anio;
        double precio;
        bool vendido;
        cout << "Titulo: ";
        cin >> titulo;
        cout << "Autor: ";
        cin >> autor;
        cout << "Precio: ";
        cin >> precio;
        int ayudante;
        cout << "0- No vendido \n1- Vendido \nIngrese una opcion: ";
        cin >> ayudante;
        ( ayudante == 0 ) ? vendido = false : vendido = true;
        libro l( titulo, autor, anio, precio, vendido );
        if( contlibros < 10 ){
	if( pos == -1 ){
		lista_libros[contlibros] = l;
		contlibros++;
        	cout << "Se ha creado exitosamente";
	}else{
		lista_libros[pos] = l;
		cout << "Se ha modificado correctamente";
	}
	}else cout << "Solamente pueden haber 10 libros";
	
}

void imprimir(  ){
      cout << endl << endl;
      for( int i = 0; i < 10; i++ ){
            if(lista_libros[i].getTitulo() != ""){
		  cout << endl << endl;
                  cout << "Libro #" << ( i + 1 ) << endl;
                  cout << "Titulo: " << lista_libros[i].getTitulo() << endl;
                  cout << "Autor: " << lista_libros[i].getAutor() << endl;
                  cout << "Precio: " << lista_libros[i].getPrecio() << endl;
                  cout << "Vendido: " << lista_libros[i].getVendido() << endl;
            }
      }
}

void borrar( int pos ){
        for( int i = 0; i < 10; i++ ){
                if( i == pos ){
                        while( i < 9 ){
                                lista_libros[i] = lista_libros[i+1];
                                i++;
                        }
                }
        }
	
        imprimir();
	cout << "Se ha borrado exitosamente" << endl;
}

void destruir(){
	array< libro, 10 > nuevo;
	lista_libros = nuevo;
	cout << "Se ha vaciado correctamente" << endl;
}



void admin( ){
	int opcion;
	do{
		cout << endl << endl;
		cout << "0- Salir \n" << "1- Agregar Libro \n" << "2- Modificar Libro \n" << "3- Eliminar Libro \n" << "4- Borrar Registro de Libros \n5- Listar Libros \n6- Listar Usuarios";
       		cout << "\nIngrese la opcion: ";	
		cin >> opcion;
		switch( opcion ){
			case 1:{
				crear( -1 );
			        break;
			       }
			case 2:{
				imprimir();
				int num_libro;
			 	cout << "Ingrese el libro que desea modificar: ";	
				cin >> num_libro;
				num_libro--;
				if( num_libro < 10 && num_libro >= 0 ) {
					crear( num_libro );
				}else{
					cout << "No existe ese libro" << endl;
				}
				break;
			       }
			case 3:{
				imprimir();
				int eliminar;
				cout << "Ingrese la posicion del libro que desea eliminar: ";
				cin >> eliminar;
				eliminar--;
				if( eliminar < 10 && eliminar >= 0 ){
					borrar( eliminar);
			       }else cout << "No existe ese libro" << endl;
			       break;
			       }
			case 4:{
				int seguro;
				cout << "Esta seguro que desea borrar todos los libros[ 0-No / 1-Si ]: ";
				cin >> seguro;
				if( seguro == 1 ) destruir();
				break;
			       }
			case 5:{
				imprimir( );
			        break;
			       }
			case 6:{
				usuarioscreados();
				break;
			       }
		}
	}while( opcion );
}



bool verificar( usuario* lista, string usuario, string contrasena ){
	for( int i = 0; i < 10; i++ ){
		if( lista[i].getUser() == usuario && lista[i].getContrasena() == contrasena ){
		       	entro = i;
			return true;
		}
		
	}
	return false;
}

void usuarioNuevo(){
	string u, nombre, contrasena;
	int edad;
	double dinero;
        cout << "Usuario: ";
        cin >> u;
        cout << "Contraseña: ";
        cin >> contrasena;
        cout << "Nombre: ";
        cin >> nombre;
        cout << "Edad: ";
        cin >> edad;
        cout << "Dinero: ";
        cin >> dinero;
        usuario m( u, contrasena, nombre, edad, dinero );
        users[contusers] = m;
        contusers++;

}


int main(){
	usuario u( "n.duron", "sybase", "Nicolle Duron", 20, 1000 );
	users[0] = u;
	int opcion1, edad;
	double dinero;
	string usuario, contrasena, nombre;
	do{
		cout << endl << endl;
		cout << "0- Salir" << endl  << "1- Ingresar" << endl << "2- Registrarse" << endl << "Ingrese la opcion: ";
		cin >> opcion1;
		switch( opcion1 ){
			case 1:{
				cout << "Usuario: ";
				cin >> usuario;
				cout << "Contraseña: ";
				cin >> contrasena;
				if( usuario == users[0].getUser() && contrasena == users[0].getContrasena() ){
					cout << "Bienvenida Nicolle Duron";
					admin();
				}else
					if( verificar( users, usuario, contrasena ) ){
						cout << "Bienvenido: " << usuario << endl;
						interfazUsuario();
					}else cout << "El usuario y/o contraseña es incorrecta";
			        break;
			      }
			case 2: {
				usuarioNuevo();
				break;
				}
		}
	}while( opcion1 );
}
