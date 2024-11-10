#include<stdio.h>
#include<stdlib.h>
int a[10][10], visited[10], n ,cost=0;
void get()
{
	int i, j;
	printf("Enter number of cities: ");
	scanf("%d", &n);
	printf("\n Enter elements of matrix: ");
	for(i=0;i<n;i++)
	{
		printf("\n Enter elements of row %d: ",i+1);
	for(j=0;j<n;j++)
		scanf("%d",&a[i][j]);
	visited[i]=0;
	}
	printf("\n\nThe cost matrix is : ");
	for(i=0;i<n;i++)
	{
		printf("\n");
	for(j=0;j<n;j++)
		printf(" %d",a[i][j]);
	}
}
int least(int c)
{
	int i, nc=999;
	int min=999, kmin;
	for(i=0;i<n;i++)
	{
		if((a[c][i]!=0)&&(visited[i]==0)){
			if(a[c][i]<min)
			{
			min=a[i][0]+a[c][i];
			kmin=a[c][i];
			nc=i;
			}
		}
	}
	if(min!=999)
		cost=cost+kmin;
	return nc;
}
void mincost(int c)
{
	int i,nc;
	visited[c]=1;
	printf(" %d-->", c+1);
	nc=least(c);
	if(nc==999)
	{
		nc=0;
		printf("%d", nc+1);
		cost=cost+a[c][nc];
		return;
		
	}
	mincost(nc);

}

void put()
{
	printf("\n\nMinimum cost: ");
	printf("%d",cost);
}
int main()
{
	get();
	printf("\n\nThe required Traveling Salesmanpath is : \n ");
	mincost(0);
	put();
}

