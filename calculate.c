#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>



void seekprob(int np,int n,float dim,double x[][10],double xmov[][10],double prob[],int typpot[][np],int whoactionbeg[][np],int whoactionend[][np],int begintime[][np],int endtime[][np],int t,int v,float settings[],int z,double zeroset[],double minimi[],int begif[][np],int endif[][np],int begintif[][np],int endintif[][np],double distif[][np],int fixed[],int ** connectactive,double **lengthconnectactive,int preypredator[])
{
 
     
 	int h,contatore,casual,number,w,contaprob,dd,o,ff,contatoreif,metriconif,ibeg,entif,contdim,nnn,l,kk,nomove,ii,memgredyent,parbrob;	
	char row[40],row2[40],namefile[40],stringnumb[40],stringa[40];
	float distx,distmem,distx2,distmem2,term,metricx,metricx2,vincdist,vincpar,incvinc,numrow,minimal2;
    double somprob,probtot,probsce,probnow,probafter,flotcasual,risnow,risafter,distvirt,cutoff,distcut,distcut2,num[20],param[(int)dim+1],memvinc[(int)dim+1],coef[20],vinc[10],xold[n+1][10],minimal,vincminimal,metricaconif,adj,distconnectactive,geodeticvers[20],divisorgeodetic;

    FILE *f20 = fopen("posprob.aut","a");
	FILE *f30 = fopen("movtable.aut","a");
	FILE *f35 = fopen("tableprob.aut","a");

 	h=1;
	somprob=0;
	probafter=0;
	probnow=0;	
	risnow=0;
	risafter=0;
	metricx=0;
	metricx2=0;
	int contsom=0;	
	
	for (h=1;h<=n;h++)
	{
 	risnow=0;
	risafter=0;
 	contatore=0;
	if (h!=v)
	{
	while ((typpot[h][contatore])!=0)
	{
	distmem=1000000000000;
	distmem2=100000000000;
   
    
//******************************************************************************************
//************************inizio la scelta dei potenziali***********************************
//******************************************************************************************
	if ((v>=whoactionbeg[h][contatore]) && (v<=whoactionend[h][contatore]) && (t>=begintime[h][contatore]) && (t<=endtime[h][contatore]))
	{
  	if (typpot[h][contatore]>0)	
		{
		if (settings[8]==0) strcpy(namefile,"potential.aut");
		if (settings[8]>0)  strcpy(namefile,"pot");
 		sprintf(stringnumb, "%d", typpot[h][contatore]);
		if (settings[8]>0)  strcat(namefile,stringnumb);
		if (settings[8]>0)  strcat(namefile,".aut");
		}
 //******************************************************************************************************
 //*************************potenziale gaussiano*********************************************************
//********************************************************************************************************
	if ((typpot[h][contatore]<=-1) && (typpot[h][contatore]>-100))  
	{
 		FILE *f40 = fopen("potmem1.aut","r");
 		row[0]='q';
		risnow=0;
		risafter=0;
		while (row[0]!='*')
		{
		fscanf(f40,"%s",row);
 
		while ((row[0]!='P') && (row[0]!='*'))
		{
			fscanf(f40,"%s",row);
 		}
		fscanf(f40,"%s",row);
 
		number=atoi(row)*(-1);
 		if (number==typpot[h][contatore])
		{
		for(w=0;w<=dim;w++)
		{
			fscanf(f40,"%s",row);
			param[w]=atof(row);
		}					
			fscanf(f40,"%s",row);
   			cutoff=atof(row);
   			distcut=0;
   			distcut2=0;
  		for (w=1;w<=dim;w++)
		{

			risnow=risnow+param[w]*(x[v][w]-x[h][w])*(x[v][w]-x[h][w]);
			risafter=risafter+param[w]*(xmov[z][w]-x[h][w])*(xmov[z][w]-x[h][w]);			
            distcut=distcut+(xmov[z][w]-x[h][w])*(xmov[z][w]-x[h][w]);
            distcut2=distcut2+(x[v][w]-x[h][w])*(x[v][w]-x[h][w]);
            
            
		}
   		distcut=sqrt(distcut);
        distcut2=sqrt(distcut2);
		probnow=param[0]*exp(risnow);
		probafter=param[0]*exp(risafter);
        if (cutoff<distcut) probafter=0.000000000000001;
        if (cutoff<distcut2) probnow=0.000000000000001;
        if (settings[16]>0)
        {
        if ((distcut2>cutoff) && (distcut<cutoff)) probafter=0.000000000000001;
        if ((distcut2<cutoff) && (distcut>cutoff)) probafter=param[0]*exp(risafter);
        }
        if (preypredator[h]!=0)
		{
		    if (settings[13]!=4)
		    {
			
	 		prob[0]=prob[0]+probnow;
	 		prob[z]=prob[z]+probafter;
	 	   }
	 		if (settings[13]==4)
	 		{
				if (prob[0]==0)
				{
					prob[0]=probnow;
				}
					
	 			if ((prob[0]!=0) && (probnow<prob[0]))
				 {
				   
				 memgredyent=h;
				 prob[0]=probnow;
	 		 }
			 }
		
 	 }
    }  
 	}
  	fclose(f40);	
	}// fine potmem1 (guassian pot)
//*************************************************************************************************
//*********************************potenziale arctan centrale*********************************************************************
//*************************************************************************************************	
    if ((typpot[h][contatore]<=-101) && (typpot[h][contatore]>-200))  
	{
 		FILE *f40 = fopen("potmem2.aut","r");
		row[0]='q';
		risnow=0;
		risafter=0;
    	while (row[0]!='*')
		{
		fscanf(f40,"%s",row);
		while ((row[0]!='P') && (row[0]!='*'))
		{
			fscanf(f40,"%s",row);
 		}
		fscanf(f40,"%s",row);
		number=atoi(row)*(-1);
 		if (number==typpot[h][contatore])
		{
		for(w=0;w<=dim;w++)
		{
			fscanf(f40,"%s",row);
			param[w]=atof(row);
		}					
 			fscanf(f40,"%s",row);
   			cutoff=atof(row);
   			distcut=0;
            distcut2=0;
 		for (w=1;w<=dim;w++)
		{
			risnow=risnow+param[w]*(x[v][w]-x[h][w])*(x[v][w]-x[h][w]);
			risafter=risafter+param[w]*(xmov[z][w]-x[h][w])*(xmov[z][w]-x[h][w]);			
            distcut=distcut+(xmov[z][w]-x[h][w])*(xmov[z][w]-x[h][w]);
            distcut2=distcut2+(x[v][w]-x[h][w])*(x[v][w]-x[h][w]);
  		}
    	distcut=sqrt(distcut);
    	distcut2=sqrt(distcut2);
  		probnow=param[0]*atan(sqrt(risnow));
		probafter=param[0]*atan(sqrt(risafter));
		if (probnow<0) probnow=-probnow;
		if (probafter<0) probafter=-probafter;
        if (cutoff<distcut) probafter=0.000000000000001;        
        if (cutoff<distcut2) probnow=0.000000000000001;
        if (settings[16]>0)
        {
        if ((distcut2>cutoff) && (distcut<cutoff)) probafter=0.000000000000001;
        if ((distcut2<cutoff) && (distcut>cutoff)) probafter=param[0]*atan(sqrt(risafter));
		if (probafter<0) probafter=-probafter;
        }
        if (preypredator[h]!=0)
		{
		    if (settings[13]!=4)
		    {
			
	 		prob[0]=prob[0]+probnow;
	 		prob[z]=prob[z]+probafter;
	 	   }
	 		if (settings[13]==4)
	 		{
				if (prob[0]==0)
				{
					prob[0]=probnow;
				}
					
	 			if ((prob[0]!=0) && (probnow<prob[0]))
				 {
				   
				 memgredyent=h;
				 prob[0]=probnow;
	 		 }
 	 			
			 }
	 }

     	}	
      }
		fclose(f40);		
	}// fine potmem2 (arctang pot)
//************************************************************************
//********************potenziale quadrico********************************
//************************************************************************
	if ((typpot[h][contatore]<=-201) && (typpot[h][contatore]>-300))  
	{
 		FILE *f40 = fopen("potmem3.aut","r");
		row[0]='q';
		risnow=0;
		risafter=0;
		while (row[0]!='*')
		{
		fscanf(f40,"%s",row);
 		while ((row[0]!='P') && (row[0]!='*'))
		{
			fscanf(f40,"%s",row);
 		}
		fscanf(f40,"%s",row);
		number=atoi(row)*(-1);
 		if (number==typpot[h][contatore])
		{
		for(w=1;w<=dim;w++)
		{
			fscanf(f40,"%s",row);
			param[w]=atof(row);
     	}					
 			fscanf(f40,"%s",row);
   			cutoff=atof(row);
   			distcut=0;
            distcut2=0;
 		for (w=1;w<=dim;w++)
		{
			risnow=risnow+param[w]*(x[v][w]-x[h][w])*(x[v][w]-x[h][w]);
			risafter=risafter+param[w]*(xmov[z][w]-x[h][w])*(xmov[z][w]-x[h][w]);			
            distcut=distcut+(xmov[z][w]-x[h][w])*(xmov[z][w]-x[h][w]);
            distcut2=distcut2+(x[v][w]-x[h][w])*(x[v][w]-x[h][w]);
     	}

    	distcut=sqrt(distcut);
    	distcut2=sqrt(distcut2);
		probnow=(risnow);
		probafter=(risafter);
        if (cutoff<distcut) probafter=0;
        if (cutoff<distcut2) probnow=0;
        if (settings[16]>0)
        {
        if ((distcut2>cutoff) && (distcut<cutoff)) probafter=0.000000000000001;
        if ((distcut2<cutoff) && (distcut>cutoff)) probafter=risafter;
        }
        if (preypredator[h]!=0)
		{
		    if (settings[13]!=4)
		    {
			
	 		prob[0]=prob[0]+probnow;
	 		prob[z]=prob[z]+probafter;
	 	   }
	 		if (settings[13]==4)
	 		{
				if (prob[0]==0)
				{
					prob[0]=probnow;
				}
	 			if ((prob[0]!=0) && (probnow<prob[0]))
				 {
				   
				 memgredyent=h;
				 prob[0]=probnow;
	 		 }
					
 	 			
			 }
		

	 }

 	}	
   }
		fclose(f40);		
	}// fine potmem3 (quadrica pot)
//*********************************************************************
//********************potenziale sinusoidale***************************
//**********************************************************************
	if ((typpot[h][contatore]<=-301) && (typpot[h][contatore]>-400))  
	{
 		FILE *f40 = fopen("potmem4.aut","r");
		row[0]='q';
		risnow=0;
		risafter=0;
		while (row[0]!='*')
		{
		fscanf(f40,"%s",row);
		while ((row[0]!='P') && (row[0]!='*'))
		{
			fscanf(f40,"%s",row);
 		}
		fscanf(f40,"%s",row);
		number=atoi(row)*(-1);
 		if (number==typpot[h][contatore])
		{
		for(w=0;w<=dim;w++)
		{
			fscanf(f40,"%s",row);
			param[w]=atof(row);
		}					
 			fscanf(f40,"%s",row);
   			cutoff=atof(row);
   			distcut=0;
            distcut2=0;
 		for (w=1;w<=dim;w++)
		{
			risnow=risnow+param[w]*(x[v][w]-x[h][w])*(x[v][w]-x[h][w]);
			risafter=risafter+param[w]*(xmov[z][w]-x[h][w])*(xmov[z][w]-x[h][w]);			
            distcut=distcut+(xmov[z][w]-x[h][w])*(xmov[z][w]-x[h][w]);
            distcut2=distcut2+(x[v][w]-x[h][w])*(x[v][w]-x[h][w]);
     	}
    	distcut=sqrt(distcut);
        distcut2=sqrt(distcut2);                      
     	probnow=param[0]*sin(sqrt(risnow));
		probafter=param[0]*sin(sqrt(risafter));
		if (probnow<0) probnow=-probnow;
		if (probafter<0) probafter=-probafter;
        if (cutoff<distcut) probafter=0.000000000000001;
        if (cutoff<distcut2) probnow=0.000000000000001;
        if (settings[16]>0)
        {
        if ((distcut2>cutoff) && (distcut<cutoff)) probafter=0.000000000000001;
        if ((distcut2<cutoff) && (distcut>cutoff)) probafter=param[0]*sin(sqrt(risafter));
		if (probafter<0) probafter=-probafter;
        }

        if (preypredator[h]!=0)
		{
		    if (settings[13]!=4)
		    {
			
	 		prob[0]=prob[0]+probnow;
	 		prob[z]=prob[z]+probafter;
	 	   }
	 		if (settings[13]==4)
	 		{
				if (prob[0]==0)
				{
					prob[0]=probnow;
				}
					
	 			if ((prob[0]!=0) && (probnow<prob[0]))
				 {
				   
				 memgredyent=h;
				 prob[0]=probnow;
	 		 }
 	 			
			 }
     	 }

  		}	
        }
		fclose(f40);		
     	}
//****************** fine potmem4 (sin)**********************
//********************************************************
//**********************potenziale sinc*******************
//*********************************************************
	if ((typpot[h][contatore]<=-401) && (typpot[h][contatore]>-500))  
	{
 		FILE *f40 = fopen("potmem5.aut","r");
		row[0]='q';
		risnow=0;
		risafter=0;
		while (row[0]!='*')
		{
		fscanf(f40,"%s",row);
		while ((row[0]!='P') && (row[0]!='*'))
		{
			fscanf(f40,"%s",row);
 		}
		fscanf(f40,"%s",row);
 
		number=atoi(row)*(-1);
 		if (number==typpot[h][contatore])
		{
		for(w=0;w<=dim;w++)
		{
			fscanf(f40,"%s",row);
			param[w]=atof(row);
		}					
 			fscanf(f40,"%s",row);
   			cutoff=atof(row);
   			distcut=0;
   			distcut2=0;          
		for (w=1;w<=dim;w++)
            {
			risnow=risnow+param[w]*(x[v][w]-x[h][w])*(x[v][w]-x[h][w]);
			risafter=risafter+param[w]*(xmov[z][w]-x[h][w])*(xmov[z][w]-x[h][w]);			
            distcut=distcut+(xmov[z][w]-x[h][w])*(xmov[z][w]-x[h][w]);
            distcut2=distcut2+(x[v][w]-x[h][w])*(x[v][w]-x[h][w]);
      		}
    	distcut=sqrt(distcut);
    	distcut2=sqrt(distcut2);
    	probnow=param[0]*sin(sqrt(risnow))/sqrt(risnow);
		probafter=param[0]*sin(sqrt(risafter))/sqrt(risafter);
		if (probnow<0) probnow=-probnow;
		if (probafter<0) probafter=-probafter;
        if (cutoff<distcut) probafter=0.000000000000001;;
        if (cutoff<distcut2) probnow=0.000000000000001;;
        if (settings[16]>0)
        {
        if ((distcut2>cutoff) && (distcut<cutoff)) probafter=0.000000000000001;
        if ((distcut2<cutoff) && (distcut>cutoff)) 
        {
         probafter=param[0]*sin(sqrt(risafter))/sqrt(risafter);
		 if (probafter<0) probafter=-probafter;
         }                    
        }
        if (preypredator[h]!=0)
		{
		    if (settings[13]!=4)
		    {
			
	 		prob[0]=prob[0]+probnow;
	 		prob[z]=prob[z]+probafter;
	 	   }
	 		if (settings[13]==4)
	 		{
				if (prob[0]==0)
				{
					prob[0]=probnow;
				}
					
 	 			if ((prob[0]!=0) && (probnow<prob[0]))
				 {
				   
				 memgredyent=h;
				 prob[0]=probnow;
	 		 }
	 			
			 }
     	 }

		}	
        }
		fclose(f40);		
     	}// *******fine potmem4 (sinc)*******************
    //*********************potmem******************************
    //**********************1/(x**2+1)**************************
    //************************************************************
	if ((typpot[h][contatore]<=-501) && (typpot[h][contatore]>-600))  
	{
 		FILE *f40 = fopen("potmem6.aut","r");
		row[0]='q';
		risnow=0;
		risafter=0;
		while (row[0]!='*')
		{
		fscanf(f40,"%s",row);
		while ((row[0]!='P') && (row[0]!='*'))
		{
			fscanf(f40,"%s",row);
 		}
		fscanf(f40,"%s",row);
		number=atoi(row)*(-1);
 		if (number==typpot[h][contatore])
		{
 		for(w=0;w<=dim;w++)
     	{
			fscanf(f40,"%s",row);
			param[w]=atof(row);
		}					
 			fscanf(f40,"%s",row);
   			cutoff=atof(row);
   			distcut=0;
            distcut2=0;
 		for (w=1;w<=dim;w++)
		{
			risnow=risnow+param[w]*(x[v][w]-x[h][w])*(x[v][w]-x[h][w]);
			risafter=risafter+param[w]*(xmov[z][w]-x[h][w])*(xmov[z][w]-x[h][w]);			
            distcut=distcut+(xmov[z][w]-x[h][w])*(xmov[z][w]-x[h][w]);
            distcut2=distcut2+(x[v][w]-x[h][w])*(x[v][w]-x[h][w]);
		}
    	distcut=sqrt(distcut);
    	distcut2=sqrt(distcut2);
		probnow=param[0]/(risnow+1);
		probafter=param[0]/(risafter+1);
		if (probnow<0) probnow=-probnow;
		if (probafter<0) probafter=-probafter;
        if (cutoff<distcut) probafter=0.000000000000001;
        if (cutoff<distcut2) probnow=0.000000000000001;
        if (settings[16]>0)
        {
        if ((distcut2>cutoff) && (distcut<cutoff)) probafter=0.000000000000001;
        if ((distcut2<cutoff) && (distcut>cutoff)) 
        {
          		probafter=param[0]/(risafter+1);
            	if (probafter<0) probafter=-probafter;
        }                     
        }
         if (preypredator[h]!=0)
		{
		    if (settings[13]!=4)
		    {
			
	 		prob[0]=prob[0]+probnow;
	 		prob[z]=prob[z]+probafter;
	 	   }
	 		if (settings[13]==4)
	 		{
				if (prob[0]==0)
				{
					prob[0]=probnow;
				}
					
	 			if ((prob[0]!=0) && (probnow<prob[0]))
				 {
				   
				 memgredyent=h;
				 prob[0]=probnow;
	 		 }
 	 			
			 }
		
      	 }

 		}	
        }
		fclose(f40);		
	}// fine potmem4 (1/x**2+1)
 //******************************************************************************************************
 //*************************potenziale exp(ax+by+cz+......)*********************************************************
//********************************************************************************************************
	if ((typpot[h][contatore]<=-601) && (typpot[h][contatore]>-700))  
	{
 	    double mod[20];
     	FILE *f40 = fopen("potmem7.aut","r");
 		row[0]='q';
    	risnow=0;
		risafter=0;
		while (row[0]!='*')
		{
		fscanf(f40,"%s",row);
     	while ((row[0]!='P') && (row[0]!='*'))
		{
			fscanf(f40,"%s",row);
 		}
		fscanf(f40,"%s",row);
 		number=atoi(row)*(-1);
 		if (number==typpot[h][contatore])
		{
		for(w=0;w<=dim;w++)
		{
			fscanf(f40,"%s",row);
			param[w]=atof(row);
     	}					
		for(w=1;w<=dim;w++)   //da sistemare e vedere per i moduli
		{
			fscanf(f40,"%s",row);
			mod[w]=atof(row);
     	}					
			fscanf(f40,"%s",row);
   			cutoff=atof(row);
   			distcut=0;
   			distcut2=0;
 		for (w=1;w<=dim;w++)
		{
              if (mod[w]==0)
              {               
           	  risnow=risnow+param[w]*(x[v][w]-x[h][w]);
		      risafter=risafter+param[w]*(xmov[z][w]-x[h][w]);
              }
              if (mod[w]==1)
              {               
           	  risnow=risnow+param[w]*abs((x[v][w]-x[h][w]));
		      risafter=risafter+param[w]*abs((xmov[z][w]-x[h][w]));
              }
              distcut=distcut+(xmov[z][w]-x[h][w])*(xmov[z][w]-x[h][w]);
              distcut2=distcut2+(x[v][w]-x[h][w])*(x[v][w]-x[h][w]);
              }
   		distcut=sqrt(distcut);
        distcut2=sqrt(distcut2);
		probnow=param[0]*exp(risnow);
		probafter=param[0]*exp(risafter);
        if (cutoff<distcut) probafter=0.000000000000001;
        if (cutoff<distcut2) probnow=0.000000000000001;
        if (settings[16]>0)
        {
        if ((distcut2>cutoff) && (distcut<cutoff)) probafter=0.000000000000001;
        if ((distcut2<cutoff) && (distcut>cutoff)) probafter=param[0]*exp(risafter);
        }
        if (preypredator[h]!=0)
		{
		    if (settings[13]!=4)
		    {
			
	 		prob[0]=prob[0]+probnow;
	 		prob[z]=prob[z]+probafter;
	 	   }
	 		if (settings[13]==4)
	 		{
				if (prob[0]==0)
				{
					prob[0]=probnow;
				}
					
	 			if ((prob[0]!=0) && (probnow<prob[0]))
				 {
				   
				 memgredyent=h;
				 prob[0]=probnow;
	 		 }
 	 			
			 }
		
      	 }

     }  
 	}
  	fclose(f40);	
	}// fine potmem7 (exp potential)
	if ((typpot[h][contatore]<=-701) && (typpot[h][contatore]>-800))  
	{
 		FILE *f40 = fopen("potmem8.aut","r");
		row[0]='q';
		risnow=0;
		risafter=0;
		while (row[0]!='*')
		{
		fscanf(f40,"%s",row);
		while ((row[0]!='P') && (row[0]!='*'))
		{
			fscanf(f40,"%s",row);
 		}
		fscanf(f40,"%s",row);
		number=atoi(row)*(-1);
 		if (number==typpot[h][contatore])
		{
 		for(w=0;w<=dim;w++)
     	{
			fscanf(f40,"%s",row);
			param[w]=atof(row);
		}					
 			fscanf(f40,"%s",row);
   			cutoff=atof(row);
   			distcut=0;
            distcut2=0;
 		for (w=1;w<=dim;w++)
		{
			risnow=risnow+param[w]*(x[v][w]-x[h][w])*(x[v][w]-x[h][w]);
			risafter=risafter+param[w]*(xmov[z][w]-x[h][w])*(xmov[z][w]-x[h][w]);			
            distcut=distcut+(xmov[z][w]-x[h][w])*(xmov[z][w]-x[h][w]);
            distcut2=distcut2+(x[v][w]-x[h][w])*(x[v][w]-x[h][w]);
		}
    	distcut=sqrt(distcut);
    	distcut2=sqrt(distcut2);
		probnow=param[0]*sqrt(risnow)/(risnow+1);
		probafter=param[0]*sqrt(risafter)/(risafter+1);
		if (probnow<0) probnow=-probnow;
		if (probafter<0) probafter=-probafter;
        if (cutoff<distcut) probafter=0.000000000000001;
        if (cutoff<distcut2) probnow=0.000000000000001;
        if (settings[16]>0)
        {
        if ((distcut2>cutoff) && (distcut<cutoff)) probafter=0.000000000000001;
        if ((distcut2<cutoff) && (distcut>cutoff)) 
        {
          		probafter=param[0]*sqrt(risafter)/(risafter+1);
            	if (probafter<0) probafter=-probafter;
        }                     
        }
         if (preypredator[h]!=0)
		{
		    if (settings[13]!=4)
		    {
			
	 		prob[0]=prob[0]+probnow;
	 		prob[z]=prob[z]+probafter;
	 	   }
	 		if (settings[13]==4)
	 		{
				if (prob[0]==0)
				{
					prob[0]=probnow;
				}
					
	 			if ((prob[0]!=0) && (probnow<prob[0]))
				 {
				   
				 memgredyent=h;
				 prob[0]=probnow;
	 		 }
 	 			
			 }
		
      	 }

 		}	
        }
		fclose(f40);		
	}// fine potmem4 (x/x**2+1)	
//*****************************************************************************
//******************potenziale da caricare tramite file************************
//*****************************************************************************
//********spiegazione del cut off per i potenziali impostati***********************
//---------------------------------------------------------------------------------
	if (typpot[h][contatore]>0)
	{
	FILE *f3 = fopen(namefile,"r");
    row[0]='q';
	while ((row[0]!='e'))
	{
 		fscanf(f3,"%s",row);
		if (row[0]=='P')
		{
 			fscanf(f3,"%s",row);
			number=atoi(row);
 			fscanf(f3,"%s",row);
			cutoff=atoi(row);
			if (number==typpot[h][contatore])
			{	 
 //******************************implemento per dimensione generica************************************************
				 	while(row[0]!='*')
					{
     	 				for (w=1;w<=dim;w++)
				                {
     						if (row[0]!='*')
							{		
							fscanf(f3,"%s",row);
							if (row[0]!='*')
							{
							num[w]=atof(row);
							num[w]=num[w]+x[h][w];
 							}
							}
						}	
						distx=0;
						distx2=0;
						metricx=0;
						metricx2=0;
						distcut=0;
						distcut2=0;
						if (row[0]!='*') 
      			        {
           				   fscanf(f3,"%s",row);
						   fscanf(f3,"%s",row2);
						   cutoff=atof(row2);
                     				  }
 		 				for (w=1;w<=dim;w++)
		                {
     					metricx=metricx+(num[w]-x[v][w])*(num[w]-x[v][w]);
						metricx2=metricx2+(num[w]-xmov[z][w])*(num[w]-xmov[z][w]);
 						}
     					distx=sqrt(metricx);
						distx2=sqrt(metricx2);
//*****************prende il punto piu vicino alla posizione presente****************
     		 			if (distx<distmem)
						{
							distmem=distx;
							probnow=atof(row);
 						}
//*****************prende la posiziome piu vicina al posizione scelta*****************************
						if (distx2<distmem2)
						{
							distmem2=distx2;
 							probafter=atof(row);
     					}
 						}//chiudo while
 						contsom++; 
 						double pbaftmem=probafter;
						double pbnowmem=probnow;	
//*****************per entrambi se esce dal raggio di azione non considera la funzione***********************
					        if (cutoff<distmem2) probafter=0.000000000000001;;
        					if (cutoff<distmem) probnow=0.000000000000001;;
//**********setta l'opzione "spingi fuori o lascia fuori************************
//***********se distmem ovvero posizione presente e' ancora dentro il raggio e distmem2 ovvero posizione futura************
//**********e fouri forza fuori con probabilita uguale  a quella calcolata in quel punto*************************
					        if (settings[16]>0)
        					{
        					if ((distmem>cutoff) && (distmem2<cutoff)) probafter=0.000000000000001;
        					if ((distmem<cutoff) && (distmem2>cutoff)) 
        						{
      							probafter=pbaftmem;  //da capire meglio
					           }                     
              			        }
        if (preypredator[h]!=0)
		{
		    if (settings[13]!=4)
		    {
			
	 		prob[0]=prob[0]+probnow;
	 		prob[z]=prob[z]+probafter;
	 	   }
	 		if (settings[13]==4)
	 		{
				if (prob[0]==0)
				{
					prob[0]=probnow;
				}
					
	 			if ((prob[0]!=0) && (probnow<prob[0]))
				 {
				   
				 memgredyent=h;
				 prob[0]=probnow;
	 		 }
 	 			
			 }
		
      	 }

       			}
  			}//chiudo pot
		}//chiudo row 2* 
		fclose(f3);
	}//chiudo if typpot
 		//anche qui nello spostamento cambierai le dimensioni e scriverai sui diversi files
	}
    contatore++;
//    printf ("connectactive %d",connectactive[v][h]);
     
    if (connectactive[v][h]==0)
    {
   
    prob[0]=prob[0]-probnow+0.0000000000000001;
    prob[z]=prob[z]-probafter+0.000000000000001;
    }                    
    if (connectactive[v][h]>0) 
    {
 
     distconnectactive=0;
     for (w=1;w<=dim;w++)
     {
         distconnectactive=distconnectactive+(x[h][w]-x[v][w])*(x[h][w]-x[v][w]);
         
     }
         distconnectactive=sqrt(distconnectactive);
     if (distconnectactive<lengthconnectactive[v][h]) 
     {
         connectactive[v][h]--;
     }
     }

	}//chiudo while typpot
	}//chiudo if h div
        }
//************* setting[15] esclude la considerazione del punto presente nel calcolo delle scelte per il futuro movimento***************
        if (settings[15]>0)
        {
           prob[0]=0.0000000001;
           }  
//*************************settings[9] è il numero di possibili scelte************************ 
		if (z==settings[9])
		{
 		if (settings[12]==2)
		{
 			double min=1000000000000000;
			for(o=0;o<=settings[9];o++)
			{
			 	if (min>prob[o])   min=prob[o];
			}
			for(o=0;o<=settings[9];o++)
			{
			 	prob[o]=prob[o]-min;
			}
		}
		// mettere opzione parti dal minimo assoluto//***********
//****************** entra solo se ha considerato tutti i passi dati nel MAIN**************
 		somprob=0;
        if (settings[12]==4) adj=zeroset[v];
        if (settings[12]!=4) adj=0;
 		for (dd=1;dd<=settings[9];dd++)
		{
            prob[dd]=prob[dd]-adj;                           
			somprob=somprob+prob[dd];
            if ((prob[dd])<minimi[v]) minimi[v]=prob[dd];
 		}
            prob[0]=prob[0]-adj;   
			somprob=somprob+prob[0];
		if (somprob==0)
		{
			somprob=settings[9]*0.01;
			for(o=0;o<=settings[9];o++)
			{
				prob[o]=0.0000000000000000000000000000000000000000000000001;
				somprob=somprob+0.0000000000000000000000000000000000000000000000001;
				}
		}
    for (o=1;o<=dim;o++)
    {
         xold[v][o]=x[v][o];
    }
    //**************************gestione blocco if********************
    contatoreif=0;
    metriconif=0;
    while (( distif[v][contatoreif]!=0 ) && (contatoreif<=20))
     {
          metricaconif=0;
          for (ibeg=begintif[v][contatoreif];ibeg<=endintif[v][contatoreif];ibeg++)
          {
                       for (contdim=1;contdim<=dim;contdim++)
                      {
                          metricaconif=metricaconif+(x[v][contdim]-x[ibeg][contdim])*(x[v][contdim]-x[ibeg][contdim]);
                                }                                                                       
                      if (sqrt(metricaconif)<distif[v][contatoreif])
                      {
                            fixed[v]=1;                                            
                }
           }          
  contatoreif++;
}
 	if (1==1) 
	{
 		casual=rand()%100;
		flotcasual=casual*somprob/100.0;
		if (flotcasual==0) flotcasual=0.001*somprob/100.0;
 		probsce=0;
		contaprob=-1;
     	//*******pezzo salva min prob**********
    	while (probsce<flotcasual)
		{ 	
			contaprob++;
			probsce=probsce+(prob[contaprob]);
     	}
		
		if (contaprob>0)
			{
			for (w=1;w<=dim;w++)
                {
 				if (settings[11]!=0)
				{
				distvirt=0;
				for (o=1;o<=dim;o++)
				{
					distvirt=distvirt+(xmov[contaprob][o])*(xmov[contaprob][o]);
     			} 
				distvirt=sqrt(distvirt);
				if (distvirt<settings[11])
				{
					x[v][w]=xmov[contaprob][w];
				}	 
			}
			if (settings[11]==0)
			{
				x[v][w]=xmov[contaprob][w];
		
			}
			}	
			}				 
	}
//**************************modalita minimo*****************************
		if (settings[13]==2) 
		{
		minimal=1000000000000000;
 		for (l=0;l<=settings[9];l++)
		{
		if (minimal>prob[l])
		{
 		minimal=prob[l];
 		nnn=l;	
		}	
		}
  		for (w=1;w<=dim;w++)
                {
 				if (settings[11]!=0)
				{
				distvirt=0;
				for (o=1;o<=dim;o++)
				{
					distvirt=distvirt+(xmov[nnn][o])*(xmov[nnn][o]);
										
					} 
				distvirt=sqrt(distvirt);
				if (distvirt<settings[11])
				{
					if (nnn>=0)
					{
						x[v][w]=xmov[nnn][w];
					}
				}	 
			}
			if (settings[11]==0)
			{
				if (nnn>=0)
				{
					x[v][w]=xmov[nnn][w];
				}	
			}
			}	
		}			
//***************************modalita massimo*******************************
//**************************************************************************
		if (settings[13]==3) 
		{
		minimal=-10000000000000000;
 		for (l=0;l<=settings[9];l++)
		{
		if (minimal<prob[l])
		{
		minimal=prob[l];
		nnn=l;	
		}	
		}
 		for (w=1;w<=dim;w++)
        {
				if (settings[11]!=0)
				{
				distvirt=0;
				for (o=1;o<=dim;o++)
				{
					distvirt=distvirt+(xmov[nnn][o])*(xmov[nnn][o]);
					} 
				distvirt=sqrt(distvirt);
				if (distvirt<settings[11])
				{
					if (nnn>=0)
					{
						x[v][w]=xmov[nnn][w];
					}
				}	 
			}
			if (settings[11]==0)
			{
				if (nnn>=0)
				{
					x[v][w]=xmov[nnn][w];
				}	
			}
			}	
		 
		}		
 		
		if ((settings[13]==4) && (memgredyent<=n))
	    {
			//calcolare distanza gredy e versore spostamento
        		
        divisorgeodetic=0;

  		for (w=1;w<=dim;w++)
        {
 		     geodeticvers[w]=0;					    

		}

  		for (w=1;w<=dim;w++)
        {
		    geodeticvers[w]=(x[v][w]-x[memgredyent][w])*(x[v][w]-x[memgredyent][w]);
			divisorgeodetic=divisorgeodetic+geodeticvers[w]*geodeticvers[w];
					    

		}
		divisorgeodetic=sqrt(divisorgeodetic);
  		
 
  		for (w=1;w<=dim;w++)
        {
 			x[v][w]=x[v][w]+geodeticvers[w]/divisorgeodetic;					    
 
		}
		
			
					}			
		
 //*****************************************************************************
 //******************verifica la presenza di vincoli e contorni prima di muoversi
 //***************************************************************************
         if (settings[14]>0) 
        {          		
            vincminimal=10000000000000000;         
         	FILE *f36 = fopen("vinc.aut","r");
        	row[0]='q';
            while (row[0]!='*')
            {
                  for (o=1;o<=dim;o++)
                  {
                      if (row[0]!='*')
                      {
                      fscanf(f36,"%s",row);
                      if (row[0]!='*')  vinc[o]=atof(row);
                      }
                  }
                  if (row[0]!='*')
                  {   
                  for (o=1;o<=10;o++)
                  {
                      coef[o]=0;
                  }
                  for (o=1;o<=dim;o++)
                  {
                      coef[o]=(x[v][o]-xold[v][o]);
                  }
                 vincpar=1.0/settings[14];
                 incvinc=0; 
                 for (o=1;o<=settings[14];o++)
                  {
                      vincdist=0;
                      for (kk=1;kk<=dim;kk++)
                      {    
                      vincdist=vincdist+(xold[v][kk]+coef[kk]*(incvinc)-vinc[kk])*(xold[v][kk]+coef[kk]*(incvinc)-vinc[kk]);
                      }
                      vincdist=sqrt(vincdist); 
                      if (vincdist<vincminimal) vincminimal=vincdist;
                  incvinc=incvinc+vincpar;
                  }
             }  //chiude if row                         	         
        } // chiude while   row
        nomove=0;
        if (vincminimal<settings[17]) // distanza di tocco per riconoscere il vincolo
        {
        for (kk=1;kk<=dim;kk++)
        {
			
            x[v][kk]=xold[v][kk];
        } 
        }
        
fclose(f36);
}  // chiude     settings 14
//****************************scrittura per i vari controllo*******************
//*****************************************************************************
		if (settings[6]==1)
		{
		for (w=1;w<=dim;w++)
		{
			fprintf(f20,"%f\n",x[v][w]);			
		}
			if (contaprob==0) fprintf(f20,"nonmosso\n");
			if (contaprob>0)  fprintf(f20,"mosso\n");
 			fprintf(f20,"somprobafter %f , somprobnow %f\n",prob[contaprob],prob[0]);
	for (ff=1;ff<=settings[9];ff++)
	{		
	 	for (w=1;w<=dim;w++)
			{
				fprintf(f30,"%f\n",xmov[ff][w]);
			}
		fprintf(f30,"*\n");
	}		
     fprintf(f30,"***********************************\n");
		}// chiudo setting 
	for (o=0;o<=settings[9];o++)
	{
		fprintf(f35,"%f\n",prob[o]);
	}
		fprintf(f35,"*\n");
	}//chiudo if scelta prob (settings[9])
fclose(f20); 
fclose(f30); 
fclose(f35);
}//chiudo void

