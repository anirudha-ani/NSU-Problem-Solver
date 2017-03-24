#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n ;

    scanf("%d", &n);

    vector <int> data;
    map<int , int> counter ;
    vector <int> answer ;

    int input ;
    for(int i = 0 ; i < n * n ; i++)
    {
        scanf("%d", &input);
        data.push_back(input);
        counter[data[i]]++;
    }
    sort(data.begin() , data.end());

    answer.push_back(data[n*n-1]);
    counter[data[n*n-1]] -= 1;

    for(int i = n*n-1 ; i >= 0 ; i--)
    {
        if(counter[data[i]]>0)
        {
            int length = answer.size();
            for(int j = 0 ; j < length ; j++)
            {
                counter[__gcd(data[i] , answer[j])] -= 2;
            }
            answer.push_back(data[i]);
            counter[data[i]] -= 1;
        }

    }
    bool flag = false ;
    int length = answer.size();
    for(int i = 0 ; i < length ; i++)
    {
            if(flag)
            {
                printf(" ");
            }
            printf("%d" , answer[i]);

            flag = true;

    }
    printf("\n");
    return 0 ;
}
