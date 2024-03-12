/**
* Author : OYKU ELIS TUREGUN
* ID: 21902976
* Section : 1
* Homework : 3
* Description : HEAP CLASS
*/

#include "Heap.h"
#include <iostream>
using namespace std;

// Default constructor
Heap::Heap() : size(0) {

}


bool Heap::heapIsEmpty() const {
    return (size == 0);
}



void Heap::heapDelete() {
    if (heapIsEmpty())
        cout << "" << endl;
    else {
        items[0] = items[--size];
        heapRebuild(0);
    }
    /*
    cout << "After delete " << endl;
    cout << "ID: " << items[0].getID() << endl;
    cout << "ID: " << items[1].getID() << endl;
    cout << "ID: " << items[2].getID() << endl;
    cout << "ID: " << items[3].getID() << endl;
    cout << "ID: " << items[4].getID() << endl;
    cout << "ID: " << items[5].getID() << endl;
    cout << "ID: " << items[6].getID() << endl;
    cout << "ID: " << items[7].getID() << endl;
    cout << "ID: " << items[8].getID() << endl;
    cout << "ID: " << items[9].getID() << endl;
    cout << "ID: " << items[10].getID() << endl;
    cout << "ID: " << items[11].getID() << endl;
    cout << "-----------------------------------" << endl;
*/

}

void Heap::heapInsert(const Patient& newItem) {
    if (size >= MAX_HEAP)
        cout <<"HeapException: Heap full"<< endl;


    items[size] = newItem;


    int place = size;
    int parent = (place - 1)/2;
    while ( (place > 0) && (items[place] < items[parent]) ){
        Patient temp = items[parent];
        items[parent] = items[place];
        items[place] = temp;

        place = parent;
        parent = (place - 1)/2;
    }
    ++size;
    /*cout << "ID: " << items[0].getID() << endl;
    cout << "ID: " << items[1].getID() << endl;
    cout << "ID: " << items[2].getID() << endl;
    cout << "ID: " << items[3].getID() << endl;
    cout << "ID: " << items[4].getID() << endl;
    cout << "ID: " << items[5].getID() << endl;
    cout << "ID: " << items[6].getID() << endl;
    cout << "ID: " << items[7].getID() << endl;
    cout << "ID: " << items[8].getID() << endl;
    cout << "ID: " << items[9].getID() << endl;
    cout << "ID: " << items[10].getID() << endl;
    cout << "ID: " << items[11].getID() << endl;
    cout << "-----------------------------------" << endl;*/

}

void Heap::heapRebuild(int root) {
    int child = 2 * root + 1;    // index of root's left child, if any
    if (child < size) {
        // root is not a leaf so that it has a left child
        int rightChild = child + 1;    // index of a right child, if any
        // If root has right child, find larger child
        if ((rightChild < size) &&
            (items[rightChild] < items[child]))
            child = rightChild;    // index of larger child

        // If root’s item is smaller than larger child, swap values
        if (items[root] > items[child]) {
            Patient temp = items[root];
            items[root] = items[child];
            items[child] = temp;

            // transform the new subtree into a heap
            heapRebuild(child);
        }
    }
}


Patient Heap::getMax() {
    if(heapIsEmpty()){
        cout << "heap is empty" << endl;
    }
    else
        return items[0];
}

Patient Heap::getMin() {

    int heapSize = size;
    Patient minPatient = items[heapSize / 2 + 1];

    for (int i = heapSize / 2 + 2; i < heapSize; ++i) {
        if (items[i].getArrivalTime() < minPatient.getArrivalTime()) {
            minPatient = items[i];
        }
    }

    return minPatient;
}

Patient Heap::getNextPatient(int i) {
    if (i < size) {
        return items[i];
    }
}

