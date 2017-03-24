#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;
int data[100005];
int data_taken[100005];
int query(int index)
{
    int sum = 0;

    while(index > 0)
    {
        sum+= data[index];
        index -= ((index)&(-index));
    }
    return sum;
}
void update(int index , int value)
{
    while(index<100005)
    {
        data[index] += value;
        index += ((index) &(-index));
    }
}

int main()
{
    int T;
    int n , q;
    int command , index1 , index2 , v ;

    scanf("%d", &T);

    for(int i = 0 ; i < T ; i++)
    {
        memset(data , 0 , sizeof(data));
        memset(data , 0 , sizeof(data_taken));
        scanf("%d %d", &n , &q);
        printf("Case %d:\n", i+1);

        for(int j = 1 ; j <= n ; j++)
        {
            scanf("%d", &data_taken[j]);
            update(j , data_taken[j]);
        }

        for(int j = 0 ; j < q ; j++)
        {
            scanf("%d", &command);

            switch(command)
            {
            case 1:
                scanf("%d", &index1);
                update(index1+1 , data_taken[index1+1] * -1);
                printf("%d\n",data_taken[index1+1]);
                data_taken[index1+1] = 0;
                break;
            case 2:
                scanf("%d %d", &index1 , &v);
                update(index1+1 , v);
                data_taken[index1+1] += v;
                break;
            case 3:
                scanf("%d %d", &index1 , &index2);
                printf("%d\n", query(index2+1)-query(index1));
                break;


            }
        }
    }
    return 0;
}
