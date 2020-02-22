#include <iostream>
#include <string.h>
#include <ctype.h>

#include <typeinfo>
using namespace std;


void metodo(string str){
    int inicio = 0; 
    int final = 0;

    for(int i = 0; i < str.length(); i++){
        if(!isspace(str[i])){
            final = i;
            str.erase(inicio, final);
        }
    }
    cout << str;
}

int main(){

    int quantidade = 0;
    cin >> quantidade;

    while(quantidade != 0){

        string* frases = new string[quantidade];

        for(int k = 0; k < quantidade; k++){

            string frase = "";
            string fraseAux = "";

            cin.ignore();
            getline( cin, frase);


            /*int inicio = 0; 
            int final = 0;
            bool teste = true;

            for(int p = 0; p < frase.length() && teste; p++){
                if(!isspace(frase[p])){
                    final = p;
                    frase  = frase.erase(inicio, final);
                    cout << frase << "\n";
                    teste = false;
                }
            }
            cout << frase;    TESTE  */

            for(int i = 0; i < frase.length(); i++){
                //cout << "FRASE: " << frase[i] << " ISPACE: " << isspace(frase[i]) << "\n";
                if(!(isspace(frase[i]) && (i+1 < frase.length()) && isspace(frase[i+1]))){  
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
                //cout << frases[k];           
            } 
            //cout << frases[k] << "\n";
        }
        //cout << max << "\n";

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

    }
}