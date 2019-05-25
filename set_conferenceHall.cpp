#include<stdio.h>
struct time_type{
	int time;
	bool flag;
} t_b[100],t_e[100];
int main()
{
	FILE *in,*out;
	int n=0,i,j=0,count=0,max=0;
	struct time_type a[200],t;
	in=fopen("input.txt","r");
	fscanf(in,"%d",&n);
	for(i=0;i<n;i++)
	{
		fscanf(in,"%d %d",&t_b[i].time,&t_e[i].time);
	}
	fclose(in);
	/*遍历开始结束时间存入一个数组*/
	for(i=0;i<n;i++)
	{
		a[i].time=t_b[i].time;
		a[i].flag=true;
	}
	for(i=n;i<2*n;i++)
	{
		a[i].time=t_e[i-n].time;
		a[i].flag=false;
	}
	for(i=0;i<2*n;i++)//对开始和结束时间进行选择排序
		for(j=i+1;j<2*n;j++)
		{
			if(a[j].time<a[i].time)
			{
				t=a[j];
				a[j]=a[i];
				a[i]=t;
			}
		}
		/*找出同时进行的活动就行了*/
	for(i=0;i<2*n;i++)
	{
		if(a[i].flag==true)
		{
			count++;
			if(count>max)
				max=count;
		}
		else
			count--;
		printf("%d\n",max);

	}

	out=fopen("output.txt","w");
	fprintf(out,"%d",max);
	fclose(out);
	return 0;
}