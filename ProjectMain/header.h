#pragma once
#define MAX_NAME_LENGTH 51


// Структура для врача
struct Doctor {
    char lastName[50];  // Фамилия врача
    char firstName[50]; // Имя врача
    char middleName[50]; // Отчество врача
    int birthYear;  // Год рождения врача
    char position[50]; // Должность врача
    char phone[20]; // Номер телефона врача
    char workingWard[50]; // Название палаты, в которой работает врач
};

// Структура для пациента
struct Patient {
    char lastName[50]; // Фамилия пациента
    char firstName[50]; // Имя пациента
    char middleName[50]; // Отчество пациента
    int birthYear; // Год рождения пациента
    char diagnosis[100]; // Первичный диагноз пациента
    char admissionDate[11]; // Дата поступления пациента
    Doctor attendingDoctor; // Врач, принимающий пациента
    char tests[100]; //  анализ пациента
    char dischargeDate[11]; // Дата выписки пациента
    char ward[50]; // Название палаты, в которой находится пациент
};

// Структура для палаты
struct Ward {
    char name[MAX_NAME_LENGTH]; // Название палаты
    int bedCount; // Количество кроватей в палате
};
