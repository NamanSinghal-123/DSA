#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int matrixchain(int arr[], int n)
{
    int m[n][n];
 
    int i,j,k,l,q;
    for (i=1;i<n;i++)
        m[i][i] = 0;
 
    for (l=2;l<n;l++)
    {
        for (i=1;i<n-l+1;i++)
        {
            j=i+l-1;
            m[i][j]=INT_MAX;
            for(k=i;k<=j-1;k++)
            {
                q=m[i][k]+m[k+1][j]+arr[i-1]*arr[k]*arr[j];
                if (q<m[i][j])
                    m[i][j]=q;
            }
        }
    }
    for( int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(j>=i){
                cout<<m[i][j]<<"  ";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
 
    return m[1][n - 1];
}

int main(){
    int n;
    cout<<"Enter the elements you want in order array input?"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int x=matrixchain(arr,n);
    cout<<"The number of scaler multiplications are:"<<x;
}
// Enter the elements you want in order array input?
// 7
// Enter the elements:
// 30 35 15 5 10 20 25
// The number of scaler multiplications are:
// 0      15750      7875      9375      11875      15125
//       0      2625      4375      7125      10500      
//             0      750      2500      5375
//                   0      1000      3500
//                         0      5000
//                               0      
// 15125