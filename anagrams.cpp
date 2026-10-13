#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> strs(n);
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;

        cout << strs[i] << " ";
        visited[i] = true;

        string s1 = strs[i];
        sort(s1.begin(), s1.end());

        for (int j = i + 1; j < n; j++) {
            if (!visited[j]) {
                string s2 = strs[j];
                sort(s2.begin(), s2.end());

                if (s1 == s2) {
                    cout << strs[j] << " ";
                    visited[j] = true;
                }
            }
        }

        cout << endl;
    }

    return 0;
}