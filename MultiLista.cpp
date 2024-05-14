#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

void menu();
void insertarLista(Nodo *&, int);
void mostrarLista(Nodo *);
void borrarNodo(Nodo *&, int);

Nodo *lista = NULL;      //Variables
Nodo *ultimo = NULL;     // Variable para mantener el puntero al último nodo

int main(){
	int dato;
	char opcion;
	
	menu();
	
	return 0;
}

//Insertar elemento en la lista
void insertarLista(Nodo *&lista, int n){
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->dato = n;
	
	if(lista == NULL){//Si la lista esta vacia
		lista = nuevo_nodo;
        nuevo_nodo->siguiente = nuevo_nodo; // Apunta a sí mismo en una lista vacía
		ultimo = nuevo_nodo;
	}
	else{
		// El último nodo apunta al nuevo nodo y el nuevo nodo apunta al primer nodo de la lista
		ultimo->siguiente = nuevo_nodo;
		nuevo_nodo->siguiente = lista;
		ultimo = nuevo_nodo; // El nuevo nodo ahora es el último de la lista
	}
	cout<<"\tElemento "<<n<<" agregado a lista correctamente\n";
}

//Mostrar todos los elementos de la lista
void mostrarLista(Nodo *lista){	
	Nodo *actual = lista;
	
	do { // Utilizamos do-while para asegurarnos de imprimir al menos una vez en una lista no vacía
		cout << actual->dato << " -> "; //mostramos el dato
		actual = actual->siguiente; //avanzamos al siguiente nodo
	} while (actual != lista); // Detenemos el bucle cuando volvemos al primer nodo
}

//Borrar Nodo
void borrarNodo(Nodo *&lista, int n){
	//preguntar si la lista no esta vacia 
	if(lista != NULL){
		Nodo *aux_borrar = lista;
		Nodo *anterior = NULL;

		//recorrer la lista 
		while(aux_borrar->siguiente != lista){
			anterior = aux_borrar;
			aux_borrar = aux_borrar->siguiente;
		}
		//el primer elemento es el que vamos a borrar 
		if(aux_borrar == lista){
			if (lista->siguiente == lista){ // Si solo hay un nodo en la lista
				delete aux_borrar;
				lista = NULL;
			} else {
				Nodo *temp = lista;
				while (temp->siguiente != lista)
					temp = temp->siguiente;
				temp->siguiente = lista->siguiente;
				lista = lista->siguiente;
				delete aux_borrar;
			}
		}
		else{
			anterior->siguiente = aux_borrar->siguiente;
			delete aux_borrar;
		}
	}
}

void menu(){
    int opcion,dato;

    do{
        cout<<"\t.:MENU:.\n";
        cout<<"1. Insertar elemento a la lista\n";
        cout<<"2. Mostrar elemento de la lista\n";
		cout<<"3. Eliminar elemento de la lista\n";
        cout<<"4. Salir\n";
        cout<<"Opcion: ";cin>>opcion;

        switch (opcion){
        case 1: cout<<"Digite un numero para agregarlo a lista: ";
		        cin>>dato;
		        insertarLista(lista, dato);
                cout<<"\n";
                break;
        case 2: cout<<"\nElementos de la lista: \n";
	            mostrarLista(lista); //mostramos la lista
                cout<<"\n";
                break;
		case 3: cout<<"\nDigite el elemento que desea eliminar: ";
				cin>>dato;
				borrarNodo(lista, dato);
				cout<<"\n";
				break;
        }
    }while(opcion != 4 );
}
