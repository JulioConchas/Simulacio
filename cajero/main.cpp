#include <iostream>
#include "lista.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include <conio.h>


using namespace std;

#define MAX_LENGTH       4
#define ENTER           13
#define BACKSPACE        8

class cajero{
    int option,cNumber;
    lista *customers;
    string name,nip;
    double money,deposit;
public:
    cajero();
    void menu();
    void menuATM();
    void setTitle();
    void adminValidation();
    void newClientR();
    void cOperations();
    void stop();
    void cashCheker();
    void deposits();
    void fundsTransfer();
    void cashWithdrawal();
    string hiddenPass();
};
cajero::cajero(){
    customers = new lista();
    srand(time(NULL));
    setTitle();
}
void cajero::setTitle(){
    system("cls");
    cout <<"-------- BanPatito ----------\n\n";
}
void cajero::menu(){
    bool flag = false;
    while(!flag){
        setTitle();
        cout <<"----------- Menu ------------\n";
        cout <<"Client press..............(1)"<<"\n";
        cout <<"New Client press..........(2)"<<"\n";
        cout <<"Admin press...............(3)"<<"\n";
        cout <<"Exit......................(4)"<<"\n";
        cin >>option;

        if(option == 1){
            cOperations();
            cin.get();
            cin.get();
        }
        else if(option == 3){
            setTitle();
            adminValidation();
            cin.get();
            cin.get();
        }
        else if(option == 4){
            flag = true;
        }
        else{
            newClientR();
        }
    }
}
void cajero::menuATM(){
    bool flag = false;
    while(!flag){
        setTitle();
        cout <<"--------- Menu ATM ----------\n";
        cout <<"Cash check................(1)"<<"\n";
        cout <<"Deposits..................(2)"<<"\n";
        cout <<"Cash withdrawal...........(3)"<<"\n";
        cout <<"Funds transfer............(4)"<<"\n";
        cout <<"Exit......................(5)"<<"\n";
        cin >>option;

        if(option == 1){
            cashCheker();
        }
        else if(option == 3){
            cashWithdrawal();
        }
        else if(option == 4){
            fundsTransfer();
        }
        else if(option == 5)flag = true;
        else{
            deposits();
        }
    }
}

void cajero::cOperations(){
    setTitle();
    cout <<"------------ ATM ------------\n";
    cout <<"Please enter you client number!\n";
    cin >>cNumber;
    cout <<"Please enter you'r NIP:\n";
    nip = hiddenPass();
    cout <<"\n";
    if(customers -> validationC(cNumber,nip)){
        setTitle();
        cout <<"------------ ATM ------------\n";
        menuATM();
        //customers -> showCInfo(cNumber);
    }
    else{
        cout <<"\nSomething wrong!.";
    }
}
void cajero::cashWithdrawal(){
    setTitle();
    cout <<"----- Cash withdrawal -------\n";
    cout <<"Enter deposit cash!\n";
    cin >>deposit;
    if(customers -> cashWith(cNumber,deposit)){
        cout <<"cash Withdrawal successfull\n";
    }
    else{
        cout <<"Something wrong!\n";
    }
    stop();
}
void cajero::fundsTransfer(){
    int cNumber2;
    setTitle();
    cout <<"----- Funds transfer --------\n";
    cout <<"Enter transfer cash!\n";
    cin >>deposit;
    cout <<"Enter transfer account!\n";
    cin >>cNumber2;
    if(customers -> transfer(cNumber,cNumber2,deposit)){
        cout <<"Transfer successfull\n";
    }
    else{
        cout <<"Something wrong!\n";
    }
    stop();
}
void cajero::deposits(){
    setTitle();
    cout <<"--------- Deposit -----------\n";
    cout <<"Enter deposit cash!\n";
    cin >>deposit;
    if(customers -> deposit(cNumber,deposit)){
        cout <<"Deposit successfull\n";
    }
    else{
        cout <<"Something wrong!\n";
    }
    stop();
}
void cajero::cashCheker(){
    setTitle();
    cout <<"------- Cash cheker ---------\n";
    customers -> showCInfo(cNumber);
    stop();
}
void cajero::newClientR(){
    setTitle();
    cout <<"-- New client registration --\n";
    cout <<"Enter you'r name!\n";
    cin.get();
    getline(cin,name);
    cNumber = 100000 + rand() % (10000001 - 100000);
    /*
    De forma general es:
    variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
    */
    cout <<"Enter you'r NIP (four digits):\n";
    nip = hiddenPass();
    //nip = getch("Enter you'r NIP:");
    cout <<"\nEnter you'r money!\n";
    cin >>money;
    customers -> insertar(name,nip,cNumber,money);
    setTitle();
    cout <<"----- New account detalls ---\n";
    cout <<"Name: "<<name<<"\n"<<"Client Number: "<<cNumber<<"\n"<<"NIP:****"<<"\n"<<"Saldo: "<<money<<"\n";
    //customers -> print();
    cin.get();
    cin.get();
}
void cajero::adminValidation(){
    string adminPass = "1234";
    cout <<"----------- Admin -----------\n";
    cout <<"Enter admin password\n";
        if(adminPass != hiddenPass()){
            cout <<"\nAccess denied!\n";
        }
        else{
            cout <<"\n";
            customers -> print();
        }
}
string cajero::hiddenPass(){
    char ch;
    char password[MAX_LENGTH];
    int pos = 0;

    while(true){
        ch = getch();
        /*if(pos >= MAX_LENGTH){
            cout <<'\a';
            continue;
        }*/
        if(ch == ENTER)break;
        else if(ch==BACKSPACE)  /* BACKSPACE was pressed*/
        {
          cout <<"\b \b";
          password[--pos]='\0';
        }
        else {
            cout <<"*";
            password[pos] = ch;
            pos++;
            //password[pos] = '\0';
        }
        if(pos <= 0)pos = 0;
    }
    string pass = password;
    return pass;
    //cout.flush();
    //cin.get();
}
void cajero::stop(){
    cin.get();
    cin.get();
}
int main(){
    cajero cj;
    cj.menu();
    return 0;
}
