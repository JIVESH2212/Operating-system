#include<stdio.h>
#include<stdlib.h>

typedef struct process{
	char name[5];
	int bt;
	int at;
	int ct;
	int prt;
	int wt,ta;
	int flag;
}processes;


void b_sort(processes temp[],int n)
{
	processes t;
	int i,j;
	for(i=1;i<n;i++)
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
		printf(" Enter arrival time : ");
		scanf("%d",&P[i].at);
		printf(" Enter priority : ");
		scanf("%d",&P[i].prt);
	}
	printf("\n PROC.\tB.T.\tA.T.\tPRIORITY");
	for(i=0;i<n;i++)
		printf("\n %s\t%d\t%d\t%d",P[i].name,P[i].bt,P[i].at,P[i].prt);
	return n;
}
//Priority Non Pre-emptive
void PRT_NP(processes P[],int n)
{
	processes temp[10];
	processes t;
	int sumw=0,sumt=0;
	float avgwt=0.0,avgta=0.0;
	int i,j;
	int x = 0;

	for(i=0;i<n;i++)
		temp[i]=P[i];

	b_sort(temp,n);

	for(i=2;i<n;i++)
		for(j=1;j<n-i+1;j++){
			if(temp[j].prt > temp[j+1].prt){
				t = temp[j];
				temp[j] = temp[j+1];
				temp[j+1] = t;
			}
		}

	printf("\n\n PROC.\tB.T.\tA.T.\tPRIORITY");
		for(i=0;i<n;i++)
			printf("\n %s\t%d\t%d\t%d",temp[i].name,temp[i].bt,temp[i].at,temp[i].prt);

		sumw = temp[0].wt = 0;
		sumt = temp[0].ta = temp[0].bt - temp[0].at;

		for(i=1;i<n;i++){
			temp[i].wt = (temp[i-1].bt + temp[i-1].at + temp[i-1].wt) - temp[i].at;;
			temp[i].ta = (temp[i].wt + temp[i].bt);
			sumw+=temp[i].wt;
			sumt+=temp[i].ta;
		}
		avgwt = (float)sumw/n;
		avgta = (float)sumt/n;
		/*printf("\n\n PROC.\tB.T.\tA.T.\tW.T\tT.A.T");
		for(i=0;i<n;i++)
			printf("\n %s\t%d\t%d\t%d\t%d",temp[i].name,temp[i].bt,temp[i].at,temp[i].wt,temp[i].ta);*/
		
		printf("\n\n GANTT CHART\n ");
		for(i=0;i<n;i++)
			printf("   %s   ",temp[i].name);
		printf("\n ");

		printf("0\t");
		for(i=1;i<=n;i++){
			x+=temp[i-1].bt;
			printf("%d      ",x);
			temp[i-1].ct=x;
		}
		
		printf("\n\n PROC.\tB.T.\tA.T.\tC.T.\tW.T\tT.A.T");
		for(i=0;i<n;i++)
			printf("\n %s\t%d\t%d\t%d\t%d\t%d",temp[i].name,temp[i].bt,temp[i].at,temp[i].ct,temp[i].wt,temp[i].ta);
		printf("\n\n Average waiting time = %0.2f\n Average turn-around = %0.2f.",avgwt,avgta);
}
//Priority Pre-emptive

void PRT_P(processes P[],int n){
	int i,t_total=0,tcurr,b[10],j,x,min_pr;
	int sumw=0,sumt=0;
	float avgwt=0.0,avgta=0.0;
	processes temp[10],t;

	for(i=0;i<n;i++){
		temp[i]=P[i];
		t_total+=P[i].bt;
	}

	b_sort(temp,n);

	for(i=0;i<n;i++)
		b[i] = temp[i].bt;

	i=j=0;
	printf("\n GANTT CHART\n\n %d %s",i,temp[i].name);
	for(tcurr=0;tcurr<t_total;tcurr++)
	{

		if(b[i] > 0 && temp[i].at <= tcurr)
			b[i]--;

		if(i!=j)
			printf(" %d %s",tcurr,temp[i].name);

		if(b[i]<=0 && temp[i].flag != 1)
		{
			temp[i].flag = 1;
			temp[i].wt = (tcurr+1) - temp[i].bt - temp[i].at;
			temp[i].ta = (tcurr+1) - temp[i].at;
			sumw+=temp[i].wt;
			sumt+=temp[i].ta;
		}
		j=i;
		min_pr = 999;
		for(x=0;x<n;x++){
	
			if(temp[x].at <= (tcurr+1) && temp[x].flag != 1){
			
				if(min_pr != temp[x].prt && min_pr > temp[x].prt){
					min_pr = temp[x].prt;
					i=x;
				}
			}
		}
		temp[i].ct=tcurr;
		
	}
	printf(" %d",tcurr);
	printf("\n\n PROC.\tB.T.\tA.T.\tC.T\tW.T\tT.A.T");
		for(i=0;i<n;i++)
			printf("\n %s\t%d\t%d\t%d\t%d\t%d",temp[i].name,temp[i].bt,temp[i].at,temp[i].ct,temp[i].wt,temp[i].ta);
	avgwt = (float)sumw/n;
	avgta = (float)sumt/n;
	printf("\n\n Average waiting time = %0.2f\n Average turn-around = %0.2f.",avgwt,avgta);
}


int main(){
	
	processes P[10];
	int ch,n;
	do{
		printf("\n Options:");
		printf("\n 1. Enter process data.");
		printf("\n 2. Priority Scheduling (Pre-emptive)");
		printf("\n 3. Priority Scheduling (Non Pre-emptive)");
		printf("\n 4. Exit\n Select : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				n=accept(P);
				break;
			case 2:
				PRT_P(P,n);
				break;
			case 3:
				PRT_NP(P,n);
				break;
			case 4:exit(0);	
		}
	}while(1);
	
	return 0;
}
