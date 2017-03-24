#include <cstdio>
#include <math.h>

using namespace std;

int main()
{
    int case_no;
    scanf("%d" ,  &case_no);
    bool *prime;
    prime =  new bool[10000000];

    for (int i = 0 ; i < 10000000 ; i++)
    {
        prime[i] = true ;
    }

    for (int i = 2 ; i < 10000000; i++)
    {
        if (prime[i] == true)
        {
            for (int j = 2; j*i < 10000000 ; j++)
            {
                prime[j*i] = false;
            }
        }
    }

    for(int i = 0; i <case_no ; i++)
    {
        long long int input;
        scanf("%lld" , &input);

        long long int square_no =  sqrt(input);
       // printf("%lld\n" , square_no);

        long long int answer = input;

        for(long long int i = 2 ; i <=square_no ; i++)
        {
            if(prime[i] == true)
            {
            long long reduction = input/(i*i);
            for(int j = 2; j < i ;j++)
            {
                if(prime[j] == true)
                {
                    reduction -= (input/((i*i*j*j)));
                    printf("reducing %lld\n" ,(input/((i*i*j*j))));
                }
            }
             answer = answer - reduction;
             printf("%lld " ,reduction);
            }
        }
        printf("\n%lld\n" , answer);


    }

    return 0;
}
