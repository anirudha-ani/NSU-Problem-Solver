#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

int BIT [100005];

void update(int index , int value)
{
    while(index < 100005)
    {
        BIT[index] += value;
        index += ((index) & (-index));
    }
}

long long int query(int index)
{
    long long int sum  = 0 ;

    while(index > 0)
    {
        sum += BIT[index];
        index -= ((index) & (-index));
    }

    return sum;
}

map <int , int> index;
map <int  , int > reverse_index;

int main()
{
    int N , R , input;

    vector<int> x[100000];

    scanf("%d %d", &N , &R);
    memset(BIT , 0 , sizeof(BIT));
    int count_input = 1 , min_index = 1;

    for(int  i = 0 ; i < N ; i++)
    {
        scanf("%d", &input);

        if(index[input] == 0)
        {
            index[input] = count_input;
            reverse_index[count_input] = input;
            count_input++;
        }

        update(index[input] , 1);
    }



    return 0;
}
