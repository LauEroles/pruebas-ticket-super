/*
    1)-Cargar e imprimir un ticket con items de productos de super mercado
    
    Diferencia entre precio e importe: importe esta detras de un calculo, por ej precio x cantidad

 --------------------------------------------------------------------------

    Second iteration- refactor:
    a- Load an accumulator with the total amount of the ticket
    b- Change the code to English

*/

#include <iostream>
#include <stdlib.h>
//This libraryis used for the funcion that alows persist data on the txt
#include <fstream>

using namespace std;


//armo un srtuct para poder maipular un conjunto de datos de diferentes tipos dentro de una misma estructura
struct Producto{
    string nombreProducto;
    int cantidadProducto;
    float precioProducto;

};

// es el prototipo de la funcion de escribir para los datos que irán en el txt
bool escribir(string nombreArchivo, Producto productos[], int n, float acumImporteTotal);


int main () {
    
    int cantProductos=0;
    float importeProducto=0, acumuladorImporteTotal=0;

    cout<<"Ingrese la cantidad de productos que desea cargar"<<endl;
    cin>>cantProductos;

    //defino el tamaño del array de productos
    Producto productos[cantProductos];

    //con el for mino con los valores el array del struct de productos
    for (int i = 0; i < cantProductos; i++) {
        
        cout<<"Ingrese el nombre del Producto"<<endl;
        cin>>productos[i].nombreProducto;

        cout<<"Ingrese la cantidad de unidades del producto que desea "<<endl;
        cin>>productos[i].cantidadProducto;


        //Esto no deberia tener otro formato? Se supone que el usuario no deberia cargar el precio :) Lo voy a refactorizar luego
        cout<<"Ingrese el precio del producto"<<endl;
        cin>>productos[i].precioProducto;

        //estoy calculando el importe total de cada item
        importeProducto=productos[i].cantidadProducto*productos[i].precioProducto;
        
        
        //calculo el valor total del ticket
        acumuladorImporteTotal+=importeProducto;

    }
    
    // Imprimo los datos del array del struct por consola
    for (int i = 0; i < cantProductos; i++) {
      
        cout<<"----- Item " <<i+1<< " -----"<<endl;
        cout<<"Descripción : "<<productos[i].nombreProducto<<endl;
        cout<<"Cantidad : "<<productos[i].cantidadProducto<<endl;
        cout<<"Precio : "<<productos[i].precioProducto<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"Importe producto : "<<productos[i].precioProducto * productos[i].cantidadProducto<<endl;

        
    }

    cout<<"Importe Total del ticket: "<<acumuladorImporteTotal<<endl;

    // Escribo los datos del array del struct en el archivo txt
    bool okEscritura=escribir("tickets.txt",productos,cantProductos, acumuladorImporteTotal);

    //Si la escritua del archivo fallo, le aviso al user que no se pudo escribir el txts
    if (!okEscritura){
        cout<<"El archivo no se pudo escribir, contacte a un administrador";
    }
    

    return 0;
}
 
 //Persistir en archivo

                //voy a recibir el nombre del archivo que voy a guardar en el main harcodeado
                //recibo tambien el array del struct y el tamaño del mismo para guardar los valores en el txt 
 bool escribir(string nombreArchivo, Producto productos[], int n, float acumImporteTotal){
   
    //ofstream es como un tipo de dato, pero pertenece a la libreria y representa una salida de datos, declaro la variable archivo de tipo ofstream
    ofstream archivo;
    
    //el metodo va a devolver un booleano que va a indicar si el archivo se grabó o no en el txt
    bool ok=false;

    //la funcion open va a crear y abrir archivos y el segundo parametro representa la entrada y la salida
    //se crea el archivo sin ninguna info adentro pero tiene un nombre harcodeado
    archivo.open(nombreArchivo,ios::out);

    //Esta condicion me devuelve un true si el archivo falla en la creación 
    if (archivo.fail()){
        return ok;
    }
    //si no falla la creacion del archivo guardo los datos del array del struct en el txt
    for(int i=0; i<n;i++){
        archivo<<"----- Item " <<i+1<< " -----"<<endl;
        archivo<<"Descripción : "<<productos[i].nombreProducto<<endl;
        archivo<<"Cantidad : "<<productos[i].cantidadProducto<<endl;
        archivo<<"Precio : "<<productos[i].precioProducto<<endl;
        archivo<<"-----------------------------------------------------"<<endl;
        archivo<<"Importe producto : "<<productos[i].precioProducto * productos[i].cantidadProducto<<endl;

    }

        archivo<<"Importe Total del ticket: "<<acumImporteTotal<<endl;


    //siempre que se produce una apertura o se disponibiliza un dato hay que cerrar la operacion
    archivo.close();

    ok=true;
    return ok;
 }