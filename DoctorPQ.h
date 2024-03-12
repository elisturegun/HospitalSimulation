//
// Created by Lenovo on 20.11.2023.
//

#ifndef CS202_HW3_FALL23_DOCTORPQ_H
#define CS202_HW3_FALL23_DOCTORPQ_H
#include "Doctor.h"
#include "DoctorHeap.h"
typedef Doctor PQItemType2;

class DoctorPQ {
public:
    // default constructor, copy constructor, and destructor
    // are supplied by the compiler

    // priority-queue operations:
    bool pqIsEmpty() const;
    void pqInsert(const PQItemType2& newItem);
    void pqDelete();
    PQItemType2 getHighest();

private:
    DoctorHeap h;
};
#endif //CS202_HW3_FALL23_DOCTORPQ_H
