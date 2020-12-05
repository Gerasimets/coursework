// CarProject.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include "KiaBuilder.h"
#include "NissanBuilder.h"
#include "ToyotaBuilder.h"
#include "VazBuilder.h"

using namespace std;

enum Choice //перечисляемый тип, пункты меню
{
    CMD_LOAD_ALL,
    CMD_MAKE_KIA,
    CMD_MAKE_NISSAN,
    CMD_MAKE_TOYOTA,
    CMD_MAKE_VAZ,
    CMD_EXIT
};

Choice makeChoice() {
    cout << "[1] Print all cars from file" << endl; // загрузить все автомобили из файла 
    cout << "[2] Create KIA" << endl; // создать киа
    cout << "[3] Create Nissan" << endl; //создать ниссан
    cout << "[4] Create Toyota" << endl; //создать тайота
    cout << "[5] Create VAZ" << endl; //создать ваз
    cout << "[other] Exit application" << endl; //выход
    int choice;
    cin >> choice;
    if (choice < 1 || choice > 5) {
        return CMD_EXIT;
    }
    return (Choice)choice;
}

void loadAll() {

}

void makeKia() {
    KiaBuilder builder;
    
}

void makeNissan() {

}

void makeToyota() {

}

void makeVaz() {

}

int main()
{
    Choice choice;
    do {
        choice = makeChoice();
        switch (choice) {
        case CMD_LOAD_ALL:
            loadAll();
            break;
        case CMD_MAKE_KIA:
            makeKia();
            break;
        case CMD_MAKE_NISSAN:
            makeNissan();
            break;
        case CMD_MAKE_TOYOTA:
            makeToyota();
            break;
        case CMD_MAKE_VAZ:
            makeVaz();
            break;
        }
    } while (choice != CMD_EXIT);
    _getch(); ///////////////////////////////////
    return 0;
}

