#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    bool prime[3000];
    for (int i = 0 ; i < 3000 ; i++)
    {
        prime[i] = true ;
    }



    for (int i = 2 ; i < 3000; i++)
    {
        if (prime[i] == true)
        {
            for (int j = 2; j*i < 3000 ; j++)
            {
                prime[j*i] = false;
            }
        }
    }

    int T , x , y;

    scanf("%d" , &T);

    for(int i = 0 ; i< T ; i++)
    {
        scanf("%d %d" , &x ,&y);

        int sum = x + y+1;
        int j = 0;
        for( j = sum ; prime[j] != true ; j++)
        {

        }
        printf("%d\n" , j-x-y);

    }



    return 0;
}
