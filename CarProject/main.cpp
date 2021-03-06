// CarProject.cpp: ���������� ����� ����� ��� ����������� ����������.
////

/*
0
0
300
200
300
1989
5
kia rio
somebrand
450
1.9
1

3
1
300
200
180
2005
6
Nissan Liberty
some brend
209
1.5
0

*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include "KiaBuilder.h"
#include "NissanBuilder.h"
#include "ToyotaBuilder.h"
#include "VazBuilder.h"

using namespace std;

#define MAX_IGNORE 10000
#define MAX_MY_STR 250

enum class Choice //������������� ���, ������ ����
{
    PRINT_ALL = 1,
    MAKE_KIA,
    MAKE_NISSAN,
    MAKE_TOYOTA,
    MAKE_VAZ,
    SAVE_ALL,
    LOAD_ALL,
    EDIT_CAR,
    REMOVE_CAR,
    SHOW_CAR,
    EXIT
};

Choice makeChoice() {
    cout << "[1] Print all cars" << endl; // ��������� ��� ���������� 
    cout << "[2] Create KIA" << endl; // ������� ���
    cout << "[3] Create Nissan" << endl; //������� ������
    cout << "[4] Create Toyota" << endl; //������� ������
    cout << "[5] Create VAZ" << endl; //������� ���
    cout << "[6] Save all cars to files" << endl; //��������� ������ � �����
    cout << "[7] Load all cars from files" << endl; //��������� ������ �� ������
    cout << "[8] Edit specific car" << endl; //�������� ������
    cout << "[9] Remove specific car" << endl; //������� ������
    cout << "[10] Print specific car" << endl; //������� ������ �� �����
    cout << "[other] Exit application" << endl; //�����
    int choice;
    if (!(cin >> choice)) { //���� ��������� �� �����...
        return Choice::EXIT; // �� ����������� CMD_EXIT ���� ������ Choice 
    }
    if (choice < 1 || choice >= (int)Choice::EXIT) { // ���� < 1 ��� >=11, �� 
        return Choice::EXIT; //����������� CMD_EXIT
    }
    return (Choice)choice; //���� ��� ��, ���������� ��������� ����� ����
}

void cleanAll(vector<Car*>& cars) {
    for (auto car : cars) { // ����������� �������� �� ������� �������� �������
        delete car; //�������, ��� ��� ������ ���� ������� � ������� new (���� ������, �� �����)
    }
    cars.clear(); //������� ������ �������
}

void printAll(vector<Car*>& cars) { //����� ����� �� �����
    int carNumber = 1; 
    for (auto car : cars) { // ����������� �������� �� ������� �������� �������, ���������� �������� �������� �������� ������� ����������, ����������� ��� car(���������)
        cout << "Car #" << carNumber << endl; 
        cout << "======" << endl;
        car->display(); //�������� ����� display()
        cout << endl;
        carNumber++; //��������� � ���� ������
    }
}

void skipLine() {  //������� ������
    string tmp;
    getline(cin, tmp); //��������� ������, ������ �� �������� �� ����� ������
}

void inputMainFeatures(CarBuilder& builder) { //���� ����� �������������
    while (true) {
        string color; 
        cout << "Color (black, yellow, red, pink, blue): ";
        cin >> color; //��������� ����
        if (color == "black") { //���� ������, ��
            builder.setColor(Color::BLACK); // ����������� ������
        }
        else if (color == "yellow") { //���� ������, ��
            builder.setColor(Color::YELLOW); //�������� ������
        }
        /*� ��� ����� � ���������� �������*/
        else if (color == "red") {
            builder.setColor(Color::RED);
        }
        else if (color == "pink") {
            builder.setColor(Color::PINK);
        }
        else if (color == "blue") {
            builder.setColor(Color::BLUE);
        }
        else { //���� ������� ���-�� ������, ������ ������������ ����������� ������ �����
            cout << "Wrong color. Please try again" << endl;
            continue;
        }
        break;
    }

    //��� ���������
    while (true) { 
        string engineType;
        cout << "Engine type (diesel, injector): ";
        cin >> engineType;
        if (engineType == "diesel") {
            builder.setEngineType(EngineType::DIESEL);
        }
        else if (engineType == "injector") {
            builder.setEngineType(EngineType::INJECTOR);
        }
        else {
            cout << "Wrong engine type. Please try again" << endl;
            continue;
        }
        break;
    }

    //�������� ������
    int x, y, z; 
    cout << "Length of car (cm): ";
    while (!(cin >> x)) { //���� �� ������� �����
        cin.clear(); //�������
        cin.ignore(MAX_IGNORE, '\n'); //����������
        cout << "It's not a number. Try again" << endl;
        cout << "Length of car (cm): ";
    }
    cout << "Width of car (cm): ";
    while (!(cin >> y)) { //���� �� ������� ������
        cin.clear(); //������� 
        cin.ignore(MAX_IGNORE, '\n'); //���������� 
        cout << "It's not a number. Try again" << endl;
        cout << "Width of car (cm): ";
    }
    cout << "Height of car (cm): ";
    while (!(cin >> z)) { //���� �� ������� ������
        cin.clear(); //�������
        cin.ignore(MAX_IGNORE, '\n'); //����������
        cout << "It's not a number. Try again" << endl;
        cout << "Height of car (cm): ";
    }
    VehicleSize vehicleSize(x, y, z); //�������� ��������
    builder.setSize(vehicleSize); 

    //��� ��������
    cout << "Year of creation: "; 
    int creationYear;
    while (!(cin >> creationYear)) { //���� �� ������� ��� ��������, ��
        cin.clear(); //�������
        cin.ignore(MAX_IGNORE, '\n'); //���������� 
        cout << "It's not a number. Try again" << endl;
        cout << "Year of creation: ";
    }
    builder.setYearOfBirthday(creationYear); //�������� �-�� ��� ������� ������

    // ���������� ������
    cout << "Doors count: "; 
    int doorsCount;
    while (!(cin >> doorsCount)) { //���� �� �������
        cin.clear();
        cin.ignore(MAX_IGNORE, '\n');
        cout << "It's not a number. Try again" << endl;
        cout << "Doors count: ";
    }
    builder.setDoorsCount(doorsCount); //����� �-�� ��� ������� builder

    //������
    cout << "Model: ";
    skipLine(); //
    string model;
    getline(cin, model); //��������� ������
    builder.setModel(model); //����� �-�� ��� ������� builder

    //����� ���
    cout << "Tire brand: ";
    string tireBrand;
    getline(cin, tireBrand); //��������� ����� ���
    builder.setTireBrand(tireBrand);

    //����� ���������
    cout << "Trunk volume (450 or other): ";
    double trunkVolume;
    while (!(cin >> trunkVolume)) { //���� �� �������
        cin.clear();
        cin.ignore(MAX_IGNORE, '\n');
        cout << "It's not a number. Try again" << endl;
        cout << "Trunk volume (450 or other): ";
    }
    builder.setTrunkVolume(trunkVolume);

    //����� ���������
    cout << "Engine volume (1.7 or other): ";
    double engineVolume;
    while (!(cin >> engineVolume)) { //���� �� �������
        cin.clear();
        cin.ignore(MAX_IGNORE, '\n');
        cout << "It's not a number. Try again" << endl;
        cout << "Engine volume (1.7 or other): ";
    }
    builder.setEngineVolume(engineVolume);
}

