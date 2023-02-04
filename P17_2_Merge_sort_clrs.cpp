#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
using namespace std;
void merge(int a[],int l,int m,int r)
{
    int n1=m-l+1;
    int n2=r-m;
    int l1[n1];
    int r1[n2];
    for(int i=0;i<n1;++i)
         l1[i]=a[l+i];
    for(int i=0;i<n2;++i)
       r1[i]=a[m+i+1];

    l1[n1]=INT_MAX;
    r1[n2]=INT16_MAX;              
    int i=0;
    int j=0;
    for(int k=l;k<=r;k++)
         {
            if(l1[i]<=r1[j])
            {
                a[k]=l1[i];
                i++;
            }
            else
            {
               a[k]=r1[j];
               j++;
            }
         }
    
}
void merge_sort(int a[],int p,int r)
{
    if(p<r)
    {
        int q=(p+r)/2;
        merge_sort(a,p,q);
        merge_sort(a,q+1,r);
        merge(a,p,q,r);
    }
}
int main(void)
{
    int n;
    cout<<"Enter the number of elements of the array : ";
    cin>>n;
    int a[n];
    cout<<"Enter the number of elements of the array  : ";
    for(int i=0;i<n;++i)
        cin>>a[i];
    cout<<"After applying merge sort in it: ";
    merge_sort(a,0,n-1);
    for(auto it:a)
       cout<<it<<" ";
}