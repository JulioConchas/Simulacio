#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <conio.h>
#include "nR.h"


using namespace std;

float fun (float x){
	float f;
//	f = x * x - 4;
	f = pow(x,3) + 2 * pow(x,2) + 10 * x - 20;
	return f;
}
double f(double x){
	return -(x * x) - (2 * x) + 1;
}

int main(){

	int option;

	cout << " **** Montecarlo system **** \n";
	cout <<"Newton raphson...............(1)\n";
	cout <<"Simpson......................(2)\n";
	cout <<"Secante......................(3)\n";
	cout <<"Regula Falsi.................(4)\n";
	cout <<"Muller.......................(5)\n";
	cout <<"Relajacion...................(6)\n";
	cout <<"Biseccion....................(7)\n";
	cin >>option;

		switch(option){

			case 1:
			{
				system("clear");
				cout << " **** Newton Raphson **** \n";
				nR n;
				float r;
				try{
					r = n.raiz(1,1e-6,100);
					cout <<"raiz ="<< r <<" function ="<<n.f(r)<<endl;
				}catch(string* s){
					cout <<"Error:"<<* s;
				}
				break;
			}
			case 2:{
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
							if(i%2!=0){
								f = 4*xi/sqrt(1+xi*xi*xi*xi);
								cout <<"here\n";
								}
							else if(i%2==0){
								f = (2*xi)/sqrt(1+xi*xi*xi*xi);
								cout <<"here1\n";
								}
							else if(i == 0){
								f = xi/sqrt(1+xi*xi*xi*xi);
								cout <<"here2\n";
								}
							else if(i == N){
								f = xi/sqrt(1+xi*xi*xi*xi);
								cout <<"here3\n";
								}
							}
							cout <<"efe"<<f<<endl;
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

			break;
			}
			case 3:{
				system("clear");
				cout <<" **** Secane ****\n";
				float error = 0.00001,x0,x1,x2,Ea;
				int n = 0;

				cout <<"Ingresa el primer valor x0\n";
				cin >>x0;
				cout <<"Ingresa el segundo valor x1\n";
				cin >>x1;

				Ea = error + 1;

				cout << "n	x0	x1	x2	error\n";
				cout <<n<<"\t"<<x0<<"\t"<<"-----\t"<<"-----\n";
				n++;
				while(Ea > error){
					x2 = (x1 - ((x0 - x1) / (fun(x0) - fun(x1)) * fun(x1)));
					cout <<n<<"\t"<<x0<<"\t"<<x1<<"\t"<<x2<<"\t"<<Ea<<endl;
					Ea = (fabs(x1 - x2));
					x0 = x1;
					x1 = x2;
					n++;
				}
			//	cout <<"La raiz es: "<<x2<<endl;
			break;
			}
			case 4:{
					system("clear");
					cout <<" **** Regula Falsi ****\n";
				double a = 0,b = 2,  c = 0; 	//[a,b] es el intervalo tal que f(a)* f(b) < 0
				if(f(a)*f(b) > 0){
					cout << "No se cumple que f(a) * f(b) > 0. Trate con otro interalo.\n";
					return 0;
				}
				while(1 > 0){
				//Iteramos segun el metodo de la regla falasa
					c = ((f(b) * a) - (f(a) * b)) / (f(b) - f(a));
				if(f(c) <= 1e-10){
					cout << "La raiz aproximada es r = "<<c<<endl;
					cout << "El valor de f en r = "<<f(c)<<endl;
					return 0;
				}
				if(f(a) * f(c) < 0){
					b = c;
				}
				else{
					a = c;
				}

				}
			break;
			}
	/*		case 5:
			break;
			case 6:
			break;
			case 7:
			break;	*/
		}

return 0;
}
