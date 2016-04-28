#include <iostream>
#include "stack.h"

using namespace std;

stack::stack(){
    raiz = NULL;
}
void stack::insertar(char data){
    Nodo *aux;
    aux = new Nodo();
    aux -> data = data;
    if(raiz == NULL){
        raiz = aux;
        aux -> next = NULL;
    }
    else{
        aux -> next = raiz;
        raiz = aux;
    }
}
void stack::extraer(){
    Nodo *aux = raiz;
    raiz = aux -> next;
    cout << aux -> data <<endl;
    delete aux;
}
void stack::print(){
    Nodo *aux = raiz;
    while(aux != NULL){
        cout << aux -> data;
        aux = aux -> next;
    }
    cout <<endl;
}
stack::~stack(){
    Nodo *aux = raiz;
    Nodo *kill;
    while(aux != NULL){
        kill = aux;
        aux = aux -> next;
        delete kill;
    }
}
