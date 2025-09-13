#include <bits/stdc++.h>
 using namespace std;
 
void heapify(int a[], int n, int i)
{
    int l = 2*i+1;
    int r = 2*i+2;
    int max = i;
    if (l < n && a[l] > a[max]) max = l;
    if (r < n && a[r] > a[max]) max = r;
    if (max != i)
    {
        swap(a[i], a[max]);
        heapify(a,n,max);
    }
}
 
void heapsort(int a[], int n)
{
    for (int i = n/2 -1; i >= 0; i--) heapify(a,n,i); // xay dung max heap
    for (int i = n-1; i>=0; i--)
    {
        swap(a[i], a[0]);
        heapify(a,i,0);
    }
}

int main()
{
    int n; cin >> n; int a[100];
    for (int i=0; i <n; i++) cin >> a[i];
    heapsort(a,n);
    for (int i=0; i < n; i++) cout << a[i] << " ";
    return 0;
}