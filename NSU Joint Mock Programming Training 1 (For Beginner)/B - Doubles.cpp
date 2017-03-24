#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int input , counter = 0 ;
    bool marker [200] ;
    for(int i = 0 ; i < 200 ; i++)
    {
        marker[i] = false;
    }
    while(scanf("%d",&input) == 1)
    {
        if(input == -1)
        {
            break;
        }
        if(input == 0)
        {
            for(int i = 0 ; i < 200 ; i++)
            {
                if(marker[i] == true)
                {
                    if(marker[i*2] == true)
                    {
                        counter++;
                    }
                }
            }
            for(int i = 0 ; i < 200 ; i++)
            {
                marker[i] = false;
            }
            printf("%d\n", counter);
            counter = 0 ;
        }
        else
        {
            marker[input] = true;
        }


    }
    return 0;
}
