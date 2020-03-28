#include<bits/stdc++.h> 
#include<string>  
using namespace std; 

int fib(long f[], int n) 
{ 
    f[0] = 0; 
    f[1] = 1; 

    for (int i = 2; i <= n; i++) 
        f[i] = (f[i - 1] + f[i - 2]) % 1000; 
  
    return f[n]; 
} 

long* findLastDigit() 
{ 
    long* f = new long[1500];
    fib(f, 1500); 
  
    return f;
} 
int mod(string num, int a) 
{ 
    int res = 0; 

    for (int i = 0; i < num.length(); i++) 
         res = (res*10 + (int)num[i] - '0') %a; 
  
    return res; 
} 

int main () 
{ 
    int qtd = 0;
    cin >> qtd;
    long* f = findLastDigit();
    cin.ignore();
    while(qtd > 0){
        string n = "";
        getline(cin,n);
        string result = ""; 
        int modResp = mod(n,1500);
        int resp = to_string(f[modResp]).length();
        for(int i = 0; i < 3-resp; i++){
            result += "0";
        }
        cout << result+to_string(f[modResp]) << endl;
        qtd--;
    } 
    return 0; 
}