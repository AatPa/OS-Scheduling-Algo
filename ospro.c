#include<stdio.h>
//#include<conio.h>
#include<time.h>

int main()
{
    int ch;
    int ran,i,j,temp;
    int npr[20],bt[20],at[20],wt[20],total=0;
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
                int 1pre=i;
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
            for(i=1;i<n;i++)
            {
              wt[i]=0;
              for(j=0;j<i;j++)
              {
                wt[i]+=bt[j];
              }

            total+=wt[i];
    }

   switch(ch)
    {
        case 1:npre();
                    break;

        case 2:break;
    }

return 0;
}
