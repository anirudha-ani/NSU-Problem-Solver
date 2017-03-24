//
//  main.cpp
//  B - Fibonacci Freeze
//
//  Created by Anirudha Paul on 5/12/15.
//  Copyright (c) 2015 Anirudha Paul. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

void sum(string , string);
char fibonacci[5001][1046];
int fibonacci_no = 2;

int main(int argc, const char * argv[])
{
    int a;
    while (cin >> a)
    {
        fibonacci[0][0] = '0';
        fibonacci[0][1] = '\0';
        fibonacci[1][0] = '1';
        fibonacci[1][1] = '\0';
        
        while (fibonacci_no < a+1)
        {
            string string1(fibonacci[fibonacci_no - 1]);
            string string2(fibonacci[fibonacci_no - 2]);
            
            sum(string1, string2);
            
            fibonacci_no ++ ;
            
        }
        int i = 0;
        cout << "The Fibonacci number for " << a <<" is ";
        while(fibonacci[a][i] != '\0')
        {
            cout << fibonacci[a][i];
            i++;
        }
        cout << endl;
    }
    
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
        fibonacci[fibonacci_no][k] = (((string1[i]-'0') + (string2[j] - '0') + c) % 10) + '0';
        c = ((string1[i]-'0') + (string2[j] - '0') + c) / 10;
        i--;
        j--;
        k++;
        
    }
    
    while ( i>=0)
    {
        fibonacci[fibonacci_no][k] = (((string1[i]-'0') + c) % 10) + '0';
        c = ((string1[i]-'0') + c) / 10;

        i--;
        k++;
    }
    
    while ( j>=0)
    {
        fibonacci[fibonacci_no][k] = (((string2[j]-'0') + c) % 10) + '0';
        c = ((string2[j]-'0') + c) / 10;
        j--;
        k++;
    }
    if(c != 0)
    {
        fibonacci[fibonacci_no][k] = c + '0';
        k++;
    }
    fibonacci[fibonacci_no][k] = '\0';
    
    int q = 0;
    int w = k-1;
    
    while (q<w)
    {
        char a = fibonacci [fibonacci_no][q];
        fibonacci[fibonacci_no][q] = fibonacci[fibonacci_no][w];
        fibonacci[fibonacci_no][w] = a;
        q++;
        w--;
    }
}

