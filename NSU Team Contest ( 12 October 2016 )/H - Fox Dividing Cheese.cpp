#include <bits/stdc++.h>

using namespace std;

int calculate(int a , int  b )
{

    queue<int> a_queue;
    queue <int> b_queue ;
    queue <int> step_queue;

    a_queue.push(a);
    b_queue.push(b);
    step_queue.push(0);

    while(a_queue.empty()!= true)
    {
        int a = a_queue.front();
        int b = b_queue.front();
        int current_step = step_queue.front();
        //cout << current_a << " " << current_b <<" " << current_step<< endl;
        //int x ;
        //cin >> x;
        a_queue.pop();
        b_queue.pop();
        step_queue.pop();

        if(a == b)
        {
            return current_step;
        }

        else if(a>b)
        {
            if(a%2 == 0)
            {
                a_queue.push(a/2);
                b_queue.push(b);
                step_queue.push(current_step+1);
            }
            if(a%3 == 0)
            {
                a_queue.push(a/3);
                b_queue.push(b);
                step_queue.push(current_step+1);
            }
             if(a%5 == 0)
            {
                a_queue.push(a/5);
                b_queue.push(b);
                step_queue.push(current_step+1);
            }
        }
        else if(a<b)
        {
            if(b%2 == 0)
            {
                a_queue.push(a);
                b_queue.push(b/2);
                step_queue.push(current_step+1);
            }
            if(b%3 == 0)
            {
                a_queue.push(a);
                b_queue.push(b/3);
                step_queue.push(current_step+1);
            }
             if(b%5 == 0)
            {
                a_queue.push(a);
                b_queue.push(b/5);
                step_queue.push(current_step+1);
            }
        }

    }
    return -1;
}

int main()
{
    int a , b ;
    scanf("%d %d", &a , &b);
    int ans = calculate(a , b);
    printf("%d\n", ans);
    return 0 ;
}
