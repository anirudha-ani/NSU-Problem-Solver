//
//  main.cpp
//  F - Combinations
//
//  Created by Anirudha Paul on 5/27/15.
//  Copyright (c) 2015 Anirudha Paul. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

long long int Combinations(int long long n, int long long k);
long long int combi [200][200];

int main()
{
    long long int n , k ;
    
    memset(combi, -1, sizeof(combi));
    
    scanf("%lld %lld" , &n , &k);
    
    while (n!=0 && k!=0)
    {
        printf("%lld things taken %lld at a time is %lld exactly.\n" , n , k , Combinations(n, k));
        scanf("%lld %lld" , &n , &k) ;
    }
    return 0;
}

long long int Combinations(int long long n, int long long k)
{
    if(k == 1)
        return n;
    else if (n == k)
        return 1;
    if (combi[n][k]!= -1)
    {
        return combi[n][k];
    }
    else
        combi [n][k] = Combinations(n-1, k) + Combinations(n-1, k-1);
    return combi[n][k];
}
