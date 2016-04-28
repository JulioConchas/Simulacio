#include <iostream>
#include <cstdlib>
#include <ctime>
#include "matriz.h"

using namespace std;

matriz::matriz(){
    srand(time(NULL));

    for(int i = 0;i < 3;i++){
        for(int c = 0;c < 5;c++){
            mat[i][c] = 100 + rand() % (201 - 100);
        }
    }

}
void matriz::matrisDinamica(){
    cout << "Ingresa las filas:\n";
    cin >>rows;
    cout << "Incresa las columnas:\n";
    cin >>columns;

    double **M = new double *[rows];
    for (int i = 0;i < rows;i++){
        M[i] = new double [columns];
    }
    if(!M){
        cout << "No se puede reservar el espacio"<< endl;
    }
    for(int i = 0;i < rows;i++){
        for(int c = 0;c < columns;c++){
            M[i][c] = 1000 + rand() % (2001 - 1000);
        }
    }
    cout <<"------------------------------------\n";
    cout <<"\nMatriz dinamica:\n";
    for(int i = 0;i < rows;i++){
        for(int c = 0;c < columns;c++){
            cout <<M[i][c];
        }
        cout <<endl;
    }

    delete [] M;
}
void matriz::operaciones(){
    cout << "Ingresa las filas:\n";
    cin >>rows;
    cout << "Incresa las columnas:\n";
    cin >>columns;
    double **M1 = new double *[rows];
    for (int i = 0;i < rows;i++){
        M1[i] = new double [columns];
    }
    double **M2 = new double *[rows];
    for (int i = 0;i < rows;i++){
        M2[i] = new double [columns];
    }
    double **M3 = new double *[rows];
    for (int i = 0;i < rows;i++){
        M3[i] = new double [columns];
    }
    if(!M1 || !M2 || M3){
        cout << "No se puede reservar el espacio"<< endl;
    }
    for(int i = 0;i < rows;i++){
        for(int c = 0;c < columns;c++){
            M1[i][c] = 1000 + rand() % (2001 - 1000);
        }
    }
    for(int i = 0;i < rows;i++){
        for(int c = 0;c < columns;c++){
            M2[i][c] = 1000 + rand() % (2001 - 1000);
        }
    }
    cout <<"------------------------------------\n";
    cout <<"Matriz1:\n";
    for(int i = 0;i < rows;i++){
        for(int c = 0;c < columns;c++){
            cout <<M1[i][c];
        }
        cout <<endl;
    }
    cout <<"------------------------------------\n";
    cout <<"Matriz2:\n";
    for(int i = 0;i < rows;i++){
        for(int c = 0;c < columns;c++){
            cout <<M2[i][c];
        }
        cout <<endl;
    }
    cout <<"------------------------------------\n";
    cout <<"Suma!\n";
    for(int i = 0;i < rows;i++){
        for(int c = 0;c < columns;c++){
            M3[i][c] = M1[i][c] + M2[i][c];
        }
    }
    for(int i = 0;i < rows;i++){
        for(int c = 0;c < columns;c++){
            cout <<M3[i][c];
        }
        cout <<endl;
    }
    cout <<"------------------------------------\n";
    cout <<"Resta!\n";
    for(int i = 0;i < rows;i++){
        for(int c = 0;c < columns;c++){
            M3[i][c] = M1[i][c] - M2[i][c];
        }
    }
    for(int i = 0;i < rows;i++){
        for(int c = 0;c < columns;c++){
            cout <<M3[i][c];
        }
        cout <<endl;
    }
    cout <<"------------------------------------\n";
    cout <<"Multiplicacion!\n";
    for(int i = 0;i < rows;i++){
        for(int c = 0;c < columns;c++){
            M3[i][c] = M1[i][c] * M2[i][c];
        }
    }
    for(int i = 0;i < rows;i++){
        for(int c = 0;c < columns;c++){
            cout <<M3[i][c];
        }
        cout <<endl;
    }
    cout <<"------------------------------------\n";
    cout <<"Divicion!\n";
    for(int i = 0;i < rows;i++){
        for(int c = 0;c < columns;c++){
            M3[i][c] = M1[i][c] / M2[i][c];
        }
    }
    for(int i = 0;i < rows;i++){
        for(int c = 0;c < columns;c++){
            cout <<M3[i][c];
        }
        cout <<endl;
    }
}
void matriz::print(){
    cout <<"------------------------------------\n";
    cout <<"Matriz estatica:\n";
    for(int i = 0;i < 3;i++){
        for(int c = 0;c < 5;c++){
            cout <<mat[i][c];
        }
        cout <<"\n";
    }

}
