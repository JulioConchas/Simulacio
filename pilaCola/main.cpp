#include <iostream>
#include <Windows.h>
#include "stack.h"
#include "queue.h"

using namespace std;

int main(){

    // cout << "countdown:\n";
    // for(int i = 10;i > 0; --i){
    //     cout <<i << endl;
    //     Sleep(5000);
    // }
    // cout << "Lift off!\n";
    stack *st = new stack();
    queue *qe = new queue();
    int counter = 0;
    while(counter != 101){
            system("cls");
            cout <<"LIFO"<<endl;
            st -> insertar('|');
            st -> print();
            cout <<counter<<"%"<<endl;
            Sleep(50);
            cout <<"FIFO"<<endl;
            qe -> insertar('|');
            qe -> print();
            cout <<counter<<"%"<<endl;
            counter++;
    }

    return 0;
}
