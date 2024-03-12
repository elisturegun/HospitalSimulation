//
// Created by Lenovo on 16.11.2023.
//

#ifndef CS202_HW3_FALL23_DOCTOR_H
#define CS202_HW3_FALL23_DOCTOR_H
class Doctor{
public:
    Doctor();
    Doctor(int ID, bool available,  int endTime);
    Doctor(Doctor const &D);

    void setID(int newID);
    int getID();

    void setIsAvailable(bool newStatus);
    bool getIsAvailable();

    void setEndExaminationTime( int newEndT);
    int getEndExaminationTime();
    bool operator<(const Doctor& other) const;


    int endExaminationTime;
private:
    int id;
    bool isAvailable;

};
#endif //CS202_HW3_FALL23_DOCTOR_H
