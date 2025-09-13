#include <bits/stdc++.h>
using namespace std;

void insertion(int a[], int n)
{
    for (int i=1; i<n; i++)
    {
        int x = a[i], vt = i-1;
        while (vt>=0 && x<a[vt])
        {
            a[vt+1]=a[vt];
            --vt;
        }
        a[vt+1]=x;
    }
}

int main()
{
    int n; cin >> n;
    int a[1000];
    srand(time(NULL));
    for (int i=0; i<n; i++) a[i] = rand() % 1000;
    auto start = chrono::high_resolution_clock::now();
    insertion(a,n);
    auto stop = chrono::high_resolution_clock::now();
    for (int i=0; i<n; i++) cout << a[i] << " ";
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << endl;
    cout << "Time running: " << duration.count() << " micro seconds" << endl;
    return 0;
}

