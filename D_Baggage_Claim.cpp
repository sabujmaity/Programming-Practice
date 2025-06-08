#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath> // For abs function
#include <utility> // For pair (used for Point definition)

using namespace std;

// Use long long for dynamic programming counts to avoid potential overflow
using ll = long long;
// Define the modulus for calculations, as specified in the problem
const int MOD = 1e9 + 7;

// Define Point as a pair of integers to represent grid coordinates (x, y)
using Point = pair<int, int>;

// Use standard map for DP states. Key is Point, Value is the count of ways.
// Map performance is sufficient because the maximum number of states per step is 2.
using DPMap = map<Point, ll>;


int main() {
    // Faster I/O settings
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int T; // Number of test cases
    cin >> T;
    while (T--) {
        int n, m, k; // Grid dimensions N x M, path parameter K
        cin >> n >> m >> k;

        vector<Point> P_odd(k + 1); // Store the given odd-indexed cells p_1, p_3, ..., p_{2k+1}
        set<Point> OddCellsSet; // Set to quickly check if a candidate cell is one of the given odd cells
        for (int i = 0; i <= k; ++i) {
            cin >> P_odd[i].first >> P_odd[i].second;
            OddCellsSet.insert(P_odd[i]); // Add the read point to the set
        }

        DPMap dp_prev; // DP states from the previous step (i-1). Stores count of paths ending at each cell.
        ll total_prev = 0; // Sum of values in dp_prev, modulo MOD. Represents total ways to reach step i-1.

        bool possible = true; // Flag to track if path restoration is feasible throughout the process.

        // Iterate through each missing cell p_{2i}, for i = 1 to k
        for (int i = 1; i <= k; ++i) {
            Point A = P_odd[i - 1]; // Start cell p_{2i-1} for the current segment
            Point B = P_odd[i];     // End cell p_{2i+1} for the current segment

            vector<Point> candidates; // Store potential common neighbors (candidates for p_{2i})
            int dx = abs(A.first - B.first); // Difference in x-coordinates
            int dy = abs(A.second - B.second); // Difference in y-coordinates

            // A path segment p_{2i-1} -> p_{2i} -> p_{2i+1} is possible only if p_{2i} is a common neighbor of A and B.
            // This condition implies the Manhattan distance between A and B must be exactly 2.
            if (dx + dy == 2) { 
                if (dx == 2 && dy == 0) { // Cells A and B are in the same row, 2 units apart horizontally
                    // The unique common neighbor is the cell directly between them
                    Point P = {(A.first + B.first) / 2, A.second};
                    // Check if the candidate midpoint P is within grid boundaries
                     if (P.first >= 1 && P.first <= n && P.second >= 1 && P.second <= m)
                        candidates.push_back(P);
                } else if (dx == 0 && dy == 2) { // Cells A and B are in the same column, 2 units apart vertically
                    // The unique common neighbor is the cell directly between them
                    Point P = {A.first, (A.second + B.second) / 2};
                    // Check if the candidate midpoint P is within grid boundaries
                    if (P.first >= 1 && P.first <= n && P.second >= 1 && P.second <= m)
                        candidates.push_back(P);
                } else if (dx == 1 && dy == 1) { // Cells A and B are diagonally adjacent
                    // There are two potential common neighbors forming a 2x2 square with A and B
                    Point P1 = {A.first, B.second}; // First potential common neighbor
                    Point P2 = {B.first, A.second}; // Second potential common neighbor
                    // Check if P1 is within grid boundaries and add if it is
                     if (P1.first >= 1 && P1.first <= n && P1.second >= 1 && P1.second <= m)
                        candidates.push_back(P1);
                    // Check if P2 is within grid boundaries. P1 and P2 are always distinct when dx=1, dy=1.
                     if (P2.first >= 1 && P2.first <= n && P2.second >= 1 && P2.second <= m) {
                        // If P1 was also added, we just need to add P2.
                        // If P1 was not added (because it's out of bounds), P2 might be the only candidate.
                         candidates.push_back(P2);
                    }
                }
                 // There are no other cases where dx+dy=2.
            } else {
                // If Manhattan distance is not 2, there's no single cell p_{2i} that is adjacent to both A and B. Path is impossible.
                 possible = false;
                 break; // Exit the loop for this test case
            }

            // Filter the generated candidates: remove any candidate P that coincides with a given odd-indexed cell
            // as the path must be simple (no repeated vertices).
            vector<Point> valid_candidates; 
            for(const auto& P : candidates) {
                if (OddCellsSet.find(P) == OddCellsSet.end()) { // Check if P exists in the set of odd-indexed points
                    valid_candidates.push_back(P);
                }
            }
            
            // If after filtering, no valid cell exists for p_{2i}, the path reconstruction is impossible.
            if (valid_candidates.empty()) {
                possible = false;
                break; // Exit loop
            }

            // Prepare for the current DP step computation
            DPMap dp_curr; // DP states for the current step i. Stores map from cell P to number of paths ending at P.
            ll total_curr = 0; // Sum of DP values in dp_curr, modulo MOD. Represents total ways to complete step i.

            if (i == 1) { // Base case: for the first missing cell p_2 (i=1)
                // Each valid candidate P starts a distinct valid path segment of length 1 (from p_1 to P).
                for (const auto& P : valid_candidates) {
                    dp_curr[P] = 1; // Initialize count to 1 for each path starting via P
                    total_curr = (total_curr + 1) % MOD; // Add to the total count for this step
                }
            } else { // DP transition for subsequent steps i > 1
                 for (const auto& P : valid_candidates) { // P is a valid candidate cell for p_{2i}
                     ll prev_val_at_P = 0; // Stores the count of paths that ended at cell P *in the previous step* i-1 (i.e., P was p_{2i-2})
                     // Check if P existed as a state in the previous step's DP map
                     if (dp_prev.count(P)) { 
                         prev_val_at_P = dp_prev.at(P); // Retrieve the count
                     }
                     // DP Transition Rule: The number of ways to arrive at cell P at step i (i.e., P is p_{2i}) is
                     // the total number of ways to complete step i-1 (total_prev), 
                     // MINUS the number of ways that ended at P itself at step i-1. This subtraction enforces the
                     // simple path constraint p_{2i} != p_{2i-2}. Modular arithmetic must be used.
                     ll current_dp_val = (total_prev - prev_val_at_P + MOD) % MOD; // `+ MOD` ensures the result is non-negative before modulo.
                     dp_curr[P] = current_dp_val; // Store the calculated DP value for cell P at step i
                     total_curr = (total_curr + current_dp_val) % MOD; // Accumulate the total count for step i
                 }
            }

             // If at any step, the total number of ways to proceed (total_curr) becomes 0, then no valid path can be completed.
             if (total_curr == 0 && i <= k) { // check i <= k ensures this doesn't trigger wrongly if k=0 (though problem guarantees k>=1)
                possible = false;
                break; // Stop processing this test case.
            }

            // Prepare for the next iteration: current DP states become previous states.
            // Use std::move for potential efficiency gain (avoids copy if map implementation allows move semantics).
            dp_prev = std::move(dp_curr); 
            total_prev = total_curr; // Update the total count for the previous step
        }

        // Output the final result for the test case
        if (!possible) {
            cout << 0 << "\n"; // If path reconstruction was determined impossible at any step, output 0
        } else {
            // Otherwise, total_prev holds the total number of ways to restore the full path, modulo MOD
            cout << total_prev << "\n"; 
        }
    }

    return 0; // Indicate successful program execution
}