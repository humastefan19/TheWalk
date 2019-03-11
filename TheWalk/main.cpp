#include<iostream>
#include "C:\Facultate Anul 1\Semestrul II\POO\TheWalk\include\Robot.h"
#include "C:\Facultate Anul 1\Semestrul II\POO\TheWalk\include\Item.h"
#include "C:\Facultate Anul 1\Semestrul II\POO\TheWalk\include\Harta.h"
#include "C:\Facultate Anul 1\Semestrul II\POO\TheWalk\include\GestionareJoc.h"
using namespace std;

int main()
{

    cout << "0:SlowRobot\nCaracteristici:\npower=1\nvisual=1\n";
    cout << "1:SpeedyRobot\nCaracteristici:\npower=2\nvisual=2\n";
    cout << "2:FastRobot\nCaracteristici:\npower=3\nvisual=3\n";
    int tip_robot;
    cin >> tip_robot;
	Robot *RO = RobotFactory::Factory(tip_robot);
	GestionareJoc Joc;
	cout << "\nAti ales robotul: ";
	RO->get_type();
	cout << "\n";
    Harta C;
    Joc.runda_joc(RO, C);
	return 0;
}
