//
// Created by Lenovo on 16.11.2023.
//

#ifndef CS202_HW3_FALL23_PATIENTPQ_H
#define CS202_HW3_FALL23_PATIENTPQ_H
#include "Patient.h"
#include "Heap.h"
typedef Patient PQItemType;

class PatientPQ {
public:
    // default constructor, copy constructor, and destructor
    // are supplied by the compiler

    // priority-queue operations:
    bool pqIsEmpty() const;
    void pqInsert(const PQItemType& newItem);
    void pqDelete();
    PQItemType getHighest(int i);
    PQItemType getHighest2();

private:
    Heap h;
};
#endif //CS202_HW3_FALL23_PATIENTPQ_H
