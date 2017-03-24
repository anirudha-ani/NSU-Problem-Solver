//
//  main.cpp
//  E - Coin Change (II)
//
//  Created by Anirudha Paul on 5/28/15.
//  Copyright (c) 2015 Anirudha Paul. All rights reserved.
//

#include <iostream>

#include<cstdio>
using namespace std;


int main()
{
    int m, coins[30000] , coin_no = 0;
    long long ways[30000] ;
    
    int case_no;
    
    scanf("%d" , &case_no);
    
    for (int i = 0 ; i < case_no ; i++)
    {
        scanf("%d %d" , &coin_no , &m);
        
        for (int i = 0 ; i < coin_no; i++)
        {
            int x;
            scanf("%d" , &x);
            coins[i] = x;
        }
        
        for(int i = 0 ; i < 30000 ; i ++)
        {
            ways[i] = 0 ;
        }
        ways[0] = 1;
        
        
        for(int i = 0; i < coin_no; i++)
        {
            for(int j = coins[i]; j <= 30000; j++)
            {
                ways[j] = (ways[j] + ways[j - coins[i]])%100000007;
            }
            
        }
        
        printf("Case %d: %lld\n" , i+1 , ways[m]%100000007);

    }
    
    
    return 0;
    
}
