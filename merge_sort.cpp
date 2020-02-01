#include <bits/stdc++.h>
using namespace std;

void merge(vector<string> &arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<string> L(n1), R(n2);

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<string> &arr, int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void printArray(vector<string> & arr, int size)
{
    int i;
    for (i=0; i < size; i++)
        cout<<arr[i]<< "\n";
}

int main()
{
   int T;
   cin>>T;
   while (T--)
   {
       vector<string> arr;
       string tmp;
       int n ;
       cin >>n;
       for (int i = 0; i < n; ++i) {
           cin>>tmp;
           arr.push_back(tmp);
       }
       int arr_size = arr.size();
       mergeSort(arr, 0, arr_size - 1);
       printArray(arr, arr_size);
   }
    return 0;
} 