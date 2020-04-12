#include <iostream>
#include <string.h>

using namespace std;
void getSubstrings(string str,string* distinctSubstrig, int length){
int aux = -1;
    string auxString = "";
    for(int i = 0; i < str.length(); i++){
        for(int j = i; j < str.length(); j++){
            aux++;
            auxString += str[j];
            distinctSubstrig[aux] = auxString;
        }
        auxString = "";
    }
}
int qtdSubstring(string str, string* distinctSubstrig, int length){
    getSubstrings(str, distinctSubstrig, length);

    int c = 0;
    for(int i = 0; i < length; i++){
        for(int j = 0; j < length; j++){
            if(distinctSubstrig[i] != distinctSubstrig[j])
                c++;
        }
    }
    return c;
}
int main(){

    int quantidade = 0;
    cin >> quantidade;

    cin.ignore();

    while(quantidade > 0){
    
        string first, second;
        getline(cin, first);
        getline(cin, second);
        
        int length = 0;
        for(int i = 1; i <= first.length(); i++){
            length += i;
        }

        string* substrig1 = new string[length];
        string* substrig2 = new string[length];;

        int qtd1 = qtdSubstring(first, substrig1, length);
        int qtd2 = qtdSubstring(second, substrig2, length);

        if(qtd1 == qtd2){
            cout << "s" << endl;
        }else cout << "n" << endl;
        
        quantidade--;
    }

    return 0;
}