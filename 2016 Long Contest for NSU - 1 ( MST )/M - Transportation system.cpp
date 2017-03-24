#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

struct coordinates
{
    double x ;
    double y ;
}points[1005];

struct chalte_chalte
{
    int point1;
    int point2;
    double distance;
}paths[1000025];

bool ascending_sort(chalte_chalte x , chalte_chalte y)
{
    return x.distance < y.distance;
}

int fathers[1005];
int level[1005];

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
            level[a]++;
    }
}

int main()
{
    //ofstream myfile ("output.txt");
    int T , r ,n , states;
    double x , y ,roads , rails;

    scanf("%d", &T);

    for(int i = 0 ; i < T ; i++)
    {
        scanf("%d %d", &n , &r);

        for(int j = 0 ; j < n ;j++)
        {
            scanf("%lf %lf", &x , &y);

            points[j].x = x;
            points[j].y = y;
        }

        int path_no = 0;

        for(int k = 0 ; k < n ;k++)
        {
            for(int l = k+1 ; l<n ;l++)
            {
                paths[path_no].point1 = k;
                paths[path_no].point2 = l;

                paths[path_no].distance =  sqrt(((points[k].x - points[l].x) * (points[k].x - points[l].x)) + ((points[k].y - points[l].y) * (points[k].y - points[l].y)));
                path_no++;
            }
        }

        sort(paths , paths+path_no , ascending_sort);

        states = 1;
        rails = 0;
        roads = 0;

        for(int j = 0 ; j < 1005 ;j++ )
        {
            fathers[j] = j;
            level[j] = 0;
        }
        for(int j = 0 ; j < path_no ;j++)
        {
            if(khoj(paths[j].point1) != khoj(paths[j].point2))
            {
                unite(paths[j].point1 , paths[j].point2);

                if(paths[j].distance<=r)
                {
                    roads += paths[j].distance;
                }
                else
                {
                    states++;
                    rails += paths[j].distance;
                }
            }
        }
        int int_roads = (int)roads;
        int int_rails = (int)rails;

        if(roads - int_roads >=0.5)
        {
            int_roads++;
        }
        if(rails - int_rails >= 0.5)
        {
            int_rails++;
        }
        printf("Case #%d: %d %d %d\n", i+1 , states , int_roads , int_rails);


    }
    return 0;
}
