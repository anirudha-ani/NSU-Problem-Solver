#include <iostream>

using namespace std;
double power(double x ,int y)
{
    double result = 1 ;

    for(long long  i = 0 ; i < y ; i++)
    {
        result*=x;
    }
    return result;
}
int main()
{
    double asol , porer_ashol , rate ;
    int year = 0;
    while (cin >> asol >> rate >> porer_ashol )
    {
        year = 0;

        while(1)
        {
            if(porer_ashol <= (asol * power((1.0+rate/100), year)))
            {
                break;
            }
            year++;
        }
        cout << year << endl;
    }
    return 0;
}
