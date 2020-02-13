#include <iostream>
#include <cmath>
using namespace std;

double** cloneMatriz(int tamanho){

    double** matriz = new double*[100];                                         
    for(int i = 0; i < tamanho; i ++){            
        matriz[i] = new double[tamanho];
    }
    for(int i = 0; i < tamanho; i++){           
        for(int j = 0; j < tamanho; j++){
            matriz[i][j] = -128; 
        }
    }                                                                
    return matriz;
}

int metodo(int** matriz, int tamMatriz){

    bool teste = 1;
    int maior = matriz[0][0];
    for(int i = 0; i < tamMatriz; i++){
        for(int j = 0; j < tamMatriz; j++){
            if(matriz[i][j] > maior){
                maior = matriz[i][j];
            }
        }
    }
    for(int i = 0; i < tamMatriz; i ++){
        for(int j = 0; j < tamMatriz; j++){
            if(j+1 < tamMatriz) {if( matriz[i][j] + matriz[i][j+1] > maior) {maior = matriz[i][j] + matriz[i][j+1];}}
            if(j-1 > 0) {if( matriz[i][j] + matriz[i][j-1] > maior) {maior = matriz[i][j] +  matriz[i][j-1];}}
            if(i+1 < tamMatriz) {if( matriz[i][j] + matriz[i+1][j] > maior) {maior = matriz[i][j] +  matriz[i+1][j];}}
            if(i-1 > 0) {if( matriz[i][j] + matriz[i-1][j] > maior) {maior = matriz[i][j] +  matriz[i-1][j];}}
        }
    }
    int bigger = matriz[0][0];
    for(int i = 0; i < tamMatriz; i++){
        for(int j = 0; j < tamMatriz; j++){
            for(int k = 1; k < tamMatriz; k++){
                for(int l = 0; l < tamMatriz; l++){
                    bigger = 0;
                    for(int m = 0; m <= k && m+i < tamMatriz; m++){
                        for(int n = 0; n <= l && n+j < tamMatriz; n++){
                            bigger += matriz[i+m][j+n];
                        }
                    }
                    if(bigger > maior){
                        maior = bigger;
                    }
                }
            }
        }
    }

    return maior;
}

int** criaMatriz(int tamanho){

    int** matriz = new int*[100];                                         
    for(int i = 0; i < tamanho; i ++){            
        matriz[i] = new int[tamanho];
    }
    for(int i = 0; i < tamanho; i++){           
        for(int j = 0; j < tamanho; j++){
            cin >> matriz[i][j]; 
        }
    }                                                                
    return matriz;
}

int main(){
    
    int tamMatriz = 0;
    cin >> tamMatriz;

    int** matriz = criaMatriz(tamMatriz);

    int maxvalue = metodo(matriz, tamMatriz);

    cout << maxvalue;
    return 0;
}