#include <bits/stdc++.h>

using namespace std;

long long int precalculate[10005];
int money[25];

int main()
{
    for(int i = 1 ; i < 25 ; i++)
    {
        money[i] = i*i*i;
    }
    precalculate[0] = 1;
    for(int i = 1 ; i < 22 ; i++)
    {
        for(int j = money[i] ; j < 10005 ; j++)
        {
            precalculate[j] += precalculate[j - money[i]];
        }
    }

    int query;

    while(scanf("%d", &query) == 1)
    {
        printf("%lld\n", precalculate[query]);
    }
    return 0 ;
}
