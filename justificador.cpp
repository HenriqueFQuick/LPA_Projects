#include <iostream>
#include <string.h>

using namespace std;


int main(){

    int quantidade = 0;
    cin >> quantidade;
    cin.ignore();

    while(quantidade != 0){

        string* frases = new string[quantidade];
        string frase = "";
        string fraseAux = "";

        for(int k = 0; k < quantidade; k++){

            frase = "";
            fraseAux = "";

            getline(cin, frase);

            //cout << frase << "\n";
            
            bool isbegining = true;

            for(int i = 0; i < frase.length(); i++){
                //cout << "FRASE: " << frase << " i: " << i << " frase[i]: " << frase[i] <<"\n"; 
                if(isbegining){
                    if(!isspace(frase[i])){  
                        fraseAux=frase[i];
                        isbegining = false;
                    }
                }else if(!(isspace(frase[i]) && (i+1 < frase.length()) && isspace(frase[i+1]))){  
                    fraseAux+=frase[i];  
                }
                
            }
            //cout << " NOVA FRASE: " << fraseAux << "\n";
            frases[k] = fraseAux;
        }
        int max = frases[0].length();
        for(int k = 0; k < quantidade; k++){
            if(frases[k].length() > max){
                max = frases[k].length();  
            }
        }

        string* resultado = new string[quantidade];

        for(int k = 0; k < quantidade; k++){
            for(int a = 0; a < (max - frases[k].length()); a++){
                resultado[k] += " " ;
            }
            resultado[k] += frases[k];
        }

        for(int k = 0; k < quantidade; k++){
            cout << resultado[k] << "\n";
        }

        cin >> quantidade;
        cin.ignore();
    }
}