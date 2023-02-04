#include<stdio.h>
#include<conio.h>
void bubble(int ar[],int n){
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(ar[j]>ar[j+1]){
				int temp=ar[j];
				ar[j]=ar[j+1];
				ar[j+1]=temp;
			}
		}
	}
}
int main()
{
	int i,j,n;
	int a[]={12,5,3,8,33,55};
	printf("Unsorted array is:\n");
	for(i=0;i<6;i++){
		printf("%d ",a[i]);
	}
	
	bubble(a,6);
	
	printf("\nSorted array is:\n");
	for(i=0;i<6;i++){
		printf("%d ",a[i]);
	}
	


return 0;}


// C++ code

// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// void display(int a[],int n)
// {
//     for(int i=0;i<n;i++)
//     {
//         cout<<a[i]<<" ";
//     }
// }


//  int main()
// {
//     int n;
//     cout<<"Enter the number of elements of the array: ";
//     cin>>n;
//      int a[n];
//      cout<<"Enter the elements of the array: ";
//      for(int i=0;i<n;i++)
//         cin>>a[i];
//      cout<<"bubble sort: ";
//      bubble(a,n);
//      display(a,n);
//      cout<<endl;
// }


