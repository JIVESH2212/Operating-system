#include<stdio.h>
#include<stdlib.h>

typedef struct process{
	char name[5];
	int bt,bt1;
	int at;
	int ct;
	int wt,ta;
	int flag;
}processes;


void b_sort(processes temp[],int n)
{
	processes t;
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n-i;j++){
			if(temp[j].at > temp[j+1].at){
				t = temp[j];
				temp[j] = temp[j+1];
				temp[j+1] = t;
			}
		}
}

int accept(processes P[]){
	int i,n;
	printf("\n Enter total no. of processes : ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("\n PROCESS [%d]",i+1);
		printf(" Enter process name : ");
		scanf("%s",&P[i].name);
		printf(" Enter burst time : ");
		scanf("%d",&P[i].bt);
		P[i].bt1=P[i].bt;
		printf(" Enter arrival time : ");
		scanf("%d",&P[i].at);
		
	}
	printf("\n PROC.\tB.T.\tA.T.");
	for(i=0;i<n;i++)
		printf("\n %s\t%d\t%d",P[i].name,P[i].bt,P[i].at);
	return n;
}
//Round Robin Scheduling
void RR(processes P[],int n)
{
	int pflag=0,t,tcurr=0,k,i,Q=0;
	int sumw=0,sumt=0;
	float avgwt=0.0,avgta=0.0;
	processes temp1[10],temp2[10];	

	for(i=0;i<n;i++)
		temp1[i]=P[i];

	b_sort(temp1,n);
	
	for(i=0;i<n;i++)
		temp2[i]=temp1[i];
	
	printf("\n Enter quantum time : ");
	scanf("%d",&Q);
	
	for(k=0;;k++){
		if(k>n-1)
			k=0;
		if(temp1[k].bt>0)
			printf("  %d  %s",tcurr,temp1[k].name);
		t=0;
		while(t<Q && temp1[k].bt > 0){
			t++;
			tcurr++;
			temp1[k].bt--;
		}  
		if(temp1[k].bt <= 0 && temp1[k].flag != 1){
			temp1[k].wt = tcurr - temp2[k].bt - temp1[k].at;
			temp1[k].ta = tcurr - temp1[k].at;
			pflag++;
			temp1[k].flag = 1;
			sumw+=temp1[k].wt;
			sumt+=temp1[k].ta;
		}
		temp1[k].ct=tcurr;
		if(pflag == n)
			break;
	}
	printf("  %d",tcurr);
	printf("\n\n PROC.\tB.T.\tA.T.\tC.T\tW.T\tT.A.T");
		for(i=0;i<n;i++)
			printf("\n %s\t%d\t%d\t%d\t%d\t%d",temp1[i].name,temp1[i].bt1,temp1[i].at,temp1[i].ct,temp1[i].wt,temp1[i].ta);
	avgwt = (float)sumw/n;
	avgta = (float)sumt/n;
	printf("\n\n Average waiting time = %0.2f\n Average turn-around = %0.2f.",avgwt,avgta);
}

int main(){
	
	processes P[10];
	int a;
	a=accept(P);
	RR(P,a);
	return 0;
}

