#include <bits/stdc++.h>

using namespace std;

int main()
{
    unsigned long long int y = 2 ;
    unsigned long long int x = 1;
    unsigned long long int n ;
    unsigned long long int y1 = y;
     unsigned long long int p ;

    int level ;

    scanf("%d", &level);

    while(x<=level)
    {
        for(int i = 1 ; i <= 100000 ; i++)
        {
            if(sqrt(x*i)*sqrt(x*i) == x*i)
            {
                p = x*i;
                break;
            }
        }
        n = x*p*p + 2*p*p +p*p/x - y/x ;
        //printf("%lld\n", n );
        y = (long long int)sqrt(y+x*n);
        cout << y << endl;
        x++;
    }
    return 0 ;
}
