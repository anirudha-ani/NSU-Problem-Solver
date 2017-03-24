#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
using namespace std;
vector <int> primes;

int sieve()
{

	int a[102];
	memset(a, 0, sizeof(a));

	for (int i = 2; i <= 100; i++) {

		if(a[i] == 0) {
			primes.push_back(i);
			for (int j = 2 * i; j <= 100; j = j + i) {
				a[j] = 1;
			}
		}

	}



}


int main()
{

	int t;
	int n;
	int a[105];
	int ans[105];
	int Cases;

	sieve();

	scanf("%d", &Cases);

	for (int cases = 1; cases <= Cases; cases++) {
		scanf("%d", &n);
		memset(ans, 0, sizeof(ans));
		for (int i = 1; i <= n; i++) {
			a[i] = i;
		}

		for (int j = 0; primes[j] <= n and j < primes.size(); j++) {
			t = primes[j];
			for (int i = t; i <= n; i = i + t) {
				while(a[i] % t == 0) {
					a[i] = a[i] / t;
					ans[t]++;
				}

			}

		}
		printf("Case %d: %d = ", cases, n);
		for (int i = 0; primes[i] <= n and i < primes.size(); i++) {
			printf("%d (%d)",primes[i], ans[primes[i]]);
			if(i != primes.size() - 1 and primes[i+1] <= n) {
				printf(" * ");
			}
		}

		printf("\n");

		int count[101] = {0};
        int N = n;
        int i = cases - 1;
        int prime[4] = {2 , 3 , 5 , 7};

         for(int i = 2 ; i <= N ; i++)
         {
             int input = i;
             for(int i = 0 ; i < 4 ; i++)
            {
                while(input % prime[i] == 0)
                {
                    count[prime[i]]++;
                    input = input / prime[i] ;
                }
            }
            if(input > 1)
                count[input] ++ ;
         }
         int m_count = -1;
         for(int i = 0 ; i < 101 ; i++)
         {
             if(count[i] != 0)
                m_count++;
         }
         printf("Case %d: %d = " , i+1 , N);
         for(int i = 2 ; i < 101 ; i++)
         {
             if(count[i] != 0)
             {
                printf("%d (%d)" ,i ,count[i] );

                if(m_count != 0)
                {
                  printf(" * ");
                  m_count--;
                }
             }
         }
         printf("\n");



	}



}

