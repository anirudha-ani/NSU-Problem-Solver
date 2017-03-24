#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    int B , R , Y;
    int input , ans = 1;
    string color;

    scanf("%d %d %d", &B , &R , &Y);

    scanf("%d", &input);

    for(int i = 0 ; i < input ; i++)
    {
        cin >> color ;

        if(color == "Red")
        {
            ans *= R;
        }
        else if(color == "Yellow")
        {
            ans *= Y;
        }
        else if(color == "Blue")
        {
            ans *= B;
        }
    }

    printf("%d\n",ans);

    return 0;
}
