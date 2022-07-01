#ifndef TOPPING_H
#define TOPPING_H

#include<iostream>
#include<string>
#include<vector>
using namespace std;

//Definition der Klasse Topping
class Topping{
private:
	string name;
	string allergenes;
	bool specialty;
public:
	Topping(string name, string allergenes = "", bool specialty = false);

	bool is_specialty()const{return specialty;}

	bool operator==(const Topping& t)const{return name == t.name;}

	bool is_allergene(const char&)const;

	string getAllergenes()const{return allergenes;}

	ostream& print(ostream&)const;
};

ostream& operator<<(ostream&, const Topping&);

#endif