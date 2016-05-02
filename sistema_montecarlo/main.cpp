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
			case 5:{
				system("clear");
				cout<< " **** Muller **** \n";

				int i,MAXIT;
				double x0,x1,x2,x3,A,B,C,D,E,H0,H1;
				double Fx0,Fx1,Fx2,Fx3,F10,F21,F210;
				double A0,A1,A2,D0,D1;
				double EA,EA1;

				cout <<"\n\t\t METODO DE MULLER";
				cout <<"\n\n FUNCION f(x) = x5 + x2 - 1";
	
				cout <<"\n\n Ingrese el valor para x0 = ";
				cin >> x0;
				cout <<"\n\n Ingrese el valor para x1 ";
				cin >>x1;
				cout <<"\n\n Ingrese el valor para x2 ";
				cin >>x2;
				cout <<"\n\n Ingrese numero de iteraciones ";
				cin >> MAXIT;

				i = 1;
				while(i <= MAXIT){
					Fx0 = pow(x0,5) + pow(x0,2) - 1;
					Fx1 = pow(x1,5) + pow(x1,2) - 1;
					Fx2 = pow(x2,5) + pow(x2,2) - 1;

					F10 = (Fx1 - Fx0) / (x1 - x0);
					F21 = (Fx2 - Fx1) / (x2 - x1);
					F210 = (F21 - F10) / (x2 - x0);

					H0 = x1 - x0;
					H1 = x2 - x1;

					
					D0 = (Fx1 - Fx0) / H0;
					D1 = (Fx2 - Fx1) / H1;
					
					A = (D1 - D0) / (H1 + H0);	
					B = (A * H1) + D1;
					C = Fx2;

					if(B > C){
						x3 = (2 * A0) / D1;
					}
					else{
						x3 = (2 * A0) / D2;
					}
					Fx3 = pow(x3,3) + pow(x3,2) - 5 * x3 + 20;

					D = abs(x3 - x0);
					E = abs(Fx3);

					if((D < EA1) || (E < EA1)){
						cout << "\n\n calor de x: "<<x3<<endl<<endl;
						cout << "\n\n El numero de iteracion encontrado: "<<i<<endl;
						break;						
					}
					x0 = x1;
					x1 = x2;
					x2 = x3;

					i++;

				
				}
				cout << "El sistema no converge "<<MAXIT<<" Iteraciones.\n";
				cout << "El ultimo valor encontrado para x: "<<x3<<endl;
				
			break;
			}
	/*		case 6:
			break;
			case 7:
			break;	*/
		}

return 0;
}
