#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void get_next(string T, int next[])
{
    int i = 1, j = 0;
    next[1] = 0;
    while (i <= T.length())
    {
        if (j == 0 || T[i-1] == T[j-1])
        {
            ++i, ++j;
            next[i] = j;
        }
        else
            j = next[j];
    }
}
int Index_KMP(string S, string T, int next[])
{
    int i = 1, j = 1;
    while (i <= S.length() && j < T.length())
    {
        if (j == 0 || S[i-1] == T[j-1])
        {
            ++i, ++j;
        }
        else
            j = next[j];
    }
    if (j >= T.length())
        return i - T.length();
    else
        return 0;
}

int main()
{
    string s = "asbfabaabcababiwoff";
    string t = "abaabcaba";
    int n =t.length();
    int *next = new int[t.length()+1];
    get_next(t,next);
    for(int i=1;i<=n;i++)cout<<next[i]<<endl;
    cout<<Index_KMP(s,t,next);

    getchar();
    getchar();
    return 0;
}