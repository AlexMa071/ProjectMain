#pragma once
#include "header.h"


// ������� ��� ������ � �������
void addDoctor(Doctor newDoctor, Doctor doctors[], int& doctorCount);
void displayDoctorInfo(Doctor doctor);

// ������� ��� ������ � ����������
void addPatient(Patient newPatient, Patient patients[], int& patientCount);
void displayPatientInfo(Patient patient);

// ������� ��� ������ � ��������
void addWard(Ward newWard, Ward wards[], int& wardCount);
void displayWardInfo(Ward ward);

// ������� ��� ������ � �������
void saveDoctors(const Doctor doctors[], int doctorCount);
void loadDoctors(Doctor doctors[], int& doctorCount);

// ������� ��� ������ � ����������
void savePatients(const Patient patients[], int patientCount);
void loadPatients(Patient patients[], int& patientCount);

// ������� ��� ������ � ��������
void saveWards(const Ward wards[], int wardCount);
void loadWards(Ward wards[], int& wardCount);

// ������� ��� ���������� ������
void saveData(const Doctor doctors[], int doctorCount, const Patient patients[], int patientCount, const Ward wards[], int wardCount);

// ������� ��� �������� ������
void loadData(Doctor doctors[], int& doctorCount, Patient patients[], int& patientCount, Ward wards[], int& wardCount);


// ������� ��� ���������� ������
void saveData(const Doctor doctors[], int doctorCount, const Patient patients[], int patientCount, const Ward wards[], int wardCount) {
    saveDoctors(doctors, doctorCount);
    savePatients(patients, patientCount);
    saveWards(wards, wardCount);
}

// ������� ��� �������� ������
void loadData(Doctor doctors[], int& doctorCount, Patient patients[], int& patientCount, Ward wards[], int& wardCount) {
    loadDoctors(doctors, doctorCount);
    loadPatients(patients, patientCount);
    loadWards(wards, wardCount);
}