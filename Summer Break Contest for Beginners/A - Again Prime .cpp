#include <bits/stdc++.h>

bool prime[5001];
int prime_num[5001];

void findPrime()
{
    prime[0] = false;
    prime[1] = false;

    for (int i = 2 ; i < 5001 ; i++)
    {
        prime[i] = true ;
    }


    for (int i = 2 ; i < 5001; i++)
    {
        if (prime[i] == true)
        {
            for (int j = 2; j*i < 5001 ; j++)
            {
                prime[j*i] = false;
            }
        }
    }
    int k = 0;

    for(int i = 0 ; i < 5001 ; i++)
    {
        if(prime[i] == true)
        {
            prime_num[k] = i;
            k++;
        }
    }
}


int main()
{
    int cases;

    int m,n;

    scanf("%d" , &cases);

    for(int i = 0 ; i < cases ; i++)
    {
        scanf("%d %d", &m , &n);

        result = 9999999999;


    }

    return 0;
}
