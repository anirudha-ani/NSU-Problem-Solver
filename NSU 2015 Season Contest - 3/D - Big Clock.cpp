#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    int test_case;

    scanf("%d" , &test_case);

    for(int i =  0 ; i < test_case ; i++)
    {
        int h , m;
        char colon;

        scanf("%d" , &h);
        scanf("%c" , &colon);
        scanf("%d" , &m);

        if (m == 0)
        {
            if(h == 12)
            printf("24\n");
            else
            printf("%d\n" , (h+12)%24);
        }
        else
        {
            printf("0\n");
        }

    }
    return 0;
}
