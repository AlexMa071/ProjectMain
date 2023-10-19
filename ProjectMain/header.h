#pragma once
#define MAX_NAME_LENGTH 51


// ��������� ��� �����
struct Doctor {
    char lastName[50];  // ������� �����
    char firstName[50]; // ��� �����
    char middleName[50]; // �������� �����
    int birthYear;  // ��� �������� �����
    char position[50]; // ��������� �����
    char phone[20]; // ����� �������� �����
    char workingWard[50]; // �������� ������, � ������� �������� ����
};

// ��������� ��� ��������
struct Patient {
    char lastName[50]; // ������� ��������
    char firstName[50]; // ��� ��������
    char middleName[50]; // �������� ��������
    int birthYear; // ��� �������� ��������
    char diagnosis[100]; // ��������� ������� ��������
    char admissionDate[11]; // ���� ����������� ��������
    Doctor attendingDoctor; // ����, ����������� ��������
    char tests[100]; //  ������ ��������
    char dischargeDate[11]; // ���� ������� ��������
    char ward[50]; // �������� ������, � ������� ��������� �������
};

// ��������� ��� ������
struct Ward {
    char name[MAX_NAME_LENGTH]; // �������� ������
    int bedCount; // ���������� �������� � ������
};
