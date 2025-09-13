#include <bits/stdc++.h>
using namespace std;

void quick(int a[], int l, int r)
{
    int i, j, pivot;
    if (l < r) {
        i = l;
        j = r + 1;
        pivot = a[l];
        do {
            do {
                i++;
            } while (a[i] < pivot);
            do {
                j--;
            } while (a[j] > pivot);
            if (i < j) {
                swap(a[i], a[j]);
            }
        } while (i < j);
        swap(a[l], a[j]);
        quick(a, l, j - 1);
        quick(a, j + 1, r);
    }
}

int main()
{
    int n;
    cin >> n;
    srand(time(NULL));
    int a[n];
    for (int i = 0; i < n; i++) a[i] = rand()%1000;
    auto start = chrono::high_resolution_clock::now();
    quick(a, 0, n - 1);
    auto stop = chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Time running: " << duration.count() << " micro seconds" << endl;
    return 0;
}
