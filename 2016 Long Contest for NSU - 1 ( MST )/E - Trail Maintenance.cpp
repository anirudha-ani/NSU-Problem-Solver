#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct path_pair
{
    int point1;
    int point2;
    int distance ;
}trails[6005];

bool ascending_sort(path_pair x , path_pair y)
{
   return   x.distance < y.distance;
}

int fathers[202];
int level[202];

int khoj(int x)
{
    if(fathers[x] != x)
    {
        fathers[x] = khoj(fathers[x]);
    }
    return fathers[x];
}

void unite(int x, int y)
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

    int T ,point1 , point2 , distance , total_distance , N ,W;
    int i , j , k , l;
    int node_count;
    scanf("%d", &T);

    for(i = 0 ; i < T ; i++)
    {
        //bool mark[6005 = {false];
        scanf("%d %d", &N , &W);
        printf("Case %d:\n",i+1);
        int path_count = 0;
        for(j = 0 ; j < W ; j++)
        {

            total_distance = 0;
            scanf("%d %d %d", &point1 , &point2 , &distance);

            trails[path_count].point1 = point1;
            trails[path_count].point2 = point2;
            trails[path_count].distance = distance;
            path_count++;
            if(path_count < N-1)
            {
                printf("-1\n");
            }
            else
            {
                sort(trails , trails +path_count , ascending_sort);

                for(k = 0 ; k < 202 ;k++)
                {
                    fathers[k] = k;
                    level[k] = 0;
                }
                node_count = 0;
                int delete_node = -1;
                for(l = 0; l < path_count ;l++)
                {
                    int x  = khoj(trails[l].point1);
                    int y = khoj(trails[l].point2);
                    if(x!= y)
                    {

                        unite(trails[l].point1,trails[l].point2);
                        total_distance += trails[l].distance;
                        node_count++;
//                        if(node_count == N-1)
//                            break;
                    }
                    else
                    {
                       delete_node = l;
                    }
                }
                if(delete_node != -1)
                {
                    trails[delete_node] = trails[path_count-1];
                    path_count--;

                }
                if(node_count != N-1)
                {
                    printf("-1\n");
                }
                else
                {
                    printf("%d\n", total_distance);
                }
            }
        }
    }
    return 0;
}
