//
//  main.cpp
//  G - Marvelous Mazes
//
//  Created by Anirudha Paul on 5/15/15.
//  Copyright (c) 2015 Anirudha Paul. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(int argc, const char * argv[])
{
    string input;
    
    while (getline(cin, input))
    {
            long long length ;
            length = input.length();
            
            int repetation =  0 ;
            
            for (int i = 0 ; i < length ; i++)
            {
                if (input[i] >= '0' && input [i] <= '9')
                {
                    repetation = repetation + input[i] - '0';
                }
                else if (input[i]== '!' || i >= length)
                {
                    printf("\n");
                }
                else if (input[i] == 'b')
                {
                    for (int j = 0 ; j < repetation ; j++)
                    {
                        printf(" ");
                    }
                    repetation = 0 ;

                }
                else
                {
                    for (int j = 0 ; j < repetation ; j++)
                    {
                        printf("%c" , input[i]);
                    }
                    
                    repetation = 0 ;
                }
            }

        printf("\n");
        
    }
    return 0;
}
