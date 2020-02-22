#include <iostream>
#include <string.h>

using namespace std;

string* formatStrings(string* frases, int quantidade, int max){
    string* resultado = new string[quantidade];
    for(int k = 0; k < quantidade; k++){
        for(int a = 0; a < (max - frases[k].length()); a++){
            resultado[k] += " " ;
        }
        resultado[k] += frases[k];
    }
    return resultado;
}

string removeExtraSpaces(string frase){
    string fraseAux = "";
    bool isbegining = true;

    for(int i = 0; i < frase.length(); i++){
        if(isbegining && !isspace(frase[i])){ 
                fraseAux=frase[i];
                isbegining = false;
        }else if(!(isspace(frase[i]) && (i+1 < frase.length()) && isspace(frase[i+1]))){  
            fraseAux+=frase[i];  
        }
        
    }
    return fraseAux;
}

int getMaximumLength(string* frases, int quantidade){
    int max = frases[0].length();
    for(int k = 0; k < quantidade; k++){
        if(frases[k].length() > max){
            max = frases[k].length();  
        }
    }
    return max;
}


int main(){

    int quantidade = 0;
    cin >> quantidade;

    while(quantidade != 0){

        string* frases = new string[quantidade];
        string frase = "";

        cin.ignore();

        for(int k = 0; k < quantidade; k++){
            frase = "";
            getline(cin, frase);
            frases[k] = removeExtraSpaces(frase);
        }

        int max = getMaximumLength(frases, quantidade);

        string* resultado = formatStrings(frases, quantidade, max);

        for(int k = 0; k < quantidade; k++){
            cout << resultado[k] << "\n";
        }

        cin >> quantidade;
    }
}