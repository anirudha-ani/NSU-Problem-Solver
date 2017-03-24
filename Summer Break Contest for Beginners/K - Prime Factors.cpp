#include <bits/stdc++.h>

int main()
{
    int input;

    while(scanf("%d", &input))
    {
        if(input == 0)
        {
            break;
        }
        if(input < 0 )
        {
            printf("%d = -1 x ",input);
            input = input * -1 ;
        }
        else
        {
            printf("%d = ",input);
        }

        int limit = sqrt(input);

        for(int i = 2 ; i <= limit ; i++)
        {
            while(input % i == 0)
            {
                printf("%d", i);
                input = input / i ;
                if(input > 1)
                    printf(" x ");
            }
        }
        if(input > 1)
            printf("%d", input);
        printf("\n");
    }
    return 0 ;
}

