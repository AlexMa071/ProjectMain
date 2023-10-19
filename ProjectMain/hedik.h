#pragma once
#include <iostream>
#include "hospital.h"
#include "header.h"
#include <cstdio>
using namespace std;

void displayMainMenu() {
    cout << "------------------------" << endl;
    cout << "������� ����:" << endl;
    cout << "1. ������� ���������� � �����" << endl;
    cout << "2. ������� ���������� � ��������" << endl;
    cout << "3. ������� ���������� � ������" << endl;
    cout << "4. ������� ���������� � ��������" << endl;
    cout << "5. ����� ������" << endl;
    cout << "6. ������ ������" << endl;
    cout << "7. ������ ���������" << endl;
    cout << "0. �����" << endl;
    cout << "------------------------" << endl;
}

void saveWards(const Ward wards[], int wardCount) {
    FILE* file;
    if (fopen_s(&file, "wards.bin", "wb") == 0) {
        fwrite(wards, sizeof(Ward), wardCount, file);
        fclose(file);
    }
    else {
        printf("�� ������� ������� ���� ��� ���������� �����.\n");
    }
}

// ������� ��� �������� ���������� � �������
void loadWards(Ward wards[], int& wardCount) {
    FILE* file;
    if (fopen_s(&file, "wards.bin", "rb") == 0) {
        fread(wards, sizeof(Ward), 100, file);
        wardCount = ftell(file) / sizeof(Ward);
        fclose(file);
    }
    else {
        printf("�� ������� ������� ���� ��� �������� �����.\n");
    }
}

void loadDoctors(Doctor doctors[], int& doctorCount) {
    FILE* file;
    if (fopen_s(&file, "doctors.bin", "rb") == 0) {
        fread(doctors, sizeof(Doctor), 100, file);
        doctorCount = ftell(file) / sizeof(Doctor);
        fclose(file);
    }
    else {
        printf("�� ������� ������� ���� ��� �������� ������.\n");
    }
}

void loadPatients(Patient patients[], int& patientCount) {
    FILE* file;
    if (fopen_s(&file, "patients.bin", "rb") == 0) {
        fread(patients, sizeof(Patient), 1000, file);
        patientCount = ftell(file) / sizeof(Patient);
        fclose(file);
    }
    else {
        printf("�� ������� ������� ���� ��� �������� ���������.\n");
    }
}

void saveDoctors(const Doctor doctors[], int doctorCount) {
    FILE* file;
    if (fopen_s(&file, "doctors.bin", "wb") == 0) {
        fwrite(doctors, sizeof(Doctor), doctorCount, file);
        fclose(file);
    }
    else {
        printf("�� ������� ������� ���� ��� ���������� ������.\n");
    }
}

void savePatients(const Patient patients[], int patientCount) {
    FILE* file;
    if (fopen_s(&file, "patients.bin", "wb") == 0) {
        fwrite(patients, sizeof(Patient), patientCount, file);
        fclose(file);
    }
    else {
        printf("�� ������� ������� ���� ��� ���������� ���������.\n");
    }
}


void addDoctor(Doctor newDoctor, Doctor doctors[], int& doctorCount) {
    if (doctorCount < 100) {
        doctors[doctorCount++] = newDoctor;
    }
    else {
        cout << "���������� ������������ ���������� ������." << endl;
    }
}

void displayDoctorInfo(Doctor doctor) {
    cout << "�������: " << doctor.lastName << endl;
    cout << "���: " << doctor.firstName << endl;
    cout << "��������: " << doctor.middleName << endl;
    cout << "��� ��������: " << doctor.birthYear << endl;
    cout << "���������: " << doctor.position << endl;
    cout << "�������: " << doctor.phone << endl;
}

// ������� ��� ������ � ����������
void addPatient(Patient newPatient, Patient patients[], int& patientCount) {
    if (patientCount < 1000) {
        patients[patientCount++] = newPatient;
    }
    else {
        cout << "���������� ������������ ���������� ���������." << endl;
    }
}

void displayPatientInfo(Patient patient) {
    cout << "�������: " << patient.lastName << endl;
    cout << "���: " << patient.firstName << endl;
    cout << "��������: " << patient.middleName << endl;
    cout << "��� ��������: " << patient.birthYear << endl;
    cout << "�������: " << patient.diagnosis << endl;
    cout << "���� �����������: " << patient.admissionDate << endl;
    cout << "�������: " << patient.tests << endl;
    cout << "���� �������: " << patient.dischargeDate << endl;
}

// ������� ��� ������ � ��������
void addWard(Ward newWard, Ward wards[], int& wardCount) {
    if (wardCount < 100) {
        wards[wardCount++] = newWard;
    }
    else {
        cout << "���������� ������������ ���������� �����." << endl;
    }
}

void displayWardInfo(Ward ward) {
    cout << "�������� ������: " << ward.name << endl;
    cout << "���������� ��������: " << ward.bedCount << endl;
}


