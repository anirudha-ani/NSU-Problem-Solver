#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

struct points
{
    double x;
    double y;
}dots[105];

struct distance_mark
{
    int a;
    int b;
    double distance;
}data[10025];

bool ascending_sort(distance_mark x , distance_mark y)
{
    return x.distance < y.distance;
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
    int test_case ,  inputs;
    double x , y ;

    scanf("%d", &test_case);

    for(int i = 0 ; i < test_case ; i++)
    {
        scanf("%d", &inputs);

        for(int j = 0 ; j < inputs ; j++)
        {
            scanf("%lf %lf", &x , &y);
           // cout<<x <<y<<endl;
            dots[j].x = x;
            dots[j].y = y;
        }

        int distance_no = 0;
        for(int j = 0 ; j < inputs ;j++)
        {
            for(int k = j+1 ; k < inputs ;k++)
            {
                data[distance_no].a = j;
                data[distance_no].b = k;
               // cout<< "Here"<<endl;
                data[distance_no].distance= sqrt((dots[j].x - dots[k].x) * (dots[j].x - dots[k].x) + (dots[j].y - dots[k].y) * (dots[j].y - dots[k].y));
               // cout<< "Here1"<<endl;
                distance_no++;
            }
        }

        sort (data , data + distance_no , ascending_sort);

        for(int j = 0 ; j < 105 ;j++)
        {
            fathers[j] = j;
            level[j] = 0;
        }

        double total_cost = 0.0;
        for(int j = 0 ; j < distance_no ;j++)
        {
           if(khoj(data[j].a) != khoj(data[j].b))
           {
               unite(data[j].a , data[j].b);
               total_cost += data[j].distance;
              // cout << data[j].distance << endl;
           }
        }

        printf("%.2lf\n", total_cost);
        if( i != test_case - 1)
        {
            printf("\n");
        }
    }
    return 0;
}
