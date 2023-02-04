
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int parent(int i)
{
    return (i-2)/2;
}
int left(int i)
{
    return 2*i+1;
}
int right(int i)
{
    return 2*i+2;
}
void heapify(int a[],int n,int i)
{
    int largest=i;
    int l=left(i);
    int r=right(i);
    if(l<n && a[l]>a[largest])largest=l;
    if(r<n && a[r]>a[largest])largest=r;
    if(largest!=i)
    {
        swap(a[i],a[largest]);
        heapify(a,n,largest);
    }
}
void build_max_heap(int a[],int n)
{
    for(int i=n/2;i>=0;i--)
        heapify(a,n,i);
}
void heapsort(int a[],int n)
{
    build_max_heap(a,n);
    for(int i=n-1;i>=0;i--)
        {
            swap(a[0],a[i]);
            n=n-1;
            heapify(a,n,0);
        }
}
int main(void)
{
    int n;
    cout<<"Enter the number of elements of the array: ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    heapsort(a,n);
    for(auto it:a)
       cout<<it<<" ";
}

// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;
// void heapify(int arr[],int n,int i)
// {
//  int largest=i;
//  int l=2*i+1;
//  int r=2*i+2;
//  if (l<n &&arr[l]>arr[largest])
//   largest=l;
//  if (r<n && arr[r]>arr[largest])
//   largest=r;
//  if (largest !=i)
//  {
//   swap(arr[largest],arr[i]);
//   heapify(arr,n,largest);
//  }
// }

// void heapsort(int arr[], int n)
// {
//  for (int i=n/2-1;i>=0;i--)
//   heapify(arr, n, i);
//  for (int i=n-1;i>=0;i--)
//  {
//   swap(arr[0], arr[i]);
//   heapify(arr, i, 0);
//  }
// }
// int main()
// {
// cout<<"Enter size of array:"<<endl;
//  int n;
//  cin >> n;
//  int arr[n];
//  for (int i = 0; i < n; i++)
//   cin >> arr[i];
//  heapsort(arr, n);
//  cout<<"Sorted array is:"<<endl;
//  for (int i = 0; i < n; i++)
//   cout << arr[i] << " ";
// }