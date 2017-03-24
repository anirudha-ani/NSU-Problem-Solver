#include <cstdio>
#include <cmath>

using namespace std;

int main ()
{
    double big_length , small_length ,info ;

    int type , manholes, answer = 0;

    scanf("%d %lf", &type , &info);

    switch(type)
    {
    case 1:
        big_length = info * 2;
        break;
    case 2:
        big_length = sqrt(2.0 * info * info);
        break;
    case 3:
        big_length = info;
        break;
    }

    scanf("%d", &manholes);

    for(int  i = 0 ; i < manholes ; i++)
    {
        scanf("%d %lf", &type , &info);
        switch(type)
        {
        case 1:
            small_length = info * 2;
            break;
        case 2:
            small_length = info;
            break;
        case 3:
            small_length = sqrt(info * info - (info*info)/4.0);
            break;
        }
        if(small_length <= big_length)
        {
            answer++;
        }
    }
    printf("%d\n",answer);
    return 0;
}
