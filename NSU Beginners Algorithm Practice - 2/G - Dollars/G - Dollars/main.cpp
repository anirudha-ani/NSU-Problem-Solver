//
//  main.cpp
//  G - Dollars
//
//  Created by Anirudha Paul on 5/28/15.
//  Copyright (c) 2015 Anirudha Paul. All rights reserved.
//

#include<cstdio>
using namespace std;

int main()
{
    int coins[] = {1, 2, 4, 10 , 20 , 40 , 100 , 200 , 400 , 1000 ,2000 };
    long long ways[6010] ;
    int m;
    
    for(int i = 0 ; i < 6010 ; i ++)
    {
        ways[i] = 0 ;
    }
    ways[0] = 1;
    for(int i = 0; i < 11; i++)
    {
        for(int j = coins[i]; j <= 6010; j++)
        {
            ways[j] += (ways[j - coins[i]]);
        }
        
    }
    
    
    float input ;
    
    scanf("%f" , &input);
    
    while (input != 0)
    {
        m = (int) (input *20);
        
        printf("%6.2f%17lld\n" ,input , ways[m]);
        scanf("%f" , &input);

    }
    return 0;
    
}