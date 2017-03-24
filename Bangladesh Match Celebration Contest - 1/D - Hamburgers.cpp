#include <bits/stdc++.h>

using namespace std;
int B =0 , S =0 , C =0 ;
int nb , ns , nc ;
int pb , ps , pc ;
long long int low = 0 , high = 10000000000000 , mid;
long long int money ;

long long ans = 0 ;

int bSearch(long long int result)
{
    long long int B_needed , S_needed , C_needed;

    B_needed = result * B;
    S_needed = result * S ;
    C_needed = result * C ;

    long long int B_buy , S_buy , C_buy ;

    B_buy = B_needed - nb >0 ? B_needed - nb : 0;
    S_buy = S_needed - ns >0 ? S_needed - ns : 0;
    C_buy = C_needed - nc >0 ? C_needed - nc : 0;

    if(B_buy * pb + S_buy * ps + C_buy *pc <= money)
    {
        return 1 ;
    }
    else return 0 ;

}

int main()
{
    string input ;

    getline(cin ,input);

    int length = input.length();

    for(int i = 0 ; i < length ; i++)
    {
        if(input[i] == 'B')
        {
            B++;
        }
        else if(input[i] == 'S')
        {
            S++;
        }
        else
        {
            C++;
        }
    }


    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> money ;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(bSearch(mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << ans << endl ;
    return 0;
}
