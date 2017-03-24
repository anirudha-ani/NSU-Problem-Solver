#include <bits/stdc++.h>

using namespace std;

#define MAX 300005

int segment_tree_array[4*MAX];
int data[MAX];
int position_array[300005];
int cumulative_sum_of_position_array[300005];

int query(int current_node , int data_start , int data_finish , int query_start , int query_finish)
{
    if(data_start > query_finish || data_finish < query_start)
    {
        return -999999999 ;
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

        return max(left_answer , right_answer) ;
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
        segment_tree_array[current_node] = max(segment_tree_array[current_node] , value);
        return ;
    }
    else
    {
         segment_tree_array[current_node] = max(segment_tree_array[current_node] , value);

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


struct node
{
    int index ;
    int position ;
    int height ;
    int counter ;
};

vector <node> data_set ;

int bs_upper_bound(int n, int x)
{
    int l = 0;
    int h = n-1; // Not n - 1
    int counter = 0 ;
    int mid ;
    while (counter < 40)
    {

        mid = (l + h) / 2;
        //cout << "L = " << l << " H = " << h <<" mid = " << mid << " data = " << data_set[mid].position << " x = " << x << endl;

        if (data_set[mid].position <= x)
        {
            l = mid;
        }
        else
        {
            h = mid - 1 ;
        }
        counter++;
    }

    while(l+1<=n && data_set[l+1].position <= x)
    {
        l++;
    }
   return l;
}

bool sortByPosition(node a , node b)
{
    return a.position < b.position;
}

bool sortByIndex(node a , node b)
{
    return a.index < b.index;
}

int main()
{
   int n , x , h;
   scanf("%d",&n);

  // vector <int> mapping_vector;
   //vector <int> height_vector ;

   for(int i = 0 ; i < n ; i++)
   {
       scanf("%d %d",&x, &h);

       node input ;
       input.height = h;
       input.position = x ;
       input.index = i+1;
       input.counter = 0;

       data_set.push_back(input);

//       mapping_vector.push_back(x);
//       mapping_vector.push_back(h);
   }

//   sort(mapping_vector.begin() , mapping_vector.end());
//
//   map<int, int> mapping ;
//
//   int total_mapping = mapping_vector.size();
//
//   for(int i = 0 ; i < total_mapping ; i++ )
//   {
//       mapping[mapping_vector[i]] = i+1;
//   }

   memset(segment_tree_array , 0 , sizeof(segment_tree_array));
   memset(data , 0 , sizeof(data));

   sort(data_set.begin() , data_set.end() , sortByPosition);



//   memset(position_array ,0,sizeof(position_array));
//   memset(cumulative_sum_of_position_array , 0 , sizeof(cumulative_sum_of_position_array));
//
//   for(int i = 0 ; i < n ; i++)
//   {
//       position_array[data_set[i].position] = 1;
//   }
//   for(int i = 1 ; i < 300005 ; i++)
//   {
//       cumulative_sum_of_position_array[i] = cumulative_sum_of_position_array[i-1] + position_array[i];
//   }


   for(int i = n-1 ; i >=0  ; i--)
   {

        update(1 , 1 , n , i+1 , i+1);

        int upper_bound_index = bs_upper_bound(n , data_set[i].position + data_set[i].height - 1);
        upper_bound_index++;
        //cout << "Up index = " << upper_bound_index << endl;

        int search_result = query(1,1,n, i+1 ,upper_bound_index);

        //cout << "search_result = " << search_result << endl ;
        //int ans = cumulative_sum_of_position_array[search_result] - cumulative_sum_of_position_array[data_set[i].position - 1];

        update(1 , 1 , n , i+1 , search_result);

        data_set[i].counter = search_result-i ;
   }

   sort(data_set.begin() , data_set.end() , sortByIndex);

   for(int i = 0 ; i < n ; i++)
   {
       printf("%d", data_set[i].counter);
       if(i!= n-1)
       {
           printf(" ");
       }
       else
       {
           printf("\n");
       }
   }
    return 0 ;
}
