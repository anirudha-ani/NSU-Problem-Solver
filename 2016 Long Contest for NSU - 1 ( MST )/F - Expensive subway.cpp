#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

struct connection
{
    int city1;
    int city2;
    int fare;
}data[79899];

bool ascending_sort(connection x , connection y)
{
    return x.fare < y.fare;
}

int fathers[405];
int level[405];

int khoj(int x)
{
    if(fathers[x] != x)
    {
        fathers[x] = khoj(fathers[x]);
    }
    return fathers[x];
}

void unite(int x , int y)
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
    int s , c;

    scanf("%d %d", &s , &c);

    while(s != 0 || c !=0)
    {
        if(c==0 && s !=1)
        {
            string y;
            for(int x= 0 ; x < s ;x++)
                cin >> y;
            cin>>y;
            printf("Impossible\n");
            scanf("%d %d", &s , &c);
            continue;
        }
        else if(c==0 && s==1)
        {
            string y;
            for(int x= 0 ; x < s ;x++)
                cin >> y;
            cin>>y;
            printf("0\n");
            scanf("%d %d", &s , &c);
            continue;
        }

        string city_name;
        string home;
        map<string , int> city_index;

        for(int i = 0 ; i < s ; i++)
        {
            cin >> city_name;
            city_index[city_name] = i;
        }

        string city1 , city2 ;
        int fare;

        for(int i = 0 ; i < c ; i++)
        {
            cin >> city1 >> city2 >> fare;

            data[i].city1 = city_index[city1];
            data[i].city2 = city_index[city2];
            data[i].fare = fare;

        }

        cin >> home;

        sort(data , data+c , ascending_sort);

        int total_fare = 0;
        int connection = 0;
        for(int i = 0 ; i < 405 ; i++)
        {
            fathers[i] = i;
            level[i] = 0;
        }

        for(int i = 0 ; i < c ;i++)
        {
            if(khoj(data[i].city1) != khoj(data[i].city2))
            {
                //cout << "CITY1::" << data[i].city1 << " CITY2::" << data[i].city2 << endl;
                unite(data[i].city1 , data[i].city2);
                total_fare += data[i].fare;
                connection++;
            }
        }



        if(connection == s-1)
        {
            printf("%d\n", total_fare);
        }
        else
        {
            printf("Impossible\n");
        }


        scanf("%d %d", &s , &c);
    }
    return 0;
}
