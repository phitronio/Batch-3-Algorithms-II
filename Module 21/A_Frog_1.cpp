#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int cost[n + 1], dp[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
    }
    dp[1] = 0;
    dp[2] = abs(cost[2] - cost[1]);
    for (int i = 3; i <= n; i++)
    {
        // int choice1 = dp[i - 2] + abs(cost[i] - cost[i - 2]);
        // int choice2 = dp[i - 1] + abs(cost[i] - cost[i - 1]);
        dp[i] = min(dp[i - 2] + abs(cost[i] - cost[i - 2]), dp[i - 1] + abs(cost[i] - cost[i - 1])); // dp state
    }
    cout << dp[n] << endl;
    return 0;
}
