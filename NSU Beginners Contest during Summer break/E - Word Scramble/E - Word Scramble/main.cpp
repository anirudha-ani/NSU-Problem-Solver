//
//  main.cpp
//  E - Word Scramble
//
//  Created by Anirudha Paul on 5/14/15.
//  Copyright (c) 2015 Anirudha Paul. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(int argc, const char * argv[])
{
    string input ;
    
    while (getline(cin, input))
    {
        long long length = input.length();
        
        int word_start = 0;
        int word_end = 0;
        
        for (int i = 0 ; i <= length ; i++)
        {
            if (input[i] == ' ' || input[i] == '\0' )
            {
                word_end = i;
                int q = word_start;
                int w = word_end-1;
                
                while (q<w)
                {
                    char a = input[q];
                    input[q] = input[w];
                    input[w] = a;
                    q++;
                    w--;
                }
                word_start = i+1;
            }
        }
        
        cout << input << endl ;
    }
    return 0;
}
