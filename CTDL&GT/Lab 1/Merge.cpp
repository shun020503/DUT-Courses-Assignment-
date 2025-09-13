#include <bits/stdc++.h>
using namespace std;

void merge(int a[], int l, int r, int m)
{
    vector<int> x(a+l,a+m+1);
    vector<int> y(a+m+1,a+r+1);
    int i=0,j=0;
    while (i<x.size() && j<y.size())
    {
        if (x[i]<=y[j]) { a[l]=x[i];i++;l++; }
        else { a[l]=y[j];j++;l++; }
    }
    while (i<x.size())
    {
        a[l]=x[i]; i++; l++;
    }
    while (j<y.size())
    {
        a[l]=y[j]; j++;l++;
    }
}

void mergeshort(int a[],int l, int r)
{
    if (l>=r) return;
    int m = (l+r)/2;
    mergeshort(a,l,m);
    mergeshort(a,m+1,r);
    merge(a,l,r,m);
}

int main()
{
    int n; cin >> n;
    int a[n];
    srand(time(NULL));
    for (int i=0; i<n; i++) a[i]= rand() % 1000;
    auto start = chrono::high_resolution_clock::now();
    mergeshort(a,0,n-1);
    auto stop = chrono::high_resolution_clock::now();
    for (int i=0; i<n; i++) cout << a[i] << " ";
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << endl;
    cout << "Time running: " << duration.count() << " micro second" << endl;
    return 0;
}