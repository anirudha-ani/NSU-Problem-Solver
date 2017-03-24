#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n , c , delay , input1 , input2 , ans ;

    scanf("%d %d", &n , &c);

    scanf("%d", &input2);
    ans = 1;
    for(int i = 1 ; i < n ; i++)
    {
        input1 = input2;

        scanf("%d", &input2);

        if(input2-input1 <= c)
        {
            ans++;
        }
        else
        {
            ans = 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
