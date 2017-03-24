#include <iostream>
#include <new>
#include <cstdio>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[])
{
   bool prime [31630];
   int primeno [3500];

    for (int i = 0 ; i < 31630 ; i++)
    {
        prime[i] = true ;
    }

    for (int i = 2 ; i < 31630; i++)
    {
        if (prime[i] == true)
        {
            for (int j = 2; j*i < 31630 ; j++)
            {
                prime[j*i] = false;
            }
        }
    }

    int j = 0;
    for(int i =  2 ; i < 31630 ;i++)
    {
        if(prime[i] == true)
        {
            primeno[j] = i;
            j++;
        }
    }


    long long testcase , low , high;
    scanf("%lld" , &testcase);

    for(int i = 0 ; i < testcase ; i++)
    {

        scanf("%lld %lld" , &low , &high);
        if(low%2 == 0)
        low = low + 1;
        if(low == 1)
        low =3;

        for(long long i = low ; i <= high ; i= i+2)
        {
            bool flag = true;
            long long int x = (int)sqrt(i);
            for(int k = 0 ; primeno[k] <= x ; k++)
            {
                if(i%primeno[k] == 0)
                {
                    flag = false;

                    break;
                }
            }
            if(flag)
            {
                printf("%lld\n" , i);
            }
        }
        printf("\n");
    }

    return 0;
}
