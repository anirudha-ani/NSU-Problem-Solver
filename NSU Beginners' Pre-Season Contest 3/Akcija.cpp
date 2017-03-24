#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;


bool lessThan(int a , int b)
{
    return a>b;
}

int main()
{
    int N;
    int input[100005];

    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++)
    {
        scanf("%d", &input[i]);
    }

    sort(input , input+N,lessThan);

    long long int total = 0;
    for(int i = 0 ; i < N ; i++)
    {
        if(((i+1)%3)!=0)
        {
            total += input[i];
        }
    }
    printf("%lld\n", total);
    return 0;
}
