#include <iostream>
#include "queue.h"

using namespace std;

queue::queue(){
    raiz = NULL;
    fondo = NULL;
}
void queue::insertar(char data){
    Nodo *aux;
    aux = new Nodo();
    aux -> data = data;
    aux -> next = NULL;
    if(empty()){
        raiz = aux;
        fondo = aux;
    }
    else{
        fondo -> next = aux;
        fondo = aux;
    }
}
int queue::extraer(){
    if(!empty()){
        int info = raiz -> data;
        Nodo *bor = raiz;
        if(raiz == fondo){
            raiz == NULL;
            fondo = NULL;
        }
        else{
            raiz = raiz -> next;
        }
        delete bor;
        return info;
    }
    else return -1;
}
void queue::print(){
    Nodo *reco = raiz;
    while(reco != NULL){
        cout <<reco -> data;
        reco = reco -> next;
    }
    cout <<endl;
}
bool queue::empty(){
    if (raiz == NULL)return true;
    else return false;
}
queue::~queue(){
    Nodo *reco = raiz;
    Nodo *bor;
    while(reco != NULL){
        bor = reco;
        reco = reco -> next;
        delete bor;
    }
}
