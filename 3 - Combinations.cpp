#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void findCombinations(int target, const vector<int>& candidates, vector<int>& current, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(current);
        return;
    }

    for (int i = 0; i < candidates.size(); i++) {
        if (!current.empty() && candidates[i] < current.back()) continue;
        if (candidates[i] > target) break;
        current.push_back(candidates[i]);
        findCombinations(target - candidates[i], candidates, current, result);
        current.pop_back();
    }
}

int main() {
    int n, target;
    cout << "Enter number of candidates: ";
    cin >> n;
    
    vector<int> candidates(n);
    cout << "Enter the candidates: ";
    for (int i = 0; i < n; i++) {
        cin >> candidates [i];
    }
    
    cout << "Enter the target: ";
    cin >> target;
    
    sort(candidates.begin(), candidates.end());
    vector<int> uniqueCandidates;
    for (int i = 0; i < n; i++) {
        if (i == 0 || candidates[i] != candidates[i - 1])
            uniqueCandidates.push_back(candidates[i]);
    }
    
    vector<int> current;
    vector<vector<int>> result;
    findCombinations(target, uniqueCandidates, current, result);
    
    if (result.empty()) {
        cout << "No combination found." << endl;
    } else {
        cout << "Combinations are: " << endl;
        for (auto &comb : result) {
            cout << "{ ";
            for (int i = 0; i < comb.size(); i++) {
                cout << comb[i] << (i < comb.size() - 1 ? " " : "");
            }
            cout << " }" << endl;
        }
    }
    
    return 0;
}