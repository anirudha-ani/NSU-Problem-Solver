
//
//  main.cpp
//  C - Road Construction
//
//  Created by Anirudha Paul on 1/5/16.
//  Copyright © 2016 Anirudha Paul. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

struct connections
{
    int city1;
    int city2;
    int value;
}pairs[55];

bool ascending_sort(connections x , connections y)
{
    return x.value < y.value ;
}

int fathers[110];
int level[110];

int khoj(int x)
{
    if(fathers[x]!=x)
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

int main(int argc, const char * argv[])
{
    int T , roads , costing , total_cost;

    string city1 , city2;

    scanf("%d", &T);

    for(int i = 0 ; i < T ; i++)
    {
        map<string , int> name_index;

        scanf("%d", &roads);

        int index_start = 1;

        for(int j = 0 ; j < roads ; j++)
        {
            cin >> city1 >> city2 >> costing;

            if (name_index[city1] == 0)
            {
                name_index[city1] = index_start;
                index_start++;
            }
            if (name_index[city2] == 0)
            {
                name_index[city2] = index_start;
                index_start++;
            }
            pairs[j].city1 = name_index[city1];
            pairs[j].city2 = name_index[city2];
            pairs[j].value = costing;
        }

        sort(pairs, pairs+roads, ascending_sort);

        for(int i = 1 ; i < index_start ; i++)
        {
            fathers[i] = i;
            level[i] = 0;
        }

        total_cost = 0;

        for (int t = 0 ; t < roads; t++)
        {
            if (khoj(pairs[t].city1)!=khoj(pairs[t].city2))
            {
                unite(pairs[t].city1, pairs[t].city2);
                total_cost += pairs[t].value;
            }
        }
        for (int i =1; i<index_start; i++)
        {
            if (khoj(1) != khoj(i))
            {
                total_cost = -1;
                break;
            }
        }
        if(total_cost != -1)
        {
            printf("Case %d: %d\n" , i+1 , total_cost);
        }
        else
        {
            printf("Case %d: Impossible\n" , i+1);
        }


    }

    return 0;
}
