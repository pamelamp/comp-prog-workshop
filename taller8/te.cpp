#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;  // num vasos
    cin >> n;
    vector<int> a(n);   // vector con satisfaccion de cada vaso
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    // iniciar una matriz nxn con 0's:
    vector<vector<long long>> matriz(n, vector<long long>(n,0));
    for (int j=0; j<n; j++) {   // llenado de la diagonal 
        // mejor caso para el vaso j: ser el último consumido
        matriz[j][j] = (a[j]*n);
    }
    // llenar el "resto" de la matriz (ie el triangulo superior)
    for (int v=2; v<=n; v++) {   // ciclo en base al num de vasos de subcadena
        for (int izq=0; izq+v<=n; izq++) {     // ciclo en base a indice izquierdo
            int der = v + izq - 1;  // indice extremo derecho
            int itr = n - (der - izq);    // iteracion actual
            // se guarda el valor optimo en la matriz
            matriz[izq][der] = max(a[izq]*itr + matriz[izq+1][der],
                                   a[der]*itr + matriz[izq][der-1]);
        }
    }
    cout << matriz[0][n-1] << "\n";
    return 0;
}