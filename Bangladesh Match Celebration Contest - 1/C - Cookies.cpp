#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n ;

    long long int  x ;

    cin >> n ;
    long long int ans = 1 ;
    if(n == 0)
    {
        printf("1\n");
    }
    else
    {
        while(n>1)
        {
            ans = (ans*3)%1000003;
            n--;
        }
        cout << ans << endl ;
    }
    return 0;
}
