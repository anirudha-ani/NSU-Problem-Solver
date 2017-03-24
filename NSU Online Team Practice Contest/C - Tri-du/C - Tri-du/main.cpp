//
//  main.cpp
//  C - Tri-du
//
//  Created by Anirudha Paul on 2/17/16.
//  Copyright © 2016 Anirudha Paul. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, const char * argv[]) {
    int a , b;
    
    while(scanf("%d %d", &a , &b) == 2)
    {
        a>b?printf("%d\n",a):printf("%d\n",b);
    }
    return 0;
}
