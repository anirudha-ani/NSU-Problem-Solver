#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input;

    cin >> input ;

    int size = input.length();
    printf("%d\n" , (size+1) * 26 - size);

    return 0;
}
