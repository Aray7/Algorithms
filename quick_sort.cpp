#include <bits/stdc++.h> 
using namespace std; 

int partition (vector<string> & arr, int low, int high)
{ 
	string pivot = arr[high];
	int i = (low - 1); 

	for (int j = low; j <= high - 1; j++) 
	{ 
		if (arr[j] < pivot) 
		{ 
			i++;
			swap(arr[i], arr[j]);
		} 
	} 
	swap(arr[i + 1], arr[high]);
	return (i + 1); 
} 

void quickSort(vector<string>& arr, int low, int high)
{ 
	if (low < high) 
	{ 
		int index = partition(arr, low, high); 
		quickSort(arr, low, index - 1); 
		quickSort(arr, index + 1, high); 
	} 
} 

void printArray(vector<string> &arr, int size)
{ 
	int i; 
	for (i = 0; i < size; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
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
        quickSort(arr, 0, arr_size - 1);
        printArray(arr, arr_size);
    }

} 

