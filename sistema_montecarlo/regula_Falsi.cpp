#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

double f(double x){
	return -(x * x) - (2 * x) + 1;
}

int main(){
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
	


return 0;
}
