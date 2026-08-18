#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find minimum number of coins
// and display the actual coins used
void coinChange(vector<int> coins, int amount)
{
    // dp[i] stores the minimum number of coins
    // required to make amount i
    vector<int> dp(amount + 1, amount + 1);

    // coinUsed[i] stores the coin used to
    // get the minimum solution for amount i
    vector<int> coinUsed(amount + 1, -1);

    // Base case
    dp[0] = 0;

    // Calculate minimum coins for every amount
    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < coins.size(); j++)
        {
            if (coins[j] <= i)
            {
                if (dp[i - coins[j]] + 1 < dp[i])
                {
                    dp[i] = dp[i - coins[j]] + 1;

                    // Store which coin gave the best result
                    coinUsed[i] = coins[j];
                }
            }
        }
    }

    // If amount cannot be formed
    if (dp[amount] > amount)
    {
        cout << "Change cannot be made." << endl;
        return;
    }

    cout << "Minimum number of coins: "
         << dp[amount] << endl;

    // Find actual coins used
    cout << "Coins used: ";

    int currentAmount = amount;

    while (currentAmount > 0)
    {
        int coin = coinUsed[currentAmount];

        cout << coin << " ";

        currentAmount = currentAmount - coin;
    }

    cout << endl;
}

int main()
{
    int n;
    int amount;

    cout << "Enter number of coins: ";
    cin >> n;

    vector<int> coins(n);

    cout << "Enter coin values: ";

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    cout << "Enter amount: ";
    cin >> amount;

    coinChange(coins, amount);

    return 0;
}
