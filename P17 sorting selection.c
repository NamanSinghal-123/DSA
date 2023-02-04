#include<stdio.h>
void selection(int ar[],int n){
	int i,j;
	
	for(i=0;i<n-1;i++){
		int min=i;
		for(j=i+1;j<n;j++){
			if(ar[j]<ar[min]){
				min=j;
			}
			int temp=ar[i];
			ar[i]=ar[min];
			ar[min]=temp;
		}
	}
}
int main()
{
	
	int i,j,n;
	int a[n];
	printf("enter size of array\n");
	scanf("%d",&n);
	printf("enter elements of array\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	selection(a,n);
	printf("array after sorting is");
	for( i=0;i<n;i++)
	{
		printf(" %d",a[i]);
	}
}

