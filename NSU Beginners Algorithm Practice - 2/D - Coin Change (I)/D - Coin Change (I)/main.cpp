//
//  main.cpp
//  D - Coin Change (I)
//
//  Created by Anirudha Paul on 5/29/15.
//  Copyright (c) 2015 Anirudha Paul. All rights reserved.
//

#include <cstdio>
#include <iostream>

using namespace std;

long long dp[30000][60];

int coins[60];
int numbers[60];

long long pathways(int input , int index , int sum , int coin_no);

int main(int argc, const char * argv[])
{
    int case_no;
    
        scanf("%d" , &case_no);
    
        for ( int i  = 0 ; i < case_no ; i++)
        {
            int input , coin_no ;
    
            scanf("%d %d" , &coin_no , &input);
    
            for (int i = 0 ; i < coin_no ; i++)
            {
                int x ;
                scanf("%d" , &x);
    
                coins[i] = x;
                
                
            }
            for (int i = 0 ; i < coin_no ; i++)
            {
                int y;
                scanf("%d" , &y);
                
                numbers [i] = y;
                
            }
            
            memset(dp,-1,sizeof(dp) );
            long long m = pathways(input , 0 ,0, coin_no);
            
            printf("%lld\n" , m);
        }

    return 0;
}


long long pathways (int input , int index ,int sum , int coin_no)
{
    if (sum > input )
    {
        return 0;
    }
    
    if (sum == input)
    {
        return 1;
    }
    
    if (dp[sum][index] != -1)
    {
        return dp[sum][index];
    }
    
    dp[sum][index] =0;
    for (int i = index ; i < coin_no ; i++   )
    
    {
        
            long long x =  pathways(input , i , sum + coins[i] , coin_no);
            dp[sum][index] += x;
        
        
        
    }
    return dp[sum][index];
}



//int pathways(int coins[] , int change , int sum , int index , int coin_no)
//{
//    
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
//        for (int i = index; i < coin_no; i++)
//        {
//            numbers[i] = numbers[i] - 1;
//    
//            int x =  pathways(coins , change , sum + coins[i] , i , coin_no);
//                
//                
//            if (numbers[i] >= 0)
//            {
//                dp[sum][index] += x;
//            }
//            
//
//
//        }
//    }
//    return dp[sum][index] ;
//
//}






//#include <iostream>
//
//int coins[60];
//int numbers[60];
//
//int main(int argc, const char * argv[])
//{
//    int case_no;
//    
//    scanf("%d" , &case_no);
//    
//    for ( int i  = 0 ; i < case_no ; i++)
//    {
//        int input , coin_no ;
//        
//        scanf("%d %d" , &coin_no , &input);
//        
//        for (int i = 0 ; i < coin_no ; i++)
//        {
//            int x , y;
//            scanf("%d %d " , &x , &y);
//            
//            coins[i] = x;
//            numbers [i] = y;
//        }
//        
//        long ways[30001] ;
//        for(int i = 0 ; i < 30001 ; i ++)
//        {
//            ways[i] = 0 ;
//        }
//        ways[0] = 1;
//        
//        for(int i = 0; i < coin_no; i++)
//        {
//            int x = 0;
//            for(int j = coins[i]; x <= numbers[i]; x++)
//            {
//                ways[j] += ways[j - coins[i]];
//            }
//            
//        }
//        
//        printf("%ld\n" , ways[input]);
//        
//    }
// 
//    
//    return 0;
//}
