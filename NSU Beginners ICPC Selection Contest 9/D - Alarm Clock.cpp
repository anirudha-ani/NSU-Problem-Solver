#include <cstdio>

int main()
{
    int H1,H2,M1,M2,hou,min;

    while(scanf("%d %d %d %d",&H1,&M1,&H2,&M2)==4)
    {
        if(H1==0 && M1==0 && H2==0 && M2==0)
        {
            break;
        }
        else
        {
             hou = H2-H1;
             min = M2-M1;

             if(min<0)
             {
                  min = min +60;
                  hou = hou -1;
              }
             if(hou <0)
             {
                 hou = hou +24;
             }
        }

        int time = hou * 60 + min ;
        printf("%d\n",time);
    }
    return 0;
}

