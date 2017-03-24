#include <cstdio>

using namespace std;

int main()
{
    int case_no;
    long long x , y;

    scanf("%d" , &case_no );

    for(int i =0 ; i < case_no ; i++)
    {
        scanf("%lld %lld" , &x ,&y);

        if(x>y)
        printf(">\n");
        else if(x<y)
        printf("<\n");
        else if(x==y)
        printf("=\n");
    }
    return 0;
}
