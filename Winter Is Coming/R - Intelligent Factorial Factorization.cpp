#include <cstdio>

using namespace std;

int main()
{
    int T , N;
    int prime[4] = {2 , 3 , 5 , 7};

     scanf("%d" , &T);

     for(int i = 0 ; i < T ; i++)
     {
         int count[101] = {0};
         scanf("%d" , &N);

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

    return 0;
}
