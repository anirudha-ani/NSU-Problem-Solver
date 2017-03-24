//
//  main.cpp
//  A - Kindergarten Counting Game
//
//  Created by Anirudha Paul on 5/12/15.
//  Copyright (c) 2015 Anirudha Paul. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[])
{
    string input ;
    
    while(getline(cin,input))
    {
        int wordCount = 0;
        int i = 0;
        while (i < input.length())
        {
            if (((input[i+1]>= 0 &&input[i+1]<65) || (input [i+1] > 90 && input [i+1] < 97) || (input[i+1] > 122 && input[i+1] <=127)) && ( (input[i] >= 65 && input[i] <= 90) || (input[i] >= 97 && input[i] <= 122)))
            {
                wordCount++;
            }
            i++;
        }
        
        cout << wordCount << endl;
        cin.clear();

    }
    
    
    return 0;
}
