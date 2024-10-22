#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool valid(unsigned long long s, int k, int n, vector<int> t) {
    unsigned long long p = 0;
    for (int i=0; i<n; i++) {
        p += (s/t[i]);
    }
    return (p>=k);
}

int main() {
    int n;  // num impresoras
    cin >> n;
    int k;  // num figuras
    cin >> k;
    vector<int> t(n);
    for (int i=0; i<n; i++) {
        cin >> t[i];
    }
    unsigned long long min = 1;
    unsigned long long max = 10000000000000000000ULL;
    while (min < max) {
        unsigned long long half = ((min + max) / 2);
        if (valid(half, k, n, t)) {
            max = half;
        }
        else {
            min = half + 1;
        }
    }
    cout << min << "\n";
    return 0;
}
