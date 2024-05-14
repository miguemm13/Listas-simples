#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

struct Nodo {
    int dato;
    Nodo *siguiente;	
};

void menu();
void insertarLista(Nodo *&, int);
void mostrarLista(Nodo *);
void reorganizarLista(Nodo *&);
Nodo *lista = NULL; // Variable global

int main() {
    menu();	
    return 0;
}

// Insertar elemento en la lista
void insertarLista(Nodo *&lista, int n) {
    Nodo *nuevo_nodo = new Nodo();
    Nodo *aux;
	
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = NULL;
	
    if (lista == NULL) { // Si la lista esta vacia
        lista = nuevo_nodo; // Agregamos el primer nodo
    } else {
        aux = lista;
        while (aux->siguiente != NULL) { // Recorremos la lista hasta llegar al final
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo_nodo; // Agregamos el nuevo nodo al final de la lista
    }
    cout<<"\tElemento "<<n<<" agregado a lista correctamente\n";
}

// Mostrar todos los elementos de la lista
void mostrarLista(Nodo *lista) {
    Nodo *actual = new Nodo();
    actual = lista;
    while (actual != NULL) { // Mientras no sea final de la lista
        cout<<actual->dato<<" -> "; // Mostramos el dato
        actual = actual->siguiente; // Avanzamos a la siguiente posición de la lista
    }
}

// Función para reorganizar la lista
void reorganizarLista(Nodo *&lista) {
    Nodo *par = NULL;
    Nodo *impar = NULL;
    Nodo *temp = lista;
	
    while (temp != NULL) {
        if (temp->dato % 2 == 0) { // Si el dato es par
            insertarLista(par, temp->dato); // Insertar al principio de la lista de pares
        } else {
            insertarLista(impar, temp->dato); // Insertar al principio de la lista de impares
        }
        temp = temp->siguiente;
    }
	
    // Concatenar la lista de pares con la lista de impares
    if (par != NULL) {
        temp = par;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = impar;
        lista = par;
    } else {
        lista = impar;
    }
}

void menu() {
    int opcion, dato;
    do {
        cout<<"\t.:MENU:.\n";
        cout<<"1. Insertar elemento al principio de la lista\n";
        cout<<"2. Mostrar elementos de la lista\n";
        cout<<"3. Reorganizar lista (pares al principio, impares al final)\n";
        cout<<"4. Salir\n";
        cout<<"Opcion: ";
        cin>>opcion;
		
        switch (opcion) {
            case 1: cout<<"Digite un numero para agregarlo al principio de la lista: ";
                    cin>>dato;
                    insertarLista(lista, dato);
                    cout<<"\n";
                    break;
            case 2: cout<<"\nElementos de la lista: \n";
                    mostrarLista(lista); // Mostramos la lista
                    cout<<"\n";
                    break;
            case 3: reorganizarLista(lista); // Reorganizamos la lista
                    cout<<"\nLa lista ha sido reorganizada correctamente.\n";
                    break;
        }
    } while (opcion != 4);
}
