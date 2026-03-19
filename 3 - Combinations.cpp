#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, target;
    cout << "Enter number of candidates: ";
    cin >> n;

    vector<int> candidates(n);
    cout << "Enter the candidates: ";
    for (int i = 0; i < n; i++) {
        cin >> candidates[i];
    }
    
    cout << "Enter the target: ";
    cin >> target;

    sort(candidates.begin(), candidates.end());
    candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());

    vector<vector<vector<int>>> dp(target + 1);
    dp[0].push_back({});

    for (int num : candidates) {
        for (int t = num; t <= target; t++) {
            for (auto comb : dp[t - num]) {
                comb.push_back(num);
                dp[t].push_back(comb);
            }
        }
    }

    if (dp[target].empty()) {
        cout << "No combination found." << endl;
    } else {
        sort(dp[target].begin(), dp[target].end());
        cout << "Combinations are: " << endl;
        for (auto &comb : dp[target]) {
            cout << "{ ";
            for (int x : comb) cout << x << " ";
            cout << "}" << endl;
        }
    }

    return 0;
}
