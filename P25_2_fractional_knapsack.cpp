#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
//Greedy about only profit no matter bag will be full or not.
int main(){
    int len;
    double val,max_weight,max_profit=0.0;
    cout<<"Enter the number of items"<<endl;
    cin>>len;
    cout<<"Enter the maximum weight of bag"<<endl;
    cin>>max_weight;
    double profit[len],weight[len];
    cout<<"Enter the values of profit:"<<endl;
    for(int i=0;i<len;i++){
        cin>>profit[i];
    }
    cout<<"Enter the values of corresponding weights:"<<endl;
    for(int i=0;i<len;i++){
        cin>>weight[i];
    }
    for(int i=0;i<len-1;i++){
        for(int j=0;j<len-i-1;j++){
            if(profit[j]<profit[j+1]){
                double temp=profit[j];
                profit[j]=profit[j+1];
                profit[j+1]=temp;

                double temp1=weight[j];
                weight[j]=weight[j+1];
                weight[j+1]=temp1;
            }
        }
    }

    int i;
    for( i=0;i<len;i++){
        if(weight[i]< max_weight && max_weight>0){
            max_profit=max_profit+profit[i];
            max_weight=max_weight-weight[i];
        }
        else{
            break;
        }
    }
   if(max_weight>0){
        max_profit=max_profit+((profit[i]*max_weight)/weight[i]);
    }
    cout<<"\nThe max profit is:"<<max_profit<<endl;
    // cout<<"The remaining weight before partition of items is:"<<max_weight<<endl;
    return 0;
}