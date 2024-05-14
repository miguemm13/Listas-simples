#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
    Nodo *anterior; // Nuevo puntero al nodo anterior
};

void menu();
void insertarLista(Nodo *&, Nodo *&, int);
void mostrarLista(Nodo *);
void borrarNodo(Nodo *&, Nodo *&, int);

Nodo *lista = NULL;      //Variables
Nodo *ultimo = NULL;     // Variable para mantener el puntero al último nodo

int main(){
	int dato;
	char opcion;
	
	menu();
	
	return 0;
}

//Insertar elemento en la lista
void insertarLista(Nodo *&lista, Nodo *&ultimo, int n){
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = NULL;
    nuevo_nodo->anterior = NULL; // El nodo anterior del nuevo nodo se inicializa como NULL

	if(lista == NULL){//Si la lista esta vacia
		lista = nuevo_nodo;
        ultimo = nuevo_nodo; // El último nodo es el primero en una lista vacía
	}
	else{
        nuevo_nodo->anterior = ultimo; // El nodo anterior del nuevo nodo es el actual último nodo
		ultimo->siguiente = nuevo_nodo;
        ultimo = nuevo_nodo; // Ahora el nuevo nodo es el último de la lista
	}
	cout<<"\tElemento "<<n<<" agregado a lista correctamente\n";
}

//Mostrar todos los elementos de la lista
void mostrarLista(Nodo *lista){	
	Nodo *actual = lista;
	
	while(actual != NULL){ //mientras no sea final de la lista
		cout<<actual->dato<<" -> "; //mostramos el dato
		actual = actual->siguiente; //avanzamos a la siguiente posicion de la lista
	}
}

//Borrar Nodo
void borrarNodo(Nodo *&lista, Nodo *&ultimo, int n){
	//preguntar si la lista no esta vacia 
	if(lista != NULL){
		Nodo *aux_borrar = lista;
		
		//recorrer la lista 
		while((aux_borrar != NULL) && (aux_borrar->dato != n)){
			aux_borrar = aux_borrar->siguiente;
		}
		//el elemento no ha sido encontrado 
		if(aux_borrar == NULL){
			cout<<"El elemento no ha sido encontrado";
		}
		//el primer elemento es el que vamos a borrar 
		else if(aux_borrar == lista){
			lista = lista->siguiente;
            if (lista != NULL)
                lista->anterior = NULL; // Si el nuevo primer nodo no es NULL, su anterior es NULL
			delete aux_borrar;
		}
		//El elemento esta en la lista pero no es el primer nodo
		else{
            aux_borrar->anterior->siguiente = aux_borrar->siguiente;
            if (aux_borrar->siguiente != NULL)
                aux_borrar->siguiente->anterior = aux_borrar->anterior;
            else
                ultimo = aux_borrar->anterior; // Si el nodo que vamos a borrar era el último, actualizamos 'ultimo'
			delete aux_borrar;
			cout<<"elemento borrado";
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
		        insertarLista(lista, ultimo, dato);
                cout<<"\n";
                break;
        case 2: cout<<"\nElementos de la lista: \n";
	            mostrarLista(lista); //mostramos la lista
                cout<<"\n";
                break;
		case 3: cout<<"\nDigite el elemento que sea eliminar: ";
				cin>>dato;
				borrarNodo(lista, ultimo, dato);
				cout<<"\n";
				break;
        }
    }while(opcion != 4 );

}
