#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int a[1000005];

struct Node
{
	int value;
	vector<int> l;
	Node(int a)
	{
		value = a;
	}
};

vector<Node> v;

int main()
{
	int z;


	cin >> z;
	while (z--)
	{
		bool ok;
		ok = true;
		int n, m;

		cin >> n >> m;

		memset(a, 0, sizeof(a));
		v.clear();

		int count = 0;

		for (int i = 0; i < m; i++)
		{
			int temp;
			cin >> temp;
			if (temp)
			{
				if (count)
				{
					v.push_back(Node(count));
					count = 0;
				}

				int t;
				int s = v.size();

				t = a[temp];

				while (true)
				{
					if (t > s-1)
					{
						ok = false;
						
					}

					if (v[t].value)
					{
						v[t].value--;
						v[t].l.push_back(temp);
						break;
					}
					else
					{
						t++;
					}
				}
				a[temp]++;
			}
			else
			{
				count++;
			}

		}
	end:

		if (ok)
		{
			cout << "YES" << endl;
			for (int i = 0; i < v.size(); i++)
			{
				for (int j = 0; j < v[i].l.size(); j++)
				{
					if (i != 0 || j != 0)
					{
						cout << " ";
					}
					cout << v[i].l[j];
				}
				for (int j = 0; j < v[i].value; j++)
				{
					cout << " ";
					cout << 0;
				}
			}
			if (count)
			{
				for (int i = 0; i < count; i++)
				{
					cout << " ";
					cout << 0;
				}
			}
			cout << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;


}