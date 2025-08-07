#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> x(n), y(n);
        for(int i = 0; i < n; i++){
            cin >> x[i] >> y[i];
        }
        // Projection arrays: (value, index)
        vector<pair<ll,int>> P(n), Q(n);
        for(int i = 0; i < n; i++){
            P[i] = {x[i] + y[i], i};
            Q[i] = {x[i] - y[i], i};
        }
        sort(P.begin(), P.end());
        sort(Q.begin(), Q.end());

        vector<bool> used(n,false);
        // Four pointers: P front/back, Q front/back
        int pL = 0, pR = n-1, qL = 0, qR = n-1;
        int pairsNeeded = n / 2;

        while(pairsNeeded--){
            // Advance pointers past already used indices
            while(pL <= pR && used[P[pL].second]) pL++;
            while(pL <= pR && used[P[pR].second]) pR--;
            while(qL <= qR && used[Q[qL].second]) qL++;
            while(qL <= qR && used[Q[qR].second]) qR--;

            // Compute candidate gaps
            ll gapP = P[pR].first - P[pL].first;
            ll gapQ = Q[qR].first - Q[qL].first;

            int i1, i2;
            // Choose larger-gap projection
            if(gapP >= gapQ){
                i1 = P[pL].second;
                i2 = P[pR].second;
                pL++; pR--;
            } else {
                i1 = Q[qL].second;
                i2 = Q[qR].second;
                qL++; qR--;
            }
            used[i1] = used[i2] = true;
            // Output 1-based indices
            cout << i1+1 << " " << i2+1 << "\n";
        }
    }
    return 0;
}
