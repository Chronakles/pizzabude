#include<iostream>
#include<string>
#include<vector>
#include"topping.h"
using namespace std;

//Implementierung der Klasse Topping

//Konstruktor for Klasse Topping
Topping::Topping(string name, string allergenes, bool specialty):name{name}, allergenes{allergenes}, specialty{specialty}{
	if(name.size() == 0) throw runtime_error("e");
}


bool Topping::is_allergene(const char& c)const{
	for(size_t i{0}; i < allergenes.size(); i++){
		if(allergenes.at(i) == c) return true;
	} 
	return false;
}


ostream& Topping::print(ostream& o)const{
	o << name;

	if(allergenes.size() > 0){
		o << " (";

		for(size_t i{0}; i < allergenes.size(); i++){
			o << allergenes.at(i);
			if(i < allergenes.size()-1) o << ", ";
			else o << ")";
		}
	}
	return o;
}

ostream& operator<<(ostream& o, const Topping& t){
	return t.print(o);
}