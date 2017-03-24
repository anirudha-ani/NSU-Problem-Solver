//
//  main.cpp
//  B - Stock Market
//
//  Created by Anirudha Paul on 2/17/16.
//  Copyright © 2016 Anirudha Paul. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[])
{
    int n , c ,max , profit ;
    int data[200005];
    
    while (scanf("%d %d", &n , &c) == 2)
    {
        max = 0;
        profit = 0;
        for(int i = 0 ; i < n ; i++)
        {
            scanf("%d", &data[i]);
        }
        max = data[n-1];
        for(int i = n-2 ; i >= 0 ; i--)
        {
            if(data[i]+c < max)
            {
                profit += max - data[i] - c;
            }
            if(data[i]> max) max = data[i];
        }
        printf("%d\n", profit);
        
    }
    return 0;
}
