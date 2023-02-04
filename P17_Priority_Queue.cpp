#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int Parent(int i){
    if(i%2==0)
    return(i/2)-1;

    else
    return (i/2);
}

int left(int i){
    return 2*i+1;
}
int right(int i){
    return 2*i+1;
}


void swap(int *a,int *b){
    int temp =*a;
    *a = *b;
    *b =temp;
}

void Max_Heapify(int a[],int n,int i)
{
 int largest=i;
 int l=2*i+1;
 int r=2*i+2;
 if (l<n &&a[l]>a[largest])
  largest=l;
 if (r<n && a[r]>a[largest])
  largest=r;
 if (largest !=i)
 {
  swap(&a[largest],&a[i]);
  Max_Heapify(a,n,largest);
 }
}
void Build_Maxheap(int arr[],int n){
    for(int i=(n/2)-1;i>=0;i--){
        Max_Heapify(arr,n,i);
    }
}

int Max(int arr[]){
    return arr[0];
}

int Extract_Max(int arr[],int l){
   
    if (l<1){
        cout<<"Underflow"<<endl;
    }

    int max=arr[0];
    arr[0]=arr[l];

    l=l-1;

   Max_Heapify(arr,l,0);
   
    return max;
}

void Increase_Key(int arr[],int i,int key){
    if(key<arr[i]){
        cout<<"Error"<<endl;
    }
    arr[i]=key;
    while(i>0 && arr[Parent(i)]<arr[i]){
        swap(&arr[i],&arr[Parent(i)]);
        i=Parent(i);
    }
}

void Insert(int arr[],int l,int key){
    
    l=l+1;
    arr[l-1]=INT_MIN;
    Increase_Key(arr,l,key);
}

 void heap_delete(int arr[],int i,int n)
    {
        if(arr[i]<arr[n-1])
        {
            Increase_Key(arr,i,arr[n-1]);
            n--;
        }
        else
        {
            arr[i]=arr[n-1];
            n--;
            Max_Heapify(arr,n,i);
        }
    }

int main(){
    cout<<"Enter size of array..."<<endl;
    int n;
     cin>>n;
    int arr[n];
    cout<<"Enter elements.."<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //1)Finding maximum element...
    
    // Build_Maxheap(arr,n);
    // cout<<"Maximum element is..."<<endl;
    // cout<<Max(arr)<<endl;

    //2)Extracting max heap...
    // cout<<"Extracting maximum element in heap..."<<endl;
    // Build_Maxheap(arr,n);
    // cout<<Extract_Max(arr,n)<<endl;
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }

    //3)Increase key...
    // cout<<"Increase key..."<<endl;
    // Enter size of array...
    // 9
    // Enter elements..
    // 16 14 10 8 7 9 3 2 4 1
    // Increase_Key(arr,8,15);
    //  for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }

    //4)Insert ...
    // cout<<"Inserting key"<<endl;
    // Insert(arr, 12,10);
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }

    //5)Delete...
    // cout<<"Deleting element..."<<endl;
    // heap_delete(arr,2,n);
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }   
}