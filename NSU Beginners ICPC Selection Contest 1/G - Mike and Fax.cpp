#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input;
    int number;

    cin >> input ;
    cin >> number ;

    int length = input.length();
    int start = 0 ;
    int finish = length / number - 1;
    for(int x = length/number ; x <= length ; x+x)
    {
        bool flag = true;
        while (start <finish)
        {
            if(start != finish)
            {
                flag = false;
            }
            start ++ ;
            finish -- ;
        }
        if(flag == true)
        {
            number -- ;
        }
    }
}
