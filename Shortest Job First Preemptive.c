#include<stdio.h>
#include<stdlib.h>

typedef struct process{
	char name[5];
	int bt;
	int at;
	int wt,ta;
	int flag;
	int ct;
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
		
	}
	printf("\n PROC.\tB.T.\tA.T.");
	for(i=0;i<n;i++)
		printf("\n %s\t%d\t%d",P[i].name,P[i].bt,P[i].at);
	return n;
}


//Shortest Job First - Pre-emptive
void SJF_P(processes P[],int n){
	int i,t_total=0,tcurr,b[10],min_at,j,x,min_bt;
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
	for(tcurr=0;tcurr<t_total;tcurr++){

		if(b[i] > 0 && temp[i].at <= tcurr)
			b[i]--;

		if(i!=j)
			printf(" %d %s",tcurr,temp[i].name);

		if(b[i]<=0 && temp[i].flag != 1){
		
			temp[i].flag = 1;
			temp[i].wt = (tcurr+1) - temp[i].bt - temp[i].at;
			temp[i].ta = (tcurr+1) - temp[i].at;
			sumw+=temp[i].wt;
			sumt+=temp[i].ta;
		}
		j=i;	min_bt = 999;
		for(x=0;x<n;x++){
		
			if(temp[x].at <= (tcurr+1) && temp[x].flag != 1){
			
				if(min_bt != b[x] && min_bt > b[x]){
					min_bt = b[x];
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
	avgwt = (float)sumw/n;	avgta = (float)sumt/n;
	printf("\n\n Average waiting time = %0.2f\n Average turn-around = %0.2f.",avgwt,avgta);
}




int main(){
	
	processes P[10];
	int a;
	a=accept(P);
	SJF_P(P,a);
	return 0;
}
