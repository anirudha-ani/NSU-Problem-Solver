#include<cstdio>

using namespace std;

int main()
{
    long long case_no , students ,max;

    scanf("%lld",&case_no);

    for(long long i=0 ;i < case_no ; i++)
    {
        long long max = 0;

        scanf("%lld",&students);

        for (long long j = 0; j < students ; j++)
        {
            long long speed;

            scanf("%lld",&speed);

            if (speed>max)
                max=speed ;
        }
        printf("Case %lld: %lld\n",i+1,max);
    }

    return 0;
}
