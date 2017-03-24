#include <bits/stdc++.h>


using namespace std;

long long int pow (int x , int y)
{
    long long int result = 1;
    for(long long int i = 0 ; i < y ; i++)
    {
        result = result * x;
    }
    return result;
}


int main()
{

    long long int a , b , case_no = 1;

    scanf("%lld %lld", &a , &b);

    while(a!= 0 || b!= 0)
    {
        if(b==1)
        {
             printf("Case %lld: 1\n", case_no );
        }
        else
        {
            long long int upper_power , lower_power;

        long long int power = 0;
        while(pow(2,power) < a)
        {
            power++;
        }
        power--;

        lower_power = power ;



        while(pow(2,power) < b)
        {
            power++;
        }
        upper_power = power ;

        long long int total_one = pow(2,(power-1)) * power ;


        long long int lower_difference = a ;

        if(lower_difference > 0 && a > 1)
        {
            for(long long int i = 1 ; i <= lower_power + 1 ; i++)
            {
                long long int power =  pow(2 , i);
                long long int divide = lower_difference / power ;
                total_one -= divide* power / 2;
                long long int remainder = lower_difference % power ;
                if (remainder> power / 2)
                {
                    total_one -= (remainder - power/2);
                }

            }
        }

        long long int less_than = pow(2 , upper_power);


        long long int upper_difference = less_than - b -1;

        if(upper_difference > 0 && less_than !=b)
        {
            for(long long int i = 1 ; i <= upper_power ; i++)
            {
                long long int power =  pow(2 , i);
                long long int divide = upper_difference / power ;
                total_one -= divide* power / 2;
                long long int remainder = upper_difference % power ;
                if (remainder> power / 2)
                {
                    total_one -=  power/2;
                }
                else
                {
                    total_one -= remainder ;
                }
            }
        }
        else if(less_than == b)
        {
            total_one++;
        }

        printf("Case %lld: %lld\n", case_no , total_one);
        }

        case_no++;

        scanf("%lld %lld", &a , &b);
    }
    return 0;
}
