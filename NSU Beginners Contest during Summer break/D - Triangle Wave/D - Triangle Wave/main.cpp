//
//  main.cpp
//  D - Triangle Wave
//
//  Created by Anirudha Paul on 5/14/15.
//  Copyright (c) 2015 Anirudha Paul. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, const char * argv[])
{
    int caseNo;
    
    scanf("%d" , &caseNo);
    
    for (int i = 0 ;  i < caseNo ; i++)
    {
        
        int amplitude , frequency ;
        
        scanf("%d" , &amplitude);
        scanf("%d" , &frequency);
        
        for (int i = 0 ; i < frequency ; i++)
        {
            
            for (int j = 0 ; j < amplitude ; j++)
            {
                for (int k = j+1; k >0 ; k--)
                {
                    printf("%d" , j+1);
                }
                printf("\n");
            }
            
            for (int j = amplitude-1 ; j >0 ; j--)
            {
                for (int k = j; k >0 ; k--)
                {
                    printf("%d" , j);
                }
                printf("\n");
            }
            if (i!= frequency - 1)
            {
                printf("\n");
            }

        }
        
        if (i!= caseNo - 1)
        {
            printf("\n");
        }
    }
    
    return 0;
}
