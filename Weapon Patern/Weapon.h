#pragma once
#include<iostream>
#include<vector>
using namespace std;

class Weapon abstract {
protected:
	string name;
	float caliber;
public:
	Weapon(const string &name="No name",float caliber=0.0) :name(name),caliber(caliber) {

	}
	virtual void reload()const = 0;
	virtual void Shoot()const = 0;
	virtual void print()const = 0;
	virtual Weapon* clone() = 0;
};
class Rifel :public Weapon {
public:
	Rifel(const string& name = "No name", float caliber = 0.0) :Weapon(name,caliber) {

	}
	void reload()const override {
		cout << "Change mag in rifel" << endl;
	}
	void Shoot()const override {
		cout << "Shoot from rifel" << endl;
	}
	void print()const override {
		cout << "Name->" << name << endl;
		cout << "Caliber->" << caliber << endl;
	}
	Weapon* clone() override {
		return new Rifel(*this);
	}
};
class Pistol :public Weapon {
public:
	Pistol(const string& name = "No name", float caliber = 0.0) :Weapon(name, caliber) {

	}
	void reload()const override {
		cout << "Change mag in pistol" << endl;
	}
	void Shoot()const override {
		cout << "Shoot from rifel" << endl;
	}
	void print()const override {
		cout << "Name->" << name << endl;
		cout << "Caliber->" << caliber << endl;
	}
	Weapon* clone() override {
		return new Pistol(*this);
	}
};
class WeaponStorage {
	vector<Weapon*>weapons;
public:
	void pushBack(Weapon* weapen) {
		weapons.push_back(weapen);
	}
	Weapon* getWeapon(int id) {
		if (id<0 || id>weapons.size()) {
			return nullptr;
		}
		return weapons[id]->clone();
	}
	void print() {
		for (auto w : weapons) {
			w->print();
		}
	}
};