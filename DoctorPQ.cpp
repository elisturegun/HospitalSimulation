//
// Created by Lenovo on 20.11.2023.
//
#include "DoctorPQ.h"

bool DoctorPQ::pqIsEmpty() const {
    return h.heapIsEmpty();
}

void DoctorPQ::pqInsert(const PQItemType2 &newItem) {
    h.heapInsert(newItem);
}

void DoctorPQ::pqDelete() {
    h.heapDelete();
}

PQItemType2 DoctorPQ::getHighest() {
    return h.getMin();
}

