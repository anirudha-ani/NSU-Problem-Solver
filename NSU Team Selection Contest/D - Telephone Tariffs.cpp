#include <cstdio>
#include <iostream>


using namespace std;


int main()
{
    int N1 , C1 , N2 , T , C2 , N3 , K , mm , ss , total_minutes = 0;

    scanf("%d %d", &N1 , &C1);

    scanf("%d %d %d", &N2 , &T , &C2);
    scanf("%d", &N3);

    scanf("%d", &K);

    for(int i = 0 ; i < K ; i++)
    {
        scanf("%d:%d", &mm , &ss);

        if(mm == 0 && ss <= 6)
            continue;

        if(ss != 0)
        {
            mm = mm+1;
        }
        total_minutes += mm;
    }

    printf("Basic:     %d\n", total_minutes * C1 + N1);
    if(total_minutes>T)
    printf("Combined:  %d\n", N2 + C2 * (total_minutes - T));
    else
         printf("Combined:  %d\n", N2 );
    printf("Unlimited: %d\n", N3 );



    return 0;
}