Car* makeKia() {
    KiaBuilder builder; //������� ������ builder ���� KiaBuilder
    inputMainFeatures(builder);//��������� ����� �������������� �����
    cout << "Has heated mirrors (type \"yes\" if it's right): ";
    string answer;
    cin >> answer;
    builder.setHeatedMirrors(answer == "yes");
    return builder.getResult(); //���������� ����� ����, ����������� ������
}

Car* makeNissan() {
    NissanBuilder builder;
    inputMainFeatures(builder);
    cout << "Has heated seats (type \"yes\" if it's right): ";
    string answer;
    cin >> answer;
    builder.setHeatedSeats(answer == "yes");
    return builder.getResult();
}

Car* makeToyota() {
    ToyotaBuilder builder;
    inputMainFeatures(builder);
    cout << "Has automatic transmission (type \"yes\" if it's right): ";
    string answer;
    cin >> answer;
    builder.setAutomaticTransmission(answer == "yes");
    return builder.getResult();
}

Car* makeVaz() {
    VazBuilder builder;
    inputMainFeatures(builder);
    cout << "Trunk is on roof (type \"yes\" if it's right): ";
    string answer;
    cin >> answer;
    builder.setTrunkOnRoof(answer == "yes");
    return builder.getResult();
}

// true on success; otherwise false
bool loadCar(CarBuilder& builder, ifstream& file, int carNumber, const char* path) {
    int color, engineType, x, y, z, year, doorsCount;
    string model, tireBrand;
    double trunkVolume, engineVolume;
    if (!(file >> color >> engineType >> x >> y >> z >> year >>
        doorsCount)) { //������ �� ����� ������, ���� �� ������� ����� ������� �..
        if (!file.eof()) { // ..� ���� ��� �� ����� �����, ��
            char* msg = new char[MAX_MY_STR]; //
            sprintf_s(msg, MAX_MY_STR, "Bad format for car #%d in file \"%s\"", carNumber, path); //������� ���������� �� ������
            throw msg; //����������� ������
        }
        return false;
    }
    string tmp;
    getline(file, tmp); //��������� ������. �� ��������� ������� �����, ����� �� ��������� �������, "�������" ������
    getline(file, model); //��������� ������ ������ 7
    getline(file, tireBrand); //��������� ����� ���
    file >> trunkVolume; //��������� ����� ���������
    file >> engineVolume;
    /*������ ������, ������� �������*/
    builder.setColor((Color)color);
    builder.setEngineType((EngineType)engineType);
    VehicleSize vehicleSize(x, y, z);
    builder.setSize(vehicleSize);
    builder.setYearOfBirthday(year);
    builder.setDoorsCount(doorsCount);
    builder.setModel(model);
    builder.setTireBrand(tireBrand);
    builder.setTrunkVolume(trunkVolume);
    builder.setEngineVolume(engineVolume);
    return true;
}

