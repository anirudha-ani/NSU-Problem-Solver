#include <cstdio>

using namespace std;

int main()
{
    bool prime [1000001];

    for(int i = 0 ; i < 1000001 ; i++)
        prime [i] = true;

     for (int i = 2; i * i <= 1000001; i++)
     {
        if (prime[i] == true)
        {
            for (int j = i * i; j <= 1000001; j += i)
            {
                prime[j] = false;
            }
        }
     }

    long long int K , L , mark;

    while((scanf("%lld %lld", &K , &L)) == 2)
    {
        if(K == 0 && L == 0)
            break;
        bool flag = true;
        for(int i = 2 ; i < L ; i++)
        {
            if(prime[i] == true)
            {
                if(K%i == 0)
                {
                    flag = false;
                    mark = i;
                    break;
                }
            }
        }
        if(flag)
        {
            printf("GOOD\n");
        }
        else
        {
            printf("BAD %d\n",mark);
        }
    }

    return 0;
}
