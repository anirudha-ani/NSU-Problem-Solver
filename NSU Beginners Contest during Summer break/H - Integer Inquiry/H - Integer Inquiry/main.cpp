//
//  main.cpp
//  H - Integer Inquiry
//
//  Created by Anirudha Paul on 5/15/15.
//  Copyright (c) 2015 Anirudha Paul. All rights reserved.
//


#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

void sum(string , string);
char input_array[101][101];
char result[105];
char result_copy[105];
int result_length;

int main(int argc, const char * argv[])
{
    string input;
    result[0] = '0';
    result[1] = '\0';
    
    getline( cin , input);
    

    int number_of_input = 1;
    
    while (input[0]!= '0')
    {
        for (int i = 0 ; i < input.length(); i++)
        {
            input_array[number_of_input-1][i] = input[i];
        }
        getline(cin, input);
        number_of_input++;
    }
    
    for (int i = 0 ; i < number_of_input; i++)
    {
        for (int i = 0; i<105; i++)
        {
            result_copy[i] = result[i];
        }
        string string1(result_copy);
        string string2(input_array[i]);
        
        sum(string1, string2);
    }
    
            
    for (int i = 0 ; i < result_length; i++)
    {
        printf("%c" , result[i]);
    }
    printf("\n");
    return 0;
    
}

void sum(string string1 , string string2)
{
    long long i = string1.length() - 1;
    long long j = string2.length() - 1;
    int k = 0;
    int c = 0;
    
    
    while ( i >= 0 && j >= 0)
    {
        result[k] = (((string1[i]-'0') + (string2[j] - '0') + c) % 10) + '0';
        c = ((string1[i]-'0') + (string2[j] - '0') + c) / 10;
        i--;
        j--;
        k++;
        
    }
    
    while ( i>=0)
    {
        result[k] = (((string1[i]-'0') + c) % 10) + '0';
        c = ((string1[i]-'0') + c) / 10;
        
        i--;
        k++;
    }
    
    while ( j>=0)
    {
        result[k] = (((string2[j]-'0') + c) % 10) + '0';
        c = ((string2[j]-'0') + c) / 10;
        j--;
        k++;
    }
    if(c != 0)
    {
        result[k] = c + '0';
        k++;
    }
    result[k] = '\0';
    
    int q = 0;
    int w = k-1;
    
    result_length = k;
    while (q<w)
    {
        char a = result[q];
        result[q] = result[w];
        result[w] = a;
        q++;
        w--;
    }
}

