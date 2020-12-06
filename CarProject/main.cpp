// CarProject.cpp: определяет точку входа для консольного приложения.
////
/*
TODO:
Исключения с текстом
Ошибки при работе с файлом
*/

/*
1
2
blue
injector
100
50
40
2000
5
KIA Rio
somebrand
1.9
yes
1
3
yellow
diesel
20
30
50
1980
7
Nissan Liberty
some other brand
1.8
no
1
*/

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <vector>
#include "KiaBuilder.h"
#include "NissanBuilder.h"
#include "ToyotaBuilder.h"
#include "VazBuilder.h"

using namespace std;

#define MAX_IGNORE 10000

enum Choice //перечисляемый тип, пункты меню
{
    CMD_PRINT_ALL = 1,
    CMD_MAKE_KIA,
    CMD_MAKE_NISSAN,
    CMD_MAKE_TOYOTA,
    CMD_MAKE_VAZ,
    CMD_SAVE_ALL,
    CMD_LOAD_ALL,
    CMD_EDIT_CAR,
    CMD_REMOVE_CAR,
    CMD_SHOW_CAR,
    CMD_EXIT
};

Choice makeChoice() {
    cout << "[1] Print all cars" << endl; // загрузить все автомобили 
    cout << "[2] Create KIA" << endl; // создать киа
    cout << "[3] Create Nissan" << endl; //создать ниссан
    cout << "[4] Create Toyota" << endl; //создать тайота
    cout << "[5] Create VAZ" << endl; //создать ваз
    cout << "[6] Save all cars to files" << endl; //сохранить машины в файлы
    cout << "[7] Load all cars from files" << endl; //загрузить машины из файлов
    cout << "[8] Edit specific car" << endl; //изменить машину
    cout << "[9] Remove specific car" << endl; //удалить машину
    cout << "[10] Print specific car" << endl; //вывести машину на экран
    cout << "[other] Exit application" << endl; //выход
    int choice;
    if (!(cin >> choice)) {
        return (Choice)CMD_EXIT; //
    }
    if (choice < 1 || choice >= (int)CMD_EXIT) {
        return (Choice)CMD_EXIT;
    }
    return (Choice)choice;
}

void cleanAll(vector<Car*>& cars) {
    for (auto car : cars) {
        delete car;
    }
    cars.clear();
}

void printAll(vector<Car*>& cars) { //вывод машин на экран
    int carNumber = 1; 
    for (auto car : cars) { //
        cout << "Car #" << carNumber << endl; 
        cout << "======" << endl;
        car->display(); 
        cout << endl;
        carNumber++;
    }
}

void skipLine() {
    string tmp;
    getline(cin, tmp);
}

void inputMainFeatures(CarBuilder& builder) { //ввод общих характеристик
    while (true) {
        string color; 
        cout << "Color (black, yellow, red, pink, blue): ";
        cin >> color; //считываем цвет
        if (color == "black") { //если черный, то
            builder.setColor(COLOR_BLACK); // присваиваем черный
        }
        else if (color == "yellow") { //если желтый, то
            builder.setColor(COLOR_YELLOW); //присваивам желтый
        }
        /*и так далее с остальными цветами*/
        else if (color == "red") {
            builder.setColor(COLOR_RED);
        }
        else if (color == "pink") {
            builder.setColor(COLOR_PINK);
        }
        else if (color == "blue") {
            builder.setColor(COLOR_BLUE);
        }
        else { //если введено что-то другое, просим пользователя попробовать ввести снова
            cout << "Wrong color. Please try again" << endl;
            continue;
        }
        break;
    }
    while (true) { //тип двигателя
        string engineType;
        cout << "Engine type (diesel, injector): ";
        cin >> engineType;
        if (engineType == "diesel") {
            builder.setEngineType(ENGINE_TYPE_DIESEL);
        }
        else if (engineType == "injector") {
            builder.setEngineType(ENGINE_TYPE_INJECTOR);
        }
        else {
            cout << "Wrong engine type. Please try again" << endl;
            continue;
        }
        break;
    }
    int x, y, z; //габариты машины
    cout << "Length of car (cm): ";
    cin >> x;
    cout << "Width of car (cm): ";
    cin >> y;
    cout << "Height of car (cm): ";
    cin >> z;
    VehicleSize vehicleSize(x, y, z);
    builder.setSize(vehicleSize);
    cout << "Year of creation: "; //год создания
    int creationYear;
    cin >> creationYear;
    builder.setYearOfBirthday(creationYear);
    cout << "Doors count: "; // количество дверей
    int doorsCount;
    cin >> doorsCount;
    cout << "Model: ";
    skipLine();
    string model;
    getline(cin, model);
    builder.setModel(model);
    cout << "Tire brand: ";
    string tireBrand;
    getline(cin, tireBrand);
    builder.setTireBrand(tireBrand);
    cout << "Trunk volume (1.7 or other): ";
    double trunkVolume;
    cin >> trunkVolume;
    builder.setTrunkVolume(trunkVolume);
}

