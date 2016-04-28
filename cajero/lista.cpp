#include "lista.h"

lista::lista(){
    raiz = NULL;
}
void lista::insertar(string name,string nip,int clientN,double money){
    Nodo *aux;
    aux = new Nodo();
    aux -> name = name;
    aux -> nip = nip;
    aux -> clientNumber = clientN;
    aux -> money = money;
    if(raiz == NULL){
        raiz = aux;
        aux -> next = NULL;
    }
    else{
        aux -> next = raiz;
        raiz = aux;
    }
}
void lista::print(){
    Nodo *aux = raiz;
    cout <<"Listado de Clientes.\n";
    cout <<"Client Name        |Client NIP      |Client Number      |Client Money\n";
    cout <<"-------------------|----------------|-------------------|------------\n";
    while(aux != NULL){
        cout << aux -> name <<"\t   |"<<aux -> nip<<"\t    |"<<aux -> clientNumber<<"\t\t|"<<"$"<<aux -> money<<"\n";
        aux = aux -> next;
    }
}
void lista::showCInfo(int cNumber){
    Nodo *aux = raiz;
    while(aux != NULL){
        if(aux -> clientNumber == cNumber){
            cout <<"Client Name        |Client Number      |Client Money\n";
            cout <<"-------------------|-------------------|------------\n";
            cout << aux -> name <<"\t   |"<<aux -> clientNumber<<"\t       |"<<"$"<<aux -> money<<"\n";
        }

            aux = aux -> next;
    }
}
bool lista::deposit(int cNumber,double dep){
    Nodo *aux = raiz;
    while(aux != NULL){
        if(aux -> clientNumber == cNumber){
            aux -> money = aux -> money + dep;
            return true;
        }
            aux = aux -> next;
    }
    return false;
}
bool lista::cashWith(int cNumber,double cash){
    Nodo *aux = raiz;
    while(aux != NULL){
        if(aux -> clientNumber == cNumber){
            aux -> money = aux -> money - cash;
            return true;
        }
            aux = aux -> next;
    }
    return false;
}
bool lista::transfer(int c1,int c2,double cash){
    Nodo *aux = raiz;
    bool flag1 = false;
    bool flag2 = false;

    while(aux != NULL){
        if(aux -> clientNumber == c1){
            aux -> money = aux -> money - cash;
            flag1 = true;
        }
        else if(aux -> clientNumber == c2){
            aux -> money = aux -> money + cash;
            flag2 = true;
        }
        if(flag1 && flag2)return true;
            aux = aux -> next;
    }
    return false;
}
bool lista::validationC(int cNumber,string nip){
    Nodo *aux = raiz;

    while(aux != NULL){
        if(aux -> clientNumber == cNumber){
            if(aux -> nip == nip)return true;
            else return false;
        }
        else{
            aux = aux -> next;
        }
    }
    return false;
}
void lista::extraer(){
    //need to looking for client and showing theyr info
}
lista::~lista(){
    Nodo *aux = raiz;
    Nodo *kill;
    while(aux != NULL){
        kill = aux;
        aux = aux -> next;
        delete kill;
    }
}
