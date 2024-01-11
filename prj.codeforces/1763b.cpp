#include <iostream>
 
int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, k;
       std:: cin >> n >> k;
        int* ptr = new int[n];
        int* p = new int[n];
        for (int i = 0; i < n; i++)
        {
            std::cin >> ptr[i];
        }
        for (int i = 0; i < n; i++)
        {
            std::cin >> p[i];
        }
        while (k > 0)
        {
            for (int i = 0; i < n; i++)
            {
                ptr[i] = ptr[i] - k;
                if (ptr[i] < 0)
                    ptr[i] = 0;
            }
            int min = INT_MAX;
            for (int i = 0; i < n; i++)
            {
 
                if (ptr[i] != 0 && p[i] < min)
                    min = p[i];
            }
            k = k - min;
        }
        int f = 0;
        for (int i = 0; i < n; i++)
        {
            if (ptr[i] != 0) {
                f = 1;
                break;
            }
        }
        if (f == 0)
            std::cout << "YES" << std::endl;
        else
            std::cout << "NO" << std::endl;
    }
}
