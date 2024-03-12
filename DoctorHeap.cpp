#include <iostream>
#include "DoctorHeap.h"
using namespace std;
// Default constructor
DoctorHeap::DoctorHeap() : size(0) {

}


bool DoctorHeap::heapIsEmpty() const {
    return (size == 0);
}

void DoctorHeap::heapInsert(const HeapItemType &newItem) {
    if (size >= MAX_HEAP2)
        cout <<"HeapException: Heap full"<< endl;

    // Place the new item at the end of the heap
    items[size] = newItem;

    // Trickle new item up to its proper position
    int place = size;
    int parent = (place - 1)/2;
    while ( (place > 0) && (items[place] < items[parent]) ){
        Doctor temp = items[parent];
        items[parent] = items[place];
        items[place] = temp;

        place = parent;
        parent = (place - 1)/2;
    }
    ++size;
}

void DoctorHeap::heapDelete() {
    if (heapIsEmpty())
        cout << "";
    else {
        // rootItem = items[0];
        items[0] = items[--size];
        heapRebuild(0);
    }
}

void DoctorHeap::heapRebuild(int root) {

        int child = 2 * root + 1;    // index of root's left child, if any
        if (child < size) {
            // root is not a leaf so that it has a left child
            int rightChild = child + 1;    // index of a right child, if any
            // If root has right child, find larger child

            if(rightChild < size && items[rightChild] < items[child]){
                child = rightChild;
            }
            // If root’s item is smaller than larger child, swap values
            if (items[child] < items[root]) {
                Doctor temp = items[root];
                items[root] = items[child];
                items[child] = temp;

                // transform the new subtree into a heap
                heapRebuild(child);
            }
        }
}

Doctor DoctorHeap::getMin() {

    return items[0];

}


