#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <chrono>
#include <iterator>

using namespace std;

/*输出 行 不换行*/
template <typename Container_iter>
void Container_print(Container_iter start, Container_iter last, char del = ' ')
{
	while (start != prev(last))
	{
		cout << *start++ << del;
	};
	cout << *start;
}

int main(int argc, char const *argv[])
{
	int l, r;
	cin >> l >> r;
	vector<long long int> sum;
	sum.resize(10);

	for (size_t i = l; i <= r; i++)
	{
		 int current = i;
		 int g = 1;


		while (current / g >= g)
		{

			if (current % g == 0)
			{

				string num = to_string(g);
				if (num.size() > 1)
				{
					sum[num[1] - '0']++;
				}
				sum[num[0] - '0']++;

				if (current / g > g)
				{
					num = to_string(current / g);
					if (num.size() > 1)
					{
						sum[num[1] - '0']++;
					}
					sum[num[0] - '0']++;
				}
				

			}
			++g;
		}
	}
	Container_print(sum.begin() + 1, sum.end(), '\n');

	return 0;
}
