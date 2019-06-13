#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include<fstream>
using namespace std;
int main()
{
	int i, n, j, k, minx;
	int s;
	double t;
	int a[1000], b[1000];
	ifstream cinfile;
	cinfile.open("input.txt", ios::in);
	cinfile >> n;
	cinfile >> s;
	for (int i = 0; i < n; i++) {
		cinfile >> a[i];
	}
	cinfile.close();
		sort(a, a + n); //将数组从小到大排序 
		memset(b, 0, sizeof(b)); // 将b中的数组初始化为0
		for (i = 0; i < n; i++) //遍历顾客的等待时间 
		{
			minx = 0x7fffffff; //定义一个非常大的数 
			k = 0; // 
			for (j = 0; j < s; j++)  //有几个工位 进行几次循环 
			{
				if (minx > b[j]) // 这个和上个小的进行对比 
				{
					minx = b[j]; //记录小的 
					k = j; //记录小的对应的工位 
				}
			}
			b[k] += a[i]; // b[k] = b[k] + a[i]  记录每个工位的总时间 
			a[i] = b[k];  // 把每个工位的时间赋给对应顾客 形成 顾客总时间数组 
		}
		t = 0;
		for (i = 0; i < n; i++) // 计算顾客平均等待时间 
			t += a[i];
		t /= n;
		ofstream outfile;
		outfile.open("output.txt", ios::out);
		outfile << (int)(t);
		outfile.close();
	return 0;

}
