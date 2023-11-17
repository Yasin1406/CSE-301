// // Recursive C++ program for
// // coin change problem.
// #include <bits/stdc++.h>
// using namespace std;

// // Returns the count of ways we can
// // sum coins[0...n-1] coins to get sum "sum"
// int count(int coins[], int n, int sum)
// {

// 	// If sum is 0 then there is 1 solution
// 	// (do not include any coin)
// 	if (sum == 0)
// 		return 1;

// 	// If sum is less than 0 then no
// 	// solution exists
// 	if (sum < 0)
// 		return 0;

// 	// If there are no coins and sum
// 	// is greater than 0, then no
// 	// solution exist
// 	if (n <= 0)
// 		return 0;

// 	// count is sum of solutions (i)
// 	// including coins[n-1] (ii) excluding coins[n-1]
// 	return count(coins, n, sum - coins[n - 1])
// 		+ count(coins, n - 1, sum);
// }

// // Driver code
// int main()
// {
// 	int i, j;
// 	int coins[] = { 1, 2, 3 };
// 	int n = sizeof(coins) / sizeof(coins[0]);
// 	int sum = 5;

// 	cout << " " << count(coins, n, sum)<<endl;

// 	return 0;
// }








#include <bits/stdc++.h>

using namespace std;

// Returns total distinct ways to make sum using n coins of
// different denominations
int count(vector<int>& coins, int n, int sum)
{
	// 2d dp array where n is the number of coin
	// denominations and sum is the target sum
	vector<vector<int> > dp(n + 1, vector<int>(sum + 1, 0));

	// Represents the base case where the target sum is 0,
	// and there is only one way to make change: by not
	// selecting any coin
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {

			// Add the number of ways to make change without
			// using the current coin,
			dp[i][j] += dp[i - 1][j];

			if ((j - coins[i - 1]) >= 0) {

				// Add the number of ways to make change
				// using the current coin
				dp[i][j] += dp[i][j - coins[i - 1]];
			}
		}
	}
    for(auto r:dp){
        for(auto c: r){
            cout<<c<<" ";
        }
        cout<<endl;
    }
	return dp[n][sum];
}

// Driver Code
int main()
{
	vector<int> coins{ 1, 2, 3 };
	int n = 3;
	int sum = 5;
	cout << count(coins, n, sum);

	return 0;
}
// Write to nth GC - UI/UX





// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;
#define MAX 100000

// dp array to memoize the results
int dp[MAX + 1];

// List to store the result
list<int> denomination;

// Function to find the minimum number of
// coins to make the sum equals to X
int countMinCoins(int n, int C[], int m)
{
	// Base case
	if (n == 0) {
		dp[0] = 0;
		return 0;
	}

	// If previously computed
	// subproblem occurred
	if (dp[n] != -1)
		return dp[n];

	// Initialize result
	int ret = INT_MAX;

	// Try every coin that has smaller
	// value than n
	for (int i = 0; i < m; i++) {

		if (C[i] <= n) {

			int x
				= countMinCoins(n - C[i],
								C, m);

			// Check for INT_MAX to avoid
			// overflow and see if result
			// can be minimized
			if (x != INT_MAX)
				ret = min(ret, 1 + x);
		}
	}

	// Memoizing value of current state
	dp[n] = ret;
	return ret;
}

// Function to find the possible
// combination of coins to make
// the sum equal to X
void findSolution(int n, int C[], int m)
{
	// Base Case
	if (n == 0) {

		// Print Solutions
		for (auto it : denomination) {
			cout << it << ' ';
		}

		return;
	}

	for (int i = 0; i < m; i++) {

		// Try every coin that has
		// value smaller than n
		if (n - C[i] >= 0
			and dp[n - C[i]] + 1
					== dp[n]) {

			// Add current denominations
			denomination.push_back(C[i]);

			// Backtrack
			findSolution(n - C[i], C, m);
			break;
		}
	}
}

// Function to find the minimum
// combinations of coins for value X
void countMinCoinsUtil(int X, int C[],
					int N)
{

	// Initialize dp with -1
	memset(dp, -1, sizeof(dp));

	// Min coins
	int isPossible
		= countMinCoins(X, C,
						N);

	// If no solution exists
	if (isPossible == INT_MAX) {
		cout << "-1";
	}

	// Backtrack to find the solution
	else {
		findSolution(X, C, N);
	}
}

// Driver code
int main()
{
	int X = 21;

	// Set of possible denominations
	int arr[] = { 2, 3, 4, 5 };

	int N = sizeof(arr) / sizeof(arr[0]);

	// Function Call
	countMinCoinsUtil(X, arr, N);

	return 0;
}