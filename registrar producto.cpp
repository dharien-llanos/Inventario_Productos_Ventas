#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

struct Producto 
{
    string nombre;
    float precio;
};

Producto productos[MAX];
int totalProductos=0;

void registrarProducto() 
{
    if (totalProductos >= MAX) return;
    cout<<"Nombre del producto: ";
    cin>>ws;
    getline(cin, productos[totalProductos].nombre);
    cout<<"Precio: ";
    cin>>productos[totalProductos].precio;
    totalProductos++;
}

int main() 
{
    char opcion;
    do {
        cout<<"\nMenu:\n";
        cout<<"A. Registrar producto\n";
        cout<<"S. Salir\n";
        cout<<"Opcion: ";
        cin >> opcion;
        opcion=toupper(opcion);
        switch (opcion) {
            case 'A': registrarProducto(); 
			break;
            case 'S': cout<<"Saliendo...\n"; 
			break;
            default: cout<<"Opcion no valida.\n"; 
			break;
        }
    } while(opcion != 'S');
    return 0;
}