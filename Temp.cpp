#include <bits/stdc++.h>
using namespace std;

vector<long long> generateValidKeys(long long limit) {
    long long maxPrime = sqrt(limit) + 1;
    vector<bool> isPrime(maxPrime + 1, true);
    isPrime[0] = isPrime[1] = false;

    // Sieve of Eratosthenes
    for (long long i = 2; i * i <= maxPrime; i++) {
        if (isPrime[i]) {
            for (long long j = i * i; j <= maxPrime; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // Store squares of primes
    vector<long long> validKeys;
    for (long long i = 2; i <= maxPrime; i++) {
        if (isPrime[i]) {
            long long sq = i * 1LL * i;
            if (sq <= limit) validKeys.push_back(sq);
        }
    }
    sort(validKeys.begin(), validKeys.end());
    return validKeys;
}

vector<int> getValidKey(vector<long long>& numbers) {
    long long maxLimit = *max_element(numbers.begin(), numbers.end());
    vector<long long> validKeys = generateValidKeys(maxLimit);

    vector<int> result;
    for (long long num : numbers) {
        // Count numbers ≤ num using upper_bound
        int count = upper_bound(validKeys.begin(), validKeys.end(), num) - validKeys.begin();
        result.push_back(count);
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> numbers(n);
    for (int i = 0; i < n; i++) cin >> numbers[i];

    vector<int> ans = getValidKey(numbers);

    for (int x : ans) cout << x << "\n";

    return 0;
}
