//
//  main.cpp
//  C - Rotating Sentences
//
//  Created by Anirudha Paul on 5/13/15.
//  Copyright (c) 2015 Anirudha Paul. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, const char * argv[])
{
    char rotationMirror[101][101];
    string input;
    
    int inputNumber = 0;
    int maxLength = 0;
    
    while (getline(cin,input))
    {
        cin.clear();
        int i = 0;
        
        while (input[i] != '\0')
        {
            rotationMirror[inputNumber][i] = input[i];
            
            i++;
        }
        if (i> maxLength)
        {
            maxLength = i;
        }
        rotationMirror[inputNumber][i] = '\0';
        inputNumber++;
    }
    
    for (int i = 0 ; i < inputNumber; i++)
    {
        int j = 0 ;
        while (rotationMirror[i][j] != '\0')
        {
            j++;
        }
        while (j < maxLength)
        {
            rotationMirror[i][j] = ' ';
            j++;
        }
        rotationMirror[i][j] = '\0';
    }
    
    for (int i = 0 ; i < maxLength ; i++)
    {
        for (int j = inputNumber-1 ; j >=0 ; j--)
        {
            cout << rotationMirror[j][i];
        }
        cout << endl;
    }
    return 0;
}
