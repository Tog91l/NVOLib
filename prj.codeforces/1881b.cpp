#include <iostream>
#include <algorithm>
 
    int main() {
        int n;
        std::cin >> n;
 
        while (n--) {
            int a, b, c;
            std::cin >> a >> b >> c;
            int len[] = { a, b, c };
            std::sort(len, len + 3);
            if (len[0] == len[1] && len[1] == len[2]) {
                std::cout << "YES" << std::endl;
            }
            else {
                if (len[1] % len[0] == 0 && len[2] % len[0] == 0 &&
                    (len[1] / len[0] - 1) + (len[2] / len[0] - 1) <= 3) {
                    std::cout << "YES" << std::endl;
                }
                else {
                    std::cout << "NO" << std::endl;
                }
            }
        }
 
        return 0;
    }
