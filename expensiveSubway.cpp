#include <iostream>
#include <string.h>

using namespace std;

int menorValor(int* v, int tamanho){

    int menor = 99999;
    int a = 0;
    for(int i = 0; i < tamanho; i++){
        if((v[i] != -1) && (v[i] < menor)){
            menor = v[i];
            a = i;
        }
    }
    return a;     

}

int* inicializaVetor(int tamanho){

    int* vet = new int[tamanho];
    for(int i = 0 ; i < tamanho; i++){
        vet[i] = 999999;                                                   //Inicializa o vetor colocando 99999 em cada posicao
    }                                                               //Na posicao 0 eh colocado -1 para indicar que eh o comeco
    return vet;
}

int PRIM(int tamanho, int** matrizDistancia){ 
    int* vet = inicializaVetor(tamanho);                                     //Inicializo o vetor
    int c = 0;
    int contador = 0;
    vet[0] = -1;
    int menor = 0;
    while(c < tamanho-1){
        for(int i = 0; i < tamanho; i ++){
            if((menor != i)&&(vet[i] != -1)){
                if(matrizDistancia[menor][i] < vet[i]){
                    vet[i] = matrizDistancia[menor][i];
                }
            }
        }
        menor = menorValor(vet, tamanho);                                //Pegar o menor valor do vetor
        contador = contador + vet[menor];                                    //Incrementar o contador com o peso do vertice adicionado na AGM
        vet[menor] = -1;
        c++;
    }

    return contador;

}

int* percorreMatriz(int v, int **matriz, int *vertice, int qtd_Cidades, int* vetor){

    vertice[v] = 1;                                             //a cor do vertice atual passa a ser cinza
    vetor[v] = v;

    for(int i = 0; i < qtd_Cidades; i++){ 
        if(matriz[v][i] != 99999){                                  //se a o vertice visto for adjacente ao vertice atual,
            if(vertice[i] == 0){                                //e a cor dele for branca,
                vetor = percorreMatriz(i, matriz, vertice, qtd_Cidades, vetor);    //chama recursivamente o metodo com este vertice adjacente
            }
        }    
    }
    vertice[v] = 2;                                             //a cor do vertice em que todos os seus adjacentes ja foram percorridos vira preto
    return vetor;
}



int** criaMatriz(int qtd_Cidades){

    int** matriz = new int*[100];                   //declaracao da matriz
        for(int i = 0; i < qtd_Cidades; i ++){            
            matriz[i] = new int[qtd_Cidades];
        }

        for(int i = 0; i < qtd_Cidades; i++){           //inicializacao da matriz com 0
            for(int j = 0; j < qtd_Cidades; j++){
                matriz[i][j] = 99999;
            }
        }
    return matriz;
}



int* criaVetor(int qtd_Cidades){

    int* vertice = new int[qtd_Cidades];            //declaracao e inicializacao do vetor de cores do grafo              
        for(int i = 0; i< qtd_Cidades; i++){        //(0 - branco,   1 - cinza,   2 - preto) 
            vertice[i] = 0;                     //se for branco nao foi visitado, se for cinza, foi visitado mas ainda falta os
        }                                       //vertices adjacentes a ele, se for preto ja visitou ele e seus vertices adjacentes
    return vertice;                             
}


int findString(string* vetor, int tamanho, string str){
    int index = 0;
    for(int i = 0; i < tamanho; i++){
        if(vetor[i] == str)
            return i;
    }
    return -1;
}

string* split(string str){
    string* vetor = new string[3];
    string aux = "";
    int index = 0;
    for(int i = 0; i < str.length(); i++){
        if(!isspace(str[i])){
            aux += str[i];
        }else{
            vetor[index] = aux;
            aux = "";
            index++;
        }
    }
    vetor[2] = aux;
    return vetor;
}


void acrescentaArestas(int** matriz, int qtd_Relacoes, string* vetorCidades, int qtd_Cidades){
    int aux = qtd_Relacoes;
    while(aux > 0){                               //executa para a quantidade de arestas existentes
        string str;
        getline(cin, str);                         //le a quantidade de vertices no grafo
        string cidade;
        string cidade2;                                //e a quantidade de arestas existentes
        int preco;

        string* vetor = split(str);

        cidade2 = vetor[1];
        preco = atoi(vetor[2].c_str());
        cidade = vetor[0];
        int index1 = findString(vetorCidades, qtd_Cidades, cidade);
        int index2 = findString(vetorCidades, qtd_Cidades, cidade2);

        if(index1 == -1 || index2 == -1){
            return;
        }
        if(matriz[index1][index2] > preco || matriz[index1][index2] == 99999){
            matriz[index1][index2] = preco;         //acrescenta x -> y
            matriz[index2][index1] = preco;         //acrescenta y -> x
        }
        aux--;    
    }
}


void swap(int* xp, int* yp){

    int temp = *yp;

    *xp = *yp;

    *yp = temp;

}



int* ordenarVetor(int* vetor, int tam){

    int min;

    for(int i = 0; i < tam; i++){

        min = i;

        for(int j = i+1; j < tam; j++)

            if(vetor[j] < vetor[min])

                min = j;

            swap(vetor[min], vetor[i]);

    }

}



int main(){

    int qtd_Cidades;    
    cin >> qtd_Cidades;                          //Le a quantidade de grafos a serem lidos

    int qtd_Relacoes;
    cin >> qtd_Relacoes;
    cin.ignore();
    while(qtd_Cidades != 0 && qtd_Relacoes != 0){
        int c = 0;
        string* vetorCidades = new string[qtd_Cidades];
        while(c < qtd_Cidades){
            getline(cin, vetorCidades[c]);
            c++;
        }
        
        int** matriz = criaMatriz(qtd_Cidades);     //criacao e inicializacao da matriz

        int* vertice = criaVetor(qtd_Cidades);      //criacao e inicializacao do vetor

        int cont = 0;

        acrescentaArestas(matriz, qtd_Relacoes, vetorCidades, qtd_Cidades);  //acrescenta as arestas na matriz de adjacencias

        string cidadeInicial;
        int indexCidadeInicial = 0;
        getline(cin, cidadeInicial);
        indexCidadeInicial = findString(vetorCidades, qtd_Cidades, cidadeInicial);

        int contador = PRIM(qtd_Cidades, matriz);

        for(int i = 0; i < qtd_Cidades; i++){           //para cada vertice branco, entra no metodo que ira percorrer todos os vertices daquele componente
            if(vertice[i]==0){                      //se o grafo passar dessa verificacao mais de 1 vez, significa que ele tem mais de um componente
                cont++;                             //cont = quantidade de componentes
                int* vetor = new int[qtd_Cidades];
                for(int j = 0; j < qtd_Cidades; j++){
                    vetor[j] = -1;
                }
                vetor = percorreMatriz(i,matriz,vertice, qtd_Cidades, vetor);
                ordenarVetor(vetor, qtd_Cidades);
            }
        }

        if(cont > 1){
            cout << "Impossible\n";
        }else{
            cout << contador << "\n";
        }  
        cin >> qtd_Cidades;                          //Le a quantidade de grafos a serem lidos
        cin >> qtd_Relacoes;
        cin.ignore();
    }
    
    return 0;
}
