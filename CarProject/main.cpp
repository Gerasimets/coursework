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

enum class Choice //перечисляемый тип, пункты меню
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
        return Choice::EXIT; // то возвраещаем CMD_EXIT типа данных Choice 
    }
    if (choice < 1 || choice >= (int)Choice::EXIT) { // если < 1 или >=11, то 
        return Choice::EXIT; //возвраещаем CMD_EXIT
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

void skipLine() {  ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    string tmp;
    getline(cin, tmp); //считываем 
}

void inputMainFeatures(CarBuilder& builder) { //ввод общих характеристик
    while (true) {
        string color; 
        cout << "Color (black, yellow, red, pink, blue): ";
        cin >> color; //считываем цвет
        if (color == "black") { //если черный, то
            builder.setColor(Color::BLACK); // присваиваем черный
        }
        else if (color == "yellow") { //если желтый, то
            builder.setColor(Color::YELLOW); //передаем желтый
        }
        /*и так далее с остальными цветами*/
        else if (color == "red") {
            builder.setColor(Color::RED);
        }
        else if (color == "pink") {
            builder.setColor(Color::PINK);
        }
        else if (color == "blue") {
            builder.setColor(Color::BLUE);
        }
        else { //если введено что-то другое, просим пользователя попробовать ввести снова
            cout << "Wrong color. Please try again" << endl;
            continue;
        }
        break;
    }

    //тип двигателя
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

    //габариты машины
    int x, y, z; 
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

    //год создания
    cout << "Year of creation: "; 
    int creationYear;
    while (!(cin >> creationYear)) { //пока не считали год создания, то
        cin.clear(); //очищаем
        cin.ignore(MAX_IGNORE, '\n'); //игнорируем 
        cout << "It's not a number. Try again" << endl;
        cout << "Year of creation: ";
    }
    builder.setYearOfBirthday(creationYear); //вызываем ф-ию для объекта класса

    // количество дверей
    cout << "Doors count: "; 
    int doorsCount;
    while (!(cin >> doorsCount)) { //пока не считали
        cin.clear();
        cin.ignore(MAX_IGNORE, '\n');
        cout << "It's not a number. Try again" << endl;
        cout << "Doors count: ";
    }
    builder.setDoorsCount(doorsCount); //вызыв ф-ии для объекта builder

    //модель
    cout << "Model: ";
    skipLine(); //
    string model;
    getline(cin, model); //считываем модель
    builder.setModel(model); //вызыв ф-ии для объекта builder

    //марка шин
    cout << "Tire brand: ";
    string tireBrand;
    getline(cin, tireBrand); //считываем марку шин
    builder.setTireBrand(tireBrand);

    //объем багажника
    cout << "Trunk volume (450 or other): ";
    double trunkVolume;
    while (!(cin >> trunkVolume)) { //пока не считали
        cin.clear();
        cin.ignore(MAX_IGNORE, '\n');
        cout << "It's not a number. Try again" << endl;
        cout << "Trunk volume (450 or other): ";
    }
    builder.setTrunkVolume(trunkVolume);

    //объем двигателя
    cout << "Engine volume (1.7 or other): ";
    double engineVolume;
    while (!(cin >> engineVolume)) { //пока не считали
        cin.clear();
        cin.ignore(MAX_IGNORE, '\n');
        cout << "It's not a number. Try again" << endl;
        cout << "Engine volume (1.7 or other): ";
    }
    builder.setEngineVolume(engineVolume);
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
    double trunkVolume, engineVolume;
    if (!(file >> color >> engineType >> x >> y >> z >> year >>
        doorsCount)) { //читаем из файла данные, если не удалось этого сделать и..
        if (!file.eof()) { // ..и если это не конец файла, то
            char* msg = new char[MAX_MY_STR]; ///////////////////////////////////////////////////////////////////////////////////////////
            sprintf_s(msg, MAX_MY_STR, "Bad format for car #%d in file \"%s\"", carNumber, path); //выводим информацию об ошибке
            throw msg; //выбрасываем ошибку
        }
        return false;
    }
    string tmp;
    getline(file, tmp); //считываем строку. тк последним считали число, чтобы не считывать пустоту, "съедаем" строку
    getline(file, model); //считываем модель машины 7
    getline(file, tireBrand); //считываем марку шин
    file >> trunkVolume; //считываем объем двигателя
    file >> engineVolume;
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
    builder.setEngineVolume(engineVolume);
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
            if (!success) { //////////////////////////////////////////////////////////////////////////////////
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
        // если считали номер машины
        if (cin >> carNumber) {
            // если номер машины >= 1 && <= количества машин, то выходим из цикла while
            if (carNumber >= 1 && carNumber <= (int)(cars.size())) {
                break;
            }
        }
        else {
            // если пользователь ввёл что-то, не являющееся числом, то
            // убираем факт наличия ошибки при вводе из cin.
            cin.clear();
            // игнорируем все введённые пользователем символы вплоть до и включая символ '\n',
            // но не более чем MAX_IGNORE символов.
            cin.ignore(MAX_IGNORE, '\n');
        }
        // просим пользователя попробовать ввести данные снова
        cout << "Wrong choice. Try again" << endl;
    }
    // возвращаем номер машины - 1, тк начинается с 0
    return carNumber - 1;
}

//изменение машины
void editCar(vector<Car*>& cars) { 
    int carIndex = findCar(cars); //находим индекс машины
    Car* newCar = nullptr; //указатель типа car
    int choice = 1;
    cout << "[1] KIA" << endl;
    cout << "[2] Nissan" << endl;
    cout << "[3] Toyota" << endl;
    cout << "[4] VAZ" << endl;
    cout << "[other] back" << endl;
    if (!(cin >> choice)) { // если не считали число
        cin.clear(); // убираем факт наличия ошибки при вводе из cin.
        cin.ignore(MAX_IGNORE, '\n'); // игнорируем все введённые пользователем символы вплоть до и включая символ '\n',
                                     // но не более чем MAX_IGNORE символов.
        return;
    }
    if (choice < 1 || choice > 4) { //если выбор < 1 || > 4, то выходим
        return;
    }
    switch (choice) {
    case 1:
        newCar = makeKia(); //////////////////////////////////////////////////////////////////////////////
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
    delete cars[carIndex]; //удаляем машину
    cars[carIndex] = newCar; //ставим на ее место созданную машину
}

//удаление машины
void removeCar(vector<Car*>& cars) { 
    int carIndex = findCar(cars); //получаем индекс машины
    delete cars[carIndex]; //удаляем машину
    cars.erase(cars.begin() + carIndex); //удаляем доступ к машине
}

//вывод машины
void showCar(vector<Car*>& cars) {
    int carIndex = findCar(cars); //получаем индекс машины
    cars[carIndex]->display(); //отображаем ее
}

int main()
{
    vector<Car*> cars; //создаем вектор cars типа car* неопределенного размера
    Choice choice;
    do {
        choice = makeChoice(); //получили команду, которую выбрал пользователь
        switch (choice) {
        case Choice::PRINT_ALL: //вывод машин 
            if (cars.empty())
            {
                cout << "All the cars are removed or the cars are not created" << endl;
            }
            else {
                printAll(cars);
            }
            break;
        case Choice::MAKE_KIA: //создание киа
            cout << "Creating KIA" << endl;
            cars.push_back(makeKia()); //получили адрес и добавляем его в конец списка указателей
            break;
        case Choice::MAKE_NISSAN: //создание ниссан
            cout << "Creating Nissan" << endl;
            cars.push_back(makeNissan());
            break;
        case Choice::MAKE_TOYOTA: //создания тайота
            cout << "Creating Toyota" << endl;
            cars.push_back(makeToyota());
            break;
        case Choice::MAKE_VAZ: //создание ваз
            cout << "Creating VAZ" << endl;
            cars.push_back(makeVaz());
            break;
        case Choice::SAVE_ALL: //сохранить в файл
            saveAll(cars);
            break;
        case Choice::LOAD_ALL: //загрузка данных из файла
            cleanAll(cars); //очистили весь список машин
            loadAll(cars); //грузим из файла
            break;
        case Choice::EDIT_CAR: //изменить машину
            if (cars.empty())
            {
                cout << "All the cars are removed or the cars are not created" << endl;
            }
            else {
                editCar(cars);
            }
            break;
        case Choice::REMOVE_CAR: //удалить машину
            if (cars.empty())
            {
                cout << "All the cars are removed or the cars are not created" << endl;
            }
            else {
                removeCar(cars);
            }
            break;
        case Choice::SHOW_CAR: //вывести машину на экран
            if (cars.empty())
            {
                cout << "All the cars are removed or the cars are not created" << endl;
            }
            else {
                showCar(cars);
            }
            break;
        }
    } while (choice != Choice::EXIT); //пока не выход
    cleanAll(cars); //удаляем машины
    return 0;
}