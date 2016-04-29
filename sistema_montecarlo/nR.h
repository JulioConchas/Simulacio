#ifndef NEWT_H
#define NEWT_H
#include "newton_Raphson.h"

class nR:public newton_Raphson{
public:
	float f(float x){return x * x - 2;};   //Function
	float df(float x){return 2 * x;};      //Derivada  
};
# endif
