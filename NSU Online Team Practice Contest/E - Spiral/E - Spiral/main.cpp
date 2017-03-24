//
//  main.cpp
//  E - Spiral
//
//  Created by Anirudha Paul on 2/17/16.
//  Copyright © 2016 Anirudha Paul. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;


int main(int argc, const char * argv[])
{
    
    unsigned long long N , B , R  , C  , root ;
    
    while(scanf("%llu %llu", &N , &B)==2)
    {
        
        unsigned long long step_left = N*N - B + 1 ;
        
        if (N %2 == 0)
        {
            R = N / 2 + 1 ;
            C = N / 2;
            
            root = sqrt(step_left);
            if(root % 2  == 0)
            {
                R--;
                 unsigned long long  manipulate = root / 2 - 1;
                R -= manipulate;
                C -= manipulate;
                step_left -= root * root ;
                if(step_left == 0)
                {
                    printf("%llu %llu\n",R , C );
                    continue;
                }
                else if(step_left >= root+1 )
                {
                    C--;
                    R += root ;
                    step_left -= (root+1);
                    C += step_left;
                }
                else
                {
                    C--;
                    R += (step_left-1) ;
                }
            }
            else
            {
                unsigned long long manipulate = root / 2 ;
                R += manipulate;
                C += manipulate;
                step_left -= root * root ;
                if(step_left == 0)
                {
                    printf("%llu %llu\n",R , C );
                    continue;
                }
                else if(step_left >= root+1 )
                {
                    C++;
                    R -= root ;
                    step_left -= (root+1);
                    C -= step_left;
                }
                else
                {
                    C++;
                    R -= (step_left-1) ;
                }
            }
            
        }
        else
        {
            R = N / 2 + 1;
            C = N / 2 + 1;
            
            root = sqrt(step_left);
            //cout << R << ":::" << C <<"::" << root << endl ;
            if(root % 2  != 0)
            {
                
                unsigned long long manipulate = root / 2 ;
                R -= manipulate;
                C -= manipulate;
                step_left -= root * root ;
                if(step_left == 0)
                {
                    printf("%llu %llu\n",R , C );
                    continue;
                }
                else if(step_left >= root+1 )
                {
                    C--;
                    R += root ;
                    step_left -= (root+1);
                    C += step_left;
                }
                else
                {
                    C--;
                   // cout << R << ":::" << C <<endl ;
                    R += (step_left-1) ;
                    //cout << R << ":::" << C <<endl ;
                }
            }
            else
            {
                R++;
                unsigned long long manipulate = root / 2 - 1;
                R += manipulate;
                C += manipulate;
                step_left -= root * root ;
                if(step_left == 0)
                {
                    printf("%llu %llu\n",R , C );
                    continue;
                }
                else  if(step_left >= root+1 )
                {
                    C++;
                    R -= root ;
                    step_left -= (root+1);
                    C -= step_left;
                }
                else
                {
                    C++;
                    R -= (step_left-1) ;
                }
            }
            
        }
        printf("%llu %llu\n",R , C );
        
        //cout <<
        
    }
    
    
    //printf("%lld %lld\n",R , C);
    
    
    return 0;
}
