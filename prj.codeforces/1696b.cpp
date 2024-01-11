#include<iostream>
#include<vector>
int main()
{
    int t;
   std:: cin >> t;
    int n;
    for (int k = 0; k < t; k++)
    {
       std:: cin >> n;
       std:: vector<int>a(n);
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            std::cin >> a[i];
            if (i != 0)
            {
                if (a[i - 1] == 0 && a[i] != 0)
                    res++;
                    
            }
 
        }
        if (a[0] != 0)
            res++;
 
        if (res > 2)
            res = 2;
       std:: cout << res<< std::endl;
    }
 
    return 0;
}
