#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<cstdlib>
using namespace std;

struct Fraction {
    int num;
    int den;
};

int bin_array[100]; //global array to hold binary numbers

Fraction cwfrac(int p);

//Returns the fraction in position p in the Calkin-Wilf enumeration.
int cwpos(Fraction f);

//Returns the position of the fraction f in the Calkin-Wilf enumeration.
int main() {
    int position; //to hold position
    Fraction frac; //to hold fraction
    int decision;
    string repeat;
    bool valid = false;
    do {
        while (!valid) {
            cout << "Enter 1 to find the position of a fraction in the Calkin-Wilf Tree," << endl;
            cout << "or 2 to find the fraction in a given position in the Calkin-Wilf Tree: ";
            cin >> decision;
            if(cin.fail()){
                cout << "Invalid entry. Try again." << endl;
                cin.clear();
                cin.ignore(50, '\n');
                
                valid = false;
            }
            else if (decision == 1 || decision == 2)
                valid = true;
            else {
                cout << "Invalid entry. Try again." << endl;
                valid = false;
            }
        }
        cout << endl;
        if (decision == 1) {
            cout << "Enter a positive fraction and I will find its position in the Calkin- Wilf Tree" << endl;
            do {
                cout << "Numerator: ";
                cin >> frac.num;
                if(cin.fail()){
                    cout << "Invalid entry. Try again." << endl;
                    cin.clear();
                    cin.ignore(50, '\n');
                }
                cout << "Denominator: ";
                cin >> frac.den;
                if(cin.fail()){
                    cout << "Invalid entry. Try again." << endl;
                    cin.clear();
                    cin.ignore(50, '\n');
                }
                else if (frac.num <= 0 || frac.den <= 0)
                    cout << "Invalid Entry. Must be greater than 0." << endl;
            } while (frac.num <= 0 || frac.den <= 0);
            position = cwpos(frac);
            cout << endl;
            cout << frac.num << "/" << frac.den << " is located at position " << position << endl << endl;
        }
        else if (decision == 2) {
            do {
                cout << "Enter a position and I will find the fraction in the Calkin-Wilf Tree: " << endl;
                cin >> position;
                
                if(cin.fail()){
                    cout << "Invalid entry. Try again." << endl;
                    cin.clear();
                    cin.ignore(50, '\n');
                }
                else if (position <= 0) {
                    cout << "Invalid Entry. Must be greater than 0." << endl; }
            } while (position <= 0);
            frac = cwfrac(position);
            cout << endl;
            cout << "The fraction at position " << position << " is " << frac.num << "/" << frac.den << endl << endl;
        }
        valid = false;
        cout << "Would you like to compute another? (Yes/No) ";
        cin >> repeat;
        cout << endl;
    } while (repeat == "yes" || repeat == "Yes");
    
    cout << "You have chosen to exit." << endl << endl;
    
    return 0;
}

int cwpos(Fraction f) {
    int i = 0; //to hold index of bin_array
    bool root = false; //true when the root is reached
    
    //execute while loop until the root 1/1 is reached
    do {
        f.num = f.num;
        f.den = f.den;
        //if fraction > 1, it is a right child
        if (f.num > f.den) {
            //insert a 1 into the binary number
            bin_array[i++] = 1;
            
            //compute parent
            f.num = f.num - f.den;
            f.den = f.den;
            
            root = false;
        }
        //if fraction < 1, it is a left child
        else if (f.num < f.den) {
            //insert a 0 into the binary number
            bin_array[i++] = 0;
            
            //compute parent
            f.den = f.den - f.num;
            f.num = f.num;
            
            root = false;
        }
        else
            root = true;
    } while (!root);
    
    //insert 1 into binary number once you get to root
    bin_array[i] = 1;
    
    int p = 0; //to hold the position integer
    int exp = i; //used as exponent for powers of 2 throughout conversion
    
    //convert binary to decimal
    for (int c = i; c >= 0; c--) {
        p += (bin_array[c] * (pow(2, exp)));
        exp--;
    }
    
    return p;
};

Fraction cwfrac(int p) {
    Fraction frac;  //to hold fraction at position p
    int r;  //to hold remainder and insert into array
    int i = 0;   //to step through array
    
    
    //Convert p to binary and store binary digits into array
    while (p != 0){
        r = p % 2;
        bin_array[i] = r;
        p /= 2;
        i++;
    }
    
    //Start at root node
    frac.num = 1;
    frac.den = 1;
    
    //Start at i-2 since leading '1' means start at root node
    //Cycle through digits in binary number and follow path
    for (int c = i - 2; c >= 0; c--) {
        //if digit is 1, move to the right child
        if (bin_array[c] == 1) {
            frac.num = frac.num + frac.den;
            frac.den = frac.den;
        }
        //if digit is 0, move to the left child
        else if (bin_array[c] == 0) {
            frac.num = frac.num;
            frac.den = frac.den + frac.num;
        }
    }
    return frac;
};



