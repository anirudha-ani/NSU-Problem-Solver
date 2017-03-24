#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct pairs
{
    int a;
    int b;
    int c;
};

bool ascending_sort(pairs x , pairs y)
{
    return x.c < y.c;
}

int fathers[10000];
int level[10000];

int khoj(int x)
{
    if(fathers[x] !=x)
    {
        fathers[x] = khoj(fathers[x]);
    }
    return fathers[x];
}

void unite(int  x , int y)
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
    int T , N , M , A , B , C;

    scanf("%d", &T);

    for(int i = 0 ; i < T ; i++)
    {
        scanf("%d %d", &N , &M);

        pairs input1[10000];
       // pairs input2[350];
        //int cheap = 350 ;
        //int cheap_index = 0;
        for(int j = 0 ; j < M ; j++)
        {
            scanf("%d %d %d", &A , &B , &C);

            input1[j].a = A;
            input1[j].b = B;
            input1[j].c = C;

//            input2[j].a = A;
//            input2[j].b = B;
//            input2[j].c = C;

//            if(cheap > input2[j].c)
//            {
//                cheap = input2[j].c;
//                cheap_index = j;
//            }
        }

        //input2[cheap_index].c = 350;

        sort(input1 , input1 + M , ascending_sort);
 //       sort(input2 , input2 + M , ascending_sort);

        int cheapest1 = 0;
        int cheapest2 = 999999999;

        for(int k = 0 ; k < 10000 ; k++)
        {
            fathers[k] = k;
            level[k] = 0;
        }

        //int main_mst[105][105][105] = {0};
        //int heavy = 0 , heavy_a , heavy_b;

        //bool [100]
        for(int k = 0 ; k < M ; k++)
        {
            if(khoj(input1[k].a) != khoj(input1[k].b))
            {
                unite(input1[k].a ,input1[k].b);
                //main_mst[input1[k].a][input1[k].b] = input1[k].c;
                cheapest1 += input1[k].c;
            }
        }

        int dropping_node = 0;

        for(int h = 0 ; h < N-1 ; h++)
        {
            int node_count = 0;
            int found_node = 0;
            int cheap  = 0;
             for(int k = 0 ; k < 10000 ; k++)
            {
                fathers[k] = k;
                level[k] = 0;
            }

            for(int k = 0 ; k < M ; k++)
            {
                if(khoj(input1[k].a) != khoj(input1[k].b))
                {
                    if(found_node == dropping_node)
                    {
                        found_node++;
                        continue;
                    }
                    else
                    {
                        unite(input1[k].a ,input1[k].b);
                        //main_mst[input1[k].a][input1[k].b] = input1[k].c;
                        cheap += input1[k].c;
                        node_count++;
                        found_node++;
                    }

                }
            }
            if(node_count == N-1)
            {
                if(cheap < cheapest2)
                    cheapest2 = cheap;
            }
            dropping_node++;
        }


//        for(int k = 0 ; k < 350 ; k++)
//        {
//            fathers[k] = k;
//            level[k] = 0;
//        }
//        for(int )
//        for(int k = 0 ; k < M ; k++)
//        {
//            if((khoj(input2[k].a) != khoj(input2[k].b))&&( ( input2[k].c!=heavy) && (heavy_a != input2[k].a) && (heavy_b = input2[k].b) ))
//            {
//                unite(input2[k].a ,input2[k].b);
//                cheapest2 += input2[k].c;
//            }
//        }

        printf("%d %d\n", cheapest1 , cheapest2);

    }
    return 0;
}
