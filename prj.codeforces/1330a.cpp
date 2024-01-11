#include <iostream>
#include <vector>
#include <algorithm>
 
int main() {
    int t;
    std::cin >> t;
 
    while (t--) {
        int n, x, a, i;
        std::cin >> n >> x;
 
        std::vector<bool> m(210, false);
 
        for (int j = 0; j < n; ++j) {
            std::cin >> a;
            m[a] = true;
        }
 
        for (i = 1; ; ++i) {
            if (!m[i] && x == 0)
                break;
            if (!m[i])
                x--;
        }
 
        std::cout << i - 1 << std::endl;
    }
 
    return 0;
}
