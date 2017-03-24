#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int fathers[30005];
int level[30005];



int khoj(int a)
{
    if(fathers[a] != a)
    {
          fathers[a] = khoj(fathers[a]);
    }
    return fathers[a];
}

void unite(int a , int  b)
{
    int x = khoj(a);
    int y = khoj(b);


        if(level[x]>level[y])
        {
            fathers[y] = x;
        }
        else if(level[x]==level[y])
        {
            fathers[x] = y;
            level[y]++;
        }
        else
        {
            fathers [x] = y;
        }

}


int main()
{
    int test_case , i , j ,k , citizens , pairs , a, b;

    scanf("%d", &test_case);

    for(i = 0 ; i < test_case ; i++)
    {
        scanf("%d %d", &citizens, &pairs);
        if(pairs == 0)
        {
            printf("0\n");
            continue;
        }
        for(k = 0 ; k < 30005 ; k++)
        {
            fathers[k] = k;
        }
//        for(int j = 0 ; j <= citizens ; j++)
//        {
//            cout << j<<":::" << fathers[j] <<endl;
//        }
        memset(level , 0 , sizeof(level));

        for(j = 0 ; j < pairs ; j++)
        {
            scanf("%d %d", &a , &b);

            if(khoj(a)!=khoj(b))
            {
                // cout <<"::::"<< a << "::" << b<<":::"<< endl;
               // cout << ":::"<<khoj(a) <<":::"<<khoj(b)<<"::::"<<endl;
                //cout<<
                unite(a,b);
                //cout << ":::"<<khoj(a) <<":::"<<khoj(b)<<"::::"<<endl;
            }
        }
        for(int j = 0 ; j <= citizens ; j++)
        {
            khoj(j);
        }
        sort(fathers ,  fathers+citizens+1);

        int answer = 0;
        int start = fathers[0];
        int count = 1;

        for(j = 1 ; j < citizens+2 ; j++)
        {
            if(start != fathers[j])
            {
                answer = count>answer?count:answer;
                count = 1;
                start = fathers[j];
                continue;
            }
            count++;
        }

        printf("%d\n", answer);
    }
    return 0;
}