Car* makeKia() {
    KiaBuilder builder;
    inputMainFeatures(builder);
    cout << "Has heated mirrors (type \"yes\" if it's right): ";
    string answer;
    cin >> answer;
    builder.setHeatedMirrors(answer == "yes");
    return builder.getResult();
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
bool loadCar(CarBuilder& builder, ifstream& file) {
    int color, engineType, x, y, z, year, doorsCount;
    string model, tireBrand;
    double trunkVolume;
    if (!(file >> color >> engineType >> x >> y >> z >> year >>
        doorsCount)) {
        return false;
    }
    string tmp;
    getline(file, tmp);
    getline(file, model);
    getline(file, tireBrand);
    file >> trunkVolume;
    builder.setColor((Color)color);
    builder.setEngineType((EngineType)engineType);
    VehicleSize vehicleSize(x, y, z);
    builder.setSize(vehicleSize);
    builder.setYearOfBirthday(year);
    builder.setDoorsCount(doorsCount);
    builder.setModel(model);
    builder.setTireBrand(tireBrand);
    builder.setTrunkVolume(trunkVolume);
    return true;
}

void loadAll(vector<Car*>& cars) {
    bool specInfo;
    ifstream kiaFile("kia");
    if (kiaFile.is_open()) {
        while (true) {
            KiaBuilder builder;
            if (!loadCar(builder, kiaFile)) {
                delete builder.getResult();
                break;
            }
            kiaFile >> specInfo;
            builder.setHeatedMirrors(specInfo);
            cars.push_back(builder.getResult());
        }
        kiaFile.close();
    }
    ifstream nissanFile("nissan");
    if (nissanFile.is_open()) {
        while (true) {
            NissanBuilder builder;
            if (!loadCar(builder, nissanFile)) {
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
        while (true) {
            ToyotaBuilder builder;
            if (!loadCar(builder, toyotaFile)) {
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
        while (true) {
            VazBuilder builder;
            if (!loadCar(builder, vazFile)) {
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

void eraseContent(const char* file_path) {
    ofstream ofs;
    ofs.open(file_path);
    ofs.close();
}

void saveAll(vector<Car*>& cars) {
    eraseContent("kia");
    eraseContent("nissan");
    eraseContent("toyota");
    eraseContent("vaz");
    for (auto car : cars) {
        car->save();
    }
}

// returns index of the required car
int findCar(vector<Car*>& cars) {
    int carNumber;
    while (true) {
        cout << "Choose car by number: ";
        if (cin >> carNumber) {
            if (carNumber >= 1 && carNumber <= cars.size()) {
                break;
            }
        }
        else {
            cin.clear();
            cin.ignore(MAX_IGNORE, '\n');
        }
        cout << "Wrong choice. Try again" << endl;
    }
    return carNumber - 1;
}

void editCar(vector<Car*>& cars) {
    int carIndex = findCar(cars);
    Car* newCar = nullptr;
    int choice = 1;
    cout << "[1] KIA" << endl;
    cout << "[2] Nissan" << endl;
    cout << "[3] Toyota" << endl;
    cout << "[4] VAZ" << endl;
    cout << "[other] back" << endl;
    if (!(cin >> choice)) {
        cin.clear();
        cin.ignore(MAX_IGNORE, '\n');
        return;
    }
    if (choice < 1 || choice > 4) {
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
    delete cars[carIndex];
    cars[carIndex] = newCar;
}

void removeCar(vector<Car*>& cars) {
    int carIndex = findCar(cars);
    delete cars[carIndex];
    cars.erase(cars.begin() + carIndex);
}

void showCar(vector<Car*>& cars) {
    int carIndex = findCar(cars);
    cars[carIndex]->display();
}

int main()
{
    vector<Car*> cars; //создаем вектор типа car* неопределенного размера
    Choice choice;
    do {
        choice = makeChoice();
        switch (choice) {
        case CMD_PRINT_ALL:
            printAll(cars);
            break;
        case CMD_MAKE_KIA:
            cout << "Creating KIA" << endl;
            cars.push_back(makeKia());
            break;
        case CMD_MAKE_NISSAN:
            cout << "Creating Nissan" << endl;
            cars.push_back(makeNissan());
            break;
        case CMD_MAKE_TOYOTA:
            cout << "Creating Toyota" << endl;
            cars.push_back(makeToyota());
            break;
        case CMD_MAKE_VAZ:
            cout << "Creating VAZ" << endl;
            cars.push_back(makeVaz());
            break;
        case CMD_LOAD_ALL:
            loadAll(cars);
            break;
        case CMD_SAVE_ALL:
            saveAll(cars);
            break;
        case CMD_EDIT_CAR:
            editCar(cars);
            break;
        case CMD_REMOVE_CAR:
            removeCar(cars);
            break;
        case CMD_SHOW_CAR:
            showCar(cars);
            break;
        }
    } while (choice != CMD_EXIT);
    cleanAll(cars);
    return 0;
}