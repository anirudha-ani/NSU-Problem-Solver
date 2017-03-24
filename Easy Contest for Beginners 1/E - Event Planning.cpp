#include<cstdio>

using namespace std;

int main()
{
    long long participents , budget , no_hotel , weeks ,cost;
    long long price [19];
    long long room [19];

    while(scanf("%lld %lld %lld %lld", &participents, &budget,&no_hotel, &weeks)==4)
    {
        cost = budget + 1 ;

        for(long long i=1 ; i <= no_hotel ; i++)
        {
            scanf("%lld", &price[i]);

            for(long long j=1 ; j<=weeks ; j++)
            {
                scanf("%lld", &room[j]);
                if(room[j] >= participents && (price[i] * participents) < cost)
                    {
                        cost= price[i] * participents;
                    }
            }
        }

        if(cost <= budget)
            printf("%lld\n",cost);
        else
            printf("stay home\n");
    }
    return 0;
}
