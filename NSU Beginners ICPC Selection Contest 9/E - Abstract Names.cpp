#include<cstdio>
#include<cstring>
#include <iostream>
#include <string>

using namespace std;

int main()
{
string name1 , name2;
int T;

cin >> T;

 for(int i=0; i<T; i++)
 {
  cin >> name1;
  cin >> name2;

  int l1 = name1.length();
  int l2 = name2.length();
  if(l1 != l2)
   {
       printf("No\n");
       continue;
    }
  else
  {
      for(int j = 0 ; j < l1 ; j++)
      {
          if(name1[j] != name2[j])
          {
              if(name1[j] == 'a' || name1[j] == 'e' ||name1[j] == 'i' ||name1[j] == 'o' ||name1[j] == 'u')
              {
                  if(name2[j] == 'a' || name2[j] == 'e' ||name2[j] == 'i' ||name2[j] == 'o' ||name2[j] == 'u')
                  {

                  }
                  else
                  {
                      printf("No\n");
                      break;
                  }
              }
              else
              {
                  printf("No\n");
                  break;
              }
          }
          if(j == l1 - 1)
          {
              printf("Yes\n");
              break;
          }
      }
  }



  }
 return 0;
}
