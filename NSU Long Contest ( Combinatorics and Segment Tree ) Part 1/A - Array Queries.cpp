#include <bits/stdc++.h>

using namespace std;

#define MAX 100005
#define MAX_INT 2147483647
int segment_tree_array[4*MAX];
int data[MAX];

void buildSegmentTree(int current_node , int data_start , int data_finish)
{
    if(data_start == data_finish)
    {
        segment_tree_array[current_node] = data[data_finish];
    }
    else
    {
        int data_mid = (data_start + data_finish) / 2 ;

        int left_node = current_node * 2 ;
        int right_node = current_node * 2 + 1 ;

        buildSegmentTree(left_node , data_start , data_mid);
        buildSegmentTree(right_node , data_mid + 1 , data_finish);

        segment_tree_array[current_node] = min(segment_tree_array[left_node] , segment_tree_array[right_node]);
    }
}

int query(int current_node , int data_start , int data_finish , int query_start , int query_finish)
{
    if(data_start > query_finish || data_finish < query_start)
    {
        return MAX_INT ;
    }
    else if(data_start >= query_start && data_finish <= query_finish)
    {
        return segment_tree_array[current_node];
    }
    else
    {
        int data_mid = (data_finish + data_start) / 2 ;

        int left_node = current_node * 2 ;
        int right_node = current_node * 2 + 1 ;

        int left_answer = query(left_node , data_start , data_mid , query_start , query_finish);
        int right_answer = query(right_node , data_mid + 1 , data_finish , query_start , query_finish);

        return min(left_answer , right_answer) ;
    }
}

int main()
{
    int T ;

    scanf("%d", &T);

    for(int test_case = 1 ; test_case <= T ; test_case++)
    {
        //memset(data , 0 , sizeof(data));
        //memset(segment_tree_array , 0 , sizeof(segment_tree_array));

        int n , q , root = 1 , z , x ;

        scanf("%d %d", &n , &q);

        for(int i = 1 ; i <= n ; i++)
        {
            scanf("%d", &data[i]);
        }

        buildSegmentTree(root , 1 , n);

        printf("Case %d:\n", test_case);

        for(int i = 0 ; i < q ; i++)
        {

                    scanf("%d %d", &z , &x);

                    printf("%d\n",query(root, 1 , n , z , x));


        }
    }
    return 0 ;
}
