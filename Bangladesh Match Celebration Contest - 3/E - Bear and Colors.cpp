#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int balls[5005];
    int counter[5005];

    memset(counter,0,sizeof(counter));

    scanf("%d",&n);


    for(int i=0;i<n;i++)
    {
        scanf("%d",&balls[i]);
    }

    for(int i=0;i<n;i++)
    {
        int localCounter[5005];

        int highest=0 ;
        int highestIndex = i;

        memset(localCounter,0,sizeof(localCounter));

        for(int j=i;j<n;j++)
        {
            localCounter[balls[j]]++;

            if (localCounter[balls[j]]>highest)
            {
                highestIndex = j;
                highest = localCounter[balls[j]];
            }
            else if (localCounter[balls[j]] == highest)
            {
                if (balls[j]<balls[highestIndex])
                {
                    highestIndex = j;
                    highest=localCounter[balls[j]];
                }
            }

            counter[balls[highestIndex]]++;
        }
    }

    for(int i=1 ; i <= n ; i++)
    {
        printf("%d ",counter[i]);
    }
    printf("\n");

    return 0;

}
