//
//  main.cpp
//  C - Neighbor House
//
//  Created by Anirudha Paul on 5/27/15.
//  Copyright (c) 2015 Anirudha Paul. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>

using namespace std;
int minimumCalculation(int index1 , int index2 , int house_no);

int min_calculation[25][3];

int color [25][3];
int cost [25][3];

static const int MAX = 99999;

int main(int argc, const char * argv[])
{
    int case_no;
    
    scanf("%d" , &case_no);
    
    
    
    for (int i = 0 ; i < case_no ; i++)
    {
        
        int house_no;
        scanf("%d" , &house_no);
        memset(cost, -1, sizeof(cost));
        
        for (int i = 0 ; i < house_no; i++)
        {
            int x , y , z;
            scanf("%d %d %d", &x , &y , &z);
            
            color[i][0] = x ;
            color[i][1] = y ;
            color[i][2] = z ;
        }
        int minimum = min(min(minimumCalculation(0, 0, house_no),minimumCalculation(0, 1, house_no)),minimumCalculation(0, 2, house_no));
        
        printf("Case %d: %d\n" , i+1 , minimum);
    }
    
    
    return 0;
}


int minimumCalculation(int index1 , int index2 , int house_no)
{
    if (cost[index1][index2] != -1)
    {
        return cost[index1][index2];
    }
    else if (index1 >=  house_no)
    {
        return MAX;
    }
    else if (index1 == house_no - 1)
    {
        cost[index1][index2] = color[index1][index2];
    }
    else if (index1 < house_no)
    {
        if (index2 == 0)
        {
            cost[index1][index2] = color[index1][index2] + min(minimumCalculation(index1+1, 1, house_no),minimumCalculation(index1+1, 2, house_no));
        }
        
        else if (index2 == 1)
        {
            
            cost[index1][index2] = color[index1][index2] + min(minimumCalculation(index1+1, 0, house_no),minimumCalculation(index1+1, 2, house_no));
        
        }
        else if(index2 == 2)
        {
            cost[index1][index2] = color[index1][index2] + min(minimumCalculation(index1+1, 0, house_no),minimumCalculation(index1+1, 1, house_no));
        }
    }
    return cost[index1][index2];
    
}



