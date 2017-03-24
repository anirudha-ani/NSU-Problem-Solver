//
//  main.cpp
//  F - The Decoder
//
//  Created by Anirudha Paul on 5/14/15.
//  Copyright (c) 2015 Anirudha Paul. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    long long length;
    string input;
    
    while(getline(cin,input))
    {
        length = input.length();
        
        for(int i=0 ; i < length ; i++)
            printf("%c",input[i]-7);
        
        printf("\n");
    }
    return 0;
}