void loadAll(vector<Car*>& cars) {
    bool specInfo;
    ifstream kiaFile("kia"); //��������� ���� � ������ ���
    int carNumber = 0;
    if (kiaFile.is_open()) { //���� ������� ������� ����
        while (true) {
            carNumber++;
            KiaBuilder builder; //������� ������ ���� KiaBuilder
            bool success;
            try { 
                success = loadCar(builder, kiaFile, carNumber, "kia"); //������ ����������
            }
            catch (const char* msg) { //���� ���-�� ����� �� ���
                cerr << msg << endl; //������� ��������� �� ������
                delete msg; //������� �� ������
                delete builder.getResult(); //�������, ��� ��� ���������, �� �� ���������
                break;
            }
            if (!success) { //////////////////////////////////////////////////////////////////////////////////
                delete builder.getResult();
                break;
            }
            kiaFile >> specInfo; //��������� �������������� ��������������
            builder.setHeatedMirrors(specInfo); //��������
            cars.push_back(builder.getResult()); //��������� ���������� ������ � �������������� ������
        }
        kiaFile.close(); //��������� ����
    }
    ifstream nissanFile("nissan");
    if (nissanFile.is_open()) {
        carNumber = 0;
        while (true) {
            carNumber++;
            NissanBuilder builder;
            bool success;
            try {
                success = loadCar(builder, nissanFile, carNumber, "nissan");
            }
            catch (const char* msg) {
                cerr << msg << endl;
                delete msg;
                delete builder.getResult();
                break;
            }
            if (!success) {
                delete builder.getResult();
                break;
            }
            nissanFile >> specInfo;
            builder.setHeatedSeats(specInfo);
            cars.push_back(builder.getResult());
        }
        nissanFile.close();
    }
    ifstream toyotaFile("toyota");
    if (toyotaFile.is_open()) {
        carNumber = 0;
        while (true) {
            carNumber++;
            ToyotaBuilder builder;
            bool success;
            try {
                success = loadCar(builder, toyotaFile, carNumber, "toyota");
            }
            catch (const char* msg) {
                cerr << msg << endl;
                delete msg;
                delete builder.getResult();
                break;
            }
            if (!success) {
                delete builder.getResult();
                break;
            }
            toyotaFile >> specInfo;
            builder.setAutomaticTransmission(specInfo);
            cars.push_back(builder.getResult());
        }
        toyotaFile.close();
    }
    ifstream vazFile("vaz");
    if (vazFile.is_open()) {
        carNumber = 0;
        while (true) {
            carNumber++;
            VazBuilder builder;
            bool success;
            try {
                success = loadCar(builder, vazFile, carNumber, "vaz");
            }
            catch (const char* msg) {
                cerr << msg << endl;
                delete msg;
                delete builder.getResult();
                break;
            }
            if (!success) {
                delete builder.getResult();
                break;
            }
            vazFile >> specInfo;
            builder.setTrunkOnRoof(specInfo);
            cars.push_back(builder.getResult());
        }
        vazFile.close();
    }
}

void eraseContent(const char* file_path) { //������� ���� 
    ofstream ofs; 
    ofs.open(file_path); //������� ���� ��� ������
    ofs.close(); //�������
}

void saveAll(vector<Car*>& cars) {
    eraseContent("kia"); 
    eraseContent("nissan");
    eraseContent("toyota");
    eraseContent("vaz");
    for (auto car : cars) { //��� ������ ������ �������� ����� save()
        car->save();
    }
}

