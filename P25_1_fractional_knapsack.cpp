#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
//Greedy about both profit and weight--> so we have calculated profit/weight ratio in it.
int main(){
    int len;
    double val,max_weight,max_profit=0.0;
    cout<<"Enter the number of items"<<endl;
    cin>>len;
    cout<<"Enter the maximum weight of bag"<<endl;
    cin>>max_weight;
    double profit[len],weight[len],pwratio[len];
    int index[len];
    cout<<"Enter the values of profit:"<<endl;
    for(int i=0;i<len;i++){
        cin>>profit[i];
    }
    cout<<"Enter the values of corresponding weights:"<<endl;
    for(int i=0;i<len;i++){
        cin>>weight[i];
    }
    for(int i=0;i<len;i++){
       pwratio[i]=(profit[i]/weight[i]);
       index[i]=i;
    }
    // sort(pwratio.begin(), pwratio.end(), greater<int>());
    for(int i=0;i<len-1;i++){
        for(int j=0;j<len-i-1;j++){
            if(pwratio[j]<pwratio[j+1]){
                double temp=pwratio[j];
                pwratio[j]=pwratio[j+1];
                pwratio[j+1]=temp;

                int temp1= index[j];
                 index[j]= index[j+1];
                 index[j+1]=temp1;
            }
        }
    }

    cout<<"The pw ratio is:"<<endl;
    for(int i=0;i<len;i++){
       cout<<pwratio[i]<<" ";
    }
    cout<<endl;
    cout<<"The sorted indexes are:"<<endl;
    for(int i=0;i<len;i++){
       cout<<index[i]<<" ";
    }
    cout<<endl;
    
    int i;
    for( i=0;i<len;i++){
        if(weight[index[i]]< max_weight && max_weight>0){
            max_profit=max_profit+profit[index[i]];
            max_weight=max_weight-weight[index[i]];
        }
        else{
            break;
        }
    }
    if(max_weight>0){
        max_profit=max_profit+((profit[index[i]]*max_weight)/weight[index[i]]);
    }
    // cout<<"\n"<<i<<endl;
    // cout<<"\nThe maximum weight is:"<<max_weight<<endl;
    cout<<"The max profit is:"<<max_profit<<endl;
    return 0;
}