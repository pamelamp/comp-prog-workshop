#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n, i=0, s=0;    // largo playlist, indice aux, secuencia + larga guardada
    cin >> n;
    vector<int> p(n);     // playlist original
    set<int> plist;     // (sub) playlist sin repeticiones
    for (int c=0; c<n; c++) {   // agregar canciones a la playlist original
        cin >> p[c];
    }
    for (int j=0; j<n; j++) {   // verificacion "factor demure"
        while (plist.find(p[j]) != plist.end()) {   // si estaba, eliminamos la 1ra copia
            plist.erase(p[i]);
            i++;
        }
        plist.insert(p[j]);     // agregamos nueva copia
        s = max(s,j-i+1);
    }
    cout << s << "\n";
    return 0;
}
