#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define nline "\n" 
#define fo(i,n) for(int i = 0;i<n;i++)
#define pb push_back
#define F first
#define S second
typedef long double ld;
typedef vector<signed> vi;
typedef vector<vector<signed>> vvi;
typedef vector<int> vll;
typedef vector<vector<int>> vvll;
const int mod = 1e9+7;

bool check_binary_search_success(int l, int r, int k, const vector<int>& p) {
    int current_l = l;
    int current_r = r;
    int n = p.size() - 1;

    while (current_l <= current_r) {
        if (current_l < 1 || current_r > n || current_l > current_r) return false;
        int m = current_l + (current_r - current_l) / 2;
        if (m < 1 || m > n) return false;

        if (p[m] == k) {
            return true;
        } else if (p[m] < k) {
            current_l = m + 1;
        } else {
            current_r = m - 1;
        }
    }
    return false;
}

vector<int> get_ideal_path(int l, int r, int target_idx, int n) {
    vector<int> path;
    int current_l = l;
    int current_r = r;

    while (current_l <= current_r) {
        if (current_l < 1 || current_r > n || current_l > current_r) break;
        int m = current_l + (current_r - current_l) / 2;
        if (m < 1 || m > n) break;

        path.push_back(m);

        if (m == target_idx) {
            break;
        } else if (m < target_idx) {
            current_l = m + 1;
        } else {
            current_r = m - 1;
        }
    }
    if (path.empty() || path.back() != target_idx) {
        return {};
    }
    return path;
}

bool check(int d, int n, int x,const set<int>& I_must_choose,int N_less,int N_greater,int k_must_less,int k_must_greater)
{
    int k_violate = I_must_choose.size();
    if (d < k_violate) return false;

    int k_extra = d - k_violate;

    int size_pool_less = max(0, (x - 1) - k_must_less);
    int size_pool_greater = max(0, (n - x) - k_must_greater);

    if (k_extra > size_pool_less + size_pool_greater) {
        return false;
    }

    int needed_extra_less = max(0, N_less - k_must_less);
    int needed_extra_greater = max(0, N_greater - k_must_greater);

    int L = max(needed_extra_less, k_extra - size_pool_greater);
    int U = min(size_pool_less, k_extra - needed_extra_greater);

    return L <= U;
}

int main() {
    IOS;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif

    int t;
    cin >> t;
    while (t--) {
        int n;
        int q;
        cin >> n >> q;

        vector<int> p(n + 1);
        vector<int> pos(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> p[i];
            pos[p[i]] = i;
        }

        vector<int> results;
        results.reserve(q);

        for (int k_query = 0; k_query < q; ++k_query) {
            int l, r, x;
            cin >> l >> r >> x;

            int idx_x = pos[x];
            int current_ans = -1;

            if (idx_x >= l && idx_x <= r) {
                if (check_binary_search_success(l, r, x, p)) {
                    current_ans = 0;
                } else {
                    vector<int> ideal_path = get_ideal_path(l, r, idx_x, n);

                    if (!ideal_path.empty()) {
                        set<int> I_path_indices;
                        int N_less = 0;
                        int N_greater = 0;

                        for (size_t i = 0; i < ideal_path.size() - 1; ++i) {
                            int m = ideal_path[i];
                            if (I_path_indices.insert(m).second) {
                                if (m < idx_x) N_less++;
                                else N_greater++;
                            }
                        }

                        set<int> I_must_choose;
                        int k_must_less = 0;
                        int k_must_greater = 0;

                        for(int m : I_path_indices) {
                            bool violates = false;
                            if (m < idx_x && p[m] >= x) violates = true;
                            if (m > idx_x && p[m] <= x) violates = true;

                            if (violates) {
                                I_must_choose.insert(m);
                                if (p[m] < x) k_must_less++;
                                else if (p[m] > x) k_must_greater++;
                            }
                        }

                        int k_violate = I_must_choose.size();
                        int low = k_violate, high = n, found_ans = -1;

                        while(low <= high) {
                            int mid = low + (high - low) / 2;
                            if (check(mid, n, x, I_must_choose, N_less, N_greater, k_must_less, k_must_greater)) {
                                found_ans = mid;
                                high = mid - 1;
                            } else {
                                low = mid + 1;
                            }
                        }
                        current_ans = found_ans;
                    }
                }
            }

            results.push_back(current_ans);
        }

        for (int i = 0; i < results.size(); ++i) {
            cout << results[i] << (i == results.size() - 1 ? "" : " ");
        }
        cout << nline;
    }
    return 0;
}
