#include<iostream>
#include"Weapon.h"
using namespace std;

int main() {
	Weapon* rifel = new Rifel("M-15",5.5);
	rifel->Shoot();
	rifel->reload();
	Weapon* pistol = new Pistol("Glock", 9.0);
	pistol->Shoot();
	pistol->reload();
	WeaponStorage ws;
	ws.pushBack(rifel);
	ws.pushBack(pistol);
	Weapon *anatherRifel = rifel->clone();
	ws.pushBack(anatherRifel);
	ws.print();
	delete rifel;
	delete pistol;
}