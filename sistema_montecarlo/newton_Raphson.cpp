#include <iostream>
#include <cmath>
#include "newton_Raphson.h"

using namespace std;

float newton_Raphson::raiz(float x,float e, int c){
	/*
	 * float x: valor inicial
	 * float e: error permitido
	 * int c:   numero maximo de ciclos
	 */

	int k = 0;

	while(fabsf(f(x)) > e && k < c){
		k++;
		if(df(x) != 0) x = x - f(x) / df(x);
		else x += e;
	}

	if(k == c)throw new string("no coverage!");
	else return x;
}

