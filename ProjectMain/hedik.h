#pragma once
#include <iostream>
#include "hospital.h"
#include "header.h"
#include <cstdio>
using namespace std;

void displayMainMenu() {
    cout << "------------------------" << endl;
    cout << "Главное меню:" << endl;
    cout << "1. Вывести информацию о враче" << endl;
    cout << "2. Вывести информацию о пациенте" << endl;
    cout << "3. Вывести информацию о палате" << endl;
    cout << "4. Вывести информацию о больнице" << endl;
    cout << "5. Админ панель" << endl;
    cout << "6. Список врачей" << endl;
    cout << "7. Список пациентов" << endl;
    cout << "0. Выход" << endl;
    cout << "------------------------" << endl;
}

void saveWards(const Ward wards[], int wardCount) {
    FILE* file;
    if (fopen_s(&file, "wards.bin", "wb") == 0) {
        fwrite(wards, sizeof(Ward), wardCount, file);
        fclose(file);
    }
    else {
        printf("Не удалось открыть файл для сохранения палат.\n");
    }
}

// Функция для загрузки информации о палатах
void loadWards(Ward wards[], int& wardCount) {
    FILE* file;
    if (fopen_s(&file, "wards.bin", "rb") == 0) {
        fread(wards, sizeof(Ward), 100, file);
        wardCount = ftell(file) / sizeof(Ward);
        fclose(file);
    }
    else {
        printf("Не удалось открыть файл для загрузки палат.\n");
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
        printf("Не удалось открыть файл для загрузки врачей.\n");
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
        printf("Не удалось открыть файл для загрузки пациентов.\n");
    }
}

void saveDoctors(const Doctor doctors[], int doctorCount) {
    FILE* file;
    if (fopen_s(&file, "doctors.bin", "wb") == 0) {
        fwrite(doctors, sizeof(Doctor), doctorCount, file);
        fclose(file);
    }
    else {
        printf("Не удалось открыть файл для сохранения врачей.\n");
    }
}

void savePatients(const Patient patients[], int patientCount) {
    FILE* file;
    if (fopen_s(&file, "patients.bin", "wb") == 0) {
        fwrite(patients, sizeof(Patient), patientCount, file);
        fclose(file);
    }
    else {
        printf("Не удалось открыть файл для сохранения пациентов.\n");
    }
}


void addDoctor(Doctor newDoctor, Doctor doctors[], int& doctorCount) {
    if (doctorCount < 100) {
        doctors[doctorCount++] = newDoctor;
    }
    else {
        cout << "Достигнуто максимальное количество врачей." << endl;
    }
}

void displayDoctorInfo(Doctor doctor) {
    cout << "Фамилия: " << doctor.lastName << endl;
    cout << "Имя: " << doctor.firstName << endl;
    cout << "Отчество: " << doctor.middleName << endl;
    cout << "Год рождения: " << doctor.birthYear << endl;
    cout << "Должность: " << doctor.position << endl;
    cout << "Телефон: " << doctor.phone << endl;
}

// Функции для работы с пациентами
void addPatient(Patient newPatient, Patient patients[], int& patientCount) {
    if (patientCount < 1000) {
        patients[patientCount++] = newPatient;
    }
    else {
        cout << "Достигнуто максимальное количество пациентов." << endl;
    }
}

void displayPatientInfo(Patient patient) {
    cout << "Фамилия: " << patient.lastName << endl;
    cout << "Имя: " << patient.firstName << endl;
    cout << "Отчество: " << patient.middleName << endl;
    cout << "Год рождения: " << patient.birthYear << endl;
    cout << "Диагноз: " << patient.diagnosis << endl;
    cout << "Дата поступления: " << patient.admissionDate << endl;
    cout << "Анализы: " << patient.tests << endl;
    cout << "Дата выписки: " << patient.dischargeDate << endl;
}

// Функции для работы с палатами
void addWard(Ward newWard, Ward wards[], int& wardCount) {
    if (wardCount < 100) {
        wards[wardCount++] = newWard;
    }
    else {
        cout << "Достигнуто максимальное количество палат." << endl;
    }
}

void displayWardInfo(Ward ward) {
    cout << "Название палаты: " << ward.name << endl;
    cout << "Количество кроватей: " << ward.bedCount << endl;
}


void removePatientByName(const char* firstName, const char* lastName, Patient patients[], int& patientCount) {
    for (int i = 0; i < patientCount; ++i) {
        if (strcmp(patients[i].firstName, firstName) == 0 && strcmp(patients[i].lastName, lastName) == 0) {
            for (int j = i; j < patientCount - 1; ++j) {
                patients[j] = patients[j + 1];
            }
            --patientCount;
            cout << "Пациент удален." << endl;
            return;
        }
    }
    cout << "Пациент не найден." << endl;
}

