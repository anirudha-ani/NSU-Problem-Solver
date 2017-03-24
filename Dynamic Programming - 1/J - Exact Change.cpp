#include <bits/stdc++.h>

using namespace std;
long long int inf = 1000000000000000000;
long long int ans[30005];
int coins[105];
int main()
{
    //freopen("intput.txt" , "r" , stdin);
    //freopen("output.txt" , "w" , stdout);
    int test_case ,want_to_make;
    int number_of_coins;

    scanf("%d", &test_case);

    for(int i = 0 ; i < test_case ; i++)
    {
        for(int j = 0 ; j < 30005 ; j++)
        {
            ans[j] = inf;
        }

        scanf("%d", &want_to_make);
        scanf("%d", &number_of_coins);

        for(int j = 0 ; j < number_of_coins ; j++)
        {
            scanf("%d", &coins[j]);
        }
        sort(coins, coins + number_of_coins);
        ans[0] = 0;

        for(int j = 0 ; j < number_of_coins ; j++)
        {
            for(int k = 30005 - coins[j] -1 ; k >= 0 ; k--)
            {
                if(ans[k]<inf)
                {
                    ans[k+coins[j]] = min(ans[k]+1, ans[k+coins[j]]);
                }

            }
        }
//        for(int j = 0 ; j < 20005 ; j++)
//        {
//            cout << ans[j] <<endl;
//        }
        for(int j = want_to_make ; j < 20005 ; j++)
        {
            if( ans[j] < inf)
            {
                printf("%d %lld\n", j , ans[j]);
                break;
            }
        }
    }
    return 0;
}
