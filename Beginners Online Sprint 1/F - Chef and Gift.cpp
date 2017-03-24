#include<cstdio>
#include <iostream>

using namespace std;

int main(){
    int T,n,k;

    int input;
    int count = 0;
    int i;

    scanf("%d",&T);

    while(T > 0)
    {
        count = 0;

        scanf("%d",&n);
        scanf("%d",&k);

           for(i=0;i<n;i++)
            {
                scanf("%d",&input);
                if(input%2 == 0)
                {
                    count++;
                }
            }


        if(((k>0) && (count >= k)) || ((k==0) && (count != n)))
            {
                printf("YES\n");
            }
        else
            {
                printf("NO\n");
            }
        T--;
    }
    return 0;
}