void removePatientByName(const char* firstName, const char* lastName, Patient patients[], int& patientCount) {
    for (int i = 0; i < patientCount; ++i) {
        if (strcmp(patients[i].firstName, firstName) == 0 && strcmp(patients[i].lastName, lastName) == 0) {
            for (int j = i; j < patientCount - 1; ++j) {
                patients[j] = patients[j + 1];
            }
            --patientCount;
            cout << "������� ������." << endl;
            return;
        }
    }
    cout << "������� �� ������." << endl;
}

// ������� ��� �������� ����� �� ����� � �������
void removeDoctorByName(const char* firstName, const char* lastName, Doctor doctors[], int& doctorCount) {
    for (int i = 0; i < doctorCount; ++i) {
        if (strcmp(doctors[i].firstName, firstName) == 0 && strcmp(doctors[i].lastName, lastName) == 0) {
            for (int j = i; j < doctorCount - 1; ++j) {
                doctors[j] = doctors[j + 1];
            }
            --doctorCount;
            cout << "���� ������." << endl;
            return;
        }
    }
    cout << "���� �� ������." << endl;
}

// ������� ��� �������� ������ �� ��������
void removeWardByName(const char* name, Ward wards[], int& wardCount) {
    for (int i = 0; i < wardCount; ++i) {
        if (strcmp(wards[i].name, name) == 0) {
            for (int j = i; j < wardCount - 1; ++j) {
                wards[j] = wards[j + 1];
            }
            --wardCount;
            cout << "������ �������." << endl;
            return;
        }
    }
    cout << "������ �� �������." << endl;
}

void adminPanel(Doctor doctors[], int& doctorCount, Patient patients[], int& patientCount, Ward wards[], int& wardCount) {
    int adminChoice;

    do {
        cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
        cout << "����� ������:" << endl;
        cout << "1. �������� �����" << endl;
        cout << "2. �������� ��������" << endl;
        cout << "3. �������� ������" << endl;
        cout << "4. ������� ��������" << endl;
        cout << "5. ������� �����" << endl;
        cout << "6. ������� ������" << endl;
        cout << "0. ��������� � ������� ����" << endl;
        cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;

        cin >> adminChoice;

        switch (adminChoice) {
        case 1: {
                Doctor newDoctor;
                cout << "������� ������� �����: ";
                cin >> newDoctor.lastName;
                cout << "������� ��� �����: ";
                cin >> newDoctor.firstName;
                cout << "������� �������� �����: ";
                cin >> newDoctor.middleName;
                cout << "������� ��� �������� �����: ";
                cin >> newDoctor.birthYear;
                cout << "������� ��������� �����: ";
                cin >> newDoctor.position;
                cout << "������� ����� �������� �����: ";
                cin >> newDoctor.phone;
                cout << "������� �������� ������, � ������� �������� ����: ";
                cin >> newDoctor.workingWard;

                addDoctor(newDoctor, doctors, doctorCount);

                cout << "���� ������� ��������!" << endl;
                break;
        }
        case 2: {
                Patient newPatient;
                cout << "������� ������� ��������: ";
                cin >> newPatient.lastName;
                cout << "������� ��� ��������: ";
                cin >> newPatient.firstName;
                cout << "������� �������� ��������: ";
                cin >> newPatient.middleName;
                cout << "������� ��� �������� ��������: ";
                cin >> newPatient.birthYear;
                cout << "������� ������� ��������: ";
                cin >> newPatient.diagnosis;
                cout << "������� ���� ����������� ��������: ";
                cin >> newPatient.admissionDate;
                cout << "������� ������� ��������: ";
                cin >> newPatient.tests;
                cout << "������� ���� ������� ��������: ";
                cin >> newPatient.dischargeDate;
                cout << "������� �������� ������, � ������� ��������� �������: ";
                cin >> newPatient.ward;

                addPatient(newPatient, patients, patientCount);

                cout << "������� ������� ��������!" << endl;
                break;
        }
        case 3: {
                Ward newWard;
                cout << "������� �������� ������: ";
                cin >> newWard.name;
                cout << "������� ���������� �������� � ������: ";
                cin >> newWard.bedCount;

                addWard(newWard, wards, wardCount);

                cout << "������ ������� ���������!" << endl;
                break;
        }
        case 4: {
            char firstName[MAX_NAME_LENGTH];
            char lastName[MAX_NAME_LENGTH];
            cout << "������� ��� �������� ��� ��������: ";
            cin >> firstName;
            cout << "������� ������� �������� ��� ��������: ";
            cin >> lastName;
            removePatientByName(firstName, lastName, patients, patientCount);
            break;
        }
        case 5: {
            char firstName[MAX_NAME_LENGTH];
            char lastName[MAX_NAME_LENGTH];
            cout << "������� ��� ����� ��� ��������: ";
            cin >> firstName;
            cout << "������� ������� ����� ��� ��������: ";
            cin >> lastName;
            removeDoctorByName(firstName, lastName, doctors, doctorCount);
            break;
        }
        case 6: {
            char wardName[MAX_NAME_LENGTH];
            cout << "������� �������� ������ ��� ��������: ";
            cin >> wardName;
            removeWardByName(wardName, wards, wardCount);
            break;
        }
        }
    } while (adminChoice != 0);
}



