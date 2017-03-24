#include <bits/stdc++.h>

using namespace std;

#define MAX 200005

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

        segment_tree_array[current_node] = segment_tree_array[left_node] + segment_tree_array[right_node];
    }
}

int query(int current_node , int data_start , int data_finish , int query_start , int query_finish)
{
    if(data_start > query_finish || data_finish < query_start)
    {
        return 0 ;
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

        return left_answer + right_answer ;
    }
}

void update(int current_node , int data_start , int data_finish , int index , int value)
{
    if(index <data_start || index > data_finish)
    {
        return ;
    }
    else if(index == data_finish && data_finish == data_start)
    {
        segment_tree_array[current_node] += value;
        return ;
    }
    else
    {
        segment_tree_array[current_node] += value;

        int data_mid = (data_finish + data_start) / 2 ;

        int left_node = current_node * 2 ;
        int right_node = current_node * 2 + 1;

        if(index <= data_mid)
        {
            update(left_node , data_start , data_mid , index , value);
        }
        else
        {
            update(right_node , data_mid + 1 , data_finish , index , value);
        }
    }
}

int main()
{

    int N , x , r , y;
    int case_no = 1 ;
    string action ;
    while(scanf("%d", &N) == 1 && N != 0)
    {
        for(int i = 1 ; i <= N ; i++)
        {
            scanf("%d", &data[i]);
        }
        buildSegmentTree(1 , 1 , N);
        if(case_no != 1)
        {
            printf("\n");
        }
        printf("Case %d:\n", case_no);
        while(cin >> action && action != "END")
        {
            if(action == "S")
            {
                scanf("%d %d", &x , &r);
                int change  = r - data[x];
                data[x] = r ;
                update(1 , 1 , N , x , change);
            }
            else if(action == "M")
            {
                scanf("%d %d", &x , &y);
                printf("%d\n",query(1, 1 , N , x , y));
            }
        }
        case_no++ ;
    }

    return 0 ;
}

