include <iostream>
#include <vector>
#include <algorithm>
 
int main() {
    int n, m;
    std::cin >> n >> m;
 
    
    std::vector<std::pair<int, int>> c(m);
 
    
    int sum = 0;
 
   
    for (int i = 0; i < m; ++i) {
        std::cin >> c[i].first >> c[i].second;
    }
 
    std::sort(c.rbegin(), c.rend(),
        [](const auto& a, const auto& b) { return a.second < b.second; });
 
   
    for (int i = 0; i < m && n > 0; ++i) {
        int s = std::min(n, c[i].first);
        sum += s * c[i].second;
        n -= s;
    }
 
    std::cout << sum << std::endl;
 
    return 0;
}
