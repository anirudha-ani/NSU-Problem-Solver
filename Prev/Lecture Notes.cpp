#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n , k , l;

    string input ;

    cin >> n >> k ;

    cin >> input ;

    bool can = false;

    for(int i = 0 ; i< k ; i++)
    {
        cin >> l;

        if(input[l-1] == '0')
        {
            can = true;
        }
    }
    if(can)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
