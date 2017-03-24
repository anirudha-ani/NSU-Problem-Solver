#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main()
{
    string input;

    cin >> input ;



    int length = input.length();

    if(length == 0)
    {
        cout << "a" <<endl;
        return 0 ;

    }

    int start = 0 ;
    int finish = length - 1;
    bool flag = true;
    while(start<finish)
    {
        if(input[start] != input[finish])
        {
            flag = false ;
            break;
        }
        start ++ ;
        finish --;
    }
    if(flag)
        cout << input << endl;
    else
    {
        int middle = ((length-1) / 2) +1;
        bool found = false;

        while(!found)
        {
            finish = (length - 1);
            start = middle - (length - 1 - middle);
            flag = true ;
            while(start<finish)
            {
                if(input[start] != input[finish])
                {
                    flag = false ;
                    break;
                }
                start ++ ;
                finish --;
            }
            if(flag)
            {
                found = true;
                break;
            }
            middle ++ ;
        }
        int position = 0 ;
        while(position <=middle)
        {
            cout << input[position];
            position++;
        }
        position = position - 2;
        while(position > -1)
        {
            cout <<  input[position];
            position--;
        }

        cout << endl;
    }





    return 0;
}
