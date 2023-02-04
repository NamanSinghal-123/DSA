#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int matrixchainrecursion(int arr[], int i, int j)
{
    if(i==j)
    return 0;

    int k;
    int minimum_scaler =INT_MAX;
    int q;
 
    for (k=i;k<j;k++)
    {
        q = matrixchainrecursion(arr,i,k)+ matrixchainrecursion(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
        if (q<minimum_scaler){
            minimum_scaler=q;
       }
    }
    return minimum_scaler;
}
// Enter the elements you want in order array input?
// 5
// Enter the elements:
// 10 5 20 10 5
// The number of scaler multiplications are:
// 1500

int main(){
    int n;
    cout<<"Enter the elements you want in order array input?"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"The number of scaler multiplications are:\n"<<matrixchainrecursion(arr,1,n-1);
}