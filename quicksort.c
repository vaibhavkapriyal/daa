#include <stdio.h>

void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int partition(int a[],int l,int h)
{
	int j,x,i;
	x=a[h];
	i=l-1;
	for(j=l;j<=h-1;j++)
	{
		if(a[j]<=x)
		{
			i=i+1;
			swap(&a[j],&a[i]);
		}
	}
	swap(&a[i+1],&a[h]);
	return i+1;
}

void quicksort(int a[],int l,int h)
{
	if(l<h)
	{
		int index=partition(a,l,h);
		quicksort(a,l,index-1);
		quicksort(a,index+1,h);
	}
}

int main()
{
	int n,i;
	printf("ENter the no. of elements of the arary\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements of the array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	quicksort(a,0,n-1);
	printf("Sorted Array:- \n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
