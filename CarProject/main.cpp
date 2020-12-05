// CarProject.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include "KiaBuilder.h"
#include "NissanBuilder.h"
#include "ToyotaBuilder.h"
#include "VazBuilder.h"

using namespace std;

enum Choice //������������� ���, ������ ����
{
    CMD_LOAD_ALL,
    CMD_MAKE_KIA,
    CMD_MAKE_NISSAN,
    CMD_MAKE_TOYOTA,
    CMD_MAKE_VAZ,
    CMD_EXIT
};

Choice makeChoice() {
    cout << "[1] Print all cars from file" << endl; // ��������� ��� ���������� �� ����� 
    cout << "[2] Create KIA" << endl; // ������� ���
    cout << "[3] Create Nissan" << endl; //������� ������
    cout << "[4] Create Toyota" << endl; //������� ������
    cout << "[5] Create VAZ" << endl; //������� ���
    cout << "[other] Exit application" << endl; //�����
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

