#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a , b , c ;

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);


    int min = 9999999;

    if(a*b+c <min)
    {
        min = a*b+c;
    }
    if(a*b-c <min)
    {
        min = a*b-c ;
    }
    if(a*b*c <min)
    {
        min = a*b*c;
    }
    if(a+b+c <min)
    {
        min = a+b+c;
    }
    if(a+b-c <min)
    {
        min = a+b-c;
    }
    if(a+b*c <min)
    {
        min = a+b*c;
    }
    if(a-b+c <min)
    {
        min = a-b+c;
    }
    if(a-b-c <min)
    {
        min = a-b-c ;
    }
    if(a-b*c <min)
    {
        min = a-b*c;
    }

    printf("%d\n",min);
    return 0;
}
