#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;  // largo cinta
    cin >> n;
    int a,b,c;
    cin >> a >> b >> c;
    vector<int> cinta(n+1, -1);  // vector con num cortes posibles segun largo, inicio -1's
    cinta[0] = 0;   // 0 cortes en cinta de largo 0
    for (int l=1; l<=n ; l++) { // cortes en cinta de largo >=1
        /*
        condiciones: se puede cortar un pedazo de largo L1 a partir de la cinta, y
        el largo L - L1 (lo que queda tras cortar) tambien es posible cortarlo por
        un largo L2. L1 y L2 pueden ser a, b, o c.
            cortes en cinta largo l = 
                max(cortes en cinta largo l, cortes en cinta largo l-a + 1)
        */
        if ((l>=a) && (cinta[l-a] != -1)) {
            cinta[l] = max(cinta[l], cinta[l-a] + 1);
        }
        if ((l>=b) && (cinta[l-b] != -1)) {
            cinta[l] = max(cinta[l], cinta[l-b] + 1);
        }
        if ((l>=c) && (cinta[l-c] != -1)) {
            cinta[l] = max(cinta[l], cinta[l-c] + 1);
        }
    }
    cout << cinta[n] << "\n";
    return 0;
}