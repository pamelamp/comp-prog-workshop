#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main() {
    int c;  // casos
    cin >> c;
    while (c--) {
        int n,m,lmolde;  // largo tag, num moldes, largo molde
        cin >> n;
        string molde;       // string con un molde
        vector<int> tag(n);     // vector con el tag/etiqueta
        for (int i=0; i<n; i++) {
            cin >> tag[i];
        }
        cin >> m;
        for (int j=0; j<m; j++) {
            cin >> molde;   // ingreso potencial molde
            lmolde = molde.size();  // largo molde
            if (n!=lmolde) {    // molde más largo/corto que tag
                cout << "NO\n";
            }
            else {
                map<char,int> mapa;
                set<int> ctag;
                set<char> cstr;
                int valid = 1;
                for (int k=0; k<n; k++) {   // revisar cada letra del molde
                    char ch = molde[k];  // char en posición k del molde (string)
                    int tgk = tag[k];  // int en posición k del tag
                    ctag.insert(tgk);
                    cstr.insert(ch);
                    if (mapa.find(ch) == mapa.end()) {  // no está
                        mapa[ch] = tgk;
                    }
                    else {
                        if (mapa[ch] != tgk) {
                            valid = 0;
                            break;
                        }
                    }
                }
                if ((valid == 1) && (ctag.size()==cstr.size())) {
                    cout << "YES\n";
                }
                else {
                    cout << "NO\n";
                }
            }
        }
    }
    return 0;
}