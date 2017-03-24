 //
//  main.cpp
//  B - Let Me Count The Ways
//
//  Created by Anirudha Paul on 5/25/15.
//  Copyright (c) 2015 Anirudha Paul. All rights reserved.
//

//#include <iostream>
//#include <cstdio>
//
//using namespace std;

#include<cstdio>
using namespace std;

int m, coins[] = { 1, 5, 10, 25, 50 };
long ways[30001] = { 0 };

int main()
{
    int m, coins[] = { 1, 5, 10, 25, 50 };
    long ways[30001] ;
    for(int i = 0 ; i < 30001 ; i ++)
    {
        ways[i] = 0 ;
    }
    ways[0] = 1;
    for(int i = 0; i < 5; i++)
    {
        for(int j = coins[i]; j <= 30000; j++)
        {
              ways[j] += ways[j - coins[i]];
        }
        
    }
    
    while(scanf("%d", &m) == 1)
    {
        if (ways[m]==1)
        {
            printf("There is only %ld way to produce %d cents change.\n" , ways[m] , m);
        }
        else
        printf("There are %ld ways to produce %d cents change.\n", ways[m], m);
    }
    
    return 0;
    
}

//int main(int argc, const char * argv[])
//{
//    int coin[5] = {1 , 5 , 10 , 25 , 50 };
//    
//    
//    long long int ways[30005];
//    
//    ways[0] = 1;
//    
//    for (int i = 0 ; i < 5 ; i++)
//    {
//        for (int j = coin[i] ; j < 30005; j++)
//        {
//            ways[j] += ways[j-coin[i]];
//        }
//    }
//    long long int n;
//    
//    while (scanf("%lld", &n) == 1)
//    {
//        long long int x = ways[n];
//        if (x == 1)
//        {
//            printf("There is only 1 way to produce %lld cents change.\n" , n);
//        }
//        else
//        {
//            printf("There are %lld ways to produce %lld cents change.\n" , x , n );
//        }
//    }
//    
//    return 0;
//}
//int pathways(int coin[] , int change , int sum , int index );
//    int n = 1 ;
//
//    while (scanf("%d" , &n) == 1)
//    {
//
//
//        int m = pathways(coin, n, 0, 0);
//
//
//
//        if(n==0)
//        {
//            printf("There are 0 ways to produce 0 cents change.\n");
//        }
//
//        else if (m == 1)
//        {
//            printf("There is only 1 way to produce %d cents change.\n",n);
//        }
//
//        else
//            printf("There are %d ways to produce %d cents change.\n" , m , n);
//
//
//    }
//
//
//
//
//int pathways(int coin[] , int change , int sum , int index)
//{
//    int path = 0;
//    
//    if (sum > change)
//    {
//        return 0;
//    }
//    
//    else if (sum == change)
//    {
//        return 1;
//    }
//    
//    else if (sum < change)
//    {
//        for (int i = index; i < 5; i++)
//        {
//            int x =  pathways(coin , change , sum + coin[i] , i);
//            
//            path += x;
//           
//           
//        }
//    }
//    return path;
//    
//}
//#include <iostream>
//#include <cstdio>
//#include <string.h>
//
//using namespace std;
//
//
//int pathways(int coin[] , int change , int sum , int index );
//int dp[30005][7] ;
//
//
//int main(int argc, const char * argv[])
//{
//    int coin[5] = {1 , 5 , 10 , 25 , 50 };
//    
//    int n = 1 ;
//    
//    while (scanf("%d" , &n) == 1)
//    {
//        
//        memset(dp,-1,sizeof(dp) );
//        int m = pathways(coin, n, 0, 0);
//        
//        
//        
//        
//        if(n==0)
//        {
//            printf("There are 0 ways to produce 0 cents change.\n");
//        }
//        
//        else if (m == 1)
//        {
//            printf("There is only 1 way to produce %d cents change.\n",n);
//        }
//        
//        else
//            printf("There are %d ways to produce %d cents change.\n" , m , n);
//        
//        
//    }
//    
//    return 0;
//}
//
//
//
//
//int pathways(int coin[] , int change , int sum , int index)
//{
//    int path = 0;
//    
//    if (sum > change)
//    {
//        return 0;
//    }
//    
//    else if (sum == change)
//    {
//        return 1;
//    }
//    
//    if(dp[sum][index] !=-1) return dp[sum][index] ;
//    
//    else if (sum < change)
//    {
//        
//        dp[sum][index] =0;
//        for (int i = index; i < 5; i++)
//        {
//            int x =  pathways(coin , change , sum + coin[i] , i);
//            
//            dp[sum][index] += x;
//            
//            
//        }
//    }
//    return dp[sum][index] ;
//    
//}
