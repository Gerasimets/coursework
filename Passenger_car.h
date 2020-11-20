#pragma once
#include <string>
using namespace std;

class Passenger_car // создаем класс Легковые машины
{
protected:
	//color // цвет машины
	//тип двигателя
	int motor_size;//объем двигателя
	//габариты: длина, ширина, высота
	int release_year;//год выпуска
	int doors_numbers;//число дверей
	//модель
	//марка шин
	int size_boot;//объем багажника
	
public:
	//virtual ~Passenger_car(); // виртуальный деструктор
};