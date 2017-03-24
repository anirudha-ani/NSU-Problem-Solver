#include <iostream>
#include <cstdio>
#include <iomanip>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    string input ;

    while(getline(cin , input))
    {
        int length = input.size();
        float counter = 0.0;
        float total = 0.0;
        bool flag = true;
        for(int i = 0 ; i < length ; i = i+2)
        {
            //cout << input[i] << endl;
            if(input[i] == 'A')
            {
                total += 4.0;
                counter++;
            }
            else if(input[i] == 'B')
            {
                total += 3.0;
                 counter++;
            }
            else if(input[i] == 'C')
            {
                total += 2.0;
                 counter++;
            }
            else if(input[i] == 'D')
            {
                total += 1.0;
                 counter++;
            }
            else if(input[i] == 'F')
            {
                total += 0.0;
                 counter++;
            }
            else
            {
                flag = false;
                break;
            }
        }
        if(flag == false )
        {
            printf("Unknown letter grade in input\n");
        }
        else
        {
            float ans = 1.0*total / (1.0*counter);
            printf("%.2f\n", ans);

        }
    }
    return 0;
}
