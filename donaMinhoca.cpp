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

void inicializarVetor(int* d, int tamanho){
    for(int i = 0; i < tamanho; i++){
        d[i] = 999999999;
    }
}

void dijkstra(int vertice, int tamanho, int** matriz, int* d, int* k){

    d[vertice] = 0;

    int c = 0;
    while(c  < tamanho){

        int menor = menorValor(d, tamanho);
        for(int i = 0; i < tamanho; i++){
            if((d[i] != -1) && (i != menor) && (matriz[menor][i] != 0) && (matriz[menor][i]+d[menor] < d[i])){
                d[i] = matriz[menor][i]+d[menor];
                k[i] = matriz[menor][i]+d[menor];
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
        
        matriz[a-1][b-1] = c;
        matriz[b-1][a-1] = c;

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

int main(){

    int vertices, relacoes;
    while(cin >> vertices){
        cin >> relacoes;

        int** matriz = CriaMatriz(vertices); 
        inicializaMatriz(matriz, relacoes, vertices);

        int* d1 = new int[relacoes];
        int* d2 = new int[relacoes];
        int* aux2 = new int[relacoes];
        int* aux3 = new int[relacoes];

        int test = 0;
        cin >> test;

        while(test > 0){

            int first = 0;
            int size = 0;
            cin >> first;
            cin >> size;

            int min = 999999999;
            int aux = 0;
            for(int i = 0; i < vertices; i++){
                for(int j = 0; j < vertices; j++){
                    inicializarVetor(aux2, relacoes);
                    inicializarVetor(aux3, relacoes);
                    inicializarVetor(d1, relacoes);
                    inicializarVetor(d2, relacoes);

                    //cout << endl << "vertice " << i+1 << " first = " << first << "   aresta (i) " << i+1 << " - (j) " << j+1 << " = " << matriz[i][j] << endl;

                    dijkstra(first-1,vertices,matriz, d1, aux2);
                    //cout << "caminho1 " << first << " - " << j+1 << " = " << aux2[j] << " tem caminho direto entre "<< i+1 <<" e "<<j+1<<"? " << (matriz[i][j] != 0) << endl;
                    if(matriz[i][j] != 0 && aux2[j] != 999999999){

                        aux = matriz[i][j];
                        matriz[i][j] = 0;

                        dijkstra(i,vertices,matriz, d2, aux3);
                        /*cout << "caminho2 " << i+1 << " - " << j+1 << " = " << aux3[j] << endl;
                        for(int k = 0; k < relacoes; k++){
                            cout << aux3[k] << " ";
                        }
                        cout << endl << "resp agr: " << aux2[j] << " + " << aux3[j] << " + " << aux2[i] <<" = " << aux2[j]+aux3[j]+aux2[i] << endl;*/
                        if(first-1 != i){
                            if((aux3[j]+2*aux2[i]+aux)< min && d2[j] != 0 && (aux3[j]+aux) >= size){
                                min = aux3[j]+2*aux2[i]+aux;
                            }
                        }else{
                            //cout << endl << "2 = resp agr: " << aux3[j] << " + " << aux << " = " << aux3[j]+aux << endl;
                            if((aux3[j]+aux)< min && d2[j] != 0 && (aux3[j]+aux) >= size){
                                min = aux3[j]+aux;
                            }
                        }
                        matriz[i][j] = aux;
                    }
                }
            }
            if(min == 999999999){
                cout << "-1\n";
            }else{
                cout << min << endl;
            }
            test--;
        }
    }
    return 0;
}