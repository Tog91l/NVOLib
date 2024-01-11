#include<iostream>
 
 
 
int n, k;
void run()
{
	std::cin >> n >> k;
	long long s = 1;
	for (int i = 1; i <= n; i++)
	{
		int t;
		std::cin >> t;
		s *= t;
	}
	if (2023 % s != 0)
	{
		std::cout << "NO" << '\n';
		
	}
	else
	{
		std::cout << "YES\n" << 2023 / s << " ";
		for (int i = 2; i <= k; i++)
			std::cout << "1 ";
		std::cout << '\n';
		
	}
}
int main()
{
	int t;
	std::cin >> t;
	while (t--)
		run();
	return 0;
}
