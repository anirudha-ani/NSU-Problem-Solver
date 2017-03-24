#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N ;
    scanf("%d", &N);

    map<int , int> marker1 , marker2 , marker3 ;
    vector<int> l1 ;
    vector <int> l2;
    vector <int> l3;
    int found2 ,found1;
    int input ;
    for(int i = 0 ; i < N ; i++)
    {
        scanf("%d", &input);
        l1.push_back(input);
        marker1[input]++;
    }
    for(int i = 0 ; i < N-1 ; i++)
    {
        scanf("%d", &input);
        l2.push_back(input);
        marker2[input]++;
    }
    for(int i = 0 ; i < N ; i++)
    {
        if(marker1[l1[i]] != marker2[l1[i]])
        {
            found1 = l1[i];
        }
    }
    for(int i = 0 ; i < N-2 ; i++)
    {
        scanf("%d", &input);
        marker3[input]++;
    }
    for(int i = 0 ; i < N-1 ; i++)
    {
        if(marker2[l2[i]] != marker3[l2[i]])
        {
            found2 = l2[i];
        }
    }


    printf("%d\n",found1 );
    printf("%d\n",found2);
    return 0;
}
