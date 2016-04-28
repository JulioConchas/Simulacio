#include <iostream>
#include <cstdlib>
//#include <Windows.h>
#include <ctime>

#define RANGO 1000

using namespace std;

float varianza(float suma){
    return suma/RANGO;
}
int main(){
    srand(time(NULL));
    float suma;
    float data;
    for(int i =0;i < RANGO;i++){
        data = (rand()/(double)RAND_MAX);
        cout <<data<<"-";
        suma += data;
        //Sleep(500);
    }
    cout <<"\nsuma:"<<suma<<endl;
    cout <<"Varialza:"<<varianza(suma)<<endl;
    return 0;
}
