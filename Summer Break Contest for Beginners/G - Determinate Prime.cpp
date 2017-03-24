#include <bits/stdc++.h>

bool prime[32001];
int gapPrime[32001];


void findPrime()
{
    prime[0] = false;
    prime[1] = false;

    for (int i = 2 ; i < 32001 ; i++)
    {
        prime[i] = true ;
    }


    for (int i = 2 ; i < 32001; i++)
    {
        if (prime[i] == true)
        {
            for (int j = 2; j*i < 32001 ; j++)
            {
                prime[j*i] = false;
            }
        }
    }
}

void gapPrime()
{
    int prime1=2;
    int prime2;

    bool flag = false;
    int i;
    for( i = 3 ; i <=32000 ; i++)
    {
        if(prime[i] == true)
        {
            prime2 = i;
            gapPrime[prime1] = prime2 - prime1;
            prime1 =i;
        }
    }
}

void gapPrime()
{

}

int main()
{
    findPrime();
    gapPrime();
    int start , finish;

    while(scanf("%d %d" , &start , &finish))
    {
        int prime1, prime2 , prime3;
        if(start == 0 && finish == 0)
            break;

        for(int i = start ; i <= finish ; i++)
        {
            if(prime[i] == true)
            {
                prime1 = i;
                while(gap[prime1] == )
            }
        }

    }

    return 0 ;
}
