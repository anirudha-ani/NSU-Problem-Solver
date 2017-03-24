#include <cstdio>
#include <iostream>

using namespace std;

int main()
{

  int ugly[1505];

  int a,b,c;


  ugly[1]=1;

  int x = 1 , y = 1 , z = 1 ;

  for(int i=2;i<=1505;i++)
  {
        a= 2*(ugly[x]);
        b= 3*(ugly[y]);
        c= 5*(ugly[z]);

        if(a<b && a<c)
        {
            ugly[i]=a;
            x++;
        }
        else if(b<a && b<c)
        {
            ugly[i]=b;
            y++;
        }
        else if(c<a && c<b)
        {
            ugly[i]=c;
            z++;
        }

        else if(a==b)
        {
            y++;
            i--;
        }
        else if(a==c)
        {
            z++;
            i--;
        }
        else if(b==c)
        {
            z++;
            i--;
        }
  }

  printf("The 1500'th ugly number is %d.\n",ugly[1500]);
  return 0;
}

