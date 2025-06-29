#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

struct Producto 
{

    string nombre;
    float precio;
};
struct Venta
{
    int idVenta;
    string producto;
    int cantidad;
    float precioTotal;
};

Producto productos[MAX];
Venta ventas[MAX];
int totalProductos=0;
int totalVentas=0;
int contadorVentas=0;

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
void listarProductos()
{
    for(int i=0;i<totalProductos;i++)
    {
        cout<<i+1<<". "<<productos[i].nombre<<" - $"<<productos[i].precio<<endl;
    }
}
void buscarProducto()
{
    string nombre;
    cout<<"Nombre del producto a buscar: ";
    cin>>ws;
    getline(cin, nombre);
    for(int i=0;i<totalProductos;i++)
    {
        if(productos[i].nombre==nombre)
        {
            cout<<"Producto encontrado: "<<productos[i].nombre<<" - $"<<productos[i].precio<<endl;
            return;
        }
    }
    cout<<"Producto no encontrado."<<endl;
}
void actualizarProducto()
{
    string nombre;
    cout<<"Nombre del producto a actualizar: ";
    cin>>ws;
    getline(cin, nombre);
    for(int i=0;i<totalProductos;i++)
    {
        if(productos[i].nombre==nombre)
        {
            cout<<"Nuevo nombre: ";
            getline(cin, productos[i].nombre);
            cout<<"Nuevo precio: ";
            cin>>productos[i].precio;
            cout<<"Producto actualizado."<<endl;
            return;
        }
    }
    cout<<"Producto no encontrado."<<endl;
}
void eliminarProducto()
{
    string nombre;
    cout<<"Nombre del producto a eliminar: ";
    cin>>ws;
    getline(cin, nombre);
    for(int i=0;i<totalProductos;i++)
    {
        if(productos[i].nombre==nombre)
        {
            for(int j=i;j<totalProductos-1;j++)
            {
                productos[j]=productos[j+1];
            }
            totalProductos--;
            cout<<"Producto eliminado."<<endl;
            return;
        }
    }
    cout<<"Producto no encontrado."<<endl;
}
void registrarVenta()
{
    string nombre;
    int cantidad;
    cout<<"Nombre del producto vendido: ";
    cin>>ws;
    getline(cin, nombre);
    cout<<"Cantidad: ";
    cin>>cantidad;
    for(int i=0;i<totalProductos;i++)
    {
        if(productos[i].nombre==nombre)
        {
            ventas[totalVentas].idVenta=++contadorVentas;
            ventas[totalVentas].producto=nombre;
            ventas[totalVentas].cantidad=cantidad;
            ventas[totalVentas].precioTotal=productos[i].precio*cantidad;
            totalVentas++;
            cout<<"Venta registrada con ID: "<<contadorVentas<<endl;
            return;
        }
    }
    cout<<"Producto no encontrado. Venta no registrada."<<endl;
}
void listarVentas()
{
    for(int i=0;i<totalVentas;i++)
    {
        cout<<"ID: "<<ventas[i].idVenta<<", Producto: "<<ventas[i].producto<<", Cantidad: "<<ventas[i].cantidad<<", Total: $"<<ventas[i].precioTotal<<endl;
    }
}

int main() 
{
    char opcion;
    do {
        cout<<"\nMenu:\n";
        cout<<"A. Registrar producto\n";
        cout<<"B. Listar productos\n";
        cout<<"C. Buscar producto\n";
        cout<<"D. Actualizar producto\n";
        cout<<"E. Eliminar producto\n";
        cout<<"F. Registrar venta\n";
        cout<<"G. Listar ventas\n";
        cout<<"S. Salir\n";
        cout<<"Opcion: ";
        cin >> opcion;
        opcion=toupper(opcion);
        switch (opcion) {
            case 'A': registrarProducto(); 
            break;
            case 'B': listarProductos(); 
            break;
            case 'C': buscarProducto(); 
            break;
            case 'D': actualizarProducto(); 
            break;
            case 'E': eliminarProducto(); 
            break;
            case 'F': registrarVenta(); 
            break;
             case 'G': listarVentas(); 
            break;
            case 'S': cout<<"Saliendo...\n"; 
            break;
            default: cout<<"Opcion no valida.\n"; 
            break;
        }
    } while(opcion != 'S');
    return 0;
}