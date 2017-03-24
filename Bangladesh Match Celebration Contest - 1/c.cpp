#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a , b;

    long long int power_two[34];
    power_two[0] = 1;

    for(int i = 1 ; i < 34 ; i++)
    {
        power_two[i] = power_two[i-1] * 2 ;
        //cout << power_two[i] << endl;
    }
    long long int counter ;
    int i = 1 ;
    while(scanf("%d %d", &a , &b) && (a!=0 || b!= 0))
    {
        counter = 0 ;
        b++;

        for(int i = 1 ; i < 34 ; i++)
        {
            counter += b / power_two[i] * power_two[i-1];

           // cout << "Counter 1 = " << counter << endl ;
            if(((b%power_two[i]) -  power_two[i-1] )> 0)
            {
                counter += (b%power_two[i]) -  power_two[i-1] ;
                //cout << "Counter 2 = " << counter << endl ;
            }
            if(a / power_two[i] > 0)
            {
                counter -= a / power_two[i] * power_two[i-1];
                //cout << "Counter 3 = " << counter << endl ;
            }


            if(((a%power_two[i]) -  power_two[i-1] )> 0)
            {
                counter -= (a%power_two[i]) -  power_two[i-1] ;
                //cout << "Counter 4 = " << counter << endl ;
            }
        }
        printf("Case %d: %lld\n", i , counter );
        i++;
    }
    return 0;
}
