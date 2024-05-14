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
void borrarNodo(Nodo *&,int);

Nodo *lista = NULL;      //Variables

int main(){
	Nodo *lista = NULL;
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

//Borrar Nodo
void borrarNodo(Nodo *&lista, int n){
	//preguntar si la lista no esta vacia 
	if(lista != NULL){
		Nodo *aux_borrar;
		Nodo *anterior = NULL; 

		aux_borrar = lista;

		//recorrer la lista 
		while((aux_borrar != NULL) && (aux_borrar->dato != n)){
			anterior = aux_borrar;
			aux_borrar = aux_borrar->siguiente;
		}
		//el elemento no ha sido encontrado 
		if(aux_borrar == NULL){
			cout<<"El elemento no ha sido encontrado";
		}
		//el primer elemento es que vamos a borrar 
		else if(anterior == NULL){
			lista = lista->siguiente;
			delete aux_borrar;
		}
		//El elemento esta en la lista pero no es el primer nodo
		else{
			anterior->siguiente = aux_borrar->siguiente;
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
        cout<<"3. Salir\n";
        cout<<"Opcion: ";cin>>opcion;

        switch (opcion){
        case 1: cout<<"Digite un numero para agregarlo a listaa: ";
		        cin>>dato;
		        insertarLista(lista,dato);
                cout<<"\n";
                break;
        case 2: cout<<"\nElementos de la lista: \n";
	            mostrarLista(lista); //mostramos la lista
                cout<<"\n";
                break;
		case 3: cout<<"\nDigite el elemento que sea eliminar: ";
				cin>>dato;
				borrarNodo(lista,dato);
				cout<<"\n";
				break;
        }
    }while(opcion != 4 );

}