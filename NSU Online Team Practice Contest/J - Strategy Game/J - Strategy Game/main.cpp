//
//  main.cpp
//  J - Strategy Game
//
//  Created by Anirudha Paul on 2/17/16.
//  Copyright © 2016 Anirudha Paul. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct players
{
    int index;
    int price;
}x[505];

bool sort_price (players a , players b)
{
    if (a.price == b.price)
    {
        return a.index > b.index;
    }
    return a.price > b.price;
}

int main(int argc, const char * argv[]) {
    int j , r , input ;
    
    while(scanf("%d %d", &j , &r) == 2)
    {
    
        for(int i = 0 ; i < j ; i++)
        {
            x[i].index = i+1;
            x[i].price = 0;
        }
        int rounds = j * r ;
    
        int turn = 0;
        for (int i = 0 ; i < rounds ; i++ )
        {
            scanf("%d", &input);
            x[turn].price+= input;
            turn++;
            if(turn== j) turn = 0;
        }
        sort(x , x+j, sort_price);
        
        printf("%d\n", x[0].index);
    }
    return 0;
}
