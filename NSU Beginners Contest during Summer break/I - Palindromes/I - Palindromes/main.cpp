//
//  main.cpp
//  I - Palindromes
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
    string input ;
    
    while (getline(cin, input))
    {
        long long start = 0 ;
        long long end  = input.length()-1;
        
        bool palindrome = true;
        bool mirrored_string = true;
        
        
        while ((start <= end) && (palindrome || mirrored_string))
        {
            if (palindrome && (input[start] == input[end]))
            {
                
            }
            
            else
            {
                palindrome = false;
            }
            
            if ((input[start] == 'A' && input[end]== 'A') && mirrored_string)
            {
                
            }
            else if ((input[start] == 'E' && input[end]== '3')&& mirrored_string)
            {
                
            }
            else if ((input[start] == 'H' && input[end]== 'H')&& mirrored_string)
            {
                
            }
            else if ((input[start] == 'I' && input[end]== 'I')&& mirrored_string)
            {
                
            }
            else if ((input[start] == 'J' && input[end]== 'L')&& mirrored_string)
            {
                
            }
            else if ((input[start] == 'L' && input[end]== 'J')&& mirrored_string)
            {
                
            }
            else if ((input[start] == 'M' && input[end]== 'M')&& mirrored_string)
            {
                
            }
            else if ((input[start] == 'O' && input[end]== 'O')&& mirrored_string)
            {
                
            }
            else if ((input[start] == '0' && input[end]== 'O')&& mirrored_string)
            {
                
            }
            else if ((input[start] == 'O' && input[end]== '0')&& mirrored_string)
            {
                
            }
            else if ((input[start] == '0' && input[end]== '0')&& mirrored_string)
            {
                
            }
            else if ((input[start] == 'S' && input[end]== '2')&& mirrored_string)
            {
                
            }
            else if ((input[start] == 'T' && input[end]== 'T')&& mirrored_string)
            {
                
            }
            else if ((input[start] == 'U' && input[end]== 'U')&& mirrored_string)
            {
                
            }
            else if ((input[start] == 'V' && input[end]== 'V')&& mirrored_string)
            {
                
            }
            else if ((input[start] == 'W' && input[end]== 'W')&& mirrored_string)
            {
                
            }
            else if ((input[start] == 'X' && input[end]== 'X')&& mirrored_string)
            {
                
            }
            else if ((input[start] == 'Y' && input[end]== 'Y')&& mirrored_string)
            {
                
            }
            else if ((input[start] == 'Z' && input[end]== '5')&& mirrored_string)
            {
                
            }
            else if ((input[start] == '1' && input[end]== '1')&& mirrored_string)
            {
                
            }
            else if ((input[start] == '2' && input[end]== 'S')&& mirrored_string)
            {
                
            }
            else if ((input[start] == '3' && input[end]== 'E')&& mirrored_string)
            {
                
            }
            else if ((input[start] == '5' && input[end]== 'Z')&& mirrored_string)
            {
                
            }
            else if ((input[start] == '8' && input[end]== '8')&& mirrored_string)
            {
                
            }
            else
            {
                mirrored_string = false;
            }
            
            start++;
            end--;
        }
        
        if (palindrome && mirrored_string)
        {
            cout << input <<" -- is a mirrored palindrome." << endl<<endl;;
        }
        else if (palindrome)
        {
            cout << input << " -- is a regular palindrome." << endl<<endl;
        }
        else if (mirrored_string)
        {
            cout << input << " -- is a mirrored string." << endl<<endl;
        }
        else
        {
            cout << input << " -- is not a palindrome." << endl<<endl;
        }
    }
    
    return 0;
   
}