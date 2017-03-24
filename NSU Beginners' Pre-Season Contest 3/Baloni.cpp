#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;


int main()
{
    int N;

    scanf("%d", &N);



    vector <int> input;;
    for(int i = 0 ; i < N; i++)
    {
        int input_x;
        scanf("%d", &input_x);
        input.push_back(input_x);
    }
    int total_arrow = 0;

    for(int i = 0 ; i < N ; i++)
    {
        if(input[i] == -5)
            continue;

        total_arrow ++;
        int reference = input[i];
        input[i] = -5;

        for(int j = i ; j < N ;j++)
        {
            if(input[j]+1 == reference)
            {
                reference = input[j];
                input[j] = -5;
            }
        }
    }

    printf("%d\n",total_arrow );

    return 0;
}
