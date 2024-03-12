//
// Created by Lenovo on 20.11.2023.
//
#include "Doctor.h"
#ifndef CS202_HW3_FALL23_DOCTORHEAP_H
#define CS202_HW3_FALL23_DOCTORHEAP_H
const int MAX_HEAP2 = 100000;
typedef Doctor HeapItemType;

class DoctorHeap {
public:
    DoctorHeap();				// default constructor
    // copy constructor and destructor are supplied by the compiler

    bool heapIsEmpty() const;
    void heapInsert(const HeapItemType& newItem);
    void heapDelete();
    Doctor getMin();

protected:
    void heapRebuild(int root);		// Converts the semiheap rooted at
    // index root into a heap
private:
    HeapItemType items[MAX_HEAP2];	// array of heap items
    int          size;            	// number of heap items
};

#endif //CS202_HW3_FALL23_DOCTORHEAP_H
