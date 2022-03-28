#include <bits/stdc++.h>
using namespace std;

void solve(string &s, int i, int j)
{
    if (s[i] == 'L' && s[j] == 'L')
    {
        // all elements will be L
        for (int k = i + 1; k < j; k++)
        {
            s[k] = 'L';
        }
    }
    else if (s[i] == 'R' && s[j] == 'R')
    {
        // all elements will be R
        for (int k = i; k < j; k++)
        {
            s[k] = 'R';
        }
    }
    else if (s[i] == 'L' && s[j] == 'R')
    {
        // No Effect
    }
    else if (s[i] == 'R' && s[j] == 'L')
    {
        // Two Cases
        int diff = j - i;
        if (diff % 2 == 0)
        { // odd dominos
            int mid = i + j / 2;
            for (int k = i + 1; k < j; i++)
            {
                if (k < mid)
                {
                    s[k] = 'R';
                }
                else
                {
                    s[k] = 'L';
                }
            }
        }
        else
        {
            // even dominos
            int mid = i + j - 1 / 2;
            for (int k = i + 1; k < j; i++)
            {
                if (k <= mid)
                {
                    s[k] = 'R';
                }
                else
                {
                    s[k] = 'L';
                }
            }
        }
    }
}

string pushDominoes(string &dominoes)
{

    string s = 'L' + dominoes + 'R';
    int n = s.size();
    //! Step 1: Method TO Split Array into Segments
    // Sliding Window
    int j = 0;
    int k = 1;
    while (k < n)
    {
        while (k < n && s[k] == '.')
            continue;
        cout<<"Hello";
        if (k - j > 1)
        {
            solve(s, j, k);
        }
        j = k;
        k++;
    }
    return s.substr(1, n - 2);
}

int main()
{
    string s = ".L.R...LR..L..";
    cout << pushDominoes(s);
}

