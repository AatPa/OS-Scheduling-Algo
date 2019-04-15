#include<stdio.h>
//#include<conio.h>
#include<time.h>

int main()
{
    int ch;
    int ran,i,j,temp,smallest,count=0,time1;
    int npr[20],bt[20],at[20],wt[20],tat[20],comple[20],x[20],total=0;
    float avg_wt=0,avg_tat=0;
    double end;
    printf("\n\t\tWelcome to Shortest job First Algorithm ");
    printf("\n\t\tSelect your type as per requirements from below:");
    printf("\n\t\t1.Shortest job First Non Preemptive \n\t\t2.Shortest job First Preemptive");
    printf("\n\t\tEnter Your choice:");
    scanf("%d",&ch);

    void npre()
    {
            //Generating random number of processes in the range 1-10
            srand(time(NULL));
            ran=rand()%10+1;
            printf("\nNumber of jobs generated randomly :%d",ran);


            //Creating rand number of processes
            for( i=0;i<ran;i++)
            {
                    npr[i]=i+1;
            }

            /*for(i=0;i<ran;i++)
            {
                printf("Process are:%d",npr[i]);
            }*/

            for( i=0;i<ran;i++)
            {
                printf("\nEnter Burst Time for %d Process:",i+1);
                scanf("%d",&bt[i]);
                printf("\nEnter Arrival time of %d Process:",i+1);
                scanf("%d",&at[i]);
            }

            for(i=0;i<ran;i++)
            {
                int pre=i;
                for(j=i+1;j<ran;j++)
                {
                    if(bt[j]<bt[pre])
                    {
                        pre=j;
                    }
                }

                temp=bt[i];
                bt[i]=bt[pre];
                bt[pre]=temp;
                temp=npr[i];
                npr[i]=npr[pre];
                npr[pre]=temp;

            }

            wt[0]=0;
            for(i=1;i<ran;i++)
            {
              wt[i]=0;
              for(j=0;j<i;j++)
              {
                wt[i]+=bt[j];
              }

            total+=wt[i];
            }

            avg_wt=(float)total/ran;
            total=0;
            printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
            for(i=0;i<ran;i++)
            {
              tat[i]=bt[i]+wt[i];
              total+=tat[i];
              printf("\nprocess %d\t  %d\t\t    %d\t\t\t%d",npr[i],bt[i],wt[i],tat[i]);
            }

            avg_tat=(float)total/ran;
            printf("\n\nAverage Waiting Time=%f",avg_wt);
            printf("\nAverage Turnaround Time=%f\n",avg_tat);
    }

    void pre()
    {
      //Generating random number of processes in the range 1-10
      srand(time(NULL));
      ran=rand()%10+1;
      printf("\nNumber of jobs generated randomly :%d",ran);

      //Creating rand number of processes

      for( i=0;i<ran;i++)
      {
              npr[i]=i+1;
      }

      //Enter arrival and burst time of processes
      for( i=0;i<ran;i++)
      {
          printf("\nEnter Burst Time for %d Process:",i+1);
          scanf("%d",&bt[i]);
          printf("\nEnter Arrival time of %d Process:",i+1);
          scanf("%d",&at[i]);
      }

      for(i=0;i<ran;i++)
      {
        x[i]=bt[i];
      }

      bt[9]=9999;

      for(time1=0;count!=ran;time1++)
      {
        smallest=9;
        for(i=0;i<ran;i++)
        {
          if(at[i]<=time1 && bt[i]<bt[smallest] && bt[i]>0)
          {
            smallest=i;
          }
        }
        bt[smallest]--;

        if(bt[smallest]==0)
        {
          count++;
          end=time1+1;
          comple[smallest]=end;
          wt[smallest]=end-at[smallest]-x[smallest];
          tat[smallest]=end-at[smallest];
        }
      }

      printf("pid \t burst \t arrival \twaiting \tturnaround \tcompletion");
      for(i=0;i<ran;i++)
      {
        printf("\n %d \t   %d \t %d\t\t%d   \t\t%d\t\t%d",i+1,x[i],at[i],wt[i],tat[i],comple[i]);
        avg_wt = avg_wt + wt[i];
        avg_tat = avg_tat + tat[i];
      }

      printf("\n  %If   %If",avg_wt,avg_tat);
      printf("\n\nAverage waiting time = %lf\n",avg_wt/ran);
      printf("Average Turnaround time = %lf",avg_tat/ran);

    }

   switch(ch)
    {
        case 1:npre();
                break;

        case 2:pre();
                break;
    }

return 0;
}
