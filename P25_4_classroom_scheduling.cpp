// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// void sorting(double arr[], int l){
//     for(int i=0;i<l-1;i++){
//         for(int j=0;j<l-i-1;j++){
//             if(arr[j]>arr[j+1]){
//                 double temp=arr[j];
//                 arr[j]=arr[j+1];
//                 arr[j+1]=temp;
//             }
//         }
//     }
// }

// int main(){
//     int no_of_classes;
//     cout<<"Enter the no. of classes today:"<<endl;
//     cin>>no_of_classes;
//     int len=2*no_of_classes;
//     int arr_start[len],arr_end[len];
//     cout<<"Enter the start times of every of every class in 24hr format:"<<endl;
//     for(int i=0;i<len;i++){
//         cout<<"Enter hours of class"<<i+1<<endl;
//         cin>>arr_start[i];
//         // cout<<":";
//         i++;
//         cout<<"Enter minutes of class"<<i<<endl;
//         cin>>arr_start[i];
//     }

//     cout<<endl;

//     cout<<"Enter the end times of every of every class in 24hr format:"<<endl;
//     for(int i=0;i<len;i++){
//         cout<<"Enter hours of class"<<i+1<<endl;
//         cin>>arr_end[i];
//         // cout<<":";
//         i++;
//         cout<<"Enter minutes of class"<<i<<endl;
//         cin>>arr_end[i];
//     }

//     cout<<"Start times of every of every class in 24hr format:"<<endl;
//     for(int i=0;i<len;i++){
//         cout<<arr_start[i];
//         cout<<":";
//         i++;
//         cout<<arr_start[i];
//         cout<<"  ";
//     }
//     cout<<endl;
//     cout<<"End times of every of every class in 24hr format:"<<endl;
//     for(int i=0;i<len;i++){
//         cout<<arr_end[i];
//         cout<<":";
//         i++;
//         cout<<arr_end[i];
//         cout<<"  ";
//     }

//     int l=len/2;
//     double start_time[l],end_time[l];
//     for(int i=0;i<l;i++){
//         start_time[i]=arr_start[i]+((arr_start[i+1]/60));
//     }
//     for(int i=0;i<l;i++){
//         end_time[i]=arr_end[i]+((arr_end[i+1]/60));
//     }


//     //continued!!!!!
//      sorting(start_time,l);
//      sorting(end_time,l);


    


//     return 0;
// }
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
        cout<<("Enter the number of classes")<<endl;
        cin>>n;
        int st_time[n];
        int end_time[n];
        string clas[n];

        cout<<("Enter the name of the classes")<<endl;
        for(int i=0;i<n;i++)
        {
            cin>>clas[i];
        }
        cout<<("Enter the start and end timings of the classes")<<endl;
        for(int i=0;i<n;i++)
        {
            cin>>st_time[i];
            cin>>end_time[i];
        }

        string order="";

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                if(end_time[j]>end_time[j+1])
                {
                    int temp1=end_time[j];
                    end_time[j]=end_time[j+1];
                    end_time[j+1]=temp1;

                    temp1=st_time[j];
                    st_time[j]=st_time[j+1];
                    st_time[j+1]=temp1;

                    string temp2=clas[j];
                    clas[j]=clas[j+1];
                    clas[j+1]=temp2;
                }
            }
        }
        order=order+clas[0]+" ";
        int temp=0;
        for(int i=1;i<n;i++)
        {
            if(end_time[temp]<=st_time[i])
            {
                order=order+clas[i]+" ";
                temp=i;
            }
            else
            {
                continue;
            }
        }
        cout<<"The order of classes = "+order<<endl;
}