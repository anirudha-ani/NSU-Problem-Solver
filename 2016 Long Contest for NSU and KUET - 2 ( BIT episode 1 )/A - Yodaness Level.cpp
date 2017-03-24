#include <cstdio>
#include <iostream>
#include <map>
#include <cstring>
#include <string>

using namespace std;

int data[30005];
int bit[30005];

void update(int index , int data)
{
    while(index < 30005)
    {
        bit[index] += data;
        index += ((index)&(-index));
    }
}

int query(int index)
{
    int sum = 0 ;

    while(index > 0)
    {
        sum += bit[index];
        index -= ((index) & (-index));
    }
    return sum;
}

int main()
{
    int test_case , word_number , answer;
    string word;

    cin >> test_case;

    for(int i = 0 ; i < test_case ; i++)
    {
        answer = 0;
        memset(data , 0 , sizeof(data));
        memset(bit , 0 , sizeof(bit));
        cin >> word_number;
        map<string,int> indexing ;

        //cout << "Here1"<<endl;
        for(int j = 1 ; j <= word_number ; j++)
        {
            cin>> word;

            indexing[word] = j;
        }
        //cout << "Here2"<<endl;
         for(int j = 1 ; j <= word_number ; j++)
         {
             cin >> word;
             data[j] = indexing[word];
         }
         //cout << "Here3"<<endl;
         for(int j = 1 ; j <= word_number ; j++)
         {
             answer += j-(query(data[j]-1))-1;
             update(data[j] , 1);
         }
         //cout << "Here4"<<endl;
         printf("%d\n", answer);
    }
    return 0;
}
