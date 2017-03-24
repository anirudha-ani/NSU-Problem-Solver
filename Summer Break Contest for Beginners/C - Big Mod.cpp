//#include <bits/stdc++.h>
//
//
//int bigMod(long long int B , long long int P , long long int M);
//
//int main()
//{
//
//    int B , P , M ;
//
//    scanf("%d" , &B);
//    scanf("%d" , &P);
//    scanf("%d" , &M);
//
//
//    printf("%d\n" , bigMod(B ,P ,M));
//
//    return 0;
//}
//
//int bigMod(long long int B , long long int P , long long int M)
//{
//    if(P == 0)
//    {
//        return 1;
//    }
//
//    else if (P%2 == 0)
//    {
//         return (bigMod(B , P/2 , M) * bigMod (B , P/2 , M))%M;
//    }
//
//
//       return (bigMod(B,P-1,M) * (B%M) ) % M;
//
//}
#include <cstdio>
#include <iostream>

using namespace std;
//long long int bigMod ( long long B, long long P, long long M );
//
//
//int main()
//{
//
//    long long B , P , M;
//
//
//    while(scanf("%lld %lld %lld",&B, &P, &M)==3)
//    {
//         printf("%d\n",bigMod(B,P,M));
//    }
//
//   return 0;
//}
//
//
//
//
//long long int  bigMod ( long long B, long long P, long long M )
//{
//    if ( P == 0 )
//        {
//            return 1;
//        }
//
//    if (P % 2 !=0)
//    {
//        return ( ( B % M ) * ( bigMod ( B, P - 1, M ) ) ) % M;
//    }
//    else
//    {
//        return ( ((bigMod ( B, P / 2, M )) % M) * ((bigMod ( B, P / 2, M )) % M) ) % M;
//    }
//}

int main()
{
    printf("%d" , (1^1)+(1^1));
}
