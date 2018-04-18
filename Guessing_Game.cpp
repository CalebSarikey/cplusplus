//  Guessing_Game.cpp
//
//  Created by CALEB SARIKEY on 2/23/17.
//  Copyright © 2017 CALEB SARIKEY. All rights reserved.
//

#include<iostream>
#include<ctime>
#include<cmath>
#include<iomanip>
#include<cstdlib>
#include<string>
#include<cstring>

using namespace std;

int main() {
    int num;            //to hold the random number
    int guess;          //to hold the users guess
    int count;          //to count the number of guesses it took
    string response;    //to play again or not
    
    //seed random number generator
    srand(time(0));
    
    do{
    num = (rand() % 100) + 1;     //generate random number between 1-100
    count = 1;              //initialize variable to count guesses
    cout << "Guess a number from 1-100: ";
        do{
            cin >> guess;
            cout << endl;
            //if input is not type int, give error, clear input, & ignore input up to 50 chars & endline
            if(cin.fail()){
                cout << "Invalid entry.  Try again: ";
                cin.clear();
                cin.ignore(50, '\n');
            }
            //if number is out of specified range, give error
            else if (guess < 1 || guess > 100){
                cout << "You must enter a number between 1-100: ";
            }
            //if the number was not guessed, guess again
            else if(guess != num){
                count++;
                if(guess < num){
                    cout << "Too low!" << endl << endl;
                }
                else{
                    cout << "Too high!" << endl << endl;
                }
                cout << "Guess again: ";
                }

        }while(guess != num);
        //when the number is guessed, confirm and display number of guesses it took
        cout << "You guessed the correct number, " << num << "!" << endl;
        if(count == 1){
            cout << "Wow!  It only took you " << count << " guess!" << endl;
        }
        else{
            cout << "It took you " << count << " guesses!" << endl;
        }
        
        cout << endl;
        cout << "Woud you like to play again? (Yes/No): ";
        cin >> response;
        cout << endl;
    
    }while(response == "yes" || response == "Yes");
    
    
    cout << "Thank you for playing!  Goodbye.";
    
    cout << endl << endl;
    return 0;
}
