#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

//int BIT_start[1010];
int BIT_finish[1010];
int MAX;
struct queries
{
   // int index ;
    int start ;
    int finish ;
   // int answer ;
};

//int query_start(int index)
//{
//    int sum = 0;
//
//    while(index > 0)
//    {
//        sum += BIT_start[index];
//        index -= ((index) & (-index));
//    }
//    return sum ;
//}
//
//int update_start(int index , int value)
//{
//    while(index < 1010)
//    {
//        BIT_start[index] += value;
//        index += ((index) & (-index));
//    }
//}

long long int query_finish(int index)
{
    long long int sum = 0;

    while(index > 0)
    {
        sum += BIT_finish[index];
        index -= ((index) & (-index));
    }
    return sum ;
}

void update_finish(int index , int value)
{
    while(index <= MAX)
    {
        BIT_finish[index] += value;
        index += ((index) & (-index));
    }
}


bool sort_by_start (queries x , queries y)
{
    if(x.start == y.start) return x.finish < y.finish;
    return x.start < y.start;
}

int main()
{

    int T , N  , M , K , start , finish ;
    long long int result;

    scanf("%d" , &T);

    for(int  i = 0 ; i < T ; i++)
    {
        memset(BIT_finish , 0 , sizeof(BIT_finish));
        scanf("%d %d %d", &N , &M , &K);
        //int total_node = K;
        result = 0;
        MAX = M ;

            queries query[1000009];

            for(int j = 0 ; j < K ; j++)
            {
                scanf("%d %d", &start , &finish);

               // query[j].index = j;
                query[j].start = start;
                query[j].finish = finish;
                //update_finish(finish, 1);
            }
            sort(query , query + K , sort_by_start);

            for(int j = 0 ; j < K ; j++)
            {
                result += (query_finish(M)-query_finish(query[j].finish));
                update_finish(query[j].finish , 1);
            }
            printf("Test case %d: %lld\n", i+1 , result);


    }
    return 0;
}
