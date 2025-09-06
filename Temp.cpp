#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<long long> A;
    long long x;
    // read all ints
    while (cin >> x) A.push_back(x);
    vector<long long> arr;
    if (A.size() >= 1 && A.size() >= (size_t)(A[0] + 1)) {
        long long n = A[0];
        arr.assign(A.begin()+1, A.begin()+1+n);
    } else {
        arr = A;
    }
    int n = arr.size();
    vector<int> ans(20, 0);
    for (int b = 0; b < 20; ++b) {
        long long mask = 1LL << b;
        int cnt = 0;
        for (long long v : arr) if ((v & mask) == 0) ++cnt;
        ans[b] = cnt;
    }
    for (int i = 0; i < 20; ++i) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';
    return 0;
}
