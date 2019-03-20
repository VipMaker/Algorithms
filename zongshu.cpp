#include<stdio.h>
//从左向右找到与中间数相同的数位置
//时间复杂度nlognlogn
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
	chaifen(l,r,s,n);//以中间数进行拆分
	int cnt=r-l;
	int num=n/2;
	if(maxnum<cnt)
	{
		maxnum=cnt;
		mid=s[num];
	}
	if(l+1>maxnum)
	{
		getMaxNum(s,l+1,mid,maxnum);//直到中间的那个数或前面的数重数大于拆分左边和右边的元素个数时递归函数结束程序完成
	}
	if(n-r>maxnum)
	{
		getMaxNum(s+r,n-r,mid,maxnum);//直到中间的那个数或前面的数重数大于拆分左边和右边的元素个数时递归函数结束程序完成
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
	getMaxNum(s,n,num,maxnum);	//递归函数
	fprintf(output,"%d\n%d",num,maxnum);
	fclose(input);
	fclose(output);
	return 0;
}
