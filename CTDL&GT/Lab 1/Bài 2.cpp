#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int a[n];
    srand(time(NULL));
    for (int i=0; i<n; i++) a[i] = rand() % 1000;
    auto start = chrono::high_resolution_clock::now();
    sort(a,a+n);
    auto stop = chrono::high_resolution_clock::now();
    for (int i=0; i<n; i++) cout << a[i] << " ";
    cout << endl;
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Time running: " << duration.count() << " micro seconds" << endl;
    return 0;
}
