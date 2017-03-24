#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t , l , r , l_z = 0 , l_o = 0 , r_z = 0  , r_o = 0 , ans = 0 ;

    scanf("%d", &t);

    for(int i = 0 ; i < t ; i++)
    {
        scanf("%d %d", &l , &r);

        if(l == 0)
        {
            l_z++;
        }
        else
        {
            l_o++;
        }
        if(r == 0)
        {
            r_z++;
        }
        else
        {
            r_o++;
        }
    }
    ans = min(l_z , l_o) + min(r_z , r_o);

    printf("%d\n" , ans);
    return 0;
}
