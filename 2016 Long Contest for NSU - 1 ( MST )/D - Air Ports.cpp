#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct connection
{
    int road1;
    int road2;
    int cost;
}street[100005];

bool ascending_sort(connection x , connection y)
{
    return x.cost < y.cost;
}

int fathers[10005];
int level[10005];


int khoj(int x)
{
    if(fathers[x] != x)
    {
        fathers[x] = khoj(fathers[x]);
    }
    return fathers[x];
}

void unite(int x, int y)
{
    int a = khoj(x);
    int b = khoj(y);

    if(level[a] < level[b])
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

int main()
{
    int T ,N ,M ,A , X , Y , C;

    scanf("%d", &T);

    for(int i = 0 ; i < T ;i++)
    {
        scanf("%d %d %d", &N ,&M ,&A);

        for(int j = 0 ; j < M ; j++)
        {
            scanf("%d %d %d", &X , &Y , &C);

            street[j].road1 = X;
            street[j].road2 = Y;
            street[j].cost = C;
        }

        sort(street , street + M , ascending_sort);

        for(int j = 0 ; j < 10005 ; j++)
        {
            fathers[j] = j;
            level[j] = 0;
        }
        int costs = 0;
        int airports = 0;
        for(int j = 0 ; j < M ; j++)
        {
            if(khoj(street[j].road1) != khoj(street[j].road2) )
            {
                if(street[j].cost < A)
                {
                    unite(street[j].road1 , street[j].road2);
                    costs += street[j].cost;
                }

            }
        }

        for(int j = 1 ; j <= N ;j++)
        {
            khoj(j);
        }
        bool sets[10005] = {false};
        for(int j = 1 ; j <= N ; j++)
        {
            if(sets[fathers[j]] == false)
            {
                sets[fathers[j]] = true;
                airports++;
            }
        }

        int ans = costs + A * airports;

        printf("Case %d: %d %d\n", i+1 , ans , airports);

    }
    return 0;
}
