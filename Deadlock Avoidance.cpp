#include<iostream>
#include<conio.h>
#include<string>

using namespace std;

int main()
{
int n,x,y;
cout<<"enter the no. of process"<<endl;
cin>>n;
cout<<"enter the resources of A"<<endl;
cin>>x;
cout<<"enter the resources of B"<<endl;
cin>>y;
int a[5][2],M[5][2], N[5][2], b[1][2],q=0,w=0,f[5],h=0,j=0;
int count1=0;
cout<<"enter the allocated resources to the process"<<endl;
for(int i=0;i<n;i++)
{
    for(int j=0;j<2;j++)
    {

        cin>>a[i][j];
    }
}

cout<<"enter the max resources to the process"<<endl;
for(int i=0;i<n;i++)
{
    for(int j=0;j<2;j++)
    {

        cin>>M[i][j];
    }
}

cout<<"now calculating the need matrix"<<endl;
for(int i=0;i<n;i++)
{
    for(int j=0;j<2;j++)
    {
N[i][j]=M[i][j] - a[i][j];
cout<<N[i][j]<<endl;
    }
}
cout<<"finding the available matrix"<<endl;
for(int i=0;i<n;i++)
{
    for(int j=0;j<2;j++)
    {
     if(j==0)
     {
         q=a[i][j]+q;
     }
     else
     {
         w=a[i][j]+w;
     }
    }
}
b[0][0]=x-q;
b[0][1]=y-w;
cout<<b[0][0]<<" " <<b[0][1]<<endl;
for(int i=0;i<10;i++)
{

if(count1==n-1)
{
    break;

}
j=0;
if(b[0][0]>N[i][j])
{
    if(b[0][1]>N[i][j+1])
    {
        f[h]=i;
        b[0][0]=a[i][j]+b[0][0];
        b[0][1]=a[i][j]+b[0][1];
        h++;
        count1;
    }
}
}
for(int i=0;i<n;i++)
{
    cout<<f[i]<<endl;

}


return 0;
}

