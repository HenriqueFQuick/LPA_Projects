#include <bits/stdc++.h>
using namespace std;

int main() {

    int qtd;
    cin >> qtd;

    long x, y;

    while (qtd != 0) {

        cin >> x;
        cin >> y;

        long mdc = __gcd(x, y);

        cout << mdc << "\n";

        qtd--;

    }
    return 0;
}