# include <stdio.h>

int main()
{
	int n,i,j,key,c=0,w=0;
	printf("Enter the no. of elements in the array\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements of the array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		key=a[i];
		for(j=i-1;j>=0;j--)
		{
			c++;
			if(key<a[j])
			{
				w++;
				a[j+1]=a[j];
			}
			else
				break;
		}
		a[j+1]=key;
	}
	printf("Sorted array:-\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\nno. of comparisons : %d",c);
	printf("\nno. of writes : %d",w);
	return 0;
}
