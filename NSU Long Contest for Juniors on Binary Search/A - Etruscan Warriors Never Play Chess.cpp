#include <cstdio>
#include <iostream>

using namespace std;

long long int binarySearch(long long int input)
{
    long long int start = 0;
    long long int finish = 1000000000;
    long long int mid ;

    while(start != finish && start != finish-1)
    {
         mid = (finish + start) /2;
        //cout << mid << endl;
        if(mid*(mid+1)/2<=input)
        {
            start = mid;
        }
        else
        {
            finish = mid;
        }
        int x;
//        cin >> x;
//        cout << start << " " << finish << endl;

    }
    return start;
}

int main()
{
    long long int test_case , input;

    scanf("%lld", &test_case);

    for(int i = 0 ; i < test_case ; i++)
    {
        scanf("%lld", &input);

        long long int ans = binarySearch(input);
        printf("%lld\n",ans);
    }

//    while(scanf("%lld", &x))
//    {
//        long long int ans = x * (x+1) / 2;
//
//        printf("%lld\n", ans);
//    }


    return 0;
}
