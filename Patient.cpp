
#include "Patient.h"

Patient::Patient() {

}
Patient::Patient(int ID, int priorityN, int arrivalT, int serviceT )  {
    this->setID(ID);
    this->setPriorityNumber(priorityN);
    this->setArrivalTime(arrivalT);
    this->setServiceTime(serviceT);
}
Patient::Patient(int ID, int priorityN, int arrivalT, int serviceT ,int waitingT, int examinationT, bool isExamined)  {
    this->setID(ID);
    this->setPriorityNumber(priorityN);
    this->setWaitingTime(waitingT);
    this->setExaminationTime(examinationT);
    this->setArrivalTime(arrivalT);
    this->setIsExamined(isExamined);
    this->setServiceTime(serviceT);
}

Patient::Patient(const Patient &P) {
    this->setID(P.id);
    this->setPriorityNumber(P.priority);
    this->setArrivalTime(P.arrivalTime);
    this->setExaminationTime(P.examinationTime);
    this->setWaitingTime(P.waitingTime);
    this->setIsExamined(P.isExamined);
    this->setServiceTime(P.serviceTime);
}

void Patient::setID(int newID) {
    this->id = newID;
}

int Patient::getID() {
    return this->id;
}

void Patient::setPriorityNumber(int priorNum) {
    this->priority = priorNum;
}

int Patient::getPriorityNumber() const {
    return priority;
}

void Patient::setArrivalTime(int newArriveTime) {
    this->arrivalTime = newArriveTime;
}

int Patient::getArrivalTime() const {
    return this->arrivalTime;
}

void Patient::setWaitingTime(int newTime) {
    this->waitingTime = newTime;
}

int Patient::getWaitingTime() {
    return this->waitingTime;
}

void Patient::setExaminationTime(int newExamineTime) {
    this->examinationTime = newExamineTime;
}

int Patient::getExaminationTime() {
    return this->examinationTime;
}

int Patient::calculateWaitingTime(int& arriveT, int& examineT) {
    return examineT-arriveT;
}

void Patient::setIsExamined(bool isExamined) {
    this->isExamined = isExamined;
}

void Patient::setServiceTime(int newServiceTime) {
    this->serviceTime = newServiceTime;
}

int Patient::getServiceTime() {
    return this->serviceTime;
}

// CHANGE OPERATORS
// bool Patient::operator<(const Patient &other) const {
//     if(arrivalTime == other.arrivalTime){
//         return priority > other.priority;
//     }
//     return arrivalTime < other.arrivalTime;
// }

// bool Patient::operator>(const Patient &other) const {
//     if(arrivalTime == other.arrivalTime){
//         return priority > other.priority;
//     }
//     return arrivalTime > other.arrivalTime;
// }

bool Patient::operator>(const Patient &other) const {
    if(priority == other.priority){
        return arrivalTime > other.arrivalTime;
    }
    return priority < other.priority;
}

bool Patient::operator<(const Patient &other) const {
    if(priority == other.priority){
        return arrivalTime < other.arrivalTime;
    }
    return priority > other.priority;
}
