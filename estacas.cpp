#include <bits/stdc++.h>

using namespace std;

int main() {

  long long x, y;

  while (cin >> x >> y) {

    long long mdc = __gcd(x, y);
    long long perimetro = 2*(x+y);
    long long resp = perimetro/mdc;

    cout << resp << "\n";

  }
  return 0;
}