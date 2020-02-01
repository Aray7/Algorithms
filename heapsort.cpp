#include <string>
#include <iostream>
using namespace std;

class Heap
{
    string *harr; //head of array
    int capacity; // max size
    int heap_size; // current size
public:
    Heap(int capacity);

    int parent(int i) { return (i-1)/2; }

    // to get index of left child of node at index i
    int left(int i) { return (2*i + 1); }

    // to get index of right child of node at index i
    int right(int i) { return (2*i + 2); }

    // create heap with root at i
    void make_heap(int i);

    // pop the minimum element
    string pop_heap();

    // Inserts a new key 'k'
    void push_heap(string k);

    // returns true if heap is empty
    bool isEmpty(){ return this->heap_size <= 0;};
};

// Constructor: Builds a heap from a given array a[] of given size
Heap::Heap(int cap) {
    heap_size = 0;
    capacity = cap;
    harr = new string[cap];
}

// Inserts a new key 'k'
void Heap::push_heap(string k) {
    if (heap_size == capacity) {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;

    // redo the heap if its distorted
    while (i != 0 && harr[parent(i)] > harr[i]) {
        harr[i].swap(harr[parent(i)]);
        i = parent(i);
    }
}


// remove minimum
string Heap::pop_heap() {
    if (heap_size <= 0)
        return "";
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }

    // remove minimum value from heap and move last value to first, then heapify
    string root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    make_heap(0);

    return root;
}

// A recursive method to make_heap a subtree with the root at given index
void Heap::make_heap(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        harr[i].swap(harr[smallest]);
        make_heap(smallest);
    }
}

int main()
{
    string line;
    getline(cin, line);
    int numCases = stoi(line);
    for(int i = 0; i < numCases; i++){
        getline(cin, line);
        int numLines = stoi(line);
        Heap h(numLines);
        for (int j = 0; j < numLines; j++) {
            getline(cin, line);
            h.push_heap(line);
        }
        while(!h.isEmpty()){
            cout << h.pop_heap() << endl;
        }
    }
    return 0;
}