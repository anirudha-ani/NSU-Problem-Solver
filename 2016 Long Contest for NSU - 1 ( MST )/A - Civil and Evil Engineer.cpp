#include <bits/stdc++.h>

using namespace std;

struct pairs1
{
    int a;
    int b;
    int cost;
}input1[12005];

struct pairs2
{
    int a;
    int b;
    int cost ;
}input2[12005];

bool ascending_sort(pairs1 x , pairs1 y)
{
    return x.cost < y.cost;
}

bool descending_sort(pairs2 x , pairs2 y)
{
    return x.cost > y.cost;
}

int fathers[105];
int level[105];

int khoj(int x)
{
    if(fathers[x] != x)
    {
        fathers[x] = khoj(fathers[x]);
    }
    return fathers[x];
}

void unite(int x , int y)
{
    int a = khoj(x);
    int b = khoj(y);

    if(level[a]<level[b])
    {
        fathers[a] = b;
    }
    else
    {
        fathers[b] = a;

        if(level[a] == level[b])
            level[a]++;
    }

}

int  main()
{
    int T , n , u ,v ,w ;

    scanf("%d", &T);

    for(int i = 0 ; i < T ; i++)
    {
        scanf("%d", &n);

        memset(level , 0 , sizeof(level));

        scanf("%d %d %d", &u , &v , &w);

        int j = 0;

        for(int m = 0 ; m < 12005 ; m++)
        {
            input1[m].cost = 10099;
            input2[m].cost = -999;
        }

        while (u != 0 || v!= 0 || w!=0)
        {
            input1[j].a = u;
            input1[j].b = v;
            input1[j].cost = w;
            input2[j].a = u;
            input2[j].b = v;
            input2[j].cost = w;
            j++;
            scanf("%d %d %d", &u , &v , &w);
        }

        sort(input1 , input1+j ,ascending_sort);

        for(int z = 0 ; z < 105 ; z++)
        {
            fathers[z] = z;
            level[z] =0;
        }


        int low_cost = 0;

        for(int k = 0 ; k < j ; k++)
        {
            if(khoj(input1[k].a) != khoj(input1[k].b))
            {
                   unite(input1[k].a , input1[k].b);
                   low_cost += input1[k].cost;
            }
        }

        sort(input2 , input2+j ,descending_sort);

        for(int z = 0 ; z < 105 ; z++)
        {
            fathers[z] = z;
            level[z] =0;
        }


        int high_cost = 0;

        for(int k = 0 ; k < j ; k++)
        {
            if(khoj(input2[k].a) != khoj(input2[k].b))
               {
                   unite(input2[k].a , input2[k].b);
                   high_cost += input2[k].cost;
               }
        }

        if((high_cost+low_cost)%2 == 0)
        {
            printf("Case %d: %d\n", i+1 , (high_cost+low_cost)/2);
        }
        else
        {
            printf("Case %d: %d/2\n", i+1 , (high_cost+low_cost));
        }

    }
    return 0;
}
