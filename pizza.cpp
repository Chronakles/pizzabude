#include<iostream>
#include<string>
#include<vector>
#include"topping.h"
#include"pizza.h"
using namespace std;

//Implementierung der Klasse Pizza
Pizza::Pizza(vector<Topping> erwuenscht, vector<Topping> unerwuenscht){
	vector<Topping> toppings{{"Tomato sauce"}, {"Cheese","G"}};

	//Löschen wenn nicht gewollt (enthalten in Vektor unerwuenscht)
	auto it = toppings.begin();
	for(size_t i{0}; i < toppings.size();){
		bool notop = false;
		for(size_t j{0}; j < unerwuenscht.size(); j++){
			if(unerwuenscht.at(j) == toppings.at(i)) notop = true;
		}
		if(notop) toppings.erase(it);
		if(!notop){
			it++; i++;
		}
	}
	
	
	//Gewuenschte Toppings einfügen
	for(size_t i{0}; i < erwuenscht.size(); i++){
		toppings.push_back(erwuenscht.at(i));
	}

	belag = toppings;

	//Doppelte entfernen
	for(size_t i{0}; i < belag.size(); i++){
		for(size_t j{i+1}; j < belag.size();){
			if(belag.at(i) == belag.at(j)) belag.erase(belag.begin()+j);
			else j++;
		}
	}


	if(belag.size() == 0) throw runtime_error("e");
}

double Pizza::price()const{
	double preis{7.00};

	for(size_t i{0}; i < belag.size(); i++){

		if(belag.at(i).is_specialty() && i < 4) preis += 0.5;

		else if(belag.at(i).is_specialty() && i >= 4) preis += 1.5;

		if(!belag.at(i).is_specialty() && i >= 4) preis += 1.0;
	}

	return preis;
	
}

string Pizza::allergenes() const{
	string allergenelist = "A";
	for(char c{'B'}; c < 'S'; c++){
		for(size_t i{0}; i < belag.size(); i++){
			if(belag.at(i).is_allergene(c)){
				allergenelist += c;
				break;
			}
		}	
	}
	return allergenelist;
}

void Pizza::accommodate(const string& forbidden){
	vector<Topping> backup{belag};
	for(size_t i{0}; i < belag.size();){
		bool weiter = true;
		for(size_t j{0}; j < forbidden.size(); j++){

				if(belag.at(i).is_allergene(forbidden.at(j))){ 

					belag.erase(belag.begin()+i);
					weiter = false;
					break;
				}
		}
		if(weiter)i++;
	}
	if(belag.size() == 0){
		belag = backup;
		throw runtime_error("e");
	}
}

ostream& Pizza::print(ostream& o)const{
	o << "[{";
	for(size_t i{0}; i < belag.size(); i++){
		o << belag.at(i);
		if(i < belag.size()-1) o << ", ";
	}
	o << "}, " << price() << " Euro]";
	return o;
}



ostream& operator<<(ostream& o, const Pizza& p){
	return p.print(o);
}

