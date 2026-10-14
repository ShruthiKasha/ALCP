#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

void firstMin(vector<vector<int>> &adj, int i, int n, int &min_val) {
    int min = INT_MAX;
    for (int j = 0; j < n; j++) {
        if (adj[i][j] < min && i != j)
            min = adj[i][j];
    }
    min_val = min;
}

void secondMin(vector<vector<int>> &adj, int i, int n, int &min_val) {
    int first = INT_MAX, second = INT_MAX;
    for (int j = 0; j < n; j++) {
        if (i == j) continue;
        if (adj[i][j] <= first) {
            second = first;
            first = adj[i][j];
        } else if (adj[i][j] < second && adj[i][j] != first) {
            second = adj[i][j];
        }
    }
    min_val = second;
}

void TSPRec(vector<vector<int>> &adj, int curr_bound, int curr_weight, 
            int level, int current_path[], vector<bool> &visited, 
            int &ans, int n) {
    if (level == n) {
        if (adj[current_path[level - 1]][current_path[0]] != 0) {
            int curr_res = curr_weight + adj[current_path[level - 1]][current_path[0]];
            if (curr_res < ans) {
                ans = curr_res;
            }
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (adj[current_path[level - 1]][i] != 0 && !visited[i]) {
            int temp = curr_bound;
            curr_weight += adj[current_path[level - 1]][i];

            if (level == 1)
                curr_bound -= ((firstMin(adj, current_path[level - 1], n, temp) + firstMin(adj, i, n, temp)) / 2);
            else
                curr_bound -= ((secondMin(adj, current_path[level - 1], n, temp) + firstMin(adj, i, n, temp)) / 2);

            if (curr_bound + curr_weight < ans) {
                current_path[level] = i;
                visited[i] = true;
                TSPRec(adj, curr_bound, curr_weight, level + 1, current_path, visited, ans, n);
            }

            curr_weight -= adj[current_path[level - 1]][i];
            curr_bound = temp;
            fill(visited.begin(), visited.end(), false);
            for (int j = 0; j <= level - 1; j++)
                visited[current_path[j]] = true;
        }
    }
}

int main() {
    int n;
    cout << "Enter number of cities: ";
    cin >> n;

    vector<vector<int>> adj(n, vector<int>(n));
    cout << "Enter the cost adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }

    int curr_bound = 0;
    vector<bool> visited(n, false);
    vector<int> current_path(n + 1, -1);

    for (int i = 0; i < n; i++) {
        int min1 = 0, min2 = 0;
        firstMin(adj, i, n, min1);
        secondMin(adj, i, n, min2);
        curr_bound += (min1 + min2);
    }

    curr_bound = (curr_bound & 1) ? (curr_bound / 2) + 1 : curr_bound / 2;

    visited[0] = true;
    current_path[0] = 0;

    int ans = INT_MAX;
    TSPRec(adj, curr_bound, 0, 1, current_path.data(), visited, ans, n);

    cout << "Minimum cost : " << ans << endl;

    return 0;
}
