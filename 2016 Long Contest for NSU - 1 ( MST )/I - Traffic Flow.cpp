#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

struct connection
{
    int point1;
    int point2;
    int capacity;
}data[10005];

bool desceneding_sort(connection x , connection y)
{
    return x.capacity > y.capacity;
}

int fathers[105];
int level[105];

int khoj(int x)
{
    if(fathers[x] != x)
    {
        fathers[x] = khoj(fathers[x]);
    }
    return fathers[x];
}

void unite(int x , int y)
{
    int a = khoj(x);
    int b = khoj(y);

    if(level[a] < level[b])
    {
        fathers[a] = b;
    }
    else
    {
        fathers[b] = a;
        if(level[a] == level[b])
        {
            level[a]++;
        }
    }
}

int main()
{
    int input_no ,n,m , u ,v ,c , countable_data;

    scanf("%d", &input_no);

    for(int i = 0 ; i < input_no ; i++)
    {
        countable_data = 0;
        scanf("%d %d", &n , &m);

        for(int j = 0 ; j < m ; j++)
        {
            scanf("%d %d %d", &u , &v , &c);

            if(u != v)
            {
                data[countable_data].point1 = u;
                data[countable_data].point2 = v;
                data[countable_data].capacity = c;
                countable_data++;
            }
        }


        sort(data , data + countable_data , desceneding_sort);

        for(int i = 0 ; i < 105 ;i++)
        {
            fathers[i] = i;
            level[i] = 0;
        }

        int answer = 0;
        int minimum = 99999;
        for(int k = 0 ; k < countable_data ; k++)
        {
            if(khoj(data[k].point1) != khoj(data[k].point2))
            {
                unite(data[k].point1 , data[k].point2);
                if(minimum > data[k].capacity)
                {
                    minimum = data[k].capacity;
                }
            }
        }
        printf("Case #%d: %d\n", i+1 , minimum);
    }

    return 0;
}
