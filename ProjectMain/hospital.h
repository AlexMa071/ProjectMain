#pragma once
#include "header.h"


// Функции для работы с врачами
void addDoctor(Doctor newDoctor, Doctor doctors[], int& doctorCount);
void displayDoctorInfo(Doctor doctor);

// Функции для работы с пациентами
void addPatient(Patient newPatient, Patient patients[], int& patientCount);
void displayPatientInfo(Patient patient);

// Функции для работы с палатами
void addWard(Ward newWard, Ward wards[], int& wardCount);
void displayWardInfo(Ward ward);

// Функции для работы с врачами
void saveDoctors(const Doctor doctors[], int doctorCount);
void loadDoctors(Doctor doctors[], int& doctorCount);

// Функции для работы с пациентами
void savePatients(const Patient patients[], int patientCount);
void loadPatients(Patient patients[], int& patientCount);

// Функции для работы с палатами
void saveWards(const Ward wards[], int wardCount);
void loadWards(Ward wards[], int& wardCount);

// Функция для сохранения данных
void saveData(const Doctor doctors[], int doctorCount, const Patient patients[], int patientCount, const Ward wards[], int wardCount);

// Функция для загрузки данных
void loadData(Doctor doctors[], int& doctorCount, Patient patients[], int& patientCount, Ward wards[], int& wardCount);


// Функция для сохранения данных
void saveData(const Doctor doctors[], int doctorCount, const Patient patients[], int patientCount, const Ward wards[], int wardCount) {
    saveDoctors(doctors, doctorCount);
    savePatients(patients, patientCount);
    saveWards(wards, wardCount);
}

// Функция для загрузки данных
void loadData(Doctor doctors[], int& doctorCount, Patient patients[], int& patientCount, Ward wards[], int& wardCount) {
    loadDoctors(doctors, doctorCount);
    loadPatients(patients, patientCount);
    loadWards(wards, wardCount);
}