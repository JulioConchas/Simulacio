#include <iostream>
#include <cstdlib>
#include "nR.h"

using namespace std;
 

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
				cin.get();
			break;
		/*	case 2:
				system("clear");
				cout << " **** Simpson ****\n";
				//agregar simpson.cpp
			break;
			case 3:
				system("clear");
				cout <<" **** Secane ****\n";
				//agregar secante.cpp
			break;
			case 4:
			break;
			case 5:
			break;
			case 6:
			break;
			case 7:
			break;	*/
		}

return 0;
}

