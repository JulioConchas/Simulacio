#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

float fun (float x){
	float f;
//	f = x * x - 4;
	f = pow(x,3) + 2 * pow(x,2) + 10 * x - 20;
	return f;
}

int main(){
	
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

return 0;
}
