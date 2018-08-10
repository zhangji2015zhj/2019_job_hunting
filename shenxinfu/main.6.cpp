#include <bits/stdc++.h>


using namespace std;

struct room
{
	int x, y;
};
struct listnode
{
	room r;
	int z;
	string t;
};
bool  comp(listnode* a, listnode* b)
{
	if(a->t<b->t)
    return true;
    else return false;
}

class listdata
{
  private:
	int n, m;
	list<listnode *> mydata;
	int maxnum = 0;
	int roomnum = 0;
	vector<vector<int>> d;
	vector<vector<int>> dback;

  public:
	listdata(/* args */) {}
	void insert(listnode *);
	void sort();
	int findmax();
	void print();
	void setnm(int nn, int mm)
	{
		n = nn;
		m = mm;
		d.resize(n+1);
		for (auto var = d.begin();var!=d.end();var++)
		{
			var->resize(m+1,0);
		}

	}
	~listdata()
	{
		for (auto var : mydata)
		{
			delete var;
		}
	}
};


int main()
{

	int n, m, k;
	int x, y, z;

	string t;
	cin >> n >> m >> k;
	listdata maindata;
	maindata.setnm(n, m);
	for (size_t i = 0; i < k; i++)
	{
		auto data = new listnode;
		cin >> data->r.x >> data->r.y >> data->z >> data->t;
		maindata.insert(data);
	}
	maindata.sort();
	maindata.findmax();
	maindata.print();

	return 0;
}

void listdata::insert(listnode *data)
{
	auto var = mydata.begin();
	mydata.insert(var, data);

}
void listdata:: sort()
{
	std::sort(mydata.begin(),mydata.end(),comp);
}
int listdata::findmax()
{
	for (auto& data : mydata)
	{
	
			if (data->z)
			{
				if (--(d[data->r.x][data->r.y]) == 0)
				{
					roomnum--;
				}
			}
			else
			{
				if ((d[data->r.x][data->r.y])++ == 0)
				{
					roomnum++;
					if (roomnum >= maxnum)
					{
						maxnum = roomnum;
						dback = d;
					}
				}
			}
		
	}

	return maxnum;
}

void listdata::print()
{

	for (size_t i = 1; i <= n; i++)
	{
		for (size_t j = 1; j <= m; j++)
		{

			if (dback[i][j] > 0)
			{
				cout << 1;
			}

			else
			{
				cout << 0;
			}
		}
		if (i != n )
		{
			cout << endl;
		}
	}
}