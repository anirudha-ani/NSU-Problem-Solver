#include <bits/stdc++.h>

using namespace std;

int main()
{
    string input ;

    cin >> input ;

    int length = input.length();

    if(length < 26)
    {
        printf("-1\n");
    }
    else
    {
        int mapper[26];
        bool found = false;
        memset(mapper , 0 , sizeof(mapper));
        int start = 0;
        int ends = 25;
        int notFound = 26;
        int question = 0;

        for(int i = 0 ; i < length ; i++)
        {

            if(input[i] == '?')
            {
                question++;
            }
            else
            {
                if(mapper[input[i]-'A'] == 0)
                {
                    notFound--;
                }
                mapper[input[i]-'A']++;
                //cout << "J= " << input[i]-'A'<<endl;
            }
            if(i>25)
            {
                if(input[start]=='?')
                {
                    question--;
                }
                else
                {
                    mapper[input[start]-'A']--;
                    if(mapper[input[start]-'A']==0)
                    {
                        notFound++;
                    }

                }
                start++;
                ends++;
            }
            if(notFound == question)
            {
                found = true ;
                break;
            }
        }
        if(found)
        {
//            for(int j = 0 ; j < 26 ;j++)
//            {
//                cout << "mapper " << j << " = " << mapper[j] <<endl;
//            }
            for(int i = start ; i<=ends ; i++)
            {
                if(input[i] == '?')
                {
                    for(int j = 0 ; j < 26 ;j++)
                    {
                        if(mapper[j] == 0)
                        {
                            mapper[j] = 1;
                            input[i] = 'A' + j;
                            break;
                        }
                    }
                }
            }
            for(int i = 0 ; i < length ; i++)
            {
                if(input[i] == '?')
                {
                    input[i] = 'A';
                }
            }
            cout << input << endl;
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}
