
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;

    scanf("%d", &N);
    int maxi = 0;
    int mini = 100000;
    int input ;
    int counter = 0;
    for(int i = 0 ; i < N ; i++)
    {
        scanf("%d", &input);
        if(i == 0)
        {
            maxi = input ;
            mini = input ;
        }
        else if(input > maxi)
        {
            counter++;
            maxi = input ;
        }
        else if(input < mini)
        {
            counter++;
            mini = input;
        }
    }
    printf("%d\n", counter);
    return 0;
}
