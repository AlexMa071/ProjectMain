#include <iostream>
#include "hospital.h"
#include "header.h"
#include <cstdio>
#include "hedik.h"
#include <Windows.h>
using namespace std;



int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Doctor* doctors = new Doctor[100];
    int doctorCount = 0;

    Patient* patients = new Patient[1000];
    int patientCount = 0;

    Ward* wards = new Ward[100];
    int wardCount = 0;

    loadDoctors(doctors, doctorCount);
    loadPatients(patients, patientCount);
    loadWards(wards, wardCount);

    int choice;
    do {
        displayMainMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            char searchLastName[MAX_NAME_LENGTH];
            char searchFirstName[MAX_NAME_LENGTH];

            cout << "Введите фамилию врача: ";
            cin >> searchLastName;
            cout << "Введите имя врача: ";
            cin >> searchFirstName;

            bool found = false;

            for (int i = 0; i < doctorCount; ++i) {
                if (strcmp(doctors[i].lastName, searchLastName) == 0 && strcmp(doctors[i].firstName, searchFirstName) == 0) {
                    found = true;
                    cout << endl;
                    cout << "Врач #" << i + 1 << ":" << endl;
                    cout << "Фамилия: " << doctors[i].lastName << endl;
                    cout << "Имя: " << doctors[i].firstName << endl;
                    cout << "Отчество: " << doctors[i].middleName << endl;
                    cout << "Год рождения: " << doctors[i].birthYear << endl;
                    cout << "Должность: " << doctors[i].position << endl;
                    cout << "Телефон: " << doctors[i].phone << endl;
                    cout << "Палата: " << doctors[i].workingWard << endl;
                    cout << "------------------------" << endl;
                }
            }

            if (!found) {
                cout << "Врач с такой фамилией и именем не найден." << endl;
            }

            break;
        }
        case 2: {
            for (int i = 0; i < patientCount; ++i) {
                cout << endl;
                cout << "Пациент #" << i + 1 << ":" << endl;
                cout << "Фамилия: " << patients[i].lastName << endl;
                cout << "Имя: " << patients[i].firstName << endl;
                cout << "Отчество: " << patients[i].middleName << endl;
                cout << "Год рождения: " << patients[i].birthYear << endl;
                cout << "Диагноз: " << patients[i].diagnosis << endl;
                cout << "Дата поступления: " << patients[i].admissionDate << endl;
                cout << "Анализы: " << patients[i].tests << endl;
                cout << "Дата выписки: " << patients[i].dischargeDate << endl;
                cout << "Палаты: " << patients[i].ward << endl;
                cout << "------------------------" << endl;
            }
            break;
        }
        case 3: {
            for (int i = 0; i < wardCount; ++i) {
                cout << endl;
                cout << "Палата #" << i + 1 << ":" << endl;
                cout << "Название: " << wards[i].name << endl;
                cout << "Количество кроватей: " << wards[i].bedCount << endl;
                cout << "------------------------" << endl;
            }
            break;
        }
        case 4: {
            cout << endl;
            cout << "Количество палат: " << wardCount << endl;
            cout << "Количество пациентов: " << patientCount << endl;
            cout << "Количество врачей: " << doctorCount << endl;
            break;
        }
        case 5: {
            adminPanel(doctors, doctorCount, patients, patientCount, wards, wardCount);
            break;
        }
        case 6: {
            for (int i = 0; i < doctorCount; ++i) {
                cout << "Врач #" << i + 1 << ":" << endl;
                cout << "Фамилия: " << doctors[i].lastName << endl;
                cout << "Имя: " << doctors[i].firstName << endl;
                cout << "Отчество: " << doctors[i].middleName << endl;
                cout << "Год рождения: " << doctors[i].birthYear << endl;
                cout << "Должность: " << doctors[i].position << endl;
                cout << "Телефон: " << doctors[i].phone << endl;
                cout << "Палата: " << doctors[i].workingWard << endl;
                cout << "------------------------" << endl;
            }
            break;
        }
        case 7: {
            for (int i = 0; i < patientCount; ++i) {
                cout << "Пациент #" << i + 1 << ":" << endl;
                cout << "Фамилия: " << patients[i].lastName << endl;
                cout << "Имя: " << patients[i].firstName << endl;
                cout << "Отчество: " << patients[i].middleName << endl;
                cout << "Год рождения: " << patients[i].birthYear << endl;
                cout << "Диагноз: " << patients[i].diagnosis << endl;
                cout << "Дата поступления: " << patients[i].admissionDate << endl;
                cout << "Анализы: " << patients[i].tests << endl;
                cout << "Дата выписки: " << patients[i].dischargeDate << endl;
                cout << "Палата: " << patients[i].ward << endl;
                cout << "------------------------" << endl;
            }
            break;
        }
        case 0: {
            saveData(doctors, doctorCount, patients, patientCount, wards, wardCount);
            break;
        }
        default: {
            cout << "Неверный выбор. Пожалуйста, попробуйте снова." << endl;
            break;
        }
        }

    } while (choice != 0);

    // Освобождаем  память
    delete[] doctors;
    delete[] patients;
    delete[] wards;

    return 0;
}