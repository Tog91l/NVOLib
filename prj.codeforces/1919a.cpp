#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int a, b;
        std::cin >> a >> b;
        std::string res;
        if ((a + b) % 2 == 1) {
            res = "Alice\n";
        }
        else {
            res = "Bob\n";
        }
        std::cout << res;
    }
}
