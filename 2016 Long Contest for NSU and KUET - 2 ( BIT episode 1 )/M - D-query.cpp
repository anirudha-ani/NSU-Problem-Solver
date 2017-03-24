#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>

using namespace std;

int data[30005];
int BIT[30005];

struct query_type
{
    int index=200005;
    int start;
    int finish=30005;
    int result;
}queries[200005];

bool sort_by_finish(query_type x , query_type y)
{
    return x.finish < y.finish;
}

int query(int index)
{
    int sum = 0 ;

    while(index > 0)
    {
        sum += BIT[index];
        index -= (index)&(-index);
    }
    return sum;
}

void update(int index , int value)
{
    while(index < 30005)
    {
        BIT[index] += value;
        index += (index) & (-index);
    }
}

bool sort_by_index(query_type x , query_type y)
{
    return x.index < y.index;
}

int main()
{
    memset(data , 0 , sizeof(data));
    memset(BIT , 0 , sizeof(BIT));

    int no_of_numbers , no_of_query , start , finish;

    scanf("%d", &no_of_numbers);

    for(int i = 1 ; i <= no_of_numbers ; i++)
    {
        scanf("%d", &data[i]);
    }

    scanf("%d", &no_of_query);

    for(int i = 0 ; i <no_of_query ; i++)
    {
        scanf("%d %d", &start , &finish);

        queries[i].index = i;
        queries[i].start = start;
        queries[i].finish = finish;

    }
    sort(queries , queries + no_of_query , sort_by_finish);
    map <int , int > flag ;

    int query_finish = 0;
    for(int i = 1 ; i <= no_of_numbers ; i++)
    {
        if(flag[data[i]] == 0)
        {
            flag[data[i]] = i;
        }
        else
        {
            update(flag[data[i]] ,  -1);
            flag[data[i]] = i;
        }
        update(i , 1);
        while(i==queries[query_finish].finish)
        {
            queries[query_finish].result = (query(queries[query_finish].finish)) - (query(queries[query_finish].start - 1));
            //cout << (query(queries[query_finish].finish)) << "<><>"<< (query(queries[query_finish].start - 1))<< "<><>"<< queries[query_finish].start << "<><>"<<queries[query_finish].finish<<endl;
            query_finish++;
        }
        if(query_finish == no_of_query) break;
    }
     sort(queries , queries + no_of_query , sort_by_index);
     for(int i = 0 ; i <no_of_query ; i++)
     {
         //cout << queries[i].start << ":::" <<queries[i].finish<<endl;
         printf("%d\n", queries[i].result);
     }

    return 0;
}
