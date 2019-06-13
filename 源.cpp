#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

const int MAX =100;
int n, m;
int x[MAX];
int bestx[MAX];

int f(int i, int n)
{
	if (i == 1)
		return n * 3;
	else
		return n / 2;
}

int k;  //搜索深度，逐步加深
bool found = false;
bool backtrack(int dep, int n)
{
	if (dep > k)
		return false;
	else
	{
		for (int i = 1; i <= 2; i++)
		{
			int temp = f(i, n);
			x[dep] = i;
			if (temp == m || backtrack(dep + 1, temp))
			{
				found = true;
				for (int j = 1; j <= k; j++)
					bestx[j] = x[j];
				return true;
			}
			x[dep] = 0;
		}
	}
	return false;
}

void search()
{
	k = 1;
	while (!backtrack(1, n))
	{
		k++;
		memset(x, 0, sizeof(x));
		memset(bestx, 0, sizeof(bestx));
	}
}

int main()
{
	ifstream cinfile;
	cinfile.open("input.txt", ios::in);
	cinfile >> n;
	cinfile >> m;
	search();
	ofstream outfile;
	if (found)
	{
		outfile.open("output.txt", ios::out);
		outfile << k;
		outfile << '\n';
		for (int i = 1; i <= k; i++)
			if (bestx[i] == 1)
				outfile << 'f';
			else
				outfile << 'g';
	}
	else
		cout << "变换失败！\n";
	outfile.close();
	return 0;
}