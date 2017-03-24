#include<cstdio>

using namespace std;

int main()
{
    long long n,x,x1,y1,y;
    while(scanf("%lld",&n)==1)
    {
    if(n==0)
    return 0;

    scanf("%lld %lld",&x,&y);

    for(long long i=0;i<n;i++)
      {
          scanf("%lld %lld",&x1,&y1);

          if(x==x1||y==y1)
          printf("divisa\n");

          else if(x1>x && y1>y)
          printf("NE\n");

          else if(x1<x && y1>y)
          printf("NO\n");

          else if(x1<x && y1<y)
          printf("SO\n");

          else if(x1>x && y1<y)
          printf("SE\n");
      }
    }
    return 0;
}
