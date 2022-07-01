#ifndef PIZZA_H
#define PIZZA_H

#include<iostream>
#include<string>
#include<vector>
#include"topping.h"
using namespace std;

//Standard toppings
//const vector<Topping> standard_toppings{{"Tomato sauce"}, {"Cheese", "G"}};

//Definition der Klasse Pizza
class Pizza{
private:
	vector<Topping> belag;
public:
	Pizza(vector<Topping> erwuenscht = {}, vector<Topping> unerwuenscht = {});

	double price()const;

	string allergenes() const;

	void accommodate(const string& forbidden);

	ostream& print(ostream&)const;
};

ostream& operator<<(ostream&, const Pizza&);

#endif