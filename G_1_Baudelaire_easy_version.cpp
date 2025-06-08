#include <iostream> // Required for input/output operations (cin, cout)
#include <vector>   // Required for using std::vector
#include <numeric>  // Not strictly needed here, but useful in similar problems
#include <cstdlib>  // Required for exit() for handling potential errors in interactive problems

/*
 * Function to query f(i) - the sum of values on the path from root to node i.
 * Sends query "? 1 i" and reads the response.
 * Ensures output is flushed using std::endl.
 * Includes basic error handling for input failure.
 */
long long query_f(int i) {
    std::cout << "? 1 " << i << std::endl; // Send query and flush output buffer
    long long response;
    std::cin >> response; // Read judge's response
    // Check if reading failed (e.g., judge terminated, wrong format)
    if (std::cin.fail()) {
        exit(0); // Exit gracefully if communication fails
    }
    return response;
}

/*
 * Function to toggle the value of node u (1 becomes -1, -1 becomes 1).
 * Sends query "? 2 u". No response is expected or read.
 * Ensures output is flushed using std::endl.
 */
void toggle_node(int u) {
    std::cout << "? 2 " << u << std::endl; // Send query and flush output buffer
    // No response value to read according to problem statement
}

// Main function
int main() {
    // Use std::endl for flushing, avoid fast I/O unless absolutely necessary
    // and tested in interactive context.

    int t; // Number of test cases
    std::cin >> t;
    // Basic validation for the number of test cases
    if (std::cin.fail()) return 1;

    // Process each test case
    while (t--) {
        int n; // Number of nodes in the tree
        std::cin >> n;
        // Basic validation for the size of the tree (n>=2 is guaranteed)
        if (std::cin.fail() || n < 2) return 1;

        // --- Step 1: Query initial f(i) values for all nodes ---
        // Use 1-based indexing for vectors to match node numbers.
        std::vector<long long> f_init(n + 1);
        // Perform n queries of type "? 1 i"
        for (int i = 1; i <= n; ++i) {
            f_init[i] = query_f(i);
        }

        // Vector to store the final node values (1 or -1)
        std::vector<int> v_final(n + 1);

        // --- Step 2: Determine if the root R is node 1 ---
        // Based on the star graph structure centered at 1:
        // If R=1, then f(1) = v[1] = +/- 1.
        // If R!=1, then f(1) = v[R] + v[1] = 0 or +/- 2.
        if (f_init[1] == 1 || f_init[1] == -1) {
            // --- Case R = 1 ---
            // No toggles needed. Final values = initial values.
            v_final[1] = f_init[1]; // v[1] = f(1)
            // For k != 1, f(k) = v[1] + v[k], so v[k] = f(k) - v[1]
            for (int k = 2; k <= n; ++k) {
                v_final[k] = f_init[k] - v_final[1];
                // Sanity check: derived v[k] should be +/- 1. Add error handling if needed.
                 if (v_final[k] != 1 && v_final[k] != -1) {
                    // This state implies inconsistency, potentially exit or handle error.
                    // exit(1); // Or handle differently based on contest rules.
                 }
            }
            // Query count for this case: n
        } else {
            // --- Case R != 1 ---
            // Need to determine initial v[1] using the toggle trick.

            // --- Step 3: Determine initial v[1] ---
            toggle_node(1); // Perform toggle on node 1
            long long f1_new = query_f(1); // Query f(1) after toggle
            long long delta_f1 = f1_new - f_init[1]; // Calculate change in f(1)

            // If R!=1, delta_f1 = -2 * v_initial[1]. Check if delta is +/- 2.
             if (delta_f1 != 2 && delta_f1 != -2) {
                 // This indicates an error or inconsistency with the R!=1 assumption.
                 exit(1); // Exit program if logic fails
             }
            // Calculate the initial value of v[1]
            int v1_determined = -delta_f1 / 2;

            toggle_node(1); // Toggle node 1 back to restore its initial value

            // --- Step 4: Find the root R and determine initial v ---
            // The root R must be a node k (k>=2) such that:
            //   a) f_init[k] = +/- 1 (since f(R) = v[R])
            //   b) The derived v[1] from assuming R=k matches v1_determined.
            //      Derived v[1] = f_init[1] - f_init[k].
            //      So, check: f_init[1] - f_init[k] == v1_determined
            
            int root_R = -1; // Store the identified root
            for (int k = 2; k <= n; ++k) {
                // Check condition (a)
                if (f_init[k] == 1 || f_init[k] == -1) {
                    // Check condition (b)
                    if (f_init[1] - f_init[k] == v1_determined) {
                        root_R = k; // Found a consistent root R
                        // Since the initial state (R, v) is unique, and multiple k might
                        // lead to the same v vector, finding the first consistent k is sufficient.
                        break; 
                    }
                }
            }

            // If no consistent root was found, something is wrong.
             if (root_R == -1) {
                 exit(1); // Exit due to inconsistency
             }

            // --- Step 5: Calculate the final (initial) v vector based on R = root_R ---
            // v[R] = f(R)
            v_final[root_R] = f_init[root_R];
            // v[1] = f(1) - f(R)
            v_final[1] = f_init[1] - v_final[root_R]; // This should match v1_determined
            // For j != 1, R: v[j] = f(j) - f(1)
            for (int j = 2; j <= n; ++j) {
                if (j == root_R) continue; // Skip the root itself
                v_final[j] = f_init[j] - f_init[1];
                 // Sanity check: derived v[j] should be +/- 1
                 if (v_final[j] != 1 && v_final[j] != -1) {
                    // Handle error or inconsistency if needed
                    // exit(1);
                 }
            }
            // Query count for this case: n (initial f) + 3 (toggle, query, toggle back) = n + 3
        }

        // --- Step 6: Output the final answer ---
        std::cout << "! ";
        for (int i = 1; i <= n; ++i) {
            // Output the final value for node i, followed by a space (except for the last one)
            std::cout << v_final[i] << (i == n ? "" : " ");
        }
        std::cout << std::endl; // Final flush for the answer line
    }
    return 0; // Indicate successful program execution
}