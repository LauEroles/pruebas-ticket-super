/*
1)-Cargar e imprimir un ticket con items de productos de super mercado
2)- Cargar un acumulador con el importe total del ticket
 
 Diferencia entre precio e importe: importe esta detras de un calculo, por ej precio x cantidad
*/

#include <iostream>
using namespace std;

struct Producto{
    string nombreProducto;
    int cantidadProducto;
    float precioProducto;

};



int main () {
    
    int cantProductos;

    cout<<"Ingrese la cantidad de productos que desea cargar"<<endl;
    cin>>cantProductos;

    Producto productos[cantProductos];

    for (int i = 0; i < cantProductos; i++) {
        
        cout<<"Ingrese el nombre del Producto"<<endl;
        cin>>productos[i].nombreProducto;

        cout<<"Ingrese la cantidad de unidades del producto que desea "<<endl;
        cin>>productos[i].cantidadProducto;


        //Esto no deberia tener otro formato? Se supone que el usuario no deberia cargar el precio :) 
        cout<<"Ingrese el precio del producto"<<endl;
        cin>>productos[i].precioProducto;

    }
    
    for (int i = 0; i < cantProductos; i++) {
      
        cout<<"----- Item " <<i+1<< " -----"<<endl;
        cout<<"Descripción : "<<productos[i].nombreProducto<<endl;
        cout<<"Cantidad : "<<productos[i].cantidadProducto<<endl;
        cout<<"Precio : "<<productos[i].precioProducto<<endl;

    }
    



    return 0;
}