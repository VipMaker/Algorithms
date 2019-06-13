//独立任务最优调度
#include<stdio.h>
#include<string.h> 
int a[100];
int b[100];
int minTime = 10000;
int sa = 0, sb = 0, max = 0;
int main() {
	FILE* in, * out;
	int n,i;
	in = fopen("input.txt", "r");
	fscanf(in, "%d", &n);
	for (i = 0; i < n; i++)
	{
		fscanf(in, "%d", &a[i]);
	}
	for (i = 0; i < n; i++)
	{
		fscanf(in, "%d", &b[i]);
	}
	fclose(in);
	for (i = 0; i < n; i++) {
		sa += a[i];
		sb += b[i];//假设都在A或B上运行
	}
	max = sa > sb ? sa : sb;

	int p[1000];
	memset(p, 0, sizeof(p));

	for (int k = 0; k < n; k++) {//遍历任务
		for (i = max; i >= 0; i--) {
			p[i] = p[i] + b[k];
			if (i > a[k]) {//当前时间是否满足其在机器a上运行
				p[i] = p[i] < p[i - a[k]] ? p[i] : p[i - a[k]];
			}
		}
	}

	for (i = 0; i <= max; i++) {//计算总时间
		int t = p[i] > i ? p[i] : i;
		if (minTime > t)
			minTime = t;
	}
	out = fopen("output.txt", "w");
	fprintf(out, "%d", minTime);
	fclose(out);
	return 0;
}