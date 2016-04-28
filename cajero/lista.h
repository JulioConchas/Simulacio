#include <iostream>
#include <string>

using namespace std;

class lista{
private:
    class Nodo{
    public:
        string name,nip;
        int clientNumber;
        double money;
        Nodo *next;
    };
    Nodo *raiz;
public:
    lista();
    ~lista();
    void insertar(string,string,int,double);
    void extraer();
    void print();
    bool validationC(int,string);
    void showCInfo(int);
    bool deposit(int,double);
    bool transfer(int,int,double);
    bool cashWith(int,double);
};