// returns index of the required car
int findCar(vector<Car*>& cars) {
    int carNumber;
    while (true) { 
        cout << "Choose car by number: ";
        // ���� ������� ����� ������
        if (cin >> carNumber) {
            // ���� ����� ������ >= 1 && <= ���������� �����, �� ������� �� ����� while
            if (carNumber >= 1 && carNumber <= (int)(cars.size())) {
                break;
            }
        }
        else {
            // ���� ������������ ��� ���-��, �� ���������� ������, ��
            // ������� ���� ������� ������ ��� ����� �� cin.
            cin.clear();
            // ���������� ��� �������� ������������� ������� ������ �� � ������� ������ '\n',
            // �� �� ����� ��� MAX_IGNORE ��������.
            cin.ignore(MAX_IGNORE, '\n');
        }
        // ������ ������������ ����������� ������ ������ �����
        cout << "Wrong choice. Try again" << endl;
    }
    // ���������� ����� ������ - 1, �� ���������� � 0
    return carNumber - 1;
}

//��������� ������
void editCar(vector<Car*>& cars) { 
    int carIndex = findCar(cars); //������� ������ ������
    Car* newCar = nullptr; //��������� ���� car
    int choice = 1;
    cout << "[1] KIA" << endl;
    cout << "[2] Nissan" << endl;
    cout << "[3] Toyota" << endl;
    cout << "[4] VAZ" << endl;
    cout << "[other] back" << endl;
    if (!(cin >> choice)) { // ���� �� ������� �����
        cin.clear(); // ������� ���� ������� ������ ��� ����� �� cin.
        cin.ignore(MAX_IGNORE, '\n'); // ���������� ��� �������� ������������� ������� ������ �� � ������� ������ '\n',
                                     // �� �� ����� ��� MAX_IGNORE ��������.
        return;
    }
    if (choice < 1 || choice > 4) { //���� ����� < 1 || > 4, �� �������
        return;
    }
    switch (choice) {
    case 1:
        newCar = makeKia();
        break;
    case 2:
        newCar = makeNissan();
        break;
    case 3:
        newCar = makeToyota();
        break;
    case 4:
        newCar = makeVaz();
        break;
    }
    delete cars[carIndex]; //������� ������
    cars[carIndex] = newCar; //������ �� �� ����� ��������� ������
}

//�������� ������
void removeCar(vector<Car*>& cars) { 
    int carIndex = findCar(cars); //�������� ������ ������
    delete cars[carIndex]; //������� ������
    cars.erase(cars.begin() + carIndex); //������� ������ � ������
}

//����� ������
void showCar(vector<Car*>& cars) {
    int carIndex = findCar(cars); //�������� ������ ������
    cars[carIndex]->display(); //���������� ��
}

int main()
{
    vector<Car*> cars; //������� ������ cars ���� car* ��������������� �������
    Choice choice;
    do {
        choice = makeChoice(); //�������� �������, ������� ������ ������������
        switch (choice) {
        case Choice::PRINT_ALL: //����� ����� 
            if (cars.empty())
            {
                cout << "All the cars are removed or the cars are not created" << endl;
            }
            else {
                printAll(cars);
            }
            break;
        case Choice::MAKE_KIA: //�������� ���
            cout << "Creating KIA" << endl;
            cars.push_back(makeKia()); //�������� ����� � ��������� ��� � ����� ������ ����������
            break;
        case Choice::MAKE_NISSAN: //�������� ������
            cout << "Creating Nissan" << endl;
            cars.push_back(makeNissan());
            break;
        case Choice::MAKE_TOYOTA: //�������� ������
            cout << "Creating Toyota" << endl;
            cars.push_back(makeToyota());
            break;
        case Choice::MAKE_VAZ: //�������� ���
            cout << "Creating VAZ" << endl;
            cars.push_back(makeVaz());
            break;
        case Choice::SAVE_ALL: //��������� � ����
            saveAll(cars);
            break;
        case Choice::LOAD_ALL: //�������� ������ �� �����
            cleanAll(cars); //�������� ���� ������ �����
            loadAll(cars); //������ �� �����
            break;
        case Choice::EDIT_CAR: //�������� ������
            if (cars.empty())
            {
                cout << "All the cars are removed or the cars are not created" << endl;
            }
            else {
                editCar(cars);
            }
            break;
        case Choice::REMOVE_CAR: //������� ������
            if (cars.empty())
            {
                cout << "All the cars are removed or the cars are not created" << endl;
            }
            else {
                removeCar(cars);
            }
            break;
        case Choice::SHOW_CAR: //������� ������ �� �����
            if (cars.empty())
            {
                cout << "All the cars are removed or the cars are not created" << endl;
            }
            else {
                showCar(cars);
            }
            break;
        }
    } while (choice != Choice::EXIT); //���� �� �����
    cleanAll(cars); //������� ������
    return 0;
}