#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input ;

    while(cin >> input )
    {

    int x = input.length();
    int a = 0,b = 0;


    for ( int y = 1 ; y < x && (a == 0 || b == 0) ; y++)
    {

        if(input[y-1] == 'A'&& input[y] == 'B')
        {
            a=1;
            y = y+2;
        }
        if(input[y-1] == 'B'&& input[y] == 'A')
        {
            b=1;
            y = y+1;
        }
    }
    if(a==1 && b==1)
        printf("YES\n");
    else
        printf("NO\n");
    }

    return 0 ;


}
