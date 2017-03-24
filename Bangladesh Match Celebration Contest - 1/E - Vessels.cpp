#include <bits/stdc++.h>

using namespace std;
int  n ;
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
void update(int index , long long int amount)
{
    while(amount >0 && index !=n+1)
    {
        long long int fills = min(amount , capacity[index] - contains[index]);
        contains[index] += fills;
        amount -= fills ;

        if(contains[index] == capacity[index])
        {
            fathers[index] = fathers[index+1];

        }
         index = khoj(index);
    }

}


int main()
{



    int  n ;

    scanf("%d", &n);
    int input ;
    for(int i = 1 ; i <= n ; i++)
    {
        scanf("%d", &input);
        capacity[i] = input ;
        contains[i] = 0;
        fathers[i] = i ;
    }
    fathers[n+1] = n+1;
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
            index = khoj(index);
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
