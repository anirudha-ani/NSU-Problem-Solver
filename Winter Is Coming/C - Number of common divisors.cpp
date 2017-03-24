#include <cstdio>
#include <cmath>

using namespace std;

int gcd(int a, int b)
{
  return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    int T , A ,B;

    scanf("%d" ,&T);
    for(int i = 0 ; i < T ; i++)
    {
        scanf("%d %d" ,&A ,&B);
        int x = gcd(A,B);
        int ans = 0;
        int sqt = (int)sqrt(x);

        for(int i = 1 ; i <= sqt; i++)
        {
              if(x % i == 0)
              {
                  ans += 2 ;
                  if(i == x/i)
                  ans--;
               }
        }
        printf("%d\n",ans);
    }

    return 0;
}
