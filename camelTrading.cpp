#include<iostream>
#include <vector> 
#include<string>

using namespace std;

long long  metodo2(vector<string> vetor){
    vector<string> soma;
    long long aux = 1;
    for(int i=0; i<vetor.size(); i++){
        while(i < vetor.size() && vetor[i] != "+"){
            if(vetor[i] == "*")
                i++;
            else{
                aux *= stoi(vetor[i]);
                i++;
            }
        }
        soma.push_back(to_string(aux));
        soma.push_back("+");
        aux = 1;
    }
    aux = 0;
    for(int i = 0; i < soma.size(); i++){
        if(soma[i] != "+")
            aux += stoll(soma[i]);
    }
    return aux;
}

long long metodo(vector<string> vetor){
    vector<string> soma;
    long long aux = 0;
    for(int i=0; i<vetor.size(); i++){
            while(i < vetor.size() && vetor[i] != "*"){
                if(vetor[i] == "+")
                    i++;
                else{
                    aux += stoi(vetor[i]);
                    i++;
                }
            }
            soma.push_back(to_string(aux));
            soma.push_back("*");
            aux = 0;
    }
    
    aux = 1;
    for(int i = 0; i < soma.size(); i++){
        if(soma[i] != "*")
            aux *= stoi(soma[i]);
    }
    return aux;
}

int main(){

    int n = 0;
    cin >> n;
    cin.ignore();
    while(n > 0){

        vector<string> operacoes;
        string teste;
        
        getline(cin, teste);
        string aux;
        for(int i = 0; i < teste.size(); i++){
            while(i < teste.size() && teste[i] != '+' && teste[i] != '*'){
                aux += teste[i];
                i++;
            };
            operacoes.push_back(aux);
            operacoes.push_back(string(1,teste[i]));

            aux = "";
        }
        operacoes.pop_back();
        
        long long  max = 0, min = 0;
        max = metodo(operacoes);
        min = metodo2(operacoes);
        operacoes.clear();
        cout << "The maximum and minimum are " << max << " and " << min << "."<< endl;
        n--;
    }

    return 0;
}