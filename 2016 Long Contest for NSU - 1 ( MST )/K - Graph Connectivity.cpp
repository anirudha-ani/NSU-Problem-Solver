#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int father[50];
int level[50];

int khoj(int a)
{
    if(father[a] != a)
    {
          father[a] = khoj(father[a]);
    }
    return father[a];
}

void unite(int a , int  b)
{
    int x = khoj(a);
    int y = khoj(b);


        if(level[x]>level[y])
        {
            father[y] = x;
        }
        else if(level[x]==level[y])
        {
            father[x] = y;
            level[y]++;
        }
        else
        {
            father [x] = y;
        }

}


int main()
{
    int input_no;
    string input , fake;


    int largest ;

    scanf("%d\n\n", &input_no);
    for(int i = 0; i < input_no ; i++)
    {
        for(int  i = 0 ; i < 50 ; i++)
        {
            father[i] = i;
            level[i] = 0;
        }


        getline(cin , input);
        int answer  = input[0] - 'A'+1;

        while(getline(cin , input) && input.empty()!= true)
        {
            if(khoj(input[0] - 'A')!= khoj(input[1] - 'A'))
            {
               // cout <<"::::"<< input[0] << "::" << input[1] <<":::"<< endl;
               // cout << ":::"<<khoj(input[0] - 'A') <<":::"<<khoj(input[1] - 'A')<<"::::"<<endl;
                unite(input[0] - 'A' , input[1] - 'A');
               // cout << ":::"<<khoj(input[0] - 'A') <<":::"<<khoj(input[1] - 'A')<<"::::"<<endl;
                answer--;
               // cout <<":::ANS:::"<<answer<<":::"<<endl;
            }

        }

        if(i!= 0) printf("\n");
        printf("%d\n", answer);


    }
    return 0;
}
