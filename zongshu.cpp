#include<stdio.h>
//从左向右找到与中间数相同的数位置
void chaifen(int &l,int &r,int s[],int n)
{
	int mid=n/2;
	for(l=0;l<n;++l)
	{
		if(s[l]==s[mid])
			break;
	}
	for(r=l+1;r<n;++r)
	{
		if(s[r]!=s[mid])
			break;
	}
}
//获取最大重数采用递归方法
void getMaxNum(int s[],int n,int &mid,int &maxnum)
{
	int l,r;
	chaifen(l,r,s,n);
	int cnt=r-l;
	int num=n/2;
	if(maxnum<cnt)
	{
		maxnum=cnt;
		mid=s[num];
	}
	if(l+1>maxnum)
	{
		getMaxNum(s,l+1,mid,maxnum);
	}
	if(n-r>maxnum)
	{
		getMaxNum(s+r,n-r,mid,maxnum);
	}
}
int main(void)
{
	int s[20];//s[20]={1,2,2,2,3,5};
	int n,num=0,maxnum=0;
	FILE *input,*output;							//文件流输入输出
	input = fopen("input.txt","r");
	output = fopen("output.txt","w");
	fscanf(input,"%d",&s);
	n=s[0];
	printf("%d\n",n);
	getMaxNum(s,n,num,maxnum);
	fprintf(output,"%d\n%d",num,maxnum);
	fclose(input);
	fclose(output);
	return 0;
}