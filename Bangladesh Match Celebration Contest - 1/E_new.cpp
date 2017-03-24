#include <bits/stdc++.h>

using namespace std;

long long int contains[200005];
long long int capacity[200005];
int fathers[200005];
int khoj(int x)
{
    if(fathers[x] != x)
    {
        fathers[x] = khoj(fathers[x]);
    }
    return fathers[x];
}
void update(int index , int amount)
{
    if(contains[index] == capacity[index])
    {
        index = khoj(index+1);
        update(index , amount );
    }
    else if(contains[index] + amount > capacity[index])
    {

        update(khoj(index+1) ,amount -(capacity[index] -contains[index]));
        fathers[index] = fathers[index+1];
        contains[index] = capacity[index];

    }
    else
        contains[index] += amount;
}


int main()
{

    for(int i = 0 ; i < 200005 ; i++)
    {
        fathers[i] = i;
    }
    memset(contains , 0 , sizeof(contains));
    memset(capacity , 0 , sizeof(capacity));


    int  n ;

    scanf("%d", &n);

    for(int i = 1 ; i <= n ; i++)
    {
        scanf("%d", &capacity[i]);
    }
    capacity[n+1] = 1000000000000000;
    capacity[n+2] = 1000000000000000;
    capacity[n+3] = 1000000000000000;
    int m ;
    scanf("%d", &m);

    int command;
    int index , amount ;
    for(int i = 1 ; i <= m ; i++)
    {
        scanf("%d", &command);

        if(command == 1)
        {
            scanf("%d %d", &index , &amount);
            update(index , amount);
        }
        else
        {
            scanf("%d", &index);
            printf("%lld\n", contains[index]);
        }
    }
    return 0;
}
