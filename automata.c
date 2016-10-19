//********Name program: Probability interaction********************************

#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "reader.h"  //********it reads the script wrote in a main.aut file **************************
#include "reader.c"  
#include "calculate.h" //*********In this file there is the procedure to calculate the results of the systems**********************
#include "calculate.c"
  
 

//******************With this function the setting table has written on the screen*******************************

void table(int np,int n,float settings[],int typpot[][np],int whoactionbeg[][np],int whoactionend[][np],int begintime[][np],int endtime[][np],int fixed[],double zeroset[],int begif[][np], int endif[][np], int begintif[][np], int endintif[][np], double distif[][np],int **connectactive,double **lengthconnectactive,int preypredator[])
{
int i,j;
 

for (i=1;i<=n;i++)
{
	printf("potenziale %d\n",n);
 
	for (j=0;j<np;j++)
	{	
		printf("  %d ",typpot[i][j]);
		  
	}
	printf("action beg\n");

	for (j=0;j<np;j++)
	{
		printf("  %d ",whoactionbeg[i][j]);
		  
	}

	printf("action end\n");
	for (j=0;j<np;j++)
	{
		printf("  %d ",whoactionend[i][j]);
		  
	}

	printf("begin time\n");
	for (j=0;j<np;j++)
	{
		printf("  %d ",begintime[i][j]);
		  
	}

	printf(" end time\n");
	for (j=0;j<np;j++)
	{
		printf("  %d ",endtime[i][j]);
		  
	}
 
}  
printf("the settings  \n");

for (i=0;i<=20;i++)
{
	printf("%f\n",settings[i]);	
}

for (i=1;i<=n;i++)
{
	printf("%d",fixed[i]);
}
for (i=1;i<=n;i++)
{
	printf("prey %d",preypredator[i]);
}

printf("\n");
for (i=1;i<=n;i++)
{
	printf("%f",zeroset[i]);
}
for (i=1;i<=n;i++)
{
    printf("****\n");
    for (j=1;j<=n;j++)
    {
	    printf("%d ",connectactive[i][j]);
    }
}  
for (i=1;i<=n;i++)
{
    printf("****\n");
    for (j=1;j<=n;j++)
    {
	    printf("%f ",lengthconnectactive[i][j]);
    }
}  

}
int main()
{
int n,np;
char riga[40];

//************************************************************************************************************************
//******* Two rows of the scripts is read, to undestand that are the numbers of the agents in the system******************
//************************************************************************************************************************ 
time_t m;
time_t now = time(NULL);




FILE *f101 = fopen("posprob.aut","w");
fclose(f101);
FILE *f110 = fopen("movtable.aut","w");
fclose(f110);
FILE *f120 = fopen("tableprob.aut","w");
fclose(f120);

FILE *f100 = fopen("main.aut","r");
while ((riga[0]!='N') || (riga[1]!='E') || (riga[2]!='L'))
{
fscanf(f100,"%s",riga);	
}
fscanf(f100,"%s",riga);	
n=atoi(riga);

fclose(f100);
FILE *f200 = fopen("main.aut","r");
while ((riga[0]!='M') || (riga[1]!='A') || (riga[2]!='X') || (riga[3]!='P'))
{
fscanf(f200,"%s",riga);	
}
fscanf(f200,"%s",riga);	
np=atoi(riga);

fclose(f200);
printf("N %d",n);
printf("Np %d",np);

//********************************************************************************************************************
//******************************* variable to describe every elements that there are******************************

 		double x[n+1][10];
		int whoactionbeg[n+1][np];
		int whoactionend[n+1][np]; 
		int typpot[n+1][np];
		int begintime[n+1][np];
		int endtime[n+1][np];
		int fixed[n+1];
        double zeroset[n+1];
		int begif[n+1][np];
		int endif[n+1][np]; 
		int begintif[n+1][np];
		int endintif[n+1][np]; 
        double distif[n+1][np];
        double distprey;
        int **connectactive;
        double **lengthconnectactive;
        int preypredator[n+1];
        connectactive=(int **)malloc(sizeof(int *)*(n+2));
        int i,j;
        for(i=0; i<n+2; i++)
                 connectactive[i]=(int *)malloc(sizeof(int)*(n+2));
        lengthconnectactive=(double **)malloc(sizeof(double *)*(n+2));
        for(i=0; i<n+2; i++)
                 lengthconnectactive[i]=(double *)malloc(sizeof(double)*(n+2));

        
//***********************************************************************************************************************
//*********************************************************************************************************************** 	 

float settings[20]; //******in this variable there are very settings parameter of the system***************************
double minimi[n+1];
 
for (i=0;i<=20;i++)
{

	settings[i]=0;
}
for (i=0;i<=n;i++)
{
	fixed[i]=0;
	minimi[i]=100000000000;  
    zeroset[i]=0;
    preypredator[i]=-1;
}
 

for (i=0;i<=n;i++)
{
    for(j=0;j<=n;j++)
    {
         connectactive[i][j]=-1; 
         lengthconnectactive[i][j]=0;                                  
    }
}                  

for (i=0;i<=n;i++)
{
	
	for (j=0;j<=np;j++)
	{
		typpot[i][j]=0;
		whoactionbeg[i][j]=0;
	   	whoactionend[i][j]=0;
		begintime[i][j]=0;
		endtime[i][j]=0;
		begif[i][j]=0;
		endif[i][j]=0;
		begintif[i][j]=0;
		endintif[i][j]=0;
		distif[i][j]=0;
 		
	}
}
readfile(np,n,settings,x,whoactionbeg,whoactionend,typpot,begintime,endtime,fixed,zeroset,begif,endif,begintif,endintif,distif,connectactive, lengthconnectactive,preypredator,distprey); 
table(np,n,settings,typpot,whoactionbeg,whoactionend,begintime,endtime,fixed,zeroset,begif,endif,begintif,endintif,distif,connectactive,lengthconnectactive,preypredator); 
calculate(np,n,settings,x,typpot,whoactionbeg,whoactionend,begintime,endtime,fixed,zeroset,minimi,begif,endif,begintif,endintif,distif,connectactive,lengthconnectactive,preypredator,distprey);
table(np,n,settings,typpot,whoactionbeg,whoactionend,begintime,endtime,fixed,zeroset,begif,endif,begintif,endintif,distif,connectactive,lengthconnectactive,preypredator);
m = difftime(time(NULL), now);
printf("tempo totale in secondi: %ld\n",m);

}

	

