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

            cout << "������� ������� �����: ";
            cin >> searchLastName;
            cout << "������� ��� �����: ";
            cin >> searchFirstName;

            bool found = false;

            for (int i = 0; i < doctorCount; ++i) {
                if (strcmp(doctors[i].lastName, searchLastName) == 0 && strcmp(doctors[i].firstName, searchFirstName) == 0) {
                    found = true;
                    cout << endl;
                    cout << "���� #" << i + 1 << ":" << endl;
                    cout << "�������: " << doctors[i].lastName << endl;
                    cout << "���: " << doctors[i].firstName << endl;
                    cout << "��������: " << doctors[i].middleName << endl;
                    cout << "��� ��������: " << doctors[i].birthYear << endl;
                    cout << "���������: " << doctors[i].position << endl;
                    cout << "�������: " << doctors[i].phone << endl;
                    cout << "������: " << doctors[i].workingWard << endl;
                    cout << "------------------------" << endl;
                }
            }

            if (!found) {
                cout << "���� � ����� �������� � ������ �� ������." << endl;
            }

            break;
        }
        case 2: {
            for (int i = 0; i < patientCount; ++i) {
                cout << endl;
                cout << "������� #" << i + 1 << ":" << endl;
                cout << "�������: " << patients[i].lastName << endl;
                cout << "���: " << patients[i].firstName << endl;
                cout << "��������: " << patients[i].middleName << endl;
                cout << "��� ��������: " << patients[i].birthYear << endl;
                cout << "�������: " << patients[i].diagnosis << endl;
                cout << "���� �����������: " << patients[i].admissionDate << endl;
                cout << "�������: " << patients[i].tests << endl;
                cout << "���� �������: " << patients[i].dischargeDate << endl;
                cout << "������: " << patients[i].ward << endl;
                cout << "------------------------" << endl;
            }
            break;
        }
        case 3: {
            for (int i = 0; i < wardCount; ++i) {
                cout << endl;
                cout << "������ #" << i + 1 << ":" << endl;
                cout << "��������: " << wards[i].name << endl;
                cout << "���������� ��������: " << wards[i].bedCount << endl;
                cout << "------------------------" << endl;
            }
            break;
        }
        case 4: {
            cout << endl;
            cout << "���������� �����: " << wardCount << endl;
            cout << "���������� ���������: " << patientCount << endl;
            cout << "���������� ������: " << doctorCount << endl;
            break;
        }
        case 5: {
            adminPanel(doctors, doctorCount, patients, patientCount, wards, wardCount);
            break;
        }
        case 6: {
            for (int i = 0; i < doctorCount; ++i) {
                cout << "���� #" << i + 1 << ":" << endl;
                cout << "�������: " << doctors[i].lastName << endl;
                cout << "���: " << doctors[i].firstName << endl;
                cout << "��������: " << doctors[i].middleName << endl;
                cout << "��� ��������: " << doctors[i].birthYear << endl;
                cout << "���������: " << doctors[i].position << endl;
                cout << "�������: " << doctors[i].phone << endl;
                cout << "������: " << doctors[i].workingWard << endl;
                cout << "------------------------" << endl;
            }
            break;
        }
        case 7: {
            for (int i = 0; i < patientCount; ++i) {
                cout << "������� #" << i + 1 << ":" << endl;
                cout << "�������: " << patients[i].lastName << endl;
                cout << "���: " << patients[i].firstName << endl;
                cout << "��������: " << patients[i].middleName << endl;
                cout << "��� ��������: " << patients[i].birthYear << endl;
                cout << "�������: " << patients[i].diagnosis << endl;
                cout << "���� �����������: " << patients[i].admissionDate << endl;
                cout << "�������: " << patients[i].tests << endl;
                cout << "���� �������: " << patients[i].dischargeDate << endl;
                cout << "������: " << patients[i].ward << endl;
                cout << "------------------------" << endl;
            }
            break;
        }
        case 0: {
            saveData(doctors, doctorCount, patients, patientCount, wards, wardCount);
            break;
        }
        default: {
            cout << "�������� �����. ����������, ���������� �����." << endl;
            break;
        }
        }

    } while (choice != 0);

    // �����������  ������
    delete[] doctors;
    delete[] patients;
    delete[] wards;

    return 0;
}