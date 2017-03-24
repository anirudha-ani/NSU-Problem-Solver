#include <cstdio>

using namespace std;

int main()
{

    int case_no;

    scanf("%d" , &case_no);

    for (int i = 0 ; i < case_no ; i++)
    {
        int n1, n2 , n3 , x , ans;
        scanf("%d %d %d" , &n1 , &n2 ,&n3);

         if((n1 > n2 && n1 < n3)||(n1 > n3 && n1 < n2))
         ans = n1;

         else if((n2 > n1 && n2 < n3)||(n2 > n3 &&  n2 < n1))
         ans = n2;

         else
         ans = n3;

        printf("Case %d: %d\n" , i+1 , ans);
    }
    return 0;
}
