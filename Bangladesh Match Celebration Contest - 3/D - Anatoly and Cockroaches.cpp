#include <bits/stdc++.h>

using namespace std;

int bitRep = 0 ;
int main()
{
    int n ;

    scanf("%d", &n);

    string input ;
    getline(cin , input);
    getline(cin , input);

    string config1 ="" , config2 ="" ;
    int oB = 0  , oR = 0 , tB = 0 , tR = 0 ;
    for(int i = 0 ; i < n ; i++)
    {
        if(i%2 == 0)
        {
            if(input[i] != 'b')
            {
                oB++;
            }
            if(input[i] != 'r')
            {
                tR++;
            }
        }
        else
        {
             if(input[i] != 'b')
            {
                tB++;
            }
            if(input[i] != 'r')
            {
                oR++;
            }
        }

    }

    int ans = min(max(oB , oR) , max(tR , tB));

    printf("%d\n", ans);
    return 0;
}
