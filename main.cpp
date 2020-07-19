//
// Lab 3 - Sorting Arrays
//  Ethan Sarnevsht
// Purpose: To demonstrate mastery of class templates and how to sort an array of different
//  types of arrays using mergesort

/*
 PSEUDOCODE:
 
 
 
 */
#include <iostream>
#include <string>
#include <cstring>

#include <fstream>

#include "Dollar.hpp"

#define SORT_MAX_SIZE 16

using namespace std;

template<typename T>
void print_array(T arr[], int size){
    for(int i=0;i<size;i++){
        cout << arr[i] << endl;
    }
}

template<typename T>
class MergeHelper {
    int size;
public:
    MergeHelper(int size) {
        this->size = size;
    }
    
    void merge(T Arr[], int start, int mid, int end){
        // create a temp array
        T temp[end - start + 1];
        
        // crawlers for both intervals and for temp
        int i = start, j = mid+1, k = 0;
        
        // traverse both arrays and in each iteration add smaller of both elements in temp
        while(i <= mid && j <= end) {
            if((Arr[i] < Arr[j]) || (Arr[i] == Arr[j])) {
                temp[k] = Arr[i];
                k += 1; i += 1;
            }
            else {
                temp[k] = Arr[j];
                k += 1; j += 1;
            }
        }
        
        // add elements left in the first interval
        while(i <= mid) {
            temp[k] = Arr[i];
            k += 1; i += 1;
        }
        
        // add elements left in the second interval
        while(j <= end) {
            temp[k] = Arr[j];
            k += 1; j += 1;
        }
        
        // copy temp to original interval
        for(i = start; i <= end; i += 1) {
            Arr[i] = temp[i - start];
        }
    }
    
    void mergeSort(T Arr[], int start, int end){
        if(start < end) {
            int mid = (start + end) / 2;
            mergeSort(Arr, start, mid);
            mergeSort(Arr, mid+1, end);
            merge(Arr, start, mid, end);
        }
    }

    
    
};






// MAIN METHOD
int main(){
    
    
    
    int num_elements=0;
    cout << "Enter a sorting size for the array (between 1 and 16): ";
    
    while( !(cin >> num_elements) || num_elements > SORT_MAX_SIZE || num_elements < 1){
        // Explain error
        cout << "Error: Enter a number between 1 and 16: ";
        // clear previous input
        cin.clear();
        // discard previous input
        cin.ignore(123, '\n');
    }
    
    // what type of data do you want to enter?
    cout << "What type of data do you want to enter? " << endl;
    cout << "1: Integer" << endl;
    cout << "2: String" << endl;
    cout << "3: Dollar" << endl;
    int choice;
    cin >> choice;
    
    int arr_int[num_elements];
    string arr_str[num_elements];
    Dollar arr_dollar[num_elements];
    
    
    
    //    Array<string, SORT_MAX_SIZE> stringarray;
    //    Array<Dollar, SORT_MAX_SIZE> dollararray;
    //    Array<int, SORT_MAX_SIZE> intarray;
    
    switch(choice){
        case 1: {
            for(int i=0; i<num_elements; i++ ){
                cout << "Enter element #" << i+1 << ": ";
                cin >> arr_int[i];
            }
            MergeHelper<int> merger(num_elements);
            merger.mergeSort(arr_int, 0, num_elements-1);
            print_array(arr_int, num_elements);
            break;
        }
        case 2: {
            for(int i=0; i<num_elements; i++ ){
                cout << "Enter element #" << i+1 << ": ";
                cin >> arr_str[i];
            }
            MergeHelper<string> merger(num_elements);
            merger.mergeSort(arr_str, 0, num_elements-1);
            print_array(arr_str, num_elements);
            break;
        }
        case 3: {
            for(int i=0; i<num_elements; i++ ){
                cout << "Enter element #" << i+1 << ": ";
                cout << "Dollars: ";
                int whole; cin >> whole;
                cout << "Cents: ";
                int part; cin >> part;
                Dollar* buffer = new Dollar(whole, part, "Dollar", "Cent");
                arr_dollar[i] = *buffer;
            }
            MergeHelper<Dollar> merger(num_elements);
            merger.mergeSort(arr_dollar, 0, num_elements-1);
            
            print_array(arr_dollar, num_elements);
            break;
        }
    }
    
    
    
    
    
    
    // end of program
    cout << "Enter string and press enter to end program. ";
    // pauses here, press enter to end
    string smth;
    cin >> smth;
}

