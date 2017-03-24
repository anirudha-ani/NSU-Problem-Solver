#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    int length ;
    string input;

    cin >> length;
    cin >> input ;

    int a = 0 , b = 0 ;

    for(int x = 0 ; x < length ; x ++)
    {
        if(input[x]== '0')
        {
            a++;
        }
        else
        {
            b++;
        }
    }

    if(a>b)
    {
        printf("%d\n" , a - b);
    }
    else
    {
        printf("%d\n" , b - a);
    }
    return  0 ;
}
