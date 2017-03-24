#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int no_of_numbers;

    scanf("%d", &no_of_numbers);
    queue<int> output ;

    int current_number = -1;
    int no_of_current_numbers = 0;
    int input;

    for(int i=0 ; i < no_of_numbers ; i++)
    {
        scanf("%d",&input);

        if(i!=0 && input != current_number)
        {
            output.push(no_of_current_numbers);
            output.push(current_number);
            current_number = input;
            no_of_current_numbers = 1;
        }
        else if(input != current_number)
        {
            current_number = input;
            no_of_current_numbers = 1;

        }
        else
        {
            no_of_current_numbers++;
        }
        if(i== no_of_numbers - 1)
            {
                output.push(no_of_current_numbers);
                output.push(current_number);
            }
    }
    while(output.empty() != true)
    {
        printf("%d", output.front());
        output.pop();
        if(output.empty() != true)
            printf(" ");
        else
            printf("\n");
    }
    return 0;
}
