#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <set>
#include <queue>

using namespace std;

// int goodOrBad(vector<int> statementCounts, vector<vector<int>> statements) {
//     int n = statementCounts.size();
//     int m = statements.size();
//     int maxGood = 0;

//     // Try every possible assignment of good/bad (2^n possibilities)
//     for (int mask = 0; mask < (1 << n); mask++) {
//         bool consistent = true;

//         // Check all statements
//         for (int i = 0, idx = 0; i < n && consistent; i++) {
//             for (int j = 0; j < statementCounts[i]; j++, idx++) {
//                 int person = statements[idx][0] - 1;  // 1-based -> 0-based
//                 int claim = statements[idx][1];

//                 if ((mask >> i) & 1) {  
//                     // i is good => statement must be true
//                     if (((mask >> person) & 1) != claim) {
//                         consistent = false;
//                         break;
//                     }
//                 }
//             }
//         }

//         if (consistent) {
//             maxGood = max(maxGood, __builtin_popcount(mask));
//         }
//     }

//     return maxGood;
// }
int goodOrBad(vector<int>& statementCounts, vector<vector<int>>& statements) {
    int n = statementCounts.size();
    int maxGood = 0;
    for (int assumeGood = 0; assumeGood < n; assumeGood++) {
        vector<int> status(n, -1); 
        status[assumeGood] = 1;
        queue<int> q;
        q.push(assumeGood);
        bool valid = true;
        while (!q.empty() && valid) {
            int speaker = q.front();
            q.pop();
            if (status[speaker] != 1) continue; 
            for (int i = 0; i < statementCounts[speaker]; i++) {
                int target = statements[speaker][i * 2] - 1; 
                int claim = statements[speaker][i * 2 + 1];
                
                if (status[target] == -1) {
                    status[target] = claim;
                    if (claim == 1) {
                        q.push(target); 
                    }
                } else if (status[target] != claim) {
                    valid = false;
                    break;
                }
            }
        }
        if (valid) {
            int goodCount = 0;
            for (int i = 0; i < n; i++) {
                if (status[i] == 1) {
                    goodCount++;
                }
            }
            maxGood = max(maxGood, goodCount);
        }
    }
    
    return maxGood;
}
// --------- HackerRank Main Wrapper ----------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
cin >> n;

    vector<int> statementCounts(n);
    for (int i = 0; i < n; i++) cin >> statementCounts[i];

    int m;
    cin >> m;

    vector<vector<int>> statements(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> statements[i][0] >> statements[i][1];
    }

    cout << goodOrBad(statementCounts, statements) << "\n";
    return 0;
}
