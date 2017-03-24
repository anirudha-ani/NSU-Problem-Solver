#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    bool prime [100000001];

    for(int i = 2 ; i < 100000001 ; i++)
        prime[i] = true;
    int i;
    for(i = 2 ; i * i < 100000001 ; i++)
    {
        if(prime[i] == true)
        {
            printf("%d\n" , i);
            for(int j = i*i ; j < 100000001 ; j+=i)
                prime[i] = false;
        }
    }
    while(i<100000001)
    {
        if(prime[i]== true)
            printf("%d\n", i);

        i++;
    }



    return 0;
}
