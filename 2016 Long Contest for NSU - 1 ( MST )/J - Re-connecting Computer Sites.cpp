#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct edge
{
    int x;
    int y;
    int cost;
}data[100011];

bool ascending_sort(edge x , edge y)
{
    return x.cost < y.cost;
}

int fathers[100011];
int level[100011];

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
    int N , a , b , cost;
    int count_input = 0;
    while(scanf("%d",&N) == 1)
    {
        if(count_input > 0)
            printf("\n");
        count_input++;
        int first_cost = 0;
        for(int i = 0 ; i < N-1 ; i++)
        {
            scanf("%d %d %d", &a , &b , &cost);
            first_cost += cost;
        }
        //cout << "Here0" << endl;
        int edge_count = 0;

        int K;

        scanf("%d" , &K);

        for(int i = 0 ; i<K ;i++)
        {
            scanf("%d %d %d", &a , &b , &cost);
            data[edge_count].x = a;
            data[edge_count].y = b;
            data[edge_count].cost = cost;
            edge_count++;
        }
        //cout << "Here1" << endl;
        int M;

        scanf("%d", &M);
        //cout<< "M = " << endl;
        for(int i = 0 ; i < M ; i++)
        {

           // cout << "Here2" << endl;
            scanf("%d %d %d", &a , &b , &cost);
            data[edge_count].x = a;
            data[edge_count].y = b;
            data[edge_count].cost = cost;
            edge_count++;
        }
        //cout << "Here2" << endl;
        sort(data , data+edge_count , ascending_sort);

        for(int i = 0 ; i < 100011 ;i++)
        {
            fathers[i] = i;
            level[i] = 0;
        }
        int second_cost = 0;
        for(int i = 0 ; i < edge_count ; i++)
        {
            if(khoj(data[i].x) != khoj(data[i].y))
            {
                unite(data[i].x , data[i].y);
                second_cost += data[i].cost;
            }
        }
        printf("%d\n", first_cost);
        printf("%d\n", second_cost);
    }

    return 0;
}
