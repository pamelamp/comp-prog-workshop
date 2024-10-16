#include <iostream>
using namespace std;
#include <vector>

int main() {
    int t; // casos
    cin >> t;
    for (int h=1; h<=t; h++) {
        int par,imp; // total pares e impares
        int n; // largo arreglo, input
        cin >> n;
        int i = 0;  // indice
        int j = 0;  // indice
        int k = 0;  // indice
        int ep = 0;  // indice extra
        int ei = 0;  // indice extra
        for (int c=1; c<=n; c++) {
            int a;
            cin >> a;
            if (a % 2 == 0) {   // es par
                par++;
                if ((i==0) && (ep==0)) {
                    ep = c;
                }
                else if (ep!=0) {
                    i = ep;
                    j = c;
                }
                //cout << "actual post par: " << i << " " << j << " " << k << " " << ep << " " << ei;
                //cout << " c: " << c << "\n";
                if (c==n) {   // completo el arreglo
                    // if ((imp>=3) || (par>=2 && imp>=1)) {
                    if ((i!=0) && (j!=0) && (k!=0)) {
                        cout << "YES\n";
                        cout << i << " " << j << " " << k << " \n";
                    } else {
                        cout << "NO\n";
                        break;
                    } 
                }
            }
            if (a % 2 != 0){    // es impar
                imp++;
                if (k==0) {
                    k = c;
                }
                else if ((k!=0) && (ei==0)) {
                    ei = c;
                } 
                else if ((k!=0) && (ei!=0)) {
                    i = c;
                    j = ei;
                }
                //cout << "actual post impar: " << i << " " << j << " " << k << " " << ep << " " << ei;
                //cout << " c: " << c << "\n";
                if (c==n) {   // completo el arreglo
                    //if ((imp>=3) || (par>=2 && imp>=1)) {
                    if ((i!=0) && (j!=0) && (k!=0)) {
                        cout << "YES\n";
                        cout << i << " " << j << " " << k << " \n";
                    } else {
                        cout << "NO\n";
                        break;
                    } 
                }
            }
        }
    }
}

/* 
6
3
1 1 1
4
1 1 2 2
3
1 2 3
5
1 4 5 1 2
4
2 6 2 4
5
5 6 3 2 1
*/