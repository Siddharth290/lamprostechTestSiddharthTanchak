#include<bits/stdc++.h>
using namespace std;

int dp(vector<int>& coins, int target)
{
    vector<int> dp(target+1, INT_MAX);

    // Base case
    dp[0] = 0;

    for(int i = 1; i <= target; i++)
    {
        // Iterate over each coin
        for(int j = 0; j < coins.size(); j++)
        {
            if(i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX)
            {
                // Cal the nbr of coins need to make curr sum
                int ans = dp[i - coins[j]];

                // Update min nbr of coins need for curr sum
                dp[i] = min(dp[i], ans + 1);
            }
        }
    }
    return dp[target];
}

int main(){

    int n;
    cin >> n;

    vector<int> coins;

    for(int i = 0; i < n; i++){
        int sid;
        cin >> sid;
        coins.push_back(sid);
    }
    
    int target;
    cin >> target;

    int ans = dp(coins, target);
    cout << ans << endl;

    return 0;
}
