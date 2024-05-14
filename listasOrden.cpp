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
void borrarNodo(Nodo *&, int);
void insertarAlFinal(Nodo *&, int);
void insercionDirecta(Nodo *&);
void seleccionDirecta(Nodo *&);
void intercambioDirecto(Nodo *&);

Nodo *lista = NULL;      //Variables

int main(){
    menu();   
    return 0;
}

//Insertar elemento en la lista
void insertarLista(Nodo *&lista, int n) {
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = NULL;
    
    if (lista == NULL) { //Si la lista esta vacia
        lista = nuevo_nodo; //agregamos el primer nodo
    } else {
        Nodo *aux = lista;
        while (aux->siguiente != NULL) { //recorremos la lista hasta llegar al final
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo_nodo; //agregamos el nuevo nodo al final de la lista
    }
    cout << "\tElemento " << n << " agregado a lista correctamente\n";
}

//Mostrar todos los elementos de la lista
void mostrarLista(Nodo *lista) {    
    Nodo *actual = lista;
    while (actual != NULL) { //mientras no sea final de la lista
        cout << actual->dato << " -> "; //mostramos el dato
        actual = actual->siguiente; //avanzamos a la siguiente posicion de la lista
    }
}

//Borrar Nodo
void borrarNodo(Nodo *&lista, int n) {
    if (lista != NULL) { //preguntar si la lista no esta vacia 
        Nodo *aux_borrar;
        Nodo *anterior = NULL; 

        aux_borrar = lista;

        //recorrer la lista 
        while ((aux_borrar != NULL) && (aux_borrar->dato != n)) {
            anterior = aux_borrar;
            aux_borrar = aux_borrar->siguiente;
        }
        //el elemento no ha sido encontrado 
        if (aux_borrar == NULL) {
            cout << "El elemento no ha sido encontrado";
        }
        //el primer elemento es el que vamos a borrar 
        else if (anterior == NULL) {
            lista = lista->siguiente;
            delete aux_borrar;
        }
        //El elemento esta en la lista pero no es el primer nodo
        else {
            anterior->siguiente = aux_borrar->siguiente;
            delete aux_borrar;
            cout << "Elemento borrado";
        }
    }
}

// Insertar elemento al final de la lista
void insertarAlFinal(Nodo *&lista, int n) {
    insertarLista(lista, n);
}

// Algoritmo de Inserción Directa (Baraja)
void insercionDirecta(Nodo *&lista) {
    if (lista == NULL || lista->siguiente == NULL) // Si la lista está vacía o tiene un solo nodo, ya está ordenada
        return;

    Nodo *actual = lista->siguiente; // Empezamos desde el segundo nodo

    while (actual != NULL) {
        Nodo *temp = actual; // Guardamos el nodo actual
        int valor = actual->dato; // Valor a insertar
        Nodo *anterior = lista; // Empezamos desde el primer nodo

        // Buscamos la posición adecuada para insertar el valor
        while (anterior != actual && anterior->dato < valor) {
            anterior = anterior->siguiente;
        }

        while (anterior != actual) {
            int temp1 = anterior->dato;
            anterior->dato = valor;
            valor = temp1;
            anterior = anterior->siguiente;
        }

        actual->dato = valor; // Insertamos el valor en la posición correcta
        actual = actual->siguiente; // Pasamos al siguiente nodo
    }
}

// Algoritmo de Selección Directa
void seleccionDirecta(Nodo *&lista) {
    if (lista == NULL || lista->siguiente == NULL) // Si la lista está vacía o tiene un solo nodo, ya está ordenada
        return;

    Nodo *i = lista;
    while (i->siguiente != NULL) {
        Nodo *min = i;
        Nodo *j = i->siguiente;

        while (j != NULL) {
            if (j->dato < min->dato) {
                min = j;
            }
            j = j->siguiente;
        }

        if (min != i) {
            int temp = i->dato;
            i->dato = min->dato;
            min->dato = temp;
        }

        i = i->siguiente;
    }
}

// Algoritmo de Intercambio Directo (Burbuja)
void intercambioDirecto(Nodo *&lista) {
    if (lista == NULL || lista->siguiente == NULL) // Si la lista está vacía o tiene un solo nodo, ya está ordenada
        return;

    Nodo *actual = lista;
    while (actual->siguiente != NULL) {
        Nodo *siguiente = actual->siguiente;
        while (siguiente != NULL) {
            if (actual->dato > siguiente->dato) {
                int temp = actual->dato;
                actual->dato = siguiente->dato;
                siguiente->dato = temp;
            }
            siguiente = siguiente->siguiente;
        }
        actual = actual->siguiente;
    }
}

void menu() {
    int opcion, dato;

    do {
        cout << "\t.:MENU:.\n";
        cout << "1. Insertar elemento al principio de la lista\n";
        cout << "2. Insertar elemento al final de la lista\n";
        cout << "3. Mostrar elementos de la lista\n";
        cout << "4. Ordenar la lista con Insercion Directa (Baraja)\n";
        cout << "5. Ordenar la lista con Seleccion Directa\n";
        cout << "6. Ordenar la lista con Intercambio Directo (Burbuja)\n";
        cout << "7. Eliminar elemento de la lista\n";
        cout << "8. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: cout << "Digite un numero para agregarlo al principio de la lista: ";
                    cin >> dato;
                    insertarLista(lista, dato);
                    cout << "\n";
                    break;
            case 2: cout << "Digite un numero para agregarlo al final de la lista: ";
                    cin >> dato;
                    insertarAlFinal(lista, dato);
                    cout << "\n";
                    break;
            case 3: cout << "\nElementos de la lista: \n";
                    mostrarLista(lista); //mostramos la lista
                    cout << "\n";
                    break;
            case 4: insercionDirecta(lista);
                    cout << "Lista ordenada con Insercion Directa (Baraja)\n";
                    break;
            case 5: seleccionDirecta(lista);
                    cout << "Lista ordenada con Seleccion Directa\n";
                    break;
            case 6: intercambioDirecto(lista);
                    cout << "Lista ordenada con Intercambio Directo (Burbuja)\n";
                    break;
            case 7: cout << "\nDigite el elemento que desea eliminar: ";
                    cin >> dato;
                    borrarNodo(lista, dato);
                    cout << "\n";
                    break;
        }
    } while (opcion != 8);
}
