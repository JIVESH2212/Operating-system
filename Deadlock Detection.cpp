//BANKERS ALGORITHM
#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
int p[5],a[5],b[5],c[5],ma[5],mb[5],mc[5],na[5],nb[5],nc[5];
int i,j;
for(i=0,j=1;i<=5;i++,j++)
{
p[i]=j;}
cout<<"ENTER THE ALLOCATED RESOURCES FOR PROCESS 1-5"<<"\n";
for(i=0;i<5;i++)
{
  cin>>a[i]>>b[i]>>c[i];
cout<<"\n";	
}
cout<<"ENTER MAX REQUIRED RSOURCES"<<"\n";
for(i=0;i<5;i++)
{
cin>>ma[i]>>mb[i]>>mc[i];
cout<<"\n";
}
for(i=0;i<5;i++)
{
na[i]=ma[i]-a[i];
nb[i]=mb[i]-b[i];
nc[i]=mc[i]-c[i];
}
cout<<"ENTER AVAILABLE RESOURCES"<<"\n";
int a1,b1,c1,s,d,f,s1,d1,f1,g1;
cin>>a1>>b1>>c1;
cout<<"\n";
for(i=0;i<5;i++)
{
for(j=1+i;j<5;j++)
{
if(na[i]>na[j])
{
s1=p[i];
d1=a[i];
f1=b[i];
g1=c[i];
s=na[i];
d=nb[i];
f=nc[i];
na[i]=na[j];
nb[i]=nb[j];
nc[i]=nc[j];
p[i]=p[j];
a[i]=a[j];
b[i]=b[j];
c[i]=c[j];
na[j]=s;
nb[j]=d;
nc[j]=f;
p[j]=s1;
a[j]=d1;
b[j]=f1;
c[j]=g1;


}}}

for(i=0;i<5;i++)
{
if(a1>=na[i]&&b1>=nb[i]&&c1>=nc[i])
{
cout<<"Process  "<<p[i]<<"\n";
a1=a1+a[i];
b1=b1+b[i];
c1=c1+c[i];

}}

    
}
























