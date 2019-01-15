#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
bool sortcol( const vector<int>& v1,
               const vector<int>& v2 ) {
 return v1[1] < v2[1];
}
int main()
{

    vector< vector <int> > Process;

    int n,bt,at,i,j,sum_TAT=0,TAT,sum_WT=0,WT,ct=0;
    cout<<"Enter number of process: ";
    cin>>n;

    for(i=1;i<=n;i++)
    {
        vector<int> row;
        cout<<"Enter burst time for process "<<i<<" : ";
        cin>>bt;
        row.push_back(bt);
        cout<<"Enter arrival time for process "<<i<<" : ";
        cin>>at;
        row.push_back(at);
        row.push_back(i);
        Process.push_back(row);
    }
    cout<<endl;
    sort(Process.begin(), Process.end(),sortcol);
    cout<<"Process id\tArrival time\tBurst time\tCompletion Time\tTAT\tWT\n";
    for (i=0;i<n;i++)
    {
            for (j=2;j>=0;j--)
        {

                    cout << Process[i][j] << "\t\t";
            
            
        }
    ct = Process[i][0] + ct;
    TAT = ct - Process[i][1];
    WT = TAT - Process[i][0];
    sum_TAT = sum_TAT + TAT;
    sum_WT = sum_WT + WT;
    cout<<ct<<"\t\t"<<TAT<<"\t\t"<<WT;
    //temp_ct = ct;
        cout << endl;
    }

    cout<<endl<<"Average TAT: "<<sum_TAT/n;
    cout<<endl<<"Average WT: "<<sum_WT/n;
       

return 0;
}