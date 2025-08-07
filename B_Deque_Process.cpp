#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>

/**
 * @brief Checks if a given block of 5 integers is strictly monotonic.
 * * @param block A deque containing up to 5 integers.
 * @return true if the block has 5 elements and is strictly increasing or decreasing, false otherwise.
 */
bool is_monotonic_block(const std::deque<int>& block) {
    if (block.size() < 5) {
        return false;
    }
    bool increasing = true;
    bool decreasing = true;
    for (size_t i = 0; i < 4; ++i) {
        if (block[i] >= block[i+1]) {
            increasing = false;
        }
        if (block[i] <= block[i+1]) {
            decreasing = false;
        }
    }
    return increasing || decreasing;
}

/**
 * @brief Solves a single test case for the Deque Process problem.
 */
void solve() {
    int n;
    std::cin >> n;
    std::deque<int> p;
    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;
        p.push_back(val);
    }

    std::string result = "";
    // q_suffix stores the last up-to-4 elements added to the output sequence q.
    // This is all the history we need for our greedy choice.
    std::deque<int> q_suffix; 

    for (int i = 0; i < n; ++i) {
        int l_val = p.front();
        int r_val = p.back();

        bool can_l = true;
        // Check if picking p.front() creates a bad contiguous block of 5
        if (q_suffix.size() == 4) {
            std::deque<int> temp_block = q_suffix;
            temp_block.push_back(l_val);
            if (is_monotonic_block(temp_block)) {
                can_l = false;
            }
        }

        bool can_r = true;
        // Check if picking p.back() creates a bad contiguous block of 5
        if (q_suffix.size() == 4) {
             std::deque<int> temp_block = q_suffix;
             temp_block.push_back(r_val);
             if (is_monotonic_block(temp_block)) {
                can_r = false;
             }
        }

        bool pick_l;
        if (can_l && can_r) {
            // Tie-breaker: Both moves are safe.
            // A simple heuristic is to pick the smaller element.
            if (l_val < r_val) {
                pick_l = true;
            } else {
                pick_l = false;
            }
        } else if (can_l) {
            pick_l = true;
        } else { // can_r must be true, as a solution is guaranteed
            pick_l = false;
        }

        if (pick_l) {
            result += 'L';
            p.pop_front();
            q_suffix.push_back(l_val);
            if (q_suffix.size() > 4) {
                q_suffix.pop_front();
            }
        } else {
            result += 'R';
            p.pop_back();
            q_suffix.push_back(r_val);
            if (q_suffix.size() > 4) {
                q_suffix.pop_front();
            }
        }
    }

    std::cout << result << std::endl;
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}