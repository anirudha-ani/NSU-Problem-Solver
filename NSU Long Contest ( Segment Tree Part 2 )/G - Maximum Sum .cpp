
#include <bits/stdc++.h>

using namespace std;

#define MAX 100005



int segment_tree_array[4*MAX];
int segment_tree_array_second[4*MAX];
int data[MAX];

void buildSegmentTree(int current_node , int data_start , int data_finish)
{
    //cout << "Data start = " << data_start << " Data finish = " << data_finish  << endl ;
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

        vector<int> four_data ;
        four_data.push_back(segment_tree_array[left_node]);
        four_data.push_back(segment_tree_array[right_node]);
        four_data.push_back(segment_tree_array_second[left_node]);
        four_data.push_back(segment_tree_array_second[right_node]);


        sort(four_data.begin() , four_data.end());


        segment_tree_array[current_node] = four_data[3];;
        segment_tree_array_second[current_node] = four_data[2];
        //cout << "Data start = " << data_start << " Data finish = " << data_finish << " max = " << segment_tree_array[current_node] << " second max = " <<  segment_tree_array_second[current_node] << endl;
    }
}

pair<int , int> query(int current_node , int data_start , int data_finish , int query_start , int query_finish)
{
    if(data_start > query_finish || data_finish < query_start)
    {
        pair <int ,int> x;
        x.first = 0 ;
        x.second = 0;
        return x ;
    }
    else if(data_start >= query_start && data_finish <= query_finish)
    {
        pair <int ,int> x;
        x.first = segment_tree_array[current_node] ;
        x.second = segment_tree_array_second[current_node];
        return x;
    }
    else
    {
        int data_mid = (data_finish + data_start) / 2 ;

        int left_node = current_node * 2 ;
        int right_node = current_node * 2 + 1 ;

        pair<int , int> left_answer , right_answer;
        left_answer = query(left_node , data_start , data_mid , query_start , query_finish);
        right_answer = query(right_node , data_mid + 1 , data_finish , query_start , query_finish);

        vector<int> four_data ;
        four_data.push_back(left_answer.first);
        four_data.push_back(left_answer.second);
        four_data.push_back(right_answer.first);
        four_data.push_back(right_answer.second);


        sort(four_data.begin() , four_data.end());

        pair <int ,int> x;
        x.first = four_data[3];;
        x.second = four_data[2];

        return x ;
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
        segment_tree_array[current_node] = value;
        return ;
    }
    else
    {

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

        vector<int> four_data ;
        four_data.push_back(segment_tree_array[left_node]);
        four_data.push_back(segment_tree_array[right_node]);
        four_data.push_back(segment_tree_array_second[left_node]);
        four_data.push_back(segment_tree_array_second[right_node]);


        sort(four_data.begin() , four_data.end());


        segment_tree_array[current_node] = four_data[3];;
        segment_tree_array_second[current_node] = four_data[2];
    }
}

int main()
{

        memset(data , 0 , sizeof(data));
        memset(segment_tree_array , 0 , sizeof(segment_tree_array));

        int n , q , root = 1 ;

        scanf("%d", &n );

        for(int i = 1 ; i <= n ; i++)
        {
            scanf("%d", &data[i]);
        }

        buildSegmentTree(root , 1 , n);
        //cout << "Here" << endl ;
        scanf("%d", &q);

        for(int i = 0 ; i < q ; i++)
        {
            char query_no[3];

            scanf("%s", query_no);

            switch(query_no[0])
            {
                case 'U':
                    int index , value ;
                    scanf("%d %d",&index , &value);
                    update(root , 1 , n , index , value);
                    data[index] = value ;
                    break;
                case 'Q':
                    int a , b ;
                    pair <int , int > answer ;
                    scanf("%d %d", &a , &b);
                    answer = query(root, 1 , n , a , b);
                    printf("%d\n",answer.first+answer.second);
                    break;
            }
        }

    return 0 ;
}
