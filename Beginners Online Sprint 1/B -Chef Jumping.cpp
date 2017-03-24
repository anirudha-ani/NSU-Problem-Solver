#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    long long int a,x,y,z;
    scanf("%lld",&a);

    x=(a-1)%6;
    y=(a-3)%6;
    z=(a-6)%6;

    if(a==0||x==0||y==0||z==0)
        printf("yes");
    else
        printf("no");

    return 0;

}

