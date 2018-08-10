#include <bits/stdc++.h>

using namespace std;

int mydata[20] = {0};
const int M = 100;
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> mydata[i];
	int m = (1 << n);
	for (int t = 1; t < m; ++t)
	{
		int sum = 0;
		int ret = 0;
		for (int i = 0; i < n; ++i)
		{
			if (t & (1 << i))
			{
				sum += mydata[i];
				++ret;
			}
		}
		if (sum == M)
		{
			cout << ret << endl;
			for (int i = 0; i < n; ++i)
			{
				if (t & (1 << i))
					cout << i + 1 << endl;
			}
			break;
		}
	}
	return 0;
}