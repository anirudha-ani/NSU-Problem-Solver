#include <cstdio>
#include <cmath>

using namespace std;


#define M 100000000
int marked[M/64 + 2];

#define on(x) (marked[x/64] & (1<<((x%64)/2)))
#define mark(x)  marked[x/64] |= (1<<((x%64)/2))

void sieve(int n)
{
  for (int i = 3; i * i < n; i += 2)
    {
    if (!on(i))
    {
      for (int j = i * i; j <= n; j += i + i)
      {
        mark(j);
      }
    }
  }
}

bool isPrime(int num)
{
  return num > 1 && (num == 2 || ((num & 1) && !on(num)));
}

int main()
{
    int T;

    scanf("%d" ,&T);

    for(int i = 0 ; i < T ; i++)
    {
        int n;

        scanf("%d", &n);
        int range = 0;

        range = (n/2) + 1;

        int count = 0;

        for(int i = range ; i <= n ; i++)
        {
            if(isPrime(i))
            {
                count++;
            }
        }
        printf("%d\n" , count);
    }
    return 0 ;
}
