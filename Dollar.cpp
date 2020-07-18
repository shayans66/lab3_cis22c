//
//  Dollar.cpp
//  Lab1_datastructs
//
//  Created by android on 7/3/20.
//  Copyright © 2020 android. All rights reserved.
//

#include "Dollar.hpp"
#include <stdio.h>
#include <iostream>

#include <string>



#define US_TO_CAD 1.36;

// Constructor to initialize Dollar object
// with number of whole and fractional currency, note and coin name
Dollar::Dollar(int whole_part, int fractional_part, std::string note_name, std::string coin_name){
    this->whole_part = whole_part;
    this-> fractional_part = fractional_part;
    
    this->note_name = note_name;
    this->coin_name = coin_name;
   
    
}


Dollar::~Dollar(){}
// Copy Constructor
Dollar::Dollar(Dollar &other){
    whole_part = other.get_whole_part();
    fractional_part = other.get_fractional_part();
    this->note_name = other.get_note_name();
    this->coin_name = other.get_coin_name();
}

// Getters
int Dollar::get_whole_part(){ return this->whole_part; }
int Dollar::get_fractional_part(){ return this->fractional_part; }
std::string Dollar::get_note_name(){ return this->note_name; }
std::string Dollar::get_coin_name(){ return this-> coin_name; }


// Setters
void Dollar::set_whole_part(int w){ this->whole_part = w; }
void Dollar::set_fractional_part(int f){ this->fractional_part = f;}
void Dollar::set_note_name(std::string n){ this->note_name = n;}
void Dollar::set_coin_name(std::string c){ this->coin_name = c;}

// Operator Overloading
// Adding
void Dollar::operator+(Dollar& other){
    this->whole_part += other.whole_part;
    this->fractional_part += other.fractional_part;
    while(this->fractional_part >= 100){
        ++this->whole_part;
        this->fractional_part -= 100;
    }
}
// Subtracting
void Dollar::operator-(Dollar& other){
    this->whole_part -= other.whole_part;
    this->fractional_part -= other.fractional_part;
    if(this->whole_part < 0)
        this->whole_part = 0;
    if(this->fractional_part < 0)
        this->fractional_part = 0;
}
// Compare 2 dollar objects
bool Dollar::operator==(Dollar& other){
    return whole_part == other.get_whole_part() &&
        fractional_part == other.get_fractional_part();
}
// Compare Dollar objects to see if 'this' is Greater than 'other'
bool Dollar::operator> (Dollar& other){
    if ( !(this->whole_part == other.whole_part))
        return this->get_whole_part() > other.get_whole_part();
    return this->get_fractional_part() > other.get_fractional_part();
        
      
}
// Compare Dollar objects to see if 'this' is less than 'other'
bool Dollar::operator< (Dollar& other){
    if ( !(this->whole_part == other.whole_part))
        return this->get_whole_part() < other.get_whole_part();
    return this->get_fractional_part() < other.get_fractional_part();
    
}
// output operator overload
std::ostream& operator<<(std::ostream& stream, Dollar& obj){
    
    stream <<  obj.whole_part << " " << obj.note_name  << "(s) and " << obj.fractional_part << " "
    << obj.coin_name << "(s)" << std::endl;

    return stream;
}


// Constructor to initialize CanadianDollar object
// with number of whole and fractional currency, note and coin name
CanadianDollar::CanadianDollar(int whole_part, int fractional_part, std::string note_name, std::string coin_name) : Dollar(whole_part, fractional_part,  note_name, coin_name) {
    // 1 USD = 1.36 CAD
    this->us_to_cad = US_TO_CAD;
}
CanadianDollar::~CanadianDollar(){}


// convert dollar to canadian dollar and reutrn canadian dollar object
CanadianDollar* CanadianDollar::convertToCanadianDollar(Dollar& dollar){
    
    int whole, frac;
    whole = dollar.get_whole_part() * US_TO_CAD;
    frac = dollar.get_fractional_part() * US_TO_CAD;

    return new CanadianDollar(whole, frac, "Loonie", "Mint");
}

// convert canadian dollar to dollar and return dollar object
Dollar* CanadianDollar::convertToDollar(CanadianDollar& cad){
    int whole, frac;
    whole = cad.get_whole_part() / US_TO_CAD;
    frac = cad.get_fractional_part() / US_TO_CAD;
    
    return new Dollar(whole, frac, "Dollar", "Cent");
    
}

Wallet::Wallet(){
    dollars[0] = new Dollar(0, 0, "Dollar", "Cent");
    dollars[1] = new CanadianDollar(0, 0, "Loonie", "Mint");
}
Wallet::~Wallet(){}

void Wallet::addDollar(Dollar& dollar){
    dollars[0]->set_whole_part( dollars[0]->get_whole_part() + dollar.get_whole_part() );
    dollars[0]->set_fractional_part( dollars[0]->get_fractional_part()+ dollar.get_fractional_part() );

    
}
void Wallet::subtractDollar(Dollar& dollar){
    dollars[0]->set_whole_part( dollars[0]->get_whole_part() - dollar.get_whole_part() );
    dollars[0]->set_fractional_part( dollars[0]->get_fractional_part() -
                                    dollar.get_fractional_part() );
}

void Wallet::addCanadianDollar(Dollar& canadianDollar){
    dollars[1]->set_whole_part( dollars[1]->get_whole_part() + canadianDollar.get_whole_part() );
    dollars[1]->set_fractional_part( dollars[1]->get_fractional_part()+ canadianDollar.get_fractional_part() );
}
void Wallet::subtractCanadianDollar(Dollar& canadianDollar){
    dollars[1]->set_whole_part( dollars[1]->get_whole_part() - canadianDollar.get_whole_part() );
    dollars[1]->set_fractional_part( dollars[1]->get_fractional_part() - canadianDollar.get_fractional_part() );
}

bool Wallet::isDollarGreater(Dollar& other){
    if ( !(dollars[0]->get_whole_part() == other.get_whole_part()))
        return dollars[0]->get_whole_part() > other.get_whole_part();
    return dollars[0]->get_fractional_part() > other.get_fractional_part();
    
}
bool Wallet::isCanadianDollarGreater(CanadianDollar& other){
    if ( !(dollars[0]->get_whole_part() == other.get_whole_part()))
        return dollars[0]->get_whole_part() < other.get_whole_part();
    return dollars[0]->get_fractional_part() < other.get_fractional_part();
    
}


