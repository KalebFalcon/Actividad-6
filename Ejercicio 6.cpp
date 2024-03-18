/******************************************************************************
//actividad 6
Nombre: Kaleb Alejandro Falcon Marquez
Fecha: 26/02/2024
Programa: Calculadora de dos matrices
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION / SEGUNDO SEMESTRE
Profesor: CARLOS JAVIER CRUZ FRANCO
Descripcion: Una calculadora de matrices, basada en coordenadas, suma, resta,
multiplicacion.
*******************************************************************************/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
using namespace std;

int matrizA[10][10];
int matrizB[10][10];
int AC, AF;
int BC, BF;
int ingresarAF, ingresarAC;
int ingresarBF, ingresarBC;
int opcion;
int suma = 0;
int suma1 = 0;

void ingresar_ABCABF(){
    cout << "\nIngresa las columnas de su matriz A:";
    cin >> AC;
    cout << "Ingresa las filas de su matiz A:";
    cin >> AF;
    matrizA[10][10] = matrizA[AC][AF];

    cout << "\nIngresa las columnas de B:";
    cin >> BC;
    cout << "Ingresa las filas de B:";
    cin >> BF;
    matrizB[10][10] = matrizB[BC][BF];

}
void ingresar_matrizA(){
    int opcion1;
    cout << "\n\t1-Ingresar valores aleatorios.";
    cout << "\n\t2-Ingresar valores uno a uno.";
    cout << "\n\tIngrese la opcion del metodo que desea usar: ";
    cin >> opcion1;

    switch (opcion1){
        case 1:
        for (int i = 0; i < AF; ++i) {
            for (int j = 0; j < AC; ++j) {
                if (matrizA[i][j] == 0) {
                matrizA[i][j] = rand() % -101, 101;
                }
            }
        }
        break;

        case 2:
        do{
            cout << "\nEn caso de un valor fuera de rango (-100,100) los valores seran solicitados nuevamente";
            cout << "\nIngrese los valores para la matriz " << AF << "x" << AC << ":" << endl;
            for (int i = 0; i < AF; ++i){
                for (int j = 0; j < AC; ++j){
                    cout << "Ingrese el valor para la fila " << i + 1 << " y columna " << j + 1 << ": ";
                    cin >> matrizA[i][j];
                }
            }
        }while(100 < matrizA[AF][AC] || matrizB[AF][AC] < -101);
        break;
    }
}

void ingresar_matrizB(){
    int opcion2;
    cout << "\n\t1-Ingresar valores aleatorios.";
    cout << "\n\t2-Ingresar valores uno a uno.";
    cout << "\n\tIngrese la opcion del metodo que desea usar: ";
    cin >> opcion2;

    switch (opcion2){
        case 1:
        for (int i = 0; i < BF; ++i) {
            for (int j = 0; j < BC; ++j) {
                if (matrizB[i][j] == 0) {
                  matrizB[i][j] = rand() % -101, 101;
                }
            }
        }
        break;

        case 2:
        do{
            cout << "\nEn caso de un valor fuera de rango (-100,100) los valores seran solicitados nuevamente";
            cout << "\nIngrese los valores para la matriz " << BF << "x" << BC << ":" << endl;
            for (int i = 0; i < BF; ++i) {
                for (int j = 0; j < BC; ++j) {
                    cout << "Ingrese el valor para la fila " << i + 1 << " y columna " << j + 1 << ": ";
                    cin >> matrizB[i][j];
                }
            }
        }while(100 < matrizB[BF][BC] || matrizB[BF][BC] < -101);
        break;
    }
}

void mostrar_valores(){
    cout << "\nLa matriz A es:" << endl;
    for (int i = 0; i < AF; i++){
        for (int j = 0; j < AC; j++){
            cout << matrizA[i][j] << " ";
        }
    cout << endl;
    }

    cout << "\nLa matriz B es:" << endl;
    for (int i = 0; i < BF; i++){
        for (int j = 0; j < BC; j++){
            cout << matrizB[i][j] << " ";
        }
    cout << endl;
    }
}

void editar_matriz(){
    int opcion3;
    cout << "\n\t1. Editar valores a la matriz A." << endl;
    cout << "\t2. Editar valores a la matriz B." << endl;

    cout << "\n\tIngrese la opcion de la matriz a editar: ";
    cin >> opcion3;

    switch (opcion3){
        case 1:
        cout << "\ningresar la fila de valor que desea ingresar.";
        cin >> ingresarAF;
        ingresarAF = ingresarAF -1;
        cout << "ingresar la columna de valor que desea ingresar.";
        cin >> ingresarAC;
        ingresarAC = ingresarAC -1;
        do{
            cout << "ingresar valor deseado:";
            cin >> matrizA[ingresarAC][ingresarAF];
        }while(100 < matrizB[ingresarAF][ingresarAC] || matrizB[ingresarAF][ingresarAC] < -101);
        break;

        case 2:
        cout << "\ningresar la fila de valor que desea ingresar:";
        cin >> ingresarBF;
        ingresarBF = ingresarBF -1;
        cout << "ingresar la columna de valor que desea ingresar:";
        cin >> ingresarBC;
        ingresarBC = ingresarBC -1;
        do{
            cout << "ingresar valor deseado:";
            cin >> matrizB[ingresarBC][ingresarBF];
        }while(100 < matrizB[ingresarBF][ingresarBC] || matrizB[ingresarBF][ingresarBC] < -101);
        break;
    }
}

void multiplicacion_matrices(){
    for (int i = 0; i < AF; i++){
        for (int j = 0; j < AC; j++){
            suma = matrizA[i][j] + suma;
        }
    }
    for (int i = 0; i < BF; i++){
        for (int j = 0; j < BC; j++){
            suma1 = matrizB[i][j] + suma1;
        }
    }
    cout << suma1 << endl;
    cout << suma << endl;
    cout << "Su multiplicacion es:";
    cout << suma * suma1 << endl;
}

void menu(){
    int opcion;
    cout << "\n\t1. Ingresar valores a la matriz A." << endl;
    cout << "\t2. Ingresar valores a la matriz B." << endl;
    cout << "\t3. Mostrar los valores de las matrices." << endl;
    cout << "\t4. Editar los valores." << endl;
    cout << "\t5. Multiplicar ambas matrices." << endl;
    cout << "\t6. Salir." << endl;

    cout << "\n\tIngrese la opcion del metodo que desea usar: ";
    cin >> opcion;

    switch (opcion){
        case 1:
        ingresar_matrizA();
        menu();
        break;

        case 2:
        ingresar_matrizB();
        menu();
        break;

        case 3:
        mostrar_valores();
        menu();
        break;

        case 4:
        editar_matriz();
        menu();
        break;

        case 5:
        multiplicacion_matrices();
        menu();
        break;
        
        case 6:
        cout << "Programa finalizado.";
        break;
    }
}

int main(){
    cout << "\t-Bienvenido-";
    cout << "\nDebera ingresar los siguentes datos para sus matrices";
    ingresar_ABCABF();
    if (10 < AC || AC < 2 || 10 < AF || AF < 2 || 10 < BC || BC < 2 || 10 < BF || BF < 2){
        cout << "\nvalores fuera del rango, ingresar nuevamente.";
        ingresar_ABCABF();
    }

    menu();

    return 0;
}