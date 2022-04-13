#include <stdio.h>

void merge(int a[],int l,int mid,int h)
{
	int i=l,j=mid+1,k=0;
	int b[h-l+1];
	while(i<=mid && j<=h)
	{
		if(a[i]<a[j])
			b[k++]=a[i++];
		else
			b[k++]=a[j++];
	}
	while(i<=mid)
	{
		b[k++]=a[i++];
	}
	while(j<=h)
	{
		b[k++]=a[j++];
	}
	int y=0;
	for(int x=l;x<=h;x++)
	{
		a[x]=b[y];
		y++;
	}
}

void mergesort(int a[],int l,int h)
{
	if(l<h)
	{
		int mid=(l+h)/2;
		mergesort(a,l,mid);
		mergesort(a,mid+1,h);
		merge(a,l,mid,h);
	}
}

int main()
{
	int n,i,c=0;
	printf("ENter the no. of elements of the arary\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements of the array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	mergesort(a,0,n-1);
	
	for(i=0;i<n;i++)
	{
		if(a[i]==a[i+1])
		{
			c++;
		}
	}
	
	if(c>=1)
		printf("\nYes");
	else
		printf("\nNo");
	return 0;
	
	
}
