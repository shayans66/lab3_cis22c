//
//  Dollar.hpp
//  Lab1_datastructs
//
//  Created by android on 7/3/20.
//  Copyright © 2020 android. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <iostream>

#include <string>



class Dollar{
private:
    int whole_part;
    int fractional_part;
    
    std::string note_name, coin_name;
    
public:
    // Constructor to initialize Dollar object
    // with number of whole and fractional currency, note and coin name
    Dollar(){};
    Dollar(int whole_part, int fractional_part, std::string note_name, std::string coin_name);
    
    // Destructor
    ~Dollar();
    // Copy Constructor
    Dollar(Dollar &other);
    
    // Getter Methods
    int get_whole_part();
    int get_fractional_part();
    std::string get_note_name();
    std::string get_coin_name();
    
    // Setter Methods
    void set_whole_part(int w);
    void set_fractional_part(int f);
    void set_note_name(std::string n);
    void set_coin_name(std::string c);
    
    // Add 2 Dollars (or canadian dollars) together
    /*
     Pre: Dollars aren't added
     Post: Dollars are added
     Return: void
     */
    void operator+(Dollar& other);
    // Subtract dollar object 'other' with this
    /*
     Pre: Dollars aren't subtracted
     Post: Dollars are subtracted
     Return: void
     */
    void operator-(Dollar& other);
    // Compare 2 dollar objects
    /*
     Pre: Dollars aren't compared
     Post: Dollars are compared
     Return: true/false boolean saying if Dollars are equal or not
     */
    bool operator==(Dollar& other);
    /*
     Pre: Dollars aren't compared
     Post: Dollars are compared
     Return: true or false comparing dollar objects if 'this' is Greater than 'other'
     */
    bool operator> (Dollar& other);
    /*
     Pre: Dollars aren't compared
     Post: Dollars are compared
     Return: true or false comparing dollar objects if 'this' is less than than 'other'
     */
    bool operator< (Dollar& other);
    /*
     Pre: Dollars aren't output to an output stream object
     Post: Dollars are output to an output stream object
     Return: altered output stream object
     */
    friend std::ostream& operator<<(std::ostream& stream, Dollar& obj);
    
};

class CanadianDollar : public Dollar{
private:
    
    // attributes
    
    int whole_part;
    int fractional_part;
    
    std::string note_name, coin_name;
    
    double us_to_cad;
    
    
    
public:
    // Constructor to initialize CanadianDollar object
    // with number of whole and fractional currency, note and coin name
    CanadianDollar(int whole_part, int fractional_part, std::string note_name, std::string coin_name);
    ~CanadianDollar();
    
    // convert dollar to canadian dollar and reutrn canadian dollar object
    /*
     Pre: American dollar exists
     Post: American dollar exists along with converted Canadian dollar that has been generated
     Return: Newly generated converted Canadian Dollar
     */
    static CanadianDollar* convertToCanadianDollar(Dollar& dollar);
    // convert canadian dollar to dollar and return dollar object
    /*
     Pre: Canadian dollar exists
     Post: Canadian dollar exists along with converted American dollar that has been generated
     Return: Newly generated converted American Dollar
     */
    static Dollar* convertToDollar(CanadianDollar& cad);
    
    
};


class Wallet{
private:
    Dollar* dollars[2];
public:
    // Constructor for Wallet
    Wallet();
    // Destructor for Wallet
    ~Wallet();
    
    // Getter methods
    Dollar& getDollar(){
        return *dollars[0];
    }
    Dollar& getCanadianDollar(){
        return *(dollars[1]);
    }
    /*
     Pre: Dollar in dollars[0] not updated
     Post: Dollar in dollars[0] is newly updated by adding
     Return: void
     */
    void addDollar(Dollar& dollar);
    /*
     Pre: Dollar in dollars[0] not updated
     Post: Dollar in dollars[0] is newly updated by subtracting
     Return: void
     */
    void subtractDollar(Dollar& dollar);
    
    /*
     Pre: Dollar in dollars[1] not updated
     Post: Dollar in dollars[1] is newly updated
     Return: void
     */
    void addCanadianDollar(Dollar& canadianDollar);
    /*
     Pre: Dollar in dollars[1] not updated
     Post: Dollar in dollars[1] is newly updated
     Return: void
     */
    void subtractCanadianDollar(Dollar& canadianDollar);
    
    /*
     Pre: Parameter dollar and dollar in dollars[0] not compared
     Post: Are compared
     Return: Boolean saying if the dollar in dollars[] is greater
     */
    bool isDollarGreater(Dollar& dollar);
    /*
     Pre: Parameter dollar and dollar in dollars[1] not compared
     Post: Are compared
     Return: Boolean saying if the dollar in dollars[] is greater
     */
    bool isCanadianDollarGreater(CanadianDollar& canadianDollar);
    
};

