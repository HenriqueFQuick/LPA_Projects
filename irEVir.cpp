#include <iostream>
#include <stdbool.h>
using namespace std;

int menorValor(int* v, int tamanho){
    int menor = 999999999;
    int a = 0;
    for(int i = 0; i < tamanho; i++){
        if((v[i] != -1) && v[i] < menor){
            menor = v[i];
            a = i;
        }
    }
    return a;     
}

void dijkstra(int vertice, int tamanho, int** matriz, int* d){

    d[vertice] = 0;

    int c = 0;
    while(c  < tamanho){

        int menor = menorValor(d, tamanho);
        for(int i = 0; i < tamanho; i++){
            if((d[i] != -1) && (i != menor) && (matriz[menor][i] != 0) && (matriz[menor][i]+d[menor] < d[i])){
                d[i] = matriz[menor][i]+d[menor];
            }
        }
        d[menor] = -1;
        int menor3 = menorValor(d, tamanho);
        if(d[menor3] == 999999999) c = tamanho;
        c++;
    }
}

void inicializaMatriz(int** matriz, int relacoes, int tam){ 

    
    while(relacoes > 0){ 
        int a, b, c;    
        cin >> a;
        cin >> b;
        cin >> c;

        matriz[a-1][b-1] = 1;

        if(c == 2)
            matriz[b-1][a-1] = 1;
        
        
   
        relacoes--;
    }

}

int** CriaMatriz(int tamanho){
    int** matriz = new int*[100];
    for(int i = 0; i < tamanho; i++){
        matriz[i] = new int[tamanho];
    }
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            matriz[i][j] = 0;
        }
    }
    return matriz;
}

void inicializarVetor(int* d, int tamanho){
    for(int i = 0; i < tamanho; i++){
        d[i] = 999999999;
    }
}

bool metodo(int relacoes, int vertices, int** matriz){
    int* d1 = new int[relacoes];
        int* d2 = new int[relacoes];
        inicializarVetor(d1, relacoes);
        inicializarVetor(d2, relacoes);

        bool resultDjk = true;

        for(int j = 0; j < vertices; j++){
            inicializarVetor(d1, relacoes);
            dijkstra(j,vertices, matriz, d1);

            for(int i = 0; i < vertices; i++){
                if(d1[i] == 999999999){
                    return false;
                }
            }
        }
        return true;
}

int main(){

    int vertices, relacoes;
    cin >> vertices;
    cin >> relacoes;

    while(vertices !=0 && relacoes != 0){

        int** matriz = CriaMatriz(vertices); 
        inicializaMatriz(matriz, relacoes, vertices);

        bool resultDjk =  metodo(relacoes, vertices, matriz);

        if(resultDjk){
            cout << "1" << endl;
       }else cout << "0" << endl;

        cin >> vertices;
        cin >> relacoes;
    }
   return 0;
}