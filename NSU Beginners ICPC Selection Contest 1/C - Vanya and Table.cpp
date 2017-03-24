#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int case_no ,sum = 0;

    scanf("%d" , &case_no);

    for(int i = 0 ; i < case_no ; i++)
    {

        int x1 , y1 , x2 , y2;

        scanf("%d %d %d %d" , &x1 , &y1 , &x2 , &y2);

        sum = sum + ((x2-x1 +1) * (y2 - y1+1));
    }
    printf("%d\n" , sum);

    return 0;
}
