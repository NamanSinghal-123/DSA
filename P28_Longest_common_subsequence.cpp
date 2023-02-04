#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void LCS_Length(string s1,string s2)
    {
        int m=s1.length();
        int n=s2.length();
        int c[m+1][n+1];
        string b[m+1][n+1];

        for(int i=0;i<=m;i++)
        for(int j=0;j<=n;j++)
        b[i][j]=" ";

        for(int i=0;i<=m;i++)
        {
            c[i][0]=0;
        }
        for(int j=0;j<=n;j++)
        {
            c[0][j]=0;
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    c[i][j]=c[i-1][j-1]+1;
                    b[i][j]="↖";
                }
                else if(c[i-1][j]>=c[i][j-1])
                {
                    c[i][j]=c[i-1][j];
                    b[i][j]="↑";
                }
                else
                {
                    c[i][j]=c[i][j-1];
                    b[i][j]="←";
                }
            }
        }
            for(int i=0;i<=m;i++)
            {
                for(int j=0;j<=n;j++)
                {
                    cout<<c[i][j]<<b[i][j]<<"  ";
                }
                cout<<endl;
            }
            cout<<"The lenght of the longest commom subsequnce : ";
            cout<<c[m][n]<<" ";
        
}

int main(){
    string s1;
    cout<<"Enter the string 1:"<<endl;
    cin>>s1;
    string s2;
    cout<<"Enter the string 2:"<<endl;
    cin>>s2;
    LCS_Length(s1, s2);
}
// Enter the string 1
// ABCBDAB
// Enter the string 1
// BDCABA
