#ifndef CS202_HW3_FALL23_HEAP_H
#define CS202_HW3_FALL23_HEAP_H
/**
* Author : OYKU ELIS TUREGUN
* ID: 21902976
* Section : 1
* Homework : 3
* Description : HEAP CLASS
*/

#include "Patient.h"
const int MAX_HEAP = 100000;


class Heap {
public:
    Heap();				// default constructor
    // copy constructor and destructor are supplied by the compiler

    bool heapIsEmpty() const;
    void heapInsert(const Patient& newItem);
    void heapDelete();
    Patient getMax();
    Patient getMin();
    Patient getNextPatient(int i);



    void heapRebuild(int root);
private:
    // array of heap items
    Patient items[MAX_HEAP];
    int          size;            	// number of heap items
};



#endif //CS202_HW3_FALL23_HEAP_H
