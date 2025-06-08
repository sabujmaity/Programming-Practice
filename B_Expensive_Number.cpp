#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        int n = s.size();
        string best = "";
        long long bestNum = 1e18;
        long long bestSum = 1;
        int bestRemoved = n;

        string curr = "";
        long long currSum = 0;
        for (int i = 0; i < n; ++i) {
            curr += s[i];
            currSum += s[i] - '0';
            if (curr[0] == '0' || currSum == 0) continue;

            long long currVal = stoll(curr);  // safe up to 18 digits
            // Compare: currVal / currSum vs bestNum / bestSum
            if (currVal * bestSum < bestNum * currSum) {
                bestNum = currVal;
                bestSum = currSum;
                bestRemoved = n - curr.size();
            }
        }

        cout << bestRemoved << '\n';
    }
}
