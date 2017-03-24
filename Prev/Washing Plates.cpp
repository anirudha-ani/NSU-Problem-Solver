#include <bits/stdc++.h>

using namespace std;


struct data
{
    int prof ;
    int loss;
};

bool compare(data a , data b)
{
    if(a.prof == b.prof)
    {
        return a.loss > b.loss;
    }
    else return a.prof > b.prof;
}
int main()
{
    ios::sync_with_stdio(false);

    data Data[200005];
    int n , k;
    cin >> n >> k ;



    for(int i = 0 ; i < n ; i++)
    {
        cin >>Data[i].prof >> Data[i].loss;
    }
    sort(Data , Data + n , compare);
    int ind1 , ind2;
    ind1 = 0 ;
    ind2 = n-1;
    int ans = 0 ;
    int taken=0;
    for(int i = 0 ; i < n-k ; i++)
    {
        if(Data[ind1].prof - Data[ind2].loss >= Data[ind2].prof - Data[ind1].loss)
        {
            ans += Data[ind1].prof;
            ind1++;
            taken++;
        }
        else
        {
            ans += Data[ind2].prof;
            ind2--;
            taken++;
        }
    }
    while(taken < k)
    {
        ans+= Data[ind1].prof;
        ind1++;
        taken++;
    }
    while(ind1 <= ind2)
    {
        ans-=Data[ind1].loss;
        ind1++;
    }
    if(ans <0)
        cout << 0 << endl;
    else
        cout << ans <<endl;
    return 0;
}
