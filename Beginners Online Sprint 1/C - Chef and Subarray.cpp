#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int N, A;

    scanf("%d" , &N);

    int maxLength = 0;
    int tempLength = 0;
    for(int i = 0 ; i < N ; i++)
    {
        scanf("%d" ,&A);
        if(A==0)
        {
            if(tempLength > maxLength)
            {
                maxLength = tempLength;
            }
            tempLength = 0;
        }
        else
        {
            tempLength++;
        }
    }
    if(tempLength > maxLength)
    {
        maxLength = tempLength;
    }
    printf("%d\n" , maxLength);
    return 0;
}
