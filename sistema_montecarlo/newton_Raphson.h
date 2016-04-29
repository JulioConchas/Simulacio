#ifndef NEWR_H
#define NEWR_H

class newton_Raphson{
public:
	virtual float f(float ) = 0;
	virtual float df(float ) = 0;
	float raiz(float,float,int);
};
# endif
