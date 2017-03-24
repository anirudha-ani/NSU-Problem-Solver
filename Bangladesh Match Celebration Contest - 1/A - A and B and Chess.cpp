#include <bits/stdc++.h>

using namespace std;

int main()
{
    string input ;
    int white = 0 ;
    int black = 0 ;
    for(int i = 0 ; i < 8 ; i++)
    {
        getline(cin ,input);

        for(int j = 0 ; j < 8 ; j++)
        {
            if(input[j]=='Q')
            {
                white +=9;
            }
            else if(input[j]=='R')
            {
                white +=5;
            }
            else if(input[j]=='B')
            {
                white +=3;
            }
            else if(input[j]=='N')
            {
                white +=3;
            }
            else if(input[j]=='P')
            {
                white +=1;
            }
            else if(input[j]=='K')
            {
                white +=0;
            }
            else if(input[j]=='q')
            {
                black +=9;
            }
            else if(input[j]=='r')
            {
                black +=5;
            }
            else if(input[j]=='b')
            {
                black +=3;
            }
            else if(input[j]=='n')
            {
                black +=3;
            }
            else if(input[j]=='p')
            {
                black +=1;
            }
            else if(input[j]=='k')
            {
                black +=0;
            }
        }

    }
    if(black == white)
        {
            printf("Draw\n");
        }
        else if(black < white)
        {
            printf("White\n");
        }
        else printf("Black\n");
    return 0;
}
