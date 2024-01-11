#include <iostream>
#include <algorithm>
int main()
{
    const int max_n = 2e5;
    int t, n, a[max_n];
    std::cin >> t;
    while (t--)
    {
        std::cin >> n;
        for (int i = 0; i < n - 1; ++i) {
            std::cin >> a[i];
            a[n - 1] = a[n - 2];
        }
 
        for (int i = n - 2; i > 0; --i) {
            a[i] = std::min(a[i], a[i - 1]);
        }
        for (int i = 0; i < n; ++i) {
            std::cout << a[i] << " \n"[i == n - 1];
        }
    }
}
