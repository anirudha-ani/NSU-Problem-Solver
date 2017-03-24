#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    int students[2005];
    int ratingStudents[2005];
    for(int i  = 0 ; i < 2005 ; i++)
    {
        ratingStudents[i] = 0;
    }
    int numberOfStudents;

    scanf("%d" , &numberOfStudents);

    for(int i = 0 ; i < numberOfStudents ; i ++)
    {
        int x ;

        scanf("%d" , &x);
        students[i] = x;
        ratingStudents[x] = ratingStudents[x] + 1;
    }
    for(int i = 0 ;i < numberOfStudents ; i++)
    {
        int sum = 0 ;

        int x = students[i];

        for (int j = 2004 ; j > x ; j--)
        {
            sum = sum + ratingStudents[j];
        }

        students[i] = sum + 1;
    }
    for(int i = 0 ; i < numberOfStudents ; i ++)
    {
        printf("%d " , students[i]);
    }
    printf("\n");
    return 0 ;
}