void calculate(int np,int n,float settings[],double x[][10],int typpot[][np],int whoactionbeg[][np],int whoactionend[][np],int begintime[][np],int endtime[][np],int fixed[],double zeroset[],double minimi[],int begif[][np], int endif[][np], int begintif[][np], int endintif[][np],double distif[][np],int **connectactive,double **lengthconnectactive,int preypredator[],double distpreyset)
{
int step=0;
char stringa[40];
float casual;
int i,sign,k,j,w,r,z,s,t,distpreypredator;
double prob[(int)settings[9]+1];
double xmov[(int)settings[9]+1][10];
FILE *f4 = fopen("posres.aut","w");
FILE *f5=fopen("minimi.aut","w");
//***********dimension 1*****************************
//minabs=10000000000000;
  	for (i=0;i<=settings[9];i++)
	{ 	
		for(j=0;j<=10;j++)
		{
			xmov[i][j]=0;
		}  
	}
 	srand((unsigned)time(NULL));
 	for(j=1;j<=settings[2];j++)
	{
  	for (i=1;i<=n;i++)
	{	
 		for (r=0;r<=settings[9]+1;r++) prob[r]=0;
		for (z=1;z<=settings[9];z++)
		{
	 	//qui va ciclato sulle realizzazioni
		if (fixed[i]!=1) 
		{
//*************il primo tipo di step \E8 settato qui in futuro degli if cambieranno varie tipologie*************
           for (w=1;w<=settings[0];w++)
	       {
         		casual=((rand()%100 +1)/(float)(100));
		        sign=(rand()%2);
		        if (sign==0) sign=-1;
		        if (sign==1) sign=1;
		        casual=casual*settings[5]*sign;
          		if ((casual>0) && (casual<settings[10])) casual=settings[10];
         		if ((casual<0) && (casual>-settings[10])) casual=-settings[10];
        		xmov[z][w]=x[i][w]+casual;
        		xmov[0][w]=x[i][w];
        		
  		}
  	 	prob[0]=0;
		seekprob(np,n,settings[0],x,xmov,prob,typpot,whoactionbeg,whoactionend,begintime,endtime,j,i,settings,z,zeroset,minimi,begif,endif,begintif,endintif,distif,fixed,connectactive,lengthconnectactive,preypredator);
		//***************controlla le distanze con le prede e cala 1 in caso*********
 		
     	}//chiudo fixed

	}//chiduo for realizzazioni		
	}//chiudo for
		for (t=1;t<=n;t++)
		{
			for (s=1;s<=n;s++)
			{
				if (s!=t)
				{
					if (preypredator[t]>0 && preypredator[s]<0)
					{
						distpreypredator=0;
						for (w=1;w<=settings[0];w++)
						{
							distpreypredator=distpreypredator+(x[t][w]-x[s][w])*(x[t][w]-x[s][w]);
						}
						distpreypredator=sqrt(distpreypredator);
						if (distpreypredator<distpreyset) preypredator[t]--;
					}
				}
			}
		}


	for (k=1;k<=n;k++)
		{		
                for (w=1;w<=settings[0];w++)
	       {
			fprintf(f4,"%f\n",x[k][w]);
      		}
	}
	fprintf(f4,"*\n");
}//chiudo for
fprintf(f4,"**\n");
   for (k=1;k<=n;k++)
   {
       fprintf(f5,"%f\n",minimi[k]);                                   
   }
	fprintf(f5,"*\n");
fclose(f4);
fclose(f5);
}
