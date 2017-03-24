#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    double total = 0 , input , ans;

    for(int i = 0 ; i < 12 ; i++)
    {
        scanf("%lf", &input);

        total+= input;
    }
    printf("$%.2f\n",1.0*total/12.0);
    return 0;
}
