#include<iostream>
using namespace std;

class Vehicle	//Транспортное средство
{
	int speed;	//Скорость
public:
	virtual void move() = 0;
};
//Наземное транспортное средство
class GroundVehicle :public Vehicle {};

class Car :public GroundVehicle
{
public:
	void move()override
	{
		cout << "Машина едет на 4-х колесах" << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	//cout << "AbstractBaseClass" << endl;
	Car bmw;
	bmw.move();
}
