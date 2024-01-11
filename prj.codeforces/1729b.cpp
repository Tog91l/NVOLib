#include <iostream>
#include <string>
 
int main()
{
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		std::cin >> n;
		std::string s, q = "";
		std::cin >> s;
		for (int j = n - 1; j >= 0; j--)
			if (s[j] != '0')
			{
				q += char(s[j] - '0' + 96);
			}
			else
			{
				q += char((s[j - 2] - '0') * 10 + (s[j - 1] - '0') + 96);
				j -= 2;
			}
		reverse(q.begin(), q.end());
		std::cout << q << std::endl;
	}
}
