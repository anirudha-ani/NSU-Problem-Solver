#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;


#define M 100000000
int marked[M/64 + 2];

#define on(x) (marked[x/64] & (1<<((x%64)/2)))
#define mark(x)  marked[x/64] |= (1<<((x%64)/2))

void sieve(int n)
{
  for (int i = 3; i * i < n; i += 2) {
    if (!on(i)) {
      for (int j = i * i; j <= n; j += i + i) {
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
    sieve(15485863);
    int prime_number[5000001];
    prime_number[1] = 2;
    int j = 3;
    for(int i = 2 ; i < 5000001 ; i++)
    {
        if(isPrime(j))
        {
            prime_number[i] = j;

        }
        j += 2;

    }

    int Q, K;

    scanf("%d" , &Q);

    for(int i = 0 ; i < Q ; i++)
    {
        scanf("%d" , &K);
        printf("%d\n",prime_number[K]);
    }
    return 0;
}
