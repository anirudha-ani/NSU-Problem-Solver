#include <bits/stdc++.h>

using namespace std;
int coins[55];
int coin_number[105];
int precalculate[1005];
int currentcoin[1005];
int inf = 4294967295;
int main()
{
    int test_case;
    int n , K;

    scanf("%d", &test_case);

    for(int i = 0 ; i < test_case ; i++)
    {
        memset(precalculate , 0 , sizeof(precalculate));
        precalculate[0] = 1;
        scanf("%d %d",&n , &K );

        for(int j = 0 ; j < n ; j++)
        {
            scanf("%d", &coins[j]);
        }

        for(int j = 0 ; j < n ; j++)
        {
            scanf("%d", &coin_number[coins[j]]);
        }

        sort(coins , coins + n);

        for(int j = 0 ; j < n ; j++)
        {
            memset(currentcoin , 0 , sizeof(currentcoin));

            currentcoin[0] = 0;

            for(int m = coins[j] ; m <= K ; m++)
            {
                if(precalculate[m - coins[j]] != 0 && currentcoin[m-coins[j]] + 1 <= coin_number[coins[j]])
                {

                    precalculate[m] = (precalculate[m] + precalculate[m-coins[j]])%100000007 ;
                    currentcoin[m] = currentcoin[m-coins[j]] + 1;

                }
            }
            for(int m = 0 ; m <= K ; m++)
            {
                cout << precalculate[m] << " " ;
            }
            cout << endl;
            for(int m = 0 ; m <= K ; m++)
            {
                cout << currentcoin[m] << " " ;
            }
            cout << endl;
        }
        printf("Case %d: %d\n", i+1 , precalculate[K]);

    }
    return 0;
}
