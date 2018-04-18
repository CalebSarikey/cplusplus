//  Created by CALEB SARIKEY on 3/4/17.
//  Copyright © 2017 CALEB SARIKEY. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main() {
    
    int lottery[5];
    int one;
    int num;
    int w = 0;
    string response = "yes";
    
    srand(time(0));
    
    cout << "Welcome to the lottery game." << endl;
    cout << "Participants have a 1 in 5 chance of winning!" << endl << endl;
    
    while(response == "yes" || response == "Yes"){
    do{
    cout << "Enter 1 to draw a lottery ticket: ";
    cin >> one;
        if(one != 1 || cin.fail()){
            cin.clear();
            cin.ignore(50, '\n');
        cout << "Invalid entry.  You did not enter 1." << endl;
            }
    }while(one != 1);
    
    num = (rand() % 10000) + 10000;
        
        cout << endl;
        cout << "Your ticket number is: " << num << endl << endl;
    
        
    int index = rand() % 5;
    lottery[index] = num;
    
    for (int i=0; i<=4; i++){
        if(i == index){
            continue;
        }
        else{
            lottery[i] = (rand() % 10000) + 10000;
        }
    }
    
    cout << "The lottery numbers are: " << endl;
    for(int i=0; i<=4; i++){
        cout << lottery[i] << "  ";
    }
    cout << endl << endl;
    
        for(int i=0; i<10; i++){
            w = rand() % 5;}
    
    cout << "The winning number is: " << lottery[w] << endl << endl;
    if (w == index){
        cout << "Congratulations, you won!" << endl;
    }
    else{
        cout << "You were not the winner." << endl;
    }
        
    cout << endl;
    cout << "Would you like to play again? ";
    cin >> response;
        
    cout << endl;
        
    }
    
    cout << "Thank you for playing.  Goodbye!" << endl << endl;
    
    
    return 0;
}
