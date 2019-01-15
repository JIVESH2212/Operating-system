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



//SJF Non Pre-emptive
void SJF_NP(processes P[],int n){
	processes temp[10];
	processes t;
	int sumw=0,sumt=0;
	int x = 0;
	float avgwt=0.0,avgta=0.0;
	int i,j;
	

	for(i=0;i<n;i++)
		temp[i]=P[i];

	b_sort(temp,n);

	for(i=2;i<n;i++)
		for(j=1;j<n-i+1;j++){
			if(temp[j].bt > temp[j+1].bt){
				t = temp[j];
				temp[j] = temp[j+1];
				temp[j+1] = t;
			}
		}

	printf("\n\n PROC.\tB.T.\tA.T.");
		for(i=0;i<n;i++)
			printf("\n %s\t%d\t%d",temp[i].name,temp[i].bt,temp[i].at);

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
		
		printf("\n\n PROC.\tB.T.\tA.T.\tC.T\tW.T\tT.A.T");
		for(i=0;i<n;i++)
			printf("\n %s\t%d\t%d\t%d\t%d\t%d",temp[i].name,temp[i].bt,temp[i].at,temp[i].ct,temp[i].wt,temp[i].ta);
		printf("\n\n Average waiting time = %0.2f\n Average turn-around = %0.2f.",avgwt,avgta);
}

int main(){
	
	processes P[10];
	int a;
	a=accept(P);
	SJF_NP(P,a);
	return 0;
}
