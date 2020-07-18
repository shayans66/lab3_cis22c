//
// Lab 1 - Classes, Inheritance and Polymorphism
//  Ethan Sarnevsht
// Purpose: to Demonstrate object oriented programming concepts using classes dealing
// with currencies like Dollar, Canadian Dollar, etc.

/*
 PSEUDOCODE:
 
 Create Wallet
 
 Do while user input is not quit:
    print options for whether to add money, subtract money, compare current american and
            canadian dollars, or quit
    if add money is choice:
        ask if us or canadian
        perform calculation
    if subtract money is choice:
        ask if us or canadian
        perform calculation
    if compare is choice:
        perform calculation
        print which one is greater

 */
#include <iostream>
#include <string>

#include "Dollar.hpp"

using namespace std;

// gets int b/w 1 and 4
void get_int(int &choice);

bool isDigitBetween(string input, int from, int to);
void printMenu();

int main(){
    
    
    // Create wallet
    Wallet* wallet = new Wallet();
    
    // output menu to console
    printMenu();
    
    int choice;
    get_int(choice);
    
    cout << choice<< endl;
    
    while(choice != 4){
        // Adding
        if(choice == 1 ){
            cout << "American or Canadian? (c/d) " << endl;
            string subchoice;
            cin >> subchoice;
            // if user chooses dollar
            if(subchoice.compare("d")==0){
                int whole, part;
                cout << "Whole dollars: "; cin >> whole;
                cout << "Fractional cents: "; cin >> part;
                // Create dollar object iwth given attributes for whole/part
                Dollar dol(whole, part, "Dollar", "Cent");
                
                // Add dollar to wallet
                wallet->addDollar(dol);
                
            }
            // if user chooses canadian dollar
            if(subchoice.compare("c")==0){
                int whole, part;
                cout << "Whole dollars: "; cin >> whole;
                cout << "Fractional cents: "; cin >> part;
                // Create dollar object iwth given attributes for whole/part
                CanadianDollar dol(whole, part, "Loonie", "Mint");
                
                // Add dollar to wallet
                wallet->addCanadianDollar(dol);
            }
            
            // print out current bills in wallet
            cout << "Current Inventory: " <<endl;
            cout << "American dollars: " << wallet->getDollar() << endl;
            cout << "Canadian dollars: " << wallet->getCanadianDollar() << endl;
        }
        // Subtracting
        if(choice == 2 ){
            cout << "American or Canadian? (c/d) " << endl;
            string subchoice;
            cin >> subchoice;
            // if user chooses dollar
            if(subchoice.compare("d")==0){
                int whole, part;
                cout << "Whole dollars: "; cin >> whole;
                cout << "Fractional cents: "; cin >> part;
                // Create dollar object iwth given attributes for whole/part
                Dollar dol(whole, part, "Dollar", "Cent");
                
                // Add dollar to wallet
                wallet->subtractDollar(dol);
                
            }
            // if user chooses canadian dollar
            if(subchoice.compare("c")==0){
                int whole, part;
                cout << "Whole dollars: "; cin >> whole;
                cout << "Fractional cents: "; cin >> part;
                // Create dollar object iwth given attributes for whole/part
                CanadianDollar dol(whole, part, "Loonie", "Mint");
                
                // Add dollar to wallet
                wallet->subtractCanadianDollar(dol);
            }
            
            // print out current bills in wallet
            cout << "Current Inventory: " <<endl;
            cout << "American dollars: " << wallet->getDollar() << endl;
            cout << "Canadian dollars: " << wallet->getCanadianDollar() << endl;
        }
        // Comparing American dollar to Canadian Dollar
        if(choice == 3 ){
            // if dollars are equal
            if( *CanadianDollar::convertToCanadianDollar(wallet->getDollar())
               == wallet->getCanadianDollar() ){
                cout << "Dollars are equal" << endl;
            }
            else if( *CanadianDollar::convertToCanadianDollar(wallet->getDollar())
               > wallet->getCanadianDollar() ){
                cout << "American dollar is greater" << endl;
            }
            else if( *CanadianDollar::convertToCanadianDollar(wallet->getDollar())
               > wallet->getCanadianDollar() ){
                cout << "Canadian dollar is greater" << endl;
            }
            
            
        }
        
        
        // print menu, and get choice
        printMenu();
        get_int(choice);
    }
    
    
    

    
    delete wallet;
    
    // end of program
    cout << "Enter string and press enter to end program. ";
    // pauses here, press enter to end
    string smth;
    cin >> smth;
}
void printMenu(){
    
    cout<<"Wallet options: Type in digit to select option"<<endl;
    cout<<"1. Add Dollars"<<endl;
    cout<<"2. Subtract Dollars"<<endl;
    cout<<"3. Compare Dollars"<<endl;
    cout<<"4. Exit Wallet"<<endl;
    
}
// gets int b/w 1 and 4
void get_int(int &choice){
    cout << "Please enter number (1-4): ";
    // Exception handling given that input integer isn't an integer or between 1 and 4
    while( !(cin >> choice) || (choice < 0 || choice>4)  ){
        cout << "Error: Enter a number 1 through 4: ";
        // Clearing previous input
        cin.clear();
        // Discarding previous input
        cin.ignore(123, '\n');
    }
}

