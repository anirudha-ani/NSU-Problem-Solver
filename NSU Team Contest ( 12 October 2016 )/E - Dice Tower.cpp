#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n ;

    scanf("%d", &n);

    int top;
    int bottom ;

    scanf("%d", &top);
    bottom = 7 - top ;

    int left , right ;
    int marker[7];
    int possible = true;

    for(int i = 0 ; i < n ; i++)
    {
        memset(marker , 0 , sizeof(marker));

        scanf("%d %d", &left , &right);

        marker[left] = 1;
        marker[right] = 1;
        marker[7-left] = 1;
        marker[7 - right] = 1;
        bool found = false;

        for(int i = 1 ; i < 7; i++)
        {
            if(marker[i] != 1)
            {
                if(i == top || i == bottom)
                {
                    found = true;
                }
            }
        }
        if(!found)
        {
            possible = false ;
        }
    }
    if(possible)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}
