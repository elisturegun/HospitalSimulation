//
// Created by Lenovo on 18.11.2023.
//
//
// Created by Lenovo on 16.11.2023.
//
/**
* Author : OYKU ELIS TUREGUN
* ID: 21902976
* Section : 1
* Homework : 3
* Description : PRIORITY QUEUE CLASS
*/
#include "PatientPQ.h"



bool PatientPQ::pqIsEmpty() const {
    return h.heapIsEmpty();
}

void PatientPQ::pqInsert(const PQItemType& newItem){


    h.heapInsert(newItem);


}

void PatientPQ::pqDelete(){


    h.heapDelete();


}

PQItemType PatientPQ::getHighest(int i) {

    return h.getNextPatient(i);

}
PQItemType PatientPQ::getHighest2(){
    return h.getMax();
}

