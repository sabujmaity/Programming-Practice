#include <iostream>
#include <vector>
#include <string>

void solve() {
    int l;
    std::cin >> l;
    while (l--) {
        int l1, l2;

        std::cout << "? 1" << std::endl;
        std::cin >> l1;

        std::cout << "? 1 1" << std::endl;
        std::cin >> l2;

        std::cout << "! " << l1 + l2 << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}