// CarProject.cpp: определяет точку входа для консольного приложения.
////

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
    if (!(cin >> choice)) { //если напечатал не число...
        return (Choice)CMD_EXIT; // то возвраещаем CMD_EXIT типа данных Choice 
    }
    if (choice < 1 || choice >= (int)CMD_EXIT) { // если < 1 или >=11, то 
        return (Choice)CMD_EXIT; //возвраещаем CMD_EXIT
    }
    return (Choice)choice; //если все ок, возвращаем выбранный пункт меню
}

void cleanAll(vector<Car*>& cars) {
    for (auto car : cars) { // Выполняется итерация по каждому элементу массива
        delete car; //очищаем, так как машины были созданы с помощью new (саму машину, не адрес)
    }
    cars.clear(); //очищаем список адресов
}

void printAll(vector<Car*>& cars) { //вывод машин на экран
    int carNumber = 1; 
    for (auto car : cars) { // Выполняется итерация по каждому элементу массива, присваивая значение текущего элемента массива переменной, объявленной как car(указатель)
        cout << "Car #" << carNumber << endl; 
        cout << "======" << endl;
        car->display(); //вызываем метод display()
        cout << endl;
        carNumber++; //переходим к след машине
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
            builder.setColor(COLOR_YELLOW); //передаем желтый
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
    while (!(cin >> x)) { //пока не считали длину
        cin.clear(); //очищаем
        cin.ignore(MAX_IGNORE, '\n'); //игнорируем
        cout << "It's not a number. Try again" << endl;
        cout << "Length of car (cm): ";
    }
    cout << "Width of car (cm): ";
    while (!(cin >> y)) { //пока не считали ширину
        cin.clear(); //очищаем 
        cin.ignore(MAX_IGNORE, '\n'); //игнорируем 
        cout << "It's not a number. Try again" << endl;
        cout << "Width of car (cm): ";
    }
    cout << "Height of car (cm): ";
    while (!(cin >> z)) { //пока не считали высоту
        cin.clear(); //очищаем
        cin.ignore(MAX_IGNORE, '\n'); //игнорируем
        cout << "It's not a number. Try again" << endl;
        cout << "Height of car (cm): ";
    }
    VehicleSize vehicleSize(x, y, z); //передаем габариты
    builder.setSize(vehicleSize); 
    cout << "Year of creation: "; //год создания
    int creationYear;
    while (!(cin >> creationYear)) { //пока не считали год создания, то
        cin.clear(); //очищаем
        cin.ignore(MAX_IGNORE, '\n'); //игнорируем 
        cout << "It's not a number. Try again" << endl;
        cout << "Year of creation: ";
    }
    builder.setYearOfBirthday(creationYear); //вызываем ф-ию для объекта класса 
    cout << "Doors count: "; // количество дверей
    int doorsCount;
    while (!(cin >> doorsCount)) { //пока не считали
        cin.clear();
        cin.ignore(MAX_IGNORE, '\n');
        cout << "It's not a number. Try again" << endl;
        cout << "Doors count: ";
    }
    builder.setDoorsCount(doorsCount); //вызыв ф-ии для объекта builder
    cout << "Model: ";
    skipLine(); //
    string model;
    getline(cin, model); //считываем модель
    builder.setModel(model); //вызыв ф-ии для объекта builder
    cout << "Tire brand: ";
    string tireBrand;
    getline(cin, tireBrand); //считываем марку шин
    builder.setTireBrand(tireBrand);
    cout << "Trunk volume (1.7 or other): ";
    double trunkVolume;
    while (!(cin >> trunkVolume)) { //пока не считали
        cin.clear();
        cin.ignore(MAX_IGNORE, '\n');
        cout << "It's not a number. Try again" << endl;
        cout << "Trunk volume (1.7 or other): ";
    }
    builder.setTrunkVolume(trunkVolume);
}

Car* makeKia() {
    KiaBuilder builder; //создаем объект builder типа KiaBuilder
    inputMainFeatures(builder);//назначаем общие характеристики машин
    cout << "Has heated mirrors (type \"yes\" if it's right): ";
    string answer;
    cin >> answer;
    builder.setHeatedMirrors(answer == "yes");
    return builder.getResult(); //возвращает адрес того, гдехранится машина
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
    double trunkVolume;
    if (!(file >> color >> engineType >> x >> y >> z >> year >>
        doorsCount)) { //читаем из файла данные, если не удалось этого сделать и..
        if (!file.eof()) { // ..и если это не конец файла, то
            char* msg = new char[MAX_MY_STR]; //////////////////////////////
            sprintf_s(msg, MAX_MY_STR, "Bad format for car #%d in file \"%s\"", carNumber, path); //выводим информацию об ошибке
            throw msg; //выбрасываем ошибку
        }
        return false;
    }
    string tmp;
    getline(file, tmp); //считываем строку. тк последним считали число, чтобы не считывать пустоту, "съедае" строку
    getline(file, model); //считываем модель машины 7
    getline(file, tireBrand); //считываем марку шин
    file >> trunkVolume; //считываем объем двигателя
    /*задаем данные, которые считали*/
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
    ifstream kiaFile("kia"); //открываем файл с именем киа
    int carNumber = 0;
    if (kiaFile.is_open()) { //если удалось открыть файл
        while (true) {
            carNumber++;
            KiaBuilder builder; //создали объект типа KiaBuilder
            bool success;
            try { 
                success = loadCar(builder, kiaFile, carNumber, "kia"); //задаем информацию
            }
            catch (const char* msg) { //если что-то пошло не так
                cerr << msg << endl; //выведет сообщение об ошибке
                delete msg; //удаляем из памяти
                delete builder.getResult(); //удаляем, так как создавали, но не применили
                break;
            }
            if (!success) { /////////////////////////////////////
                delete builder.getResult();
                break;
            }
            kiaFile >> specInfo; //считываем индивидуальную характеристику
            builder.setHeatedMirrors(specInfo); //передаем
            cars.push_back(builder.getResult()); //добавляем полученную машину в результирующий вектор
        }
        kiaFile.close(); //закрываем файл
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

void eraseContent(const char* file_path) { //очищаем файл 
    ofstream ofs; 
    ofs.open(file_path); //открыли файл для записи
    ofs.close(); //закрыли
}

void saveAll(vector<Car*>& cars) {
    eraseContent("kia"); 
    eraseContent("nissan");
    eraseContent("toyota");
    eraseContent("vaz");
    for (auto car : cars) { //для каждой машины вызываем метод save()
        car->save();
    }
}

// returns index of the required car
int findCar(vector<Car*>& cars) {
    int carNumber;
    while (true) { 
        cout << "Choose car by number: ";
        if (cin >> carNumber) { //если считали номер машины
            if (carNumber >= 1 && carNumber <= (int)(cars.size())) { // если номер машины >= 1 && <= количества машин, то идем дальше
                break;
            }
        }
        else { // если что-то не так, то
            cin.clear(); //очищаем
            cin.ignore(MAX_IGNORE, '\n'); //игнорируем
        }
        cout << "Wrong choice. Try again" << endl; //выводим сообщение об ошибке
    }
    return carNumber - 1; //возвращаем номер машины - 1, тк начинается с 0
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
    vector<Car*> cars; //создаем вектор cars типа car* неопределенного размера
    Choice choice;
    do {
        choice = makeChoice(); //получили команду, которую выбрал пользователь
        switch (choice) {
        case CMD_PRINT_ALL: //вывод машин 
            printAll(cars); 
            break;
        case CMD_MAKE_KIA: //создание киа
            cout << "Creating KIA" << endl;
            cars.push_back(makeKia()); //получили адрес и добавляем его в конец списка указателей
            break;
        case CMD_MAKE_NISSAN: //создание ниссан
            cout << "Creating Nissan" << endl;
            cars.push_back(makeNissan());
            break;
        case CMD_MAKE_TOYOTA: //создания тайота
            cout << "Creating Toyota" << endl;
            cars.push_back(makeToyota());
            break;
        case CMD_MAKE_VAZ: //создание ваз
            cout << "Creating VAZ" << endl;
            cars.push_back(makeVaz());
            break;
        case CMD_SAVE_ALL: //сохранить в файл
            saveAll(cars);
            break;
        case CMD_LOAD_ALL: //загрузка данных из файла
            cleanAll(cars); //очистили весь список машин
            loadAll(cars); //грузим из файла
            break;
        case CMD_EDIT_CAR: //изменить машину
            editCar(cars);
            break;
        case CMD_REMOVE_CAR: //удалить машину
            removeCar(cars);
            break;
        case CMD_SHOW_CAR: //вывести машину на экран
            showCar(cars);
            break;
        }
    } while (choice != CMD_EXIT); //пока не выход
    cleanAll(cars); //удаляем машины
    return 0;
}