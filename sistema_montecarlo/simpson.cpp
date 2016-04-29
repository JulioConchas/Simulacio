#include <iostream>
#include <cmath>
#include <cstdio>
#include <conio.h>

using namespace std;

int main(){

//x / raiz^2 de 1 + x^4

	int N,i;
	double a,b,suma,f,xi,h;
	char d;
		
		do{
			cout << "Ingrese el limite inferior de la Integral definida:\n";
			cin>> a;
			cout << "Ingrese el limite Superior de la integral definida:\n";
			cin >>b;
			cout << "Ingrese un numero par de iteraciones : \n";
			cin>> N;

			h = (b -a )/N;
			suma = 0;
			i = 0;
			for(i = 0;i <= N;i++){
				{
				if(i%2!=0)f = 4*xi/sqrt(1+xi*xi*xi*xi);
				else if(i%2==0)f = 2*xi/sqrt(1+xi*xi*xi*xi);
				else if(i == 0)f = xi/sqrt(1+xi*xi*xi*xi);
				else if(i == N)f = xi/sqrt(1+xi*xi*xi*xi);
				}
				xi = a + i*h;
				suma = suma + f;
			}
			cout <<"Los valore son los siguientes :"<<endl<<endl;
			cout <<"a = "<<a<<endl;
			cout <<"b = "<<b<<endl;
			cout <<"h = "<<h<<endl<<endl<<endl;
			cout <<"La suma es = "<<suma<<endl;
			cout <<"la integral es = "<<suma * h/3<<endl;
			cout <<"Desea hacer otra operacion s/n"<<endl;
			cin >>d;
		}while(d != 'n');
	

return 0;
}
