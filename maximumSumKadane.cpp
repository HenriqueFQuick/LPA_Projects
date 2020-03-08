#include <iostream>
#include <cmath>
using namespace std;
int* createVector(int tamanho){

    int* vetor = new int[tamanho];
    for(int i = 0; i < tamanho; i++){
        vetor[i] = 0;
    }
    return vetor;

}

int kadane(int* vetor, int tamanho){
    int* auxVector = createVector(tamanho);
    auxVector[0] = vetor[0];
    for(int i = 1; i < tamanho; i++){
        if(vetor[i] > vetor[i]+auxVector[i-1]){
            auxVector[i] = vetor[i];
        }else auxVector[i] = vetor[i]+auxVector[i-1];
    }
    int max = auxVector[0];
    for(int i = 0; i < tamanho; i++){
        if(auxVector[i] > max){
            max = auxVector[i];
        }
    }
    return max;
}

int metodo(int** matriz, int tamMatriz){

    int* vetor = createVector(tamMatriz);
    int maxRectangleSum = 0;
    int Left = 0;
    int Right = 0;

    for(int i=0; i<tamMatriz; i++){
        for(int row = 0; row < tamMatriz; row++){
                vetor[row] = 0;
        }
        for(int j=i; j < tamMatriz; j++){
            for(int row = 0; row < tamMatriz; row++){
                vetor[row] += matriz[row][j];
            }
            if(kadane(vetor, tamMatriz) > maxRectangleSum){
                maxRectangleSum = kadane(vetor, tamMatriz);

            }
        }
    }
    return maxRectangleSum;
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