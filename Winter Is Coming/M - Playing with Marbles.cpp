#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int input;

    while(scanf("%d", &input))
    {
        if(input == 0)
        {
            break;
        }

        int marbles = input;
        int pattern = 0;

        printf("%d = ",input);


        int limit = sqrt(input);

        for(int i = 2 ; i <= limit ; i++)
        {
            while(input % i == 0)
            {
                printf("%d", i);
                pattern++;
                input = input / i ;
                if(input > 1)
                    printf(" x ");
            }
        }
        if(input > 1)
        {
            printf("%d", input);
            pattern++;
        }
        printf("\n");

        printf("With %d marbles, %d different rectangles can be constructed.\n",marbles , pattern);
    }
    return 0 ;
}

