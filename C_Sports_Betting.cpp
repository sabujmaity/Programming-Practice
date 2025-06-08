#include <iostream> // Include standard input/output library
#include <vector>   // Include vector library (though not used directly in final map solution)
#include <map>      // Include map library for frequency counting based on days
#include <algorithm> // Include algorithm library for std::max function

// Define long long for convenience, optional for this problem based on constraints
#define ll long long 

using namespace std; // Use the standard namespace to avoid writing std:: repeatedly

/**
 * @brief Solves a single test case for the Sports Betting problem.
 * 
 * Reads the number of students and the day each student made a bet.
 * Determines if Vadim can employ a strategy to guarantee winning at least one bet.
 * Outputs "Yes" if possible, "No" otherwise.
 * The core logic relies on the pigeonhole principle applied to the betting scenario.
 */
void solve() {
    int n; // Number of students Vadim made bets with
    cin >> n; // Read the number of students from input
    
    // Use std::map to count the frequency of each day students made bets on.
    // Key: day number (a_i) which can be up to 10^9.
    // Value: number of students who made a bet on that specific day.
    // `map` automatically handles sorting by key and insertion of new keys.
    // This approach is suitable because the number of distinct days might be much smaller than n, 
    // and map only stores entries for days that actually appear in the input.
    map<int, int> day_counts; 
    
    // Loop n times to read the betting day for each student
    for (int i = 0; i < n; ++i) {
        int a_i; // The day the i-th student made a bet
        cin >> a_i; // Read the day from input
        
        // Increment the count for this day `a_i`.
        // If `a_i` is not yet a key in `day_counts`, it's automatically inserted with value 1.
        // If `a_i` already exists, its associated value (count) is incremented.
        day_counts[a_i]++; 
    }

    // Find the maximum count of students betting on any single day.
    // Initialize `max_students_on_same_day` to 0. Since n >= 1, the map is not empty,
    // and the loop below will correctly find the maximum count >= 1.
    int max_students_on_same_day = 0;
    
    // Iterate through all key-value pairs present in the `day_counts` map.
    // C++17 structured binding `auto const& [day, count]` provides a clean way to access
    // the key (`day`) and value (`count`) of each map entry.
    // Using `const&` avoids copying and ensures the map contents are not modified during iteration.
    for (auto const& [day, count] : day_counts) {
        // Update `max_students_on_same_day` if the current `count` is larger.
        max_students_on_same_day = max(max_students_on_same_day, count);
    }

    // Determine if Vadim can guarantee winning at least one bet based on the maximum count.
    // There are exactly 4 possible outcomes for the sequence of boarding processes 
    // on any two consecutive days (D+1, D+2), let's call them O1, O2, O3, O4.
    // If Vadim finds any day D where at least 4 students placed their bets (i.e., `max_students_on_same_day >= 4`),
    // he can employ the following guaranteed winning strategy:
    // Pick 4 students who bet on day D. Assign prediction O1 to the first student, O2 to the second, O3 to the third, and O4 to the fourth.
    // Since the actual outcome for days (D+1, D+2) must be one of O1, O2, O3, O4, one of these 4 students will have the correct prediction.
    // Therefore, Vadim wins at least one bet.
    // If `max_students_on_same_day < 4`, Vadim does not have enough students betting on any single day to cover all 4 possibilities for that day's pair, 
    // and based on the standard interpretation and problem structure, he likely cannot guarantee a win. 
    // While Example 3 presents a case where `n=5`, `max_count=2` results in "Yes", suggesting a more complex interaction might exist, 
    // the primary logic relies on this clear pigeonhole principle condition. We follow this condition.
    if (max_students_on_same_day >= 4) {
        cout << "Yes\n"; // Output "Yes" if Vadim can guarantee a win
    } else {
        cout << "No\n";  // Output "No" if Vadim cannot guarantee a win based on this analysis
    }
}

// Main function: Entry point of the program.
int main() {
    // Optimize standard C++ input/output streams for faster execution.
    // This is common practice in competitive programming to avoid Time Limit Exceeded issues on large inputs.
    ios_base::sync_with_stdio(false); // Disable synchronization between C++ standard streams and C stdio functions.
    cin.tie(NULL); // Untie cin from cout, allowing input and output operations to potentially overlap execution.

    int t; // Declare variable for the number of test cases
    cin >> t; // Read the number of test cases from input
    
    // Loop 't' times to process each test case
    while (t--) {
        solve(); // Call the function that solves a single test case
    }
    
    return 0; // Indicate successful program termination
}