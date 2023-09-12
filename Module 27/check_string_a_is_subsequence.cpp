#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    // normal O(M)
    int x = 0;
    bool ans = false;
    for (char c : b)
    {
        if (c == a[x])
        {
            x++;
        }
        if (x == a.size())
        {
            ans = true;
            break;
        }
    }
    if (ans)
        cout << "YES";
    else
        cout << "NO";

    // lcs approach O(N*M)
    // int dp[n + 1][m + 1];
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= m; j++)
    //     {
    //         if (i == 0 || j == 0)
    //             dp[i][j] = 0;
    //     }
    // }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         if (a[i - 1] == b[j - 1])
    //         {
    //             dp[i][j] = dp[i - 1][j - 1] + 1;
    //         }
    //         else
    //         {
    //             dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    //         }
    //     }
    // }
    // if (dp[n][m] == a.size())
    //     cout << "YES";
    // else
    //     cout << "NO";
    return 0;
}