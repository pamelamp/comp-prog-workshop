#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;  // num locales
    cin >> n;
    vector<int> a(n);   // precios empanadas
    vector<int> o(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    sort(a.begin(),a.end()); // orden precios: ascendente
    int l=0,r=n/2;
    for (int j=0; j<n; j++) {   // orden precios: marketing
        if (j % 2 == 0) {   // posicion par: nums grandes
            o[j] = a[r];
            r++;
        }
        else {  // posicion impar: nums chicos
            o[j] = a[l];
            l++;
        }
    }
    int e = 0;  // max empanadas
    for (int k=1; k<n-1; k++) {  // analizar precios
        if (o[k]<o[k-1] && o[k]<o[k+1]) {   // compra
            e++;
        }
    }
    cout << e << "\n";  // imprimir max empanadas
    for (int p=0; p<n; p++) {   // imprimir orden precios
        cout << o[p] << " ";
    }
    cout << "\n";
    return 0;
}