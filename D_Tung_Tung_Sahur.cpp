#include <iostream>
#include <string>

bool isValidSoundSequence(const std::string& p, const std::string& s) {
    int i = 0, j = 0;
    int n = p.size(), m = s.size();

    while (i < n) {
        if (j >= m || s[j] != p[i]) return false;

        int count = 0;
        while (j < m && s[j] == p[i]) {
            count++;
            j++;
        }

        if (count < 1 || count > 2) return false;

        i++;
    }

    // Ensure s has been completely used up
    return j == m;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string p, s;
        std::cin >> p >> s;

        if (isValidSoundSequence(p, s))
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
    return 0;
}
