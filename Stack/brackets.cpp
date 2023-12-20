#include <bits/stdc++.h>
#include <stack>
using namespace std;

void bracket(char exp[])
{
    int i = 0;

    stack<char> st;

    while (exp[i])
    {
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
            st.push(exp[i]);

        if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']')
        {

            if (st.empty())
                printf("false");

            else
            {

                if (st.top() == '(' && exp[i] == ')')
                {
                    printf("true");
                    st.pop();
                }

                else if (st.top() == '{' && exp[i] == '}')
                {
                    printf("true");
                    st.pop();
                }
                else if (st.top() == '[' && exp[i] == ']')
                {
                    printf("true");
                    st.pop();
                }
                else
                    printf("false");
            }
        }
        i++;
    }

    if (st.empty())
        printf("true");
    else
        printf("false");
}

