#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int data[100005];
int flag[100005] = {0};

void update (int index , int value)
{
    while(index < 100005)
    {
        data[index] += value;
        index += ((index)& (-index));
    }
}

int query(int index)
{
    int sum = 0 ;

    while(index > 0)
    {
        sum += data[index];
        index -= ((index) & (-index));
    }
    return sum ;
}

int main()
{
    int N , index1 , index2 , answer , query1 , query2;

    scanf("%d", &N);
    memset(data , 0 , sizeof(data));
    for(int i = 0 ; i < N ; i++)
    {
        scanf("%d %d", &index1 , &index2);
        query1 = 0;
        query2 = 0;


        query1 = (query(index1))-flag[index1];
        flag[index1] += query1;



        query2 = (query(index2))- flag[index2];
        flag[index2] += query2;

        answer = (query1 + query2);
        printf("%d\n", answer);
        update(index1 + 1 , 1);
        update(index2 , -1);
    }
    return 0;
}
