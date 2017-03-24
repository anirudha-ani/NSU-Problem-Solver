#include <bits/stdc++.h>

using namespace std;

long long binToDec(long long bin)        // long long Binary to decimal
{
    long long dec = 0, rem, num, base = 1;

    num = bin;
    while (num > 0)
    {
        rem = num % 10;
        dec = dec + rem * base;
        base = base * 2;
        num = num / 10;
    }

    return dec;
}
long long bin2dec( char* str)         // String Binary to Decimal
{
 long long n = 0;
 int size = strlen(str) - 1;
        int count = 0;
 while ( *str != '\0' ) {
  if ( *str == '1' )
      n = n + pow(2, size - count );
  count++;
  str++;
 }
 return n;
}

struct data
{
    string name;
    long long bin;
    long long dec;
    int byte;
}var[201];


int main()
{
    int b , v  ;                     //b = bits in byte v = number of  variables
    cin >> b >> v;
    int bas = 10;
    for(int i = 2 ; i <= b ;i++)
        bas = bas * 10;

    for(int i = 0 ; i < v ; i++)
    {
        cin >> var[i].name;
        cin >> var[i].byte ;

    }
    for(int i = 0 ; i < v ; i++)
    {
        var[i].bin = 0;
        string inputstring;
        for(int j = 0 ; j < var[i].byte ; j++)
        {
            string input ;
            cin >> input ;
            inputstring.append(input);
            //var[i].bin = var[i].bin * bas + input ;
        }
        //cout << "::::::" <<inputstring << endl;
        char * writable = new char[inputstring.size() + 1];
        std::copy(inputstring.begin(), inputstring.end(), writable);
         writable[inputstring.size()] = '\0';

        var[i].dec =  bin2dec(writable);
        //var[i].dec = binToDec(var[i].bin);
        //ut << var[i].name << "=" << var[i].dec << "=" << var[i].bin << endl;

    }
    int output;
    cin >> output;

    for(int i = 0 ; i < output ; i++)
    {
        string find;
        cin >> find;
        bool found = false ;
        for(int i = 0 ; i < v ; i++)
        {
            if(find.compare(var[i].name) == 0)
            {
                found = true;
                cout << find << "=" << var[i].dec << endl;
                break;
            }
        }
        if(found == false)
        {
            cout << find << "="<<endl;
        }
    }

    return 0;
}
