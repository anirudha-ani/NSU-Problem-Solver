//
//  main.cpp
//  B - Donation
//
//  Created by Anirudha Paul on 1/4/16.
//  Copyright © 2016 Anirudha Paul. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int fathers[55];
int level[55];

struct connection
{
    int a ;
    int b;
    int cost = 0;
}input[2505];

bool ascending_sort(connection a , connection b)
{
    return a.cost < b.cost ;
}

int khoj(int x)
{
    //cout << "X= " << x << endl ;
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

int main(int argc, const char * argv[])
{
    int T , n , donate , cost;
    
    scanf("%d", &T);
    
    for (int i = 0; i < T; i++)
    {
        //int graph[55][55] = {0};
        donate = 0;
        
        scanf("%d", &n);
        
        int m = 0;
        for (int j = 0 ; j < n ; j++)
        {
            for (int k = 0 ; k < n; k++)
            {
                
                scanf("%d", &cost);
                
                input[m].a = j;
                input[m].b = k;
                input[m].cost = cost ;
                
                if (j == k)
                {
                    input[m].cost = 0;
                    donate += cost ;
                }
                
                m++;
                
            }
        }
        
        sort(input, input+m, ascending_sort);
        
        for (int l = 0 ; l < n ; l++)
        {
            fathers[l] = l;
            level[l] = 0;
        }
        
        for (int q = 0 ; q < m ; q++)
        {
            int j = input[q].a;
            int k = input[q].b;
            int costing  = input[q].cost;
            
                //cout << j<< "::"<< k << endl ;
                if (j == k  || costing == 0)
                {
                    continue;
                }
                else if(khoj(j) != khoj(k) )
                {
                    unite (j , k);
                    //cout<< "J = " << j <<" K = " << k << endl ;
                    //donate += costing;
                    input[q].cost = 0;
                    //donate += graph[j][k] > graph[k][j] ? graph[j][k]: graph[k][j];
                }
        }
        //cout << "Here" << endl;
        
        for(int q = 0 ; q < m ; q++)
        {
            donate+= input[q].cost ;
        }
        
        for(int k = 1 ; k < n ; k++)
        {
            if (khoj(0) != khoj(k))
            {
                //cout << ":::" << k << ":::"<<endl;
                donate = -1;
            }
        }
        printf("Case %d: %d\n", i+1 , donate);
    }
    
    return 0;
}
