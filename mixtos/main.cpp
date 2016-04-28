#include <iostream>

using namespace std;

#define CONSTANTE 7
#define A 5
#define MODULO 8

int main(){
    int semilla,data,cont = 1;
    cout <<"Enter semilla\n";
    cin >>semilla;
    cout <<"-----------------"<<endl;
    cout <<"| 0 | Xn |      |"<<endl;
    cout <<"-----------------"<<endl;
    while (semilla != 0){
        data = (semilla * A) +  CONSTANTE;
        semilla = ((semilla * A) +  CONSTANTE) % MODULO;
        cout <<"| "<<cont<<" | "<<semilla<<"  | "<<semilla<<"/"<<data<<" |"<<endl;
        cont++;
    }
    cout <<"-----------------"<<endl;

    return 0;
}
