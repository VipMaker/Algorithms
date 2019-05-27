#include<stdio.h>//最小重量机器设计
int cost[100][100],weight[100][100],row=0,col=0,limite=0,i,j,bestw=10000000,x[100],x1[100],cweight=0,ccost=0;
void backtrack(int t)//t表示部件
{	//递归结束条件
	if (t == col+1 && ccost <=limite) {
		if (cweight < bestw) {
			bestw = cweight;
			for (int j=1;j <= col;j++) {
				x1[j] = x[j];
			}
		}
		return;
	}
	if (ccost <=limite) {		//剪枝纵向深度优先条件
		for (int i = 1;i <=col;i++) {  //遍历的是供应商 纵向不行横向遍历
			x[t] = i; //记录一下当前的这个部件t是从哪个供应商i购得
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