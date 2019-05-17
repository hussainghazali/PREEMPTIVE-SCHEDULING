#include<stdio.h> 
#include<bits/stdc++.h>
#include<iostream>
#include<WINDOWS.H>
#include<time.h>
#include<cstdlib>
#include<fstream>
#include<iomanip>

using namespace std;
 
void Preemptive_Priority_Scheduling()
{
      int burst_time[20], process[20], waiting_time[20], turnaround_time[20], priority[20];
      int i, j, limit, sum = 0, position, temp,check=0;
      float average_wait_time, average_turnaround_time;
      printf("Enter Total Number of Processes:\t");
      scanf("%d", &limit);
      for(i = 0; i < limit; i++)
      {
            burst_time[i]= rand() %10 +1;
		 priority[i]= rand() %limit+2;
            check= priority[i];
			if(priority[i-1]==check)
			{
				priority[i] +=1;
			}
            process[i] = i + 1;
      }
      for(i = 0; i < limit; i++)
      {
            position = i;
            for(j = i + 1; j < limit; j++)
            {
                  if(priority[j] < priority[position])
                  {
                        position = j;
                  }
            }
            temp = priority[i];
            priority[i] = priority[position];
            priority[position] = temp; 
            temp = burst_time[i];
            burst_time[i] = burst_time[position];
            burst_time[position] = temp;
            temp = process[i];
            process[i] = process[position];
            process[position] = temp;
      }
      waiting_time[0] = 0;
      for(i = 1; i < limit; i++)
      {
            waiting_time[i] = 0;
            for(j = 0; j < i; j++)
            {
                  waiting_time[i] = waiting_time[i] + burst_time[j];
            }
            sum = sum + waiting_time[i];
      }
      average_wait_time = sum / limit;
      sum = 0;
      printf("\nProcess ID\t\tBurst Time\t Waiting Time\t Turnaround Time\t Priority\n");
      for(i = 0; i < limit; i++)
      {
            turnaround_time[i] = burst_time[i] + waiting_time[i];
            sum = sum + turnaround_time[i];
            printf("\nProcess[%d]\t\t%d\t\t %d\t\t %d\t\t\t %d\n", process[i], burst_time[i], waiting_time[i], turnaround_time[i],priority[i]);
      }
      average_turnaround_time = sum / limit;
      printf("\nAverage Waiting Time:\t%f", average_wait_time);
      printf("\nAverage Turnaround Time:\t%f\n", average_turnaround_time);
}
void Preemptive_Shortest_Job_Scheduling() 
{
      int arrival_time[10], burst_time[10], temp[10];
      int i, smallest, count = 0, time, limit;
      double wait_time = 0, turnaround_time = 0, end;
      float average_waiting_time, average_turnaround_time;
      printf("\nEnter the Total Number of Processes:\t");
      scanf("%d", &limit); 
      printf("\nEnter Details of %d Processes\n", limit);
      for(i = 0; i < limit; i++)
      {
            arrival_time[i]= rand() %8 +0;
			burst_time[i]= rand() %10 +1;
			temp[i] = burst_time[i];
      }
      burst_time[9] = 9999;  
      for(time = 0; count != limit; time++)
      {
            smallest = 9;
            for(i = 0; i < limit; i++)
            {
                  if(arrival_time[i] <= time && burst_time[i] < burst_time[smallest] && burst_time[i] > 0)
                  {
                        smallest = i;
                  }
            }
            burst_time[smallest]--;
            if(burst_time[smallest] == 0)
            {
                  count++;
                  end = time + 1;
                  wait_time = wait_time + end - arrival_time[smallest] - temp[smallest];
                  turnaround_time = turnaround_time + end - arrival_time[smallest];
            }
      }
      average_waiting_time = wait_time / limit; 
      average_turnaround_time = turnaround_time / limit;
      printf("\n\nAverage Waiting Time:\t%lf\n", average_waiting_time);
      printf("Average Turnaround Time:\t%lf\n", average_turnaround_time);

}
void Round_Robin_Scheduling() 
{ 
      int i, limit, total = 0, x, counter = 0, time_quantum; 
      int wait_time = 0, turnaround_time = 0, arrival_time[10], burst_time[10], temp[10]; 
      float average_wait_time, average_turnaround_time;
      printf("\nEnter Total Number of Processes:\t"); 
      scanf("%d", &limit); 
      x = limit; 
      for(i = 0; i < limit; i++) 
      {
            arrival_time[i]= rand() %8 +0;
          burst_time[i]= rand() %10 +1;
            temp[i] = burst_time[i];
      } 
      printf("\nEnter Time Quantum:\t"); 
      scanf("%d", &time_quantum); 
      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
      for(total = 0, i = 0; x != 0;) 
      { 
            if(temp[i] <= time_quantum && temp[i] > 0) 
            { 
                  total = total + temp[i]; 
                  temp[i] = 0; 
                  counter = 1; 
            } 
            else if(temp[i] > 0) 
            { 
                  temp[i] = temp[i] - time_quantum; 
                  total = total + time_quantum; 
            } 
            if(temp[i] == 0 && counter == 1) 
            { 
                  x--; 
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, burst_time[i], total - arrival_time[i], total - arrival_time[i] - burst_time[i]);
                  wait_time = wait_time + total - arrival_time[i] - burst_time[i]; 
                  turnaround_time = turnaround_time + total - arrival_time[i]; 
                  counter = 0; 
            } 
            if(i == limit - 1) 
            {
                  i = 0; 
            }
            else if(arrival_time[i + 1] <= total) 
            {
                  i++;
            }
            else 
            {
                  i = 0;
            }
      } 
      average_wait_time = wait_time * 1.0 / limit;
      average_turnaround_time = turnaround_time * 1.0 / limit;
      printf("\n\nAverage Waiting Time:\t%f", average_wait_time); 
      printf("\nAvg Turnaround Time:\t%f\n", average_turnaround_time); 
}

void shortest_remaining_time_Scheduling()
{
 int a[10],b[10],x[10];
 int waiting[10],turnaround[10],completion[10];
 int i,j,smallest,count=0,time,n;
 double avg=0,tt=0,end;

 printf("\nEnter the number of Processes: ");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  a[i]= rand() %8 +0;
   b[i]= rand() %10 +1;
 }
 for(i=0;i<n;i++)
 x[i]=b[i];

  b[9]=9999;

 for(time=0;count!=n;time++)
 {
   smallest=9;
  for(i=0;i<n;i++)
  {
   if(a[i]<=time && b[i]<b[smallest] && b[i]>0 )
   smallest=i;
  }
  b[smallest]--;

  if(b[smallest]==0)
  {
   count++;
   end=time+1;
   completion[smallest] = end;
   waiting[smallest] = end - a[smallest] - x[smallest];
   turnaround[smallest] = end - a[smallest];

  }
 }
 printf("pid \t burst \t arrival \twaiting \tturnaround \tcompletion");
 for(i=0;i<n;i++)
 {
   printf("\n %d \t   %d \t %d\t\t%d   \t\t%d\t\t%d",i+1,x[i],a[i],waiting[i],turnaround[i],completion[i]);
   avg = avg + waiting[i];
   tt = tt + turnaround[i];
 }
 printf("\n  %lf   %lf",avg,tt);
 printf("\n\nAverage waiting time = %lf\n",avg/n);
 printf("Average Turnaround time = %lf",tt/n);
}

void Rate_Monotonic_Scheduling()
{
	int n;
	printf("\nEnter the number of processes: ");
	scanf("%d",&n);
	
	int p[n],exec[n], period[n], wt[n],tat[n],i, k, temp;
	float wtavg, tatavg;
	
	for(i=0;i<n;i++)
	{
		p[i] = i+1;
		exec[i]= rand() %10 +1;
		period[i]= rand() %8 +1;
	}
	for(i=0;i<n;i++)
	for(k=i+1;k<n;k++)
	if(period[i] > period[k])	
	{
	temp=p[i];
	p[i]=p[k];
	p[k]=temp;
	
	temp=exec[i];
	exec[i]=exec[k];
	exec[k]=temp;
	
	temp=period[i];
	period[i]=period[k];
	period[k]=temp;
	}
	wtavg = wt[0] = 0;
	tatavg = tat[0] = exec[0];
	for(i=1;i<n;i++)
	{
	wt[i] = wt[i-1] + exec[i-1];
	tat[i] = tat[i-1] + exec[i];
	wtavg = wtavg + wt[i];
	tatavg = tatavg + tat[i];
	}
	system("CLS");
	printf("\nPROCESS\t\t TIME PERIOD \tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
	for(i=0;i<n;i++)
	printf("\n%d \t\t %d \t\t\t %d \t\t %d \t\t %d ",p[i],period[i],exec[i],wt[i],tat[i]);
	printf("\nAverage Waiting Time is: %f",wtavg/n);
	printf("\nAverage Turnaround Time is: %f",tatavg/n);
}
void Preemptive_CPU_Scheduling()
{
		HANDLE hConsole;
 hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
 {
	SetConsoleTextAttribute(hConsole, 14);
	int x;
   printf("\n\n 1)Preemptive_Priority_Scheduling \n 2)Preemptive_Shortest_Job_Scheduling \n 3)Round_Robin_Scheduling \n 4)shortest_remaining_time_Scheduling \n 5)Rate Monotonic Scheduling \n 6)EXIT \n");
   printf("\n\nEnter your choice : ");
   scanf("%d",&x); 
   switch (x) 
   { 
       case 1: 
	           Preemptive_Priority_Scheduling(); 
               break; 
       case 2: 
	           Preemptive_Shortest_Job_Scheduling(); 
                break; 
       case 3:  
               Round_Robin_Scheduling();
               break;
	   case 4:  
               shortest_remaining_time_Scheduling();
               break; 
       case 5: 
	           Rate_Monotonic_Scheduling();
			   break;
       case 6: printf("\n\nThank you");        
       break;
	   default:printf("\nNot within the given parameters"); 
               break;   
   } 
   
  while(x!=6);
}
}

void Preemptive_Priority_Scheduling_REAL()
{
	printf("In case of a natural disaster,a medical team is setup and they decide what plan to follow incase of different situation.\nThey decide that when a patient in critical condition(high risk rate) comes to the emergency room they will leave all the routine checkup and\n first give priority to the critical patient.Incase two patients arrive at the same time,the patient with the high risk rate is given more priority than \na patient with lower risk rate beacuse giving him priority will eventually help in saving his life.\n\n");
      int burst_time[20], process[20], waiting_time[20], turnaround_time[20], priority[20];
      int i, j, limit, sum = 0, position, temp;
      float average_wait_time, average_turnaround_time;
      printf("Enter Total Number of Patients:\t");
      scanf("%d", &limit);
      printf("\nEnter service time of patients \n", limit);
      for(i = 0; i < limit; i++)
      {
            printf("\nPatient[%d]\n", i + 1);
            printf("Patient service Time:\t");
            scanf("%d", &burst_time[i]);
            printf("Priority of patients :\t");
            scanf("%d", &priority[i]);
            process[i] = i + 1;
      }
      for(i = 0; i < limit; i++)
      {
            position = i;
            for(j = i + 1; j < limit; j++)
            {
                  if(priority[j] < priority[position])
                  {
                        position = j;
                  }
            }
            temp = priority[i];
            priority[i] = priority[position];
            priority[position] = temp; 
            temp = burst_time[i];
            burst_time[i] = burst_time[position];
            burst_time[position] = temp;
            temp = process[i];
            process[i] = process[position];
            process[position] = temp;
      }
      waiting_time[0] = 0;
      for(i = 1; i < limit; i++)
      {
            waiting_time[i] = 0;
            for(j = 0; j < i; j++)
            {
                  waiting_time[i] = waiting_time[i] + burst_time[j];
            }
            sum = sum + waiting_time[i];
      }
      average_wait_time = sum / limit;
      sum = 0;
      printf("\nProcess ID\t\tBurst Time\t Waiting Time\t Turnaround Time\n");
      for(i = 0; i < limit; i++)
      {
            turnaround_time[i] = burst_time[i] + waiting_time[i];
            sum = sum + turnaround_time[i];
            printf("\nProcess[%d]\t\t%d\t\t %d\t\t %d\n", process[i], burst_time[i], waiting_time[i], turnaround_time[i]);
      }
      average_turnaround_time = sum / limit;
      printf("\nAverage Waiting Time:\t%f", average_wait_time);
      printf("\nAverage Turnaround Time:\t%f\n", average_turnaround_time);

}

void Preemptive_Shortest_Job_Scheduling_REAL() 
{
	printf("In a supermarket, we have two types of queues. One of them is the normal queue, while the other is an express queue.\n The express queue acts as the shortest job first algorithm. When customers come to check out, the customer with the least amount of products is asked to come \nin the express queue because it is the shortest job.\n\n");
      int arrival_time[10], burst_time[10], temp[10];
      int i, smallest, count = 0, time, limit;
      double wait_time = 0, turnaround_time = 0, end;
      float average_waiting_time, average_turnaround_time;
      printf("\nEnter the Total Number of Customers:\t");
      scanf("%d", &limit); 
      printf("\nEnter numbers of queues\n", limit);
      for(i = 0; i < limit; i++)
      {
            printf("\nEnter Arrival Time:\t");
            scanf("%d", &arrival_time[i]);
            printf("Enter service time of customers :\t");
            scanf("%d", &burst_time[i]); 
            temp[i] = burst_time[i];
      }
      burst_time[9] = 9999;  
      for(time = 0; count != limit; time++)
      {
            smallest = 9;
            for(i = 0; i < limit; i++)
            {
                  if(arrival_time[i] <= time && burst_time[i] < burst_time[smallest] && burst_time[i] > 0)
                  {
                        smallest = i;
                  }
            }
            burst_time[smallest]--;
            if(burst_time[smallest] == 0)
            {
                  count++;
                  end = time + 1;
                  wait_time = wait_time + end - arrival_time[smallest] - temp[smallest];
                  turnaround_time = turnaround_time + end - arrival_time[smallest];
            }
      }
      average_waiting_time = wait_time / limit; 
      average_turnaround_time = turnaround_time / limit;
      printf("\n\nAverage Waiting Time of customers:\t%lf\n", average_waiting_time);
      printf("Average service Time of customers:\t%lf\n", average_turnaround_time);

}

void Round_Robin_Scheduling_REAL() 
{ 
printf("JAMES visits the amusement park.At the amusement park,he goes on to his favourite ride\n.the crazy bus.After he takes the ride for the first time\nhe enjoys it a lot and decides to get another turn.to get the ride again\nhe gets in a queue in which people are waiting in turn for the ride\nwe have used round robin algorithm to show how he can take rides in that way\n\n");
      int i, limit, total = 0, x, counter = 0, time_quantum; 
      int wait_time = 0, turnaround_time = 0, arrival_time[10], burst_time[10], temp[10]; 
      float average_wait_time, average_turnaround_time;
      printf("\nEnter Total Number of children:\t"); 
      scanf("%d", &limit); 
      x = limit; 
      for(i = 0; i < limit; i++) 
      {
            printf("\nEnter Details of child[%d]\n", i + 1);
            printf("Arrival Time of child :\t");
            scanf("%d", &arrival_time[i]);
            printf("Time taken for the child to ride the roller coaster:\t");
            scanf("%d", &burst_time[i]); 
            temp[i] = burst_time[i];
      } 
      printf("\nEnter Time alloted for each ride:\t"); 
      scanf("%d", &time_quantum); 
      printf("\nChild number\t\Time taken for ride to complete\t Ride Time\t Waiting Time for ride\n");
      for(total = 0, i = 0; x != 0;) 
      { 
            if(temp[i] <= time_quantum && temp[i] > 0) 
            { 
                  total = total + temp[i]; 
                  temp[i] = 0; 
                  counter = 1; 
            } 
            else if(temp[i] > 0) 
            { 
                  temp[i] = temp[i] - time_quantum; 
                  total = total + time_quantum; 
            } 
            if(temp[i] == 0 && counter == 1) 
            { 
                  x--; 
                  printf("\nchild[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, burst_time[i], total - arrival_time[i], total - arrival_time[i] - burst_time[i]);
                  wait_time = wait_time + total - arrival_time[i] - burst_time[i]; 
                  turnaround_time = turnaround_time + total - arrival_time[i]; 
                  counter = 0; 
            } 
            if(i == limit - 1) 
            {
                  i = 0; 
            }
            else if(arrival_time[i + 1] <= total) 
            {
                  i++;
            }
            else 
            {
                  i = 0;
            }
      } 
      average_wait_time = wait_time * 1.0 / limit;
      average_turnaround_time = turnaround_time * 1.0 / limit;
      printf("\n\nAverage Waiting Time:\t%f", average_wait_time); 
      printf("\nAvg ride Time:\t%f\n", average_turnaround_time); 
}

void shortest_remaining_time_Scheduling_REAL()
{
	printf("University can be hectic when a student has a lot of assignments to complete. Assignments tend to come with deadlines and this makes it even more difficult and stressful.\nSo, when students have a host of assignments with deadlines nearby, they start doing the assignments which have the closest deadline.\n This is an example of how the shortest remaining time algorithm is implemented in real life scenario.\n\n");
 int a[10],b[10],x[10];
 int waiting[10],turnaround[10],completion[10];
 int i,j,smallest,count=0,time,n;
 double avg=0,tt=0,end;

 printf("\nEnter the number of Assignments: ");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
   printf("\nEnter arrival time of assignments %d : ",i+1);
   scanf("%d",&a[i]);
 }
 for(i=0;i<n;i++)
 {
   printf("\nEnter deadline of assignment %d : ",i+1);
   scanf("%d",&b[i]);
 }
 for(i=0;i<n;i++)
 x[i]=b[i];

  b[9]=9999;

 for(time=0;count!=n;time++)
 {
   smallest=9;
  for(i=0;i<n;i++)
  {
   if(a[i]<=time && b[i]<b[smallest] && b[i]>0 )
   smallest=i;
  }
  b[smallest]--;

  if(b[smallest]==0)
  {
   count++;
   end=time+1;
   completion[smallest] = end;
   waiting[smallest] = end - a[smallest] - x[smallest];
   turnaround[smallest] = end - a[smallest];

  }
 }
 printf("pid \tDue date \t arrival of assignment  \twaiting of assignment \t \tcompletion time of assignment");
 for(i=0;i<n;i++)
 {
   printf("\n %d \t   %d \t %d\t\t%d   \t\t%d\t\t%d",i+1,x[i],a[i],waiting[i],turnaround[i],completion[i]);
   avg = avg + waiting[i];
   tt = tt + turnaround[i];
 }
 printf("\n  %lf   %lf",avg,tt);
 printf("\n\nAverage waiting time = %lf\n",avg/n);
 printf("Average Turnaround time = %lf",tt/n);
}

void Rate_Monotonic_Scheduling_REAL()
{
int n;
printf("at a burger joint,the management decides that whenever a customer arrives \nhis meal will be given to him according to the time taken to prepare the meal\nthe meal with the lowest priority and is given to the customer first because\nif we dont give it to customer it could turn stale while waiting for other meals to be prepared\nHence meal with thr shortest preparation time is given more priority");
	printf("\nEnter the number of processes: ");
	scanf("%d",&n);
	
	int p[n],exec[n], period[n], wt[n],tat[n],i, k, temp;
	float wtavg, tatavg;
	
	for(i=0;i<n;i++)
	{
		p[i] = i+1;
		printf("\nEnter the preparation time of meal %d ", (i+1));
		scanf("%d",&exec[i]);
		
		printf("\nEnter the time period of meal delivery %d : ",(i+1));
		scanf("%d", &period[i]);
	}
	for(i=0;i<n;i++)
	for(k=i+1;k<n;k++)
	if(period[i] > period[k])	
	{
	temp=p[i];
	p[i]=p[k];
	p[k]=temp;
	
	temp=exec[i];
	exec[i]=exec[k];
	exec[k]=temp;
	
	temp=period[i];
	period[i]=period[k];
	period[k]=temp;
	}
	wtavg = wt[0] = 0;
	tatavg = tat[0] = exec[0];
	for(i=1;i<n;i++)
	{
	wt[i] = wt[i-1] + exec[i-1];
	tat[i] = tat[i-1] + exec[i];
	wtavg = wtavg + wt[i];
	tatavg = tatavg + tat[i];
	}
	system("CLS");
	printf("\nPROCESS\t\t TIME PERIOD \tpreparation time\tWAITING TIME\tDelivery TIME");
	for(i=0;i<n;i++)
	printf("\n%d \t\t %d \t\t\t %d \t\t %d \t\t %d ",p[i],period[i],exec[i],wt[i],tat[i]);
	printf("\nAverage Waiting Time of customer is: %f",wtavg/n);
	printf("\nAverage meal delivery Time is: %f",tatavg/n);	
}

void Preemptive_CPU_Scheduling_Real_LIFE_SCEANRIOS()
{
		HANDLE hConsole;
 hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
 {
	SetConsoleTextAttribute(hConsole, 10);
int x;
   do{
   printf("\n\n 1)Preemptive_Priority_Scheduling \n 2)Preemptive_Shortest_Job_Scheduling \n 3)Round_Robin_Scheduling \n 4)shortest_remaining_time_Scheduling \n 5)Rate Monotonic Scheduling \n6)EXIT \n");
   printf("\n\nEnter your choice : ");
   scanf("%d",&x); 
   switch (x) 
   { 
       case 1: 
	           Preemptive_Priority_Scheduling_REAL(); 
               break; 
       case 2: 
	           Preemptive_Shortest_Job_Scheduling_REAL(); 
                break; 
       case 3:  
               Round_Robin_Scheduling_REAL();
               break;
	   case 4:  
               shortest_remaining_time_Scheduling_REAL();
               break; 
       case 5: 
	           Rate_Monotonic_Scheduling_REAL();
			   break;        
       case 6: printf("\n\nThank you");        
       break;
	   default:printf("\nNot within the given parameters"); 
               break;   
   } 
   }
  while(x!=6);	
}
}

Preemptive_Priority_Scheduling_Gantt()
{
int pid,p,at,bt,ct,tt,wt;	
cout << '|' << setw(10) << "PID" << '|' << setw(10) << " PRIORITY " << '|' << setw(10) << " ARRIVAL TIME " << '|' << setw(10) << " BURST TIME " << '|' << setw(10) << " COMPLETION TIME " << '|' << setw(10) << " TURN-AROUND TIME " << '|' << setw(10) << " WAITING TIME " << '|' << endl;	
pid=1;
p=2;
at=0;
bt=4;
ct=25;
tt=25;
wt=21;
cout << '|' << setw(10) << pid << '|' << setw(10) << p << '|' << setw(10) << at << '|' << setw(10) << bt << '|' << setw(10) << ct << '|' << setw(19) <<  tt << '|' << setw(19) << wt << '|' << endl;
pid=2;
p=4;
at=1;
bt=2;
ct=22;
tt=21;
wt=19;
cout << '|' << setw(10) << pid << '|' << setw(10) << p << '|' << setw(10) << at << '|' << setw(10) << bt << '|' << setw(10) << ct << '|' << setw(19) << tt << '|' << setw(19) << wt << '|' << endl;
pid=3;
p=6;
at=2;
bt=3;
ct=21;
tt=19;
wt=16;
cout << '|' << setw(10) << pid << '|' << setw(10) << p << '|' << setw(10) << at << '|' << setw(10) << bt << '|' << setw(10) << ct << '|' << setw(19) << tt << '|' << setw(19) << wt << '|' << endl;
pid=4;
p=10;
at=3;
bt=5;
ct=12;
tt=9;
wt=4;
cout << '|' << setw(10) << pid << '|' << setw(10) << p << '|' << setw(10) << at << '|' << setw(10) << bt << '|' << setw(10) << ct << '|' << setw(19) << tt << '|' << setw(19) << wt << '|' << endl;
pid=5;
p=8;
at=4;
bt=1;
ct=19;
tt=15;
wt=14;
cout << '|' << setw(10) << pid << '|' << setw(10) << p << '|' << setw(10) << at << '|' << setw(10) << bt << '|' << setw(10) << ct << '|' << setw(19) << tt << '|' << setw(19) << wt << '|' << endl;
pid=6;
p=12;
at=5;
bt=4;
ct=9;
tt=4;
wt=0;
cout << '|' << setw(10) << pid << '|' << setw(10) << p << '|' << setw(10) << at << '|' << setw(10) << bt << '|' << setw(10) << ct << '|' << setw(19) << tt << '|' << setw(19) << wt << '|' << endl;
pid=7;
p=9;
at=6;
bt=6;
ct=18;
tt=12;
wt=6;
cout << '|' << setw(10) << pid << '|' << setw(10) << p << '|' << setw(10) << at << '|' << setw(10) << bt << '|' << setw(10) << ct << '|' << setw(19) << tt << '|' << setw(19) << wt << '|' << endl;

cout<<endl<<endl<< " GANTT CHART " <<endl<<endl;
cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------" <<endl;
cout << "|         |          |           |            |            |              |             |               |               |               |               |" <<endl;
cout << "|   P1    |     P2   |     P3    |     P4     |      P6    |      P4      |      P7     |        P5     |         P3    |        P2     |        P1     |" <<endl;
cout << "|         |          |           |            |            |              |             |               |               |               |               |" <<endl;
cout << "0---------1--------- 2---------- 3----------- 5----------- 9------------ 12------------18------------- 19------------- 21------------  22--------------25" <<endl;

}

void Preemptive_Shortest_Job_Scheduling_Gantt()
{
int pid,at,bt,ct,tt,wt;	
cout << '|' << setw(10) << "PID" << '|' << setw(10) << " ARRIVAL TIME " << '|' << setw(10) << " BURST TIME " << '|' << setw(10) << " COMPLETION TIME " << '|' << setw(10) << " TURN-AROUND TIME " << '|' << setw(10) << " WAITING TIME " << '|' << endl;	
pid=1;
at=0;
bt=7;
ct=19;
tt=19;
wt=12;
cout << '|' << setw(10) << pid <<   '|' << setw(10) << at << '|' << setw(10) << bt << '|' << setw(10) << ct << '|' << setw(19) <<  tt << '|' << setw(19) << wt << '|' << endl;
pid=2;
at=1;
bt=5;
ct=13;
tt=12;
wt=7;
cout << '|' << setw(10) << pid <<   '|' << setw(10) << at << '|' << setw(10) << bt << '|' << setw(10) << ct << '|' << setw(19) <<  tt << '|' << setw(19) << wt << '|' << endl;
pid=3;
at=2;
bt=3;
ct=6;
tt=4;
wt=1;
cout << '|' << setw(10) << pid <<   '|' << setw(10) << at << '|' << setw(10) << bt << '|' << setw(10) << ct << '|' << setw(19) <<  tt << '|' << setw(19) << wt << '|' << endl;
pid=4;
at=3;
bt=1;
ct=4;
tt=1;
wt=0;
cout << '|' << setw(10) << pid <<   '|' << setw(10) << at << '|' << setw(10) << bt << '|' << setw(10) << ct << '|' << setw(19) <<  tt << '|' << setw(19) << wt << '|' << endl;
pid=5;
at=4;
bt=2;
ct=9;
tt=5;
wt=3;
cout << '|' << setw(10) << pid <<   '|' << setw(10) << at << '|' << setw(10) << bt << '|' << setw(10) << ct << '|' << setw(19) <<  tt << '|' << setw(19) << wt << '|' << endl;
pid=6;
at=5;
bt=1;
ct=7;
tt=2;
wt=1;
cout << '|' << setw(10) << pid <<   '|' << setw(10) << at << '|' << setw(10) << bt << '|' << setw(10) << ct << '|' << setw(19) <<  tt << '|' << setw(19) << wt << '|' << endl;

cout<<endl<<endl<< " GANTT CHART " <<endl<<endl;
cout << "-------------------------------------------------------------------------------------------------------------------------" <<endl;
cout << "|         |          |           |            |            |              |             |               |               |" <<endl;
cout << "|   P1    |     P2   |     P3    |     P4     |      P3    |      P6      |      P5     |        P2     |         P1    |" <<endl;
cout << "|         |          |           |            |            |              |             |               |               |" <<endl;
cout << "0---------1--------- 2---------- 3----------- 4----------- 6------------  7------------ 9------------- 13------------- 19" <<endl;
}

void Round_Robin_Scheduling_Gantt()
{
int pid,at,bt;	
cout << '|' << setw(10) << "PID" << '|' << setw(10) << " ARRIVAL TIME " << '|' << setw(10) << " BURST TIME " << '|' <<endl;	
pid=1;
at=0;
bt=4;
cout << '|' << setw(10) << pid <<   '|' << setw(10) << at << '|' << setw(10) << bt << '|' <<endl;	
pid=2;
at=1;
bt=5;
cout << '|' << setw(10) << pid <<   '|' << setw(10) << at << '|' << setw(10) << bt << '|' <<endl;
pid=3;
at=2;
bt=2;
cout << '|' << setw(10) << pid <<   '|' << setw(10) << at << '|' << setw(10) << bt << '|' <<endl;
pid=4;
at=3;
bt=1;
cout << '|' << setw(10) << pid <<   '|' << setw(10) << at << '|' << setw(10) << bt << '|' <<endl;
pid=5;
at=4;
bt=6;
cout << '|' << setw(10) << pid <<   '|' << setw(10) << at << '|' << setw(10) << bt << '|' <<endl;
pid=6;
at=6;
bt=3;
cout << '|' << setw(10) << pid <<   '|' << setw(10) << at << '|' << setw(10) << bt << '|' <<endl;

cout<<endl<<endl<< " GANTT CHART " <<endl<<endl;
cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------"  <<endl;
cout << "|         |          |           |            |            |              |             |               |               |            |           |          |" <<endl;
cout << "|   P1    |     P2   |     P3    |     P1     |      P4    |      P5      |      P2     |        P6     |       P5      |     P2     |     P6    |    P5    |" <<endl;
cout << "|         |          |           |            |            |              |             |               |               |            |           |          |" <<endl;
cout << "0---------2--------- 4---------- 6----------- 8----------- 9------------  11------------13------------- 15------------- 17----------18-----------19--------21" <<endl;

}

void Rate_Monotonic_Scheduling_Gantt()
{
cout<<endl<<endl<< " GANTT CHART " <<endl<<endl;
cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" <<endl;
cout << "|                                |                         |                            |                                                                   |" <<endl;
cout << "|               P2               |       P1                |                            |                                          P1,P2                    |" <<endl;
cout << "|         |          |           |            |            |              |             |               |               |            |                      |" <<endl;
cout << "0---------10---------20----------30-----------40-----------50------------ 60------------70------------- 80-------------90----------100----------110-------120" <<endl;	
}

shortest_remaining_time_Scheduling_Gantt()
{
int pid,at,bt;	
cout << '|' << setw(10) << "PID" << '|' << setw(10) << " ARRIVAL TIME " << '|' << setw(10) << " BURST TIME " << '|' <<endl;	
pid=1;
at=0;
bt=10;
cout << '|' << setw(10) << pid <<   '|' << setw(10) << at << '|' << setw(10) << bt << '|' <<endl;	
pid=2;
at=1;
bt=5;
cout << '|' << setw(10) << pid <<   '|' << setw(10) << at << '|' << setw(10) << bt << '|' <<endl;
pid=3;
at=2;
bt=2;
cout << '|' << setw(10) << pid <<   '|' << setw(10) << at << '|' << setw(10) << bt << '|' <<endl;


cout<<endl<<endl<< " GANTT CHART " <<endl<<endl;
cout << "------------------------------------------------------------" <<endl;
cout << "|         |          |           |            |            |" <<endl;
cout << "|   P1    |     P2   |     P3    |     P2     |      P1    |" <<endl;
cout << "|         |          |           |            |            |" <<endl;
cout << "0---------1--------- 2---------- 4----------- 8----------- 17" <<endl;

}	


void Gantt_chart_Implementation_of_Algorithms()
{
		HANDLE hConsole;
 hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
 {
	SetConsoleTextAttribute(hConsole, 15);
   int x;
do{

   printf("\n\n 1)Preemptive_Priority_Scheduling \n 2)Preemptive_Shortest_Job_Scheduling \n 3)Round_Robin_Scheduling \n 4)shortest_remaining_time_Scheduling \n 5)Rate Monotonic Scheduling \n 6)EXIT");
   printf("\n\nEnter your choice : ");
   scanf("%d",&x); 
   switch (x) 
   { 
       case 1: 
	           Preemptive_Priority_Scheduling_Gantt(); 
               break; 
       case 2: 
	           Preemptive_Shortest_Job_Scheduling_Gantt(); 
                break; 
       case 3:  
               Round_Robin_Scheduling_Gantt();
               break;
	   case 4:  
               shortest_remaining_time_Scheduling_Gantt();
               break; 
       case 5: 
	           Rate_Monotonic_Scheduling_Gantt();
			   break;        
       case 6: printf("\n\nThank you");        
       break;
	   default:printf("\nNot within the given parameters"); 
               break;   
   } 
   }
  while(x!=6);	
}
}
void CPU_Utilization_of_Preemptive_CPU_Scheduling()
{
	
string PS,SJF,RR,SRT,RM;	
cout << '|' << setw(10) << "PRIOIRITY SCHEDULE" << '|' << setw(10) << " SJF " << '|' << setw(10) << " RR " << '|' << setw(10) << " SRT " << '|' << setw(15) << "RATE MONOTONIC " << '|' << setw(15) << endl;	
PS="MEDIUM";
SJF="MEDIUM";
RR="HIGH";
SRT="HIGH";
RM="LOW";
cout << '|' << setw(10) << PS <<   '|' << setw(10) << SJF << '|' << setw(10) << RR << '|' << setw(10) << SRT << '|'<< setw(1)<<RM <<'|'<< setw(1) << endl;

}

void Policy_Enforcement_of_Preemptive_CPU_Scheduling()
{
string PS,SJF,RR,SRT,RM;		
PS="CPU executes process with highest priority";
SJF="CPU executes job witH shortest time remaining to completion*";
RR="like FCFS, but with limited time slices";
SRT=" the process with the smallest amount of time remaining until completion is selected to execute.";
RM="The static priorities are assigned according to the cycle duration of the job, so a shorter cycle duration results in a higher job priority";
cout<<"\n\nPRIOIRITY SCHEDULE : " << PS << " \n\n\ SJF : " << SJF << " \n\n RR : " << RR << "\n\n SRT : " << SRT << " \n\n RATE MONOTONIC : " << RM <<endl;
}

void Efficiency_of_Preemptive_CPU_Scheduling()
{
string PS,SJF,RR,SRT,RM;	
cout << '|' << setw(10) << "PRIOIRITY SCHEDULE" << '|' << setw(10) << " SJF " << '|' << setw(10) << " RR " << '|' << setw(10) << " SRT " << '|' << setw(15) << "RATE MONOTONIC " << '|' << setw(15) << endl;	
PS="HIGH";
SJF="MEDIUM";
RR="MEDIUM";
SRT="HIGH";
RM="MEDIUM";
cout << '|' << setw(10) << PS <<   '|' << setw(10) << SJF << '|' << setw(10) << RR << '|' << setw(10) << SRT << '|'<< setw(1)<<RM <<'|'<< setw(1) << endl;	
}

void Response_Time_of_Preemptive_CPU_Scheduling()
{
string PS,SJF,RR,SRT,RM;	
cout << '|' << setw(10) << "PRIOIRITY SCHEDULE" << '|' << setw(10) << " SJF " << '|' << setw(10) << " RR " << '|' << setw(10) << " SRT " << '|' << setw(15) << "RATE MONOTONIC " << '|' << setw(15) << endl;	
PS="HIGH";
SJF="MEDIUM";
RR="HIGH";
SRT="LOW";
RM="MEDIUM";
cout << '|' << setw(10) << PS <<   '|' << setw(10) << SJF << '|' << setw(10) << RR << '|' << setw(10) << SRT << '|'<< setw(1)<<RM <<'|'<< setw(1) << endl;	
}		


void Throughput_of_Preemptive_CPU_Scheduling()
{
string PS,SJF,RR,SRT,RM;	
cout << '|' << setw(10) << "PRIOIRITY SCHEDULE" << '|' << setw(10) << " SJF " << '|' << setw(10) << " RR " << '|' << setw(10) << " SRT " << '|' << setw(15) << "RATE MONOTONIC " << '|' << setw(15) << endl;	
PS="LOW";
SJF="HIGH";
RR="MEDIUM";
SRT="LOW";
RM="MEDIUM";
cout << '|' << setw(5) << PS <<   '|' << setw(10) << SJF << '|' << setw(10) << RR << '|' << setw(10) << SRT << '|'<< setw(1)<<RM <<'|'<< setw(1) << endl;	
}			


void Analysis_of_Algorithms()
{
		HANDLE hConsole;
 hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
 {
	SetConsoleTextAttribute(hConsole, 7);
 int x;
   
   do{
   printf("\n\n 1)CPU_Utilization_of_Preemptive_CPU_Scheduling \n 2)Policy_Enforcement_of_Preemptive_CPU_Scheduling \n 3)Efficiency_of_Preemptive_CPU_Scheduling \n 4)Response_Time_of_Preemptive_CPU_Scheduling \n 5)Throughput_of_Preemptive_CPU_Scheduling \n 6) EXIT \n\n");
   printf("\n\nEnter your choice : ");
   scanf("%d",&x); 
   switch (x) 
   { 
	   case 1:  
			   CPU_Utilization_of_Preemptive_CPU_Scheduling();
               break;
	   case 2:  
               Policy_Enforcement_of_Preemptive_CPU_Scheduling();
               break;
	   case 3:  
               Efficiency_of_Preemptive_CPU_Scheduling();
               break;
	   case 4:  
               Response_Time_of_Preemptive_CPU_Scheduling();
               break;
	   case 5:  
               Throughput_of_Preemptive_CPU_Scheduling();
               break;
       case 6: printf("\n\nThank you");        
       break;
	   default:printf("\nNot within the given parameters"); 
               break;   
   } 
   }
  while(x!=6);
}	
}

int main() 
{ 
	HANDLE hConsole;
 hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
 {
	SetConsoleTextAttribute(hConsole, 11);
printf("\t \t----------------------------------------------------\n\n");
printf("\t \t \t ||OS PROJECT|| \n\n");
printf("\t \t----------------------------------------------------\n\n");

printf(" \n \n \n CREATED BY : \n");
printf(" \n -------------------------------\n ");
printf("| HUSSAIN GHAZALI  | |17k-3900| \n | M.ZUHAIR WAHEED  | |17k-3706| \n | AQEEL ABBAS      | |17k-3701| \n | SHAYAN NOOR KHAN | |17k-3744|");
printf(" \n ------------------------------- \n");
system("PAUSE");
   int x;
   
   do{
   printf("\n\n 1)Preemptive CPU Scheduling \n 2)Preemptive CPU Scheduling (Real LIFE SCEANRIOS) \n 3)Gantt chart Implementation of Algorithms \n 4)ANALYSIS of Preemptive CPU Scheduling \n 5)EXIT");
   printf("\n\nEnter your choice : ");
   scanf("%d",&x); 
   switch (x) 
   { 
       case 1: 
	           Preemptive_CPU_Scheduling(); 
               break; 
       case 2: 
	           Preemptive_CPU_Scheduling_Real_LIFE_SCEANRIOS(); 
                break; 
       case 3:  
               Gantt_chart_Implementation_of_Algorithms();
               break;
	   case 4:  
               Analysis_of_Algorithms();
               break;
       case 5: printf("\n\nThank you");
	   break;        
       default:printf("\nNot within the given parameters"); 
               break;   
   } 
   }
  while(x!=5);
}
   return 0; 
} 
