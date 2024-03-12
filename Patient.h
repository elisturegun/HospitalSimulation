
#ifndef CS202_HW3_FALL23_PATIENT_H
#define CS202_HW3_FALL23_PATIENT_H
class Patient{
public:
    Patient();
    Patient(int ID, int priorityN, int arrivalT, int serviceT ,int waitingT, int examinationT, bool isExamined);
    Patient( Patient const &P);
    Patient(int ID, int priorityN, int arrivalT, int serviceT );

    void setID( int newID);
    int getID();

    void setPriorityNumber(int priorNum);
    int getPriorityNumber() const;

    void setArrivalTime( int newArriveTime);
    int getArrivalTime() const;

    void setWaitingTime(int newTime);
    int getWaitingTime();

    void setExaminationTime(int newExamineTime);
    int getExaminationTime();

    int calculateWaitingTime(int &arriveT, int& examineT);

    void setIsExamined( bool isExamined);
    void setServiceTime( int newServiceTime);

    int getServiceTime();

    bool operator<(const Patient &other) const;
    bool operator>(const Patient &other) const;

    int id;
    int priority;
    int arrivalTime;
    int serviceTime;
    int waitingTime;
private:
    int examinationTime;
    bool isExamined;
};
#endif //CS202_HW3_FALL23_PATIENT_H
