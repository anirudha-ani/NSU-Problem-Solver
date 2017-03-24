//#include <iostream>
//#include <cstdio>
//#include <cstring>
//#include <string>
//
//using namespace std;
//
//
//int  main()
//{
//    string input;
//    int T;
//    int N;
//
//    cin >> T;
//
//    for(int i = 0 ; i < T ; i++)
//    {
//        cin >> N;
//        cin >> input;
//
//        int count = 0;
//        for(int i = 0 ; i < N ; i++)
//        {
//            if(input[i] == '1')
//                count++;
//        }
//        int ans = count +((count * (count-1))/2);
//
//        cout << ans <<endl;
//    }
//    return 0;
//}
#include<stdio.h>

int main()
{
	long long T, N, count;
	char c;

	scanf("%lld", &T);

	while(T!=0)
    {
		scanf(" %lld ", &N);
		count = 0;
		while(N !=0)
        {
            if((c = getchar()) == '1')
                count += 1;
            N--;
		}
		printf("%lld\n", count + (count * (count - 1)) / 2);
        T--;
	}
	return 0;
}
