//
// Created by Lenovo on 16.11.2023.
//
#include "Doctor.h"

Doctor::Doctor() {
    this->setID(0);
    this->setIsAvailable(true);
    this->setEndExaminationTime(0);
}

Doctor::Doctor(int ID, bool available, int endTime) {
    this->setID(ID);
    this->setIsAvailable(available);
    this->setEndExaminationTime(endTime);
}

Doctor::Doctor(const Doctor &D) {
    this->setID(D.id);
    this->setIsAvailable(D.isAvailable);
    this->setEndExaminationTime(D.endExaminationTime);
}

void Doctor::setID(int newID) {
    this->id = newID;
}

int Doctor::getID() {
    return id;
}

void Doctor::setIsAvailable(bool newStatus) {
    this->isAvailable = newStatus;
}

bool Doctor::getIsAvailable() {
    return this->isAvailable;
}

void Doctor::setEndExaminationTime(int newEndT) {
    this->endExaminationTime = newEndT;
}

int Doctor::getEndExaminationTime() {
    return this->endExaminationTime;
}

// CHANGE OPERATOR
// bool Doctor::operator<(const Doctor &other) const {
//     return id < other.id;
// }

bool Doctor::operator<(const Doctor &other) const {
    if(isAvailable){
        if(id == other.id){
            return endExaminationTime < other.endExaminationTime;
        }
        return id < other.id;
    }
    if(endExaminationTime == other.endExaminationTime){
        return id < other.id;
    }
    return endExaminationTime < other.endExaminationTime;
}

