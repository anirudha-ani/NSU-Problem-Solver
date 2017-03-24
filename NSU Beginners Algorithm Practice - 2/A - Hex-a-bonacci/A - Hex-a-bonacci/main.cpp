//
//  main.cpp
//  A - Hex-a-bonacci
//
//  Created by Anirudha Paul on 5/23/15.
//  Copyright (c) 2015 Anirudha Paul. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    long long a, b, c, d, e, f;
    long long  fib[10007];
    long long n, caseno = 0, cases;
    scanf("%lld", &cases);
    while( cases-- )
    {
        scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);
        
        fib[0] = a;
        fib[1] = b;
        fib[2] = c;
        fib[3] = d;
        fib[4] = e;
        fib[5] = f;
        
        for (int i = 6 ; i <= n ; i++)
        {
            fib [i] = (fib[i-1] + fib [i-2] + fib [i-3] + fib [i-4] + fib [i-5] + fib [i-6]) %10000007;
        }
        printf("Case %lld: %lld\n", ++caseno , fib[n]%10000007);
    }
    return 0;
}
