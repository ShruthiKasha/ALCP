#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, M;

    cout << "Enter number of items: ";
    cin >> n;

    int profits[n], weights[n];

    cout << "Enter profits:\n";
    for (int i = 0; i < n; i++)
        cin >> profits[i];

    cout << "Enter weights:\n";
    for (int i = 0; i < n; i++)
        cin >> weights[i];

    cout << "Enter maximal weight: ";
    cin >> M;

    int dp[n + 1][M + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= M; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (weights[i - 1] <= j)
                dp[i][j] = max(profits[i - 1] + dp[i - 1][j - weights[i - 1]],
                               dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << "Maximum profit = " << dp[n][M];

    return 0;
}