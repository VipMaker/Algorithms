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
		sort(a, a + n); //�������С�������� 
		memset(b, 0, sizeof(b)); // ��b�е������ʼ��Ϊ0
		for (i = 0; i < n; i++) //�����˿͵ĵȴ�ʱ�� 
		{
			minx = 0x7fffffff; //����һ���ǳ������ 
			k = 0; // 
			for (j = 0; j < s; j++)  //�м�����λ ���м���ѭ�� 
			{
				if (minx > b[j]) // ������ϸ�С�Ľ��жԱ� 
				{
					minx = b[j]; //��¼С�� 
					k = j; //��¼С�Ķ�Ӧ�Ĺ�λ 
				}
			}
			b[k] += a[i]; // b[k] = b[k] + a[i]  ��¼ÿ����λ����ʱ�� 
			a[i] = b[k];  // ��ÿ����λ��ʱ�丳����Ӧ�˿� �γ� �˿���ʱ������ 
		}
		t = 0;
		for (i = 0; i < n; i++) // ����˿�ƽ���ȴ�ʱ�� 
			t += a[i];
		t /= n;
		ofstream outfile;
		outfile.open("output.txt", ios::out);
		outfile << (int)(t);
		outfile.close();
	return 0;

}
