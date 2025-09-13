#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int n; cin >> n;
    int a[1000];
    srand(time(NULL));
    for (int i=0;i<n;i++) a[i] = rand() % 1000;
    auto start = chrono::high_resolution_clock::now();
    for (int i=0;i<n;i++)
        for (int j=i+1;j<n;j++)
            if (a[i]>a[j])
            {
                int tg=a[i];a[i]=a[j];a[j]=tg;
            }
    auto stop = chrono::high_resolution_clock::now();
    for (int i=0;i<n;i++) cout << a[i] << " ";
    cout << endl;
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Time running: " << duration.count() << " micro seconds" << endl;
    return 0;
}