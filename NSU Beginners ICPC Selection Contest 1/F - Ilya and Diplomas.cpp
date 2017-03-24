#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    int test , min1 , min2 , min3 , max1 , max2 , max3 , first , second ,third ;

    scanf("%d" , &test);
    scanf("%d %d" , &min1 , &max1);
    scanf("%d %d" , &min2 , &max2);
    scanf("%d %d" , &min3 , &max3);

    first = min1;
    second = min2;
    third = min3;
    while((first+second + third)<test)
    {
        if(first < max1)
        {
            first++;
        }
        else if(second < max2)
        {
            second++;
        }
        else if(third <max3)
        {
            third++;
        }
    }
    printf("%d %d %d\n",first , second , third);
    return 0;
}
