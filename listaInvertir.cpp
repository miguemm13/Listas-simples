#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;	
};

void menu();
void insertarLista(Nodo *&,int);
void mostrarLista(Nodo *);
void invertirLista(Nodo *&);

Nodo *lista = NULL;      //Variables

int main(){
	int dato;
	char opcion;
	
	menu();
	
	return 0;
}

//Insertar elemento en la lista
void insertarLista(Nodo *&lista,int n){
	Nodo *nuevo_nodo = new Nodo();
	Nodo *aux;
	
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = NULL;
	
	if(lista == NULL){//Si la lista esta vacia
		lista = nuevo_nodo;//agregamos el primer nodo
	}
	else{
		aux = lista;
		while(aux->siguiente != NULL){//recorremos la lista hasta llegar al final
			aux = aux->siguiente;
		}
		aux->siguiente = nuevo_nodo;//agregamos el nuevo nodo al final de la lista
	}
	cout<<"\tElemento "<<n<<" agregado a lista correctamente\n";
}

//Mostrar todos los elementos de la lista
void mostrarLista(Nodo *lista){	
	Nodo *actual = new Nodo();
	
	actual = lista;
	while(actual != NULL){ //mientras no sea final de la lista
		cout<<actual->dato<<" -> "; //mostramos el dato
		actual = actual->siguiente; //avanzamos a la siguiente posicion de la lista
	}
}

// Invertir el orden de una lista enlazada de forma iterativa
void invertirLista(Nodo *&lista) {
    Nodo *anterior = nullptr;
    Nodo *actual = lista;
    Nodo *siguiente = nullptr;

    while (actual != nullptr) {
        siguiente = actual->siguiente; // Guardamos el siguiente nodo
        actual->siguiente = anterior;  // Cambiamos el puntero al nodo anterior
        anterior = actual;             // Movemos el puntero anterior al actual
        actual = siguiente;            // Movemos el puntero actual al siguiente
    }

    lista = anterior; // El último nodo se convierte en el nuevo primero
}

void menu(){
    int opcion,dato;

    do{
        cout<<"\t.:MENU:.\n";
        cout<<"1. Insertar elemento al principio de la lista\n";
        cout<<"2. Mostrar elementos de la lista\n";
        cout<<"3. Invertir la lista\n"; // Nueva opción
        cout<<"4. Salir\n";
        cout<<"Opcion: ";cin>>opcion;

        switch (opcion){
        case 1: cout<<"Digite un numero para agregarlo al principio de la lista: ";
		        cin>>dato;
		        insertarLista(lista,dato);
                cout<<"\n";
                break;
        case 2: cout<<"\nElementos de la lista: \n";
	            mostrarLista(lista); //mostramos la lista
                cout<<"\n";
                break;
        case 3: invertirLista(lista); // Invertir la lista
                cout << "La lista ha sido invertida correctamente.\n\n";
                break;
        }
    }while(opcion != 4 );

}
