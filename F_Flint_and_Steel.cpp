#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

// Fast I/O for competitive programming
void fast_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
}

// Solves a single test case
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> e(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> e[i];
    }

    // Step 1: Preprocessing - Group bombs by their left boundary
    std::vector<std::vector<std::pair<int, int>>> bombs_starting_at(n + 2);
    for (int i = 1; i <= n; ++i) {
        if (e[i] > 0) {
            int l = std::max(1, i - e[i]);
            int r = std::min(n, i + e[i]);
            bombs_starting_at[l].push_back({r, i});
        }
    }

    std::vector<int> ans;
    int current_reach = 0;
    int bombs_added_until_l = 0;
    // Max-heap to find the bomb with the farthest reach
    std::priority_queue<std::pair<int, int>> pq; // Stores {reach, index}

    // Step 2: Greedy Simulation
    while (current_reach < n) {
        // a. Add newly available bombs to the priority queue
        int limit = current_reach + 1;
        for (int l = bombs_added_until_l + 1; l <= limit; ++l) {
            if (l > n) break; // Boundary safety check
            for (const auto& bomb : bombs_starting_at[l]) {
                pq.push(bomb);
            }
        }
        bombs_added_until_l = limit;

        // b. Prune dead bombs from the top of the PQ
        // A bomb at index `i` is dead if its position i <= current_reach
        while (!pq.empty() && pq.top().second <= current_reach) {
            pq.pop();
        }

        // c. Check if a valid jump is possible
        if (pq.empty()) {
            std::cout << -1 << std::endl;
            return;
        }

        // d. Select and detonate the best bomb
        std::pair<int, int> best_bomb = pq.top();
        
        // BUGFIX: The chosen bomb must be removed from consideration for future steps.
        pq.pop(); 

        ans.push_back(best_bomb.second);
        current_reach = best_bomb.first;
    }

    // Print the final result
    std::cout << ans.size() << std::endl;
    for (size_t i = 0; i < ans.size(); ++i) {
        std::cout << ans[i] << (i == ans.size() - 1 ? "" : " ");
    }
    std::cout << std::endl;
}

int main() {
    fast_io();
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}