#include <cstdio>

using namespace std;

int main()
{
    int n , k ;

    scanf("%d %d" , &n , &k);

    int bomb = 0 ;
    int droid = 0 ;

    for(int i = 0 ; i < n ; i++ )
    {
        int input ;

        scanf("%d" , &input);

        if(k < input)
        {
            bomb += input - k;
        }
        else
        {
            droid += k - input ;
        }
    }
    printf("%d %d\n" , bomb , droid );

    return 0;
}
