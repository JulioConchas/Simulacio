#include <iostream>
#include <iomanip> //setprecision
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <conio.h>
#include "nR.h"

#define PRECISION 6

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
void tabula(double a,double b);
double f1(double x);
double f2(double x);

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
			case 5:{
				system("clear");
				cout<< " **** Muller **** \n";
				
				int i = 1;
				double x0,x1,x2,Eadm,n;
				double h0,h1,d0,d1,A,B,C,R,denominador,h,x3;

				cout <<"Ingrese x0:"; //0.5
				cin >> x0;
				cout <<"Ingrese x1:"; //-0.5
				cin >> x1;
				cout <<"Ingrese x2:";	//0.4
				cin >> x2;
				cout <<"Ingrese Eadm:";	//2
				cin >>Eadm;
				cout <<"Ingrese n:";	//5
				cin >>n;
				
				h0 = x1 - x0;
				h1 = x2 - x1;

				d0 = (f2(x1) - f2(x0)) / (x1 - x0);
				d1 - (f2(x2) - f2(x1)) / (x2 - x1);

				A = (d1 - d0) / (h1 + h0);
				
				i = 3;

				do{
					B = A * h1 + d1;
					C = f2(x2);
					R = sqrt((pow(B,2) - (4*A*C)));
					
					if((B + R) > (B - R))denominador = (B + R);
					else denominador = (B - R);	

					h = (-2*C) / denominador;
					x3 = x2 + h;

					if(Eadm > abs(h)){
						cout <<"x3 = "<<x3<<endl;
						cout <<"Interaciones = "<<i<<endl;
						break;
					}
					else{
						x0 = x1;
						x1 = x2;
						x2 = x3;
						h0 = x1 - x0;
						h1 = x2 - x1;
						d0 = (f2(x1) - f2(x0)) / h0;
						d1 = (f2(x2) - f2(x1)) / h1;
						A = (d1 = d0) / (h1 + h0);
						i++;
					}


				}while(i <= n);
					if(i == n){
					cout << "NeuN\n";
					cout << "Iteraciones: "<<n<<endl;
					}
			break;
			}
		/*	case 6:{
				system("clear");
				cout <<" **** Relajacion ****\n";
				
				int i = 0;
				double x,x1 = 0,x2 = 0,x3 = 0;
				double tol,MAXIT,w;

				while(i < MAXIT){
					x1 = -x2 / 5 + (2 / 5 * x3) - 1/5;
					x2 = -x1 / 3 + x3 / 2 + 1/3;
					x3 = (-2/7 * x1) - x2 / 7 + 32 / 7;
					
					x = (1 - w)
				}
				

			break;
			}*/
			case 7:{
				system("clear");
				cout << " **** Biseccion ****\n";
				cout <<"Ingrese el intervalo inicial [a,b]:\n";
				cout << setprecision(PRECISION);

				double a,b,tolerancia;
				cout <<"a = ";
				cin >> a;
				cout <<"b = ";
				cin >>b;

				tabula(a,b);
				
				cout <<"Escoja el intervalo adecuado"<<endl;
				cout <<"a =";
				cin >>a;
				cout <<"b =";
				cin >>b;
				
				double xr;

				if(f1(a) * f1(b) > 0)cout <<"No se puede aplicar por que tienen el mismo signo"<<endl;
				else{
					cout <<"Tolerancia =";
					cin >>tolerancia;
					
					cout <<"a\tb\tx\tf(a)\t\tf(b)\t\tf(x)"<<endl<<endl;

					do{
						
						xr = (a + b) / 2.0;
						
						cout <<a<<"\t"<<b<<"\t"<<xr<<"\t"<<f1(a)<<"\t"<<f(b)<<"\t"<<f(xr)<<endl;

						if(abs(f1(xr)) <= tolerancia){
							cout <<"Para una tolerancia "<<tolerancia<<" la raiz de f es "<<xr<<endl;
							break;
						}
						else{
							if(f1(xr) * f1(a) > 0)a = xr;
							else if(f1(xr) * f1(b) > 0)b = xr;
						}
					}while(1);
				}
			break;
			}
		}

return 0;
}
#define INTERVALOR 10

void tabula(double a,double b){
	int puntos = INTERVALOR + 1;
	double ancho = (b - a) / INTERVALOR;

	cout <<"\tx\tf(x)\n";
	for(int i =0;i < puntos;i++){
		cout <<"\t"<<a<<"\t"<<f1(a)<<endl;
		a = a + ancho;
	}
}
double f1(double x){
	return exp(-1 * x) - cos(3 * x) - 0.5;
}
double f2(double x){
	return pow(x,3) - (13 * x) - 12;
}
