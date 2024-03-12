#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

#include "PatientPQ.h"
#include "Doctor.h"
#include "DoctorPQ.h"

struct Answer{
    int doctor, patient, at, wait;
};

int main(int argc, char *argv[]) {

    if (argc < 3) {
        cerr << "Usage: " << argv[0] << " <inputfilename> <avgwaitingtime>" << endl;
        return 1;
    }


    string inputFile = argv[1];
    int maxAverageWaitingTime;
    maxAverageWaitingTime = stoi(argv[2]);

    ifstream input_file(inputFile);

    if (!input_file.is_open()) {
        cerr << " cannot use file : " << inputFile << endl;
        return 1;
    }

    int numOfPatients;
    input_file >> numOfPatients;

    // PatientPQ waitingPatients;
    // DoctorPQ availableDoctors;

    // CHANGE
    // ONCE DYNAMIC ARRAYLA PATIENTLARI AL, DIREKT  PQ YA INSERT ETMENE GEREK YOK
    Patient *patients = new Patient[numOfPatients];

    for (int i = 0; i < numOfPatients; ++i) {
        Patient patient;
        patient.setIsExamined(false);
        input_file >> patient.id >> patient.priority >> patient.arrivalTime >> patient.serviceTime;
        patients[i] = patient;
    }

    input_file.close();

    int l = 1 , r = numOfPatients;
    int minDoctors = numOfPatients;
    Answer *minimumAnswer;
    int ansSum = 0;

    while(l <= r){  // ( 1 <= number of patients)
        int mid = (l + r) / 2;
        int sum = 0;

        DoctorPQ availableDoctors;
        DoctorPQ busyDoctors;

        int simulationRange = maxAverageWaitingTime * numOfPatients;

        PatientPQ waitingPatients;
        int index = 0;

        // initialize doctors
        for(int i = 0 ; i < mid ; i++){
            // avail.push({i , 0});
            Doctor newDoctor;
            newDoctor.setID(i);
            newDoctor.setEndExaminationTime(0);
            newDoctor.setIsAvailable(true);
            availableDoctors.pqInsert(newDoctor);
        }

        Answer *tempAnswer = new Answer[numOfPatients];
        int ansIndex = 0;

        while(true){

            int currentTime = -1;

            // no available doctor, time is first available to be doctor's lower end time
            if(availableDoctors.pqIsEmpty()){
                currentTime = busyDoctors.getHighest().getEndExaminationTime();
            }

            // process waiting patient
            // bütün arrivalı currentdan düşük olanı al
            while(index < numOfPatients && patients[index].arrivalTime <= currentTime){
                waitingPatients.pqInsert(patients[index]);
                index += 1;
            }

            if(waitingPatients.pqIsEmpty()){
                // all patients examined --> stop simulation
                if(index == numOfPatients) {
                    break;
                }
                // if there is another a patient arrival <= current simulation time
                // insert in waiting patients
                waitingPatients.pqInsert(patients[index]);
                index += 1;
            }

            // after processing all patients arrival time < currentTime
            // if examination ends for doctor, delete from busy doctors and add it to available
            while(!busyDoctors.pqIsEmpty() && busyDoctors.getHighest().getEndExaminationTime() <= waitingPatients.getHighest2().getArrivalTime()){
                Doctor curr = busyDoctors.getHighest();
                curr.setIsAvailable(true);
                availableDoctors.pqInsert(curr);
                busyDoctors.pqDelete();
            }

            int waitTime = 0;
            int startExaminationTime = waitingPatients.getHighest2().getArrivalTime();
            int doctorID = -1;

            // no available doctor, patients waiting, increase patient waiting times
            if(availableDoctors.pqIsEmpty()){
                startExaminationTime = busyDoctors.getHighest().getEndExaminationTime(); // smallest time a doctor will be available
                waitTime = startExaminationTime - waitingPatients.getHighest2().getArrivalTime(); // update waiting time

                Doctor dc = busyDoctors.getHighest();
                doctorID = busyDoctors.getHighest().getID();
                busyDoctors.pqDelete();  // a doctor is available so delete it from pq
                dc.setEndExaminationTime(startExaminationTime + waitingPatients.getHighest2().getServiceTime()); // set new end examination time for doctor

                dc.setIsAvailable(false);
                busyDoctors.pqInsert(dc);
            }
            else{
                // there is available doctor , cure patient
                doctorID = availableDoctors.getHighest().getID();
                waitTime = max(0,availableDoctors.getHighest().getEndExaminationTime() - waitingPatients.getHighest2().getArrivalTime());
                Doctor dc = availableDoctors.getHighest();
                availableDoctors.pqDelete();
                doctorID = dc.getID();
                dc.setEndExaminationTime(startExaminationTime + waitingPatients.getHighest2().getServiceTime() + waitTime); // set new end examination time for doctor
                dc.setIsAvailable(false);
                busyDoctors.pqInsert(dc);
            }
            simulationRange -= waitTime; // decrease maximum waiting time possible

            tempAnswer[ansIndex].doctor = doctorID;
            tempAnswer[ansIndex].patient = waitingPatients.getHighest2().getID();
            tempAnswer[ansIndex].at = startExaminationTime;
            tempAnswer[ansIndex].wait = waitTime; // total waiting time
            sum += waitTime;
            ansIndex += 1; // index of printing struct

            waitingPatients.pqDelete();
        }
        if(simulationRange >= 0){ // if simulation does not end,
            minDoctors = mid;  // divide doctors
            ansSum = sum; // assign total waiting time
            minimumAnswer = tempAnswer;  //print answers
            r = mid - 1; // patients with arrival < current time is in simulation, go with smaller arrivals
        }
        else {
            l = mid + 1; // patients arrival < current are processed, go with larger arrivals
        }
    }

    cout << "Minimum number of doctors required: " << minDoctors << endl;

    double averageWaitingTime = static_cast<double>(ansSum) / numOfPatients;

    cout << "Simulation with " << minDoctors << " doctors:" << endl;

    for(int index = 0 ; index < numOfPatients ; index++){
        cout << "Doctor " << minimumAnswer[index].doctor << " takes patient " << minimumAnswer[index].patient << " at minute "
             << minimumAnswer[index].at
             << " (wait " << minimumAnswer[index].wait << ")"
             << endl;
    }
    cout << "Average waiting time: " << averageWaitingTime << " minutes" << endl;

    return 0;
}