#include <bits/stdc++.h>

using namespace std;
int maps[1005];
int main()
{
    int n , k ;

    scanf("%d %d", &n , &k);

    int a , b , c , d;

    scanf("%d %d %d %d", &a , &b , &c , &d);

    maps[a] = 1;
    maps[b] = 1;
    maps[c] = 1;
    maps[d] = 1;

    if(n > 4 && k > n)
    {
        printf("%d %d " , a , c);

        for(int i = 1 ; i <= n ; i++)
        {
            if(maps[i] == 0)
            {
                printf("%d ", i);
            }
        }
        printf("%d %d\n", d , b);

        printf("%d %d " , c , a);

        for(int i = 1 ; i <= n ; i++)
        {
            if(maps[i] == 0)
            {
                printf("%d ", i);
            }
        }
        printf("%d %d\n", b , d);
    }
    else printf("-1\n");

    return 0 ;
}
