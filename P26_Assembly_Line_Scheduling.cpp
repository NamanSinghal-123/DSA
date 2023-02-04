// #include <iostream>
// using namespace std;
// #define n 6

// int assembly_line(int process_time[][n], int transfer_time[][n], int *entry, int *exit)
// {
//     int time1[n],time2[n], i;

//     time1[0]= entry[0]+process_time[0][0];
//     time2[0]= entry[1]+process_time[1][0];

//     for (i=1;i<n;i++)
//     {
//         time1[i]=min(time1[i-1]+process_time[0][i], time2[i-1]+transfer_time[1][i]+process_time[0][i]);
//         time2[i]=min(time2[i-1]+process_time[1][i], time1[i-1]+transfer_time[0][i]+process_time[1][i]);
//     }
//     return min(time1[n-1] +exit[0], time2[n-1]+ exit[1]);
// }

// int main()
// {
//     int process_time[][n] = {{7,9,3,4,8,4}, {8,5,6,4,5,7}};
//     int transfer_time[][n] = {{0,2,3,1,3,4}, {0,2,1,2,2,1}};
//     int entry[] = {2, 4};
//     int exit[] = {3, 4};

//     cout << "The minimum time taken is: " << assembly_line(process_time, transfer_time, entry, exit);

//     return 0;
// }
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define n 6
vector<int> l1(n);
vector<int> l2(n);
vector<int> f1(n);
vector<int> f2(n);
void als(int a[2][n], int t[2][n - 1], int e[], int x[])
{
    f1[0] = e[0] + a[0][0];
    f2[0] = e[1] + a[1][0];
    for (int i = 1; i < n; ++i)
    {
        if (f1[i - 1] + a[0][i] <= f2[i - 1] + t[1][i - 1] + a[0][i])
        {
            f1[i] = f1[i - 1] + a[0][i];
            l1[i] = 1;
        }
        else
        {
            f1[i] = f2[i - 1] + t[1][i - 1] + a[0][i];
            l1[i] = 2;
        }
        if (f2[i - 1] + a[1][i] <= f1[i - 1] + t[0][i - 1] + a[1][i])
        {
            f2[i] = f2[i - 1] + a[1][i];
            l2[i] = 2;
        }
        else
        {
            f2[i] = f1[i - 1] + t[0][i - 1] + a[1][i];
            l2[i] = 1;
        }
    }
    if (f1[n - 1] + x[0] <= f2[n - 1] + x[1])
    {
        int x1 = f1[n - 1] + x[0];
        int l3 = 1;
        cout << x1 << " " << l3 << endl;
    }
    else
    {
        int y = f2[n - 1] + x[1];
        int l4 = 2;
        cout << y << " " << l4 << endl;
    }
}
int main(void)
{
    int e[2];
    cout << "Enter the entry time respectively: ";
    for (int i = 0; i < 2; ++i)
    {

        cin >> e[i]; // 2,4
    }
    int x[2];
    cout << "Enter the exit time respectively: ";
    for (int i = 0; i < 2; ++i)
    {

        cin >> x[i]; // 3,2
    }
    int a[2][n];
    cout << "Enter the time at each respective station:"<<endl;
    for (int i = 0; i < 2; ++i)
    {
        cout << "Enter the processing time on station" << i+1 << ":" << endl;
        for (int j = 0; j < n; ++j)
        {
            //{7, 9, 3, 4, 8, 4};
            //{8, 5, 6, 4, 5, 7};
            cin >> a[i][j];
        }
    }
    int t[2][n - 1];
    cout << "Enter the transportation respectively: " << endl;
    for (int i = 0; i < 2; ++i)
    {
        cout << "Enter the transportation time on station" << i+1 << ":" << endl;
        for (int j = 0; j < n - 1; ++j)
        {

            cin >> t[i][j]; // 2,3,1,3,4
                            // 2 1 2 2 1
        }
    }
    cout << "The mininum time and station number is:";
    als(a, t, e, x);
    cout << endl;

    cout << "The minimum time on every station of station 1 is:";
    cout << endl;
    for (auto it : f1)
        cout << it << " ";
    cout << endl;

    cout << "The minimum time on every station of station 2 is:";
    cout << endl;
    for (auto it : f2)
        cout << it << " ";
    cout << endl;
    cout << "The path followed on the station 1: ";
    cout << endl;
    for (auto it : l1)
        cout << it << " ";
    cout << endl;
    cout << "The fastest way on the station 2: ";
    cout << endl;
    for (auto it : l2)
        cout << it << " ";
    cout << endl;
}