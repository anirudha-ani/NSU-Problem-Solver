//
//  main.cpp
//  K - Hangman Judge
//
//  Created by Anirudha Paul on 5/17/15.
//  Copyright (c) 2015 Anirudha Paul. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <list>
using namespace std;

int main ()
{
    int test;
    
    while (cin >> test) {
        
        if (test == -1)
            return 0;
        
        char solution [10000];
        char input [10000];
        
        cin >> solution;
        cin >> input;
        
        long long length = strlen (solution);
        list <char> l (&solution [0], &solution [length]);
        
        int strokes = 0;
        
        length = strlen (input);
        for (int i = 0; i < length; i++) {
            if (!l.empty())
            {
                long long size = l.size ();
                l.remove (input [i]);
                
                if (size == l.size ())
                    strokes++;
            }
            else
                break;
        }
        
        if (l.empty () && strokes < 7) {
            cout << "Round " << test << endl;
            cout << "You win." << endl;
        }
        else if (!l.empty () && strokes < 7) {
            cout << "Round " << test << endl;
            cout << "You chickened out." << endl;
        }
        else {
            cout << "Round " << test << endl;
            cout << "You lose." << endl;
        }
    }
    
    return 0;
}