// Функция для удаления врача по имени и фамилии
void removeDoctorByName(const char* firstName, const char* lastName, Doctor doctors[], int& doctorCount) {
    for (int i = 0; i < doctorCount; ++i) {
        if (strcmp(doctors[i].firstName, firstName) == 0 && strcmp(doctors[i].lastName, lastName) == 0) {
            for (int j = i; j < doctorCount - 1; ++j) {
                doctors[j] = doctors[j + 1];
            }
            --doctorCount;
            cout << "Врач удален." << endl;
            return;
        }
    }
    cout << "Врач не найден." << endl;
}

// Функция для удаления палаты по названию
void removeWardByName(const char* name, Ward wards[], int& wardCount) {
    for (int i = 0; i < wardCount; ++i) {
        if (strcmp(wards[i].name, name) == 0) {
            for (int j = i; j < wardCount - 1; ++j) {
                wards[j] = wards[j + 1];
            }
            --wardCount;
            cout << "Палата удалена." << endl;
            return;
        }
    }
    cout << "Палата не найдена." << endl;
}

void adminPanel(Doctor doctors[], int& doctorCount, Patient patients[], int& patientCount, Ward wards[], int& wardCount) {
    int adminChoice;

    do {
        cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
        cout << "Админ панель:" << endl;
        cout << "1. Добавить врача" << endl;
        cout << "2. Добавить пациента" << endl;
        cout << "3. Добавить палату" << endl;
        cout << "4. Удалить пациента" << endl;
        cout << "5. Удалить врача" << endl;
        cout << "6. Удалить палату" << endl;
        cout << "0. Вернуться в главное меню" << endl;
        cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;

        cin >> adminChoice;

        switch (adminChoice) {
        case 1: {
                Doctor newDoctor;
                cout << "Введите фамилию врача: ";
                cin >> newDoctor.lastName;
                cout << "Введите имя врача: ";
                cin >> newDoctor.firstName;
                cout << "Введите отчество врача: ";
                cin >> newDoctor.middleName;
                cout << "Введите год рождения врача: ";
                cin >> newDoctor.birthYear;
                cout << "Введите должность врача: ";
                cin >> newDoctor.position;
                cout << "Введите номер телефона врача: ";
                cin >> newDoctor.phone;
                cout << "Введите название палаты, в которой работает врач: ";
                cin >> newDoctor.workingWard;

                addDoctor(newDoctor, doctors, doctorCount);

                cout << "Врач успешно добавлен!" << endl;
                break;
        }
        case 2: {
                Patient newPatient;
                cout << "Введите фамилию пациента: ";
                cin >> newPatient.lastName;
                cout << "Введите имя пациента: ";
                cin >> newPatient.firstName;
                cout << "Введите отчество пациента: ";
                cin >> newPatient.middleName;
                cout << "Введите год рождения пациента: ";
                cin >> newPatient.birthYear;
                cout << "Введите диагноз пациента: ";
                cin >> newPatient.diagnosis;
                cout << "Введите дату поступления пациента: ";
                cin >> newPatient.admissionDate;
                cout << "Введите анализы пациента: ";
                cin >> newPatient.tests;
                cout << "Введите дату выписки пациента: ";
                cin >> newPatient.dischargeDate;
                cout << "Введите название палаты, в которой находится пациент: ";
                cin >> newPatient.ward;

                addPatient(newPatient, patients, patientCount);

                cout << "Пациент успешно добавлен!" << endl;
                break;
        }
        case 3: {
                Ward newWard;
                cout << "Введите название палаты: ";
                cin >> newWard.name;
                cout << "Введите количество кроватей в палате: ";
                cin >> newWard.bedCount;

                addWard(newWard, wards, wardCount);

                cout << "Палата успешно добавлена!" << endl;
                break;
        }
        case 4: {
            char firstName[MAX_NAME_LENGTH];
            char lastName[MAX_NAME_LENGTH];
            cout << "Введите имя пациента для удаления: ";
            cin >> firstName;
            cout << "Введите фамилию пациента для удаления: ";
            cin >> lastName;
            removePatientByName(firstName, lastName, patients, patientCount);
            break;
        }
        case 5: {
            char firstName[MAX_NAME_LENGTH];
            char lastName[MAX_NAME_LENGTH];
            cout << "Введите имя врача для удаления: ";
            cin >> firstName;
            cout << "Введите фамилию врача для удаления: ";
            cin >> lastName;
            removeDoctorByName(firstName, lastName, doctors, doctorCount);
            break;
        }
        case 6: {
            char wardName[MAX_NAME_LENGTH];
            cout << "Введите название палаты для удаления: ";
            cin >> wardName;
            removeWardByName(wardName, wards, wardCount);
            break;
        }
        }
    } while (adminChoice != 0);
}



