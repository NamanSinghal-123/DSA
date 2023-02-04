#include<stdio.h>
void insertion(int ar[],int n){
	int i,j;
	for(i=1;i<n;i++){
		int temp=ar[i];
		j=i-1;
		while(j>=0 && ar[j]>temp){
			ar[j+1]=ar[j];
			j--;
		}
		ar[j+1]=temp;
	}
}
int main(){
	int i,j,n;
	int a[n];
	printf("enter the size of array\n");
	scanf("%d",&n);
	printf("enter the elements of array\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	insertion(a,n);
	printf("elements of sorted array\n");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	
	return 0;
}

// Java code
// class Insertion_selection
// {
//     public static void main(String args[])
//     {
//         int arr[]={1,6,3,9,5,8,2,4,7,10};
//         //Insertion Sort
//         int j;int temp;
//         for(int i=1;i<arr.length;i++)
//         {
//             j=i-1;
//             temp=arr[i];
//             while(j>0 && arr[j]>temp)
//             {
//                 arr[j+1]=arr[j];
//                 j--;
//             }
//             arr[j+1]=temp;
//         }


//        // Selection sort
//         int min;
//         for(int i=0;i<arr.length-1;i++)
//         {
//             min=i;
//             for(int j=i+1;j<arr.length;j++)
//             {
//                 if(arr[j]<arr[min])
//                 min=j;
//             }
//             if(min!=i)
//             {
//                 int temp=arr[i];
//                 arr[i]=arr[min];
//                 arr[min]=temp;
//             }
//         }

//         //Bubble Sort
//         for(int i=0;i<arr.length-1;i++)
//         {
//             for(int j=0;j<arr.length-i-1;j++)
//             {
//                 if(arr[j]>arr[j+1])
//                 {
//                     int tmp=arr[j];
//                     arr[j]=arr[j+1];
//                     arr[j+1]=tmp;
//                 }
//             }
//         }
        
//         for(int i=0;i<arr.length;i++)
//         {
//             System.out.print(arr[i]+" ");
//         }
//     }
// }

// C++ code
// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// void insertion(int a[],int n)
// {
//     for(int j=1;j<n;j++)
//     {
//         int key=a[j];
//         int i=j-1;
//         while(i>=0 && a[i]>=key)
//         {
//             a[i+1]=a[i];
//             i--;
//         }
//         a[i+1]=key;
//     }
// }
// void selection(int a[],int n)
// {
//       int i=0;
//       int min_index;
//       for(int i=0;i<n-1;i++)
//       {
//         min_index=i;
//         for(int j=i+1;j<n;j++)
//         {
//             if(a[j]<a[min_index])
//             {
//                 min_index=j;
//             }
             
//         }
        
        
//         if(min_index!=i)swap(a[min_index],a[i]);        
//       }
// }
// void display(int a[],int n)
// {
//     for(int i=0;i<n;i++)
//     {
//         cout<<a[i]<<" ";
//     }
// }
// int main()
// {
//     int n;
//     cout<<"Enter the number of elements of the array: ";
//     cin>>n;
//      int a[n];
//      cout<<"Enter the elements of the array: ";
//      for(int i=0;i<n;i++)
//         cin>>a[i];
//      cout<<"insertion sort: ";
//      insertion(a,n);
//      display(a,n);
//      cout<<endl;
//      cout<<" selection sort: ";
//      selection(a,n);
//      cout<<endl;
//      display(a,n);
// }