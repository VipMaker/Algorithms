#include<stdio.h>//��С�����������
int cost[100][100],weight[100][100],row=0,col=0,limite=0,i,j,bestw=10000000,x[100],x1[100],cweight=0,ccost=0;
void backtrack(int t)//t��ʾ����
{	//�ݹ��������
	if (t == col+1 && ccost <=limite) {
		if (cweight < bestw) {
			bestw = cweight;
			for (int j=1;j <= col;j++) {
				x1[j] = x[j];
			}
		}
		return;
	}
	if (ccost <=limite) {		//��֦���������������
		for (int i = 1;i <=col;i++) {  //�������ǹ�Ӧ�� �����к������
			x[t] = i; //��¼һ�µ�ǰ���������t�Ǵ��ĸ���Ӧ��i����
			cweight += weight[t][i];
			ccost += cost[t][i];
			backtrack(t + 1);
			cweight -= weight[t][i];
			ccost -= cost[t][i];
			x[t] = 0;
		}
	}
}
int main()
{
	FILE *in,*out;
	in=fopen("input.txt","r");
	fscanf(in,"%d %d %d",&row,&col,&limite);
	for(i=1;i<=col;i++)
		for(j=1;j<=col;j++)
		{
			fscanf(in,"%d",&cost[i][j]);
		}
	for(i=1;i<=col;i++)
		for(j=1;j<=col;j++)
		{
			fscanf(in,"%d",&weight[i][j]);
		}
	for(i=1;i<=col;i++)
		for(j=1;j<=col;j++)
		{
			printf("%d ",weight[i][j]);
		}
	//printf("%d",weight[1][0]);
	fclose(in);
	backtrack(1);
	out=fopen("output.txt","w");
	/*for(i=0;i<col;i++)
	{
		cweight+=weight[i][x1[i]];
	}*/
	fprintf(out,"%d\n",bestw);
	for(i=1;i<=col;i++)
	{
		fprintf(out,"%d ",x1[i]);
	}
	fclose(out);
	return 0;
}