#include <iostream>
#include <algorithm>
using namespace std;

class Item {
public:
    int profit, weight;
    double ratio;
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

int main() {
    int n, M;
    cout << "Enter number of items: ";
    cin >> n;

    Item a[n];

    cout << "Enter profits:\n";
    for (int i = 0; i < n; i++)
        cin >> a[i].profit;

    cout << "Enter weights:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i].weight;
        a[i].ratio = (double)a[i].profit / a[i].weight;
    }

    cout << "Enter maximal weight: ";
    cin >> M;

    sort(a, a + n, compare);

    double maxProfit = 0;

    for (int i = 0; i < n; i++) {
        if (M >= a[i].weight) {
            maxProfit += a[i].profit;
            M -= a[i].weight;
        }
        else {
            maxProfit += a[i].ratio * M;
            break;
        }
    }

    cout << "Maximum profit = " << maxProfit;

    return 0;
}