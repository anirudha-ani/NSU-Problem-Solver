#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void update(vector<int> *data ,  int index ,int value)
{
    while(index < data->size())
    {
        data->at(index) += value;
        index += ((index) & (-index));
    }
}

int query(vector <int> *data , int index)
{
    int sum  = 0;
    while(index > 0)
    {
        sum += data->at(index);
        index -= ((index) & (-index));
    }
    return sum;
}

int main()
{
    int T,input_no , input_taking  , max_size;
    long long int answer;

    scanf("%d", &T);

    for(int i = 0 ; i < T ; i++)
    {
        scanf("%d", &input_no);
        max_size = 0;
        answer = 0;
        vector<int> inputs;
        for(int  j = 0 ; j < input_no ; j++)
        {
            scanf("%d" , &input_taking);
            max_size = max(input_taking , max_size);
            inputs.push_back(input_taking);
        }
        //cout << "Here" << endl;
        vector <int> data(max_size+4 , 0);
        //cout << "Here" << endl;
        for(int j = 0 ; j < input_no ; j++)
        {


                //cout << "Query = " << query_ans << " J = "<<j <<"Inputs = " << inputs[j-1]<<endl;
            answer += (j- query(&data , inputs[j]-1));


            //cout << "Answer = " << answer << endl;
            update(&data , inputs[j] , 1);
        }
        printf("%lld\n", answer);
    }
    return 0;
}
