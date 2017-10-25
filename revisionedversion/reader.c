#include <stdio.h>
#include <stdlib.h>

void readfile(int np,int n,float settings[],double x[][10],int whoactionbeg[][np],int whoactionend[][np],int typpot[][np],int begintime[][np],int endtime[][np],int fixed[],double zeroset[],int begif[][np],int endif[][np],int begintif[][np],int endintif[][np],double distif[][np],int **connectactive,double **lengthconnectactive,int preypredator[],double distprey)
{ 
   
 
   int nsost=n;
  				

   char look;
   char stringa[40];
   FILE *f1 = fopen("main.aut","r");
   float number,number2;
   int contatore,i,k,w,j;
   int contatore2,numero;
   int ii=0;
   int contatore3[nsost+1];
   int contatore4[nsost+1];
    //printf("*************controllo n %d************",*n);			
   if( f1==NULL ) {
   	 printf("Si e' verificato un errore in apertura del file\n");
    	 exit(1);
  }
   look='F';


   while ((stringa[0]!='E') || (stringa[1]!='N') || (stringa[2]!='D') || (stringa[8]!='N') || (stringa[9]!='G'))
   { 	 
	   fscanf(f1,"%s",stringa);
	//serie di cicli if per riempire il vettore settings
	   if ((stringa[0]=='S') &&(stringa[1]=='E') &&(stringa[2]=='T'))
		{ 
			look='V';
			//printf("ciao");
		}

	   if ((stringa[0]=='D') && (stringa[1]=='I') && (stringa[2]=='M') && (look=='V'))
		{
                        fscanf(f1,"%f",&number);
			settings[0]=number;
 			 				

		}


	   if ((stringa[0]=='T') && (stringa[1]=='Y') && (stringa[2]=='P') && (stringa[6]=='P') && (look=='V'))
		{
                        fscanf(f1,"%f",&number);
			settings[1]=number;
 
		}

	   if ((stringa[0]=='N') && (stringa[1]=='S') && (stringa[2]=='T') && (stringa[4]=='P') && (look=='V'))
		{
                        fscanf(f1,"%f",&number);
			settings[2]=number;
 
		}
	  
	   if ((stringa[0]=='M') && (stringa[1]=='I') && (stringa[2]=='N') && (stringa[6]=='P') && (look=='V'))
		{
                        fscanf(f1,"%f",&number);
			settings[3]=number;
 		}
	  	
	   if ((stringa[0]=='S') && (stringa[1]=='T') && (stringa[2]=='O') && (stringa[8]=='S') && (look=='V'))
		{
                        fscanf(f1,"%f",&number);
			settings[4]=number;
 		}
	   if ((stringa[0]=='M') && (stringa[1]=='A') && (stringa[6]=='P'))
	   {
                        fscanf(f1,"%f",&number);
			settings[5]=number;
 

           }

	   if ((stringa[0]=='M') && (stringa[1]=='E') && (stringa[2]=='M') && (stringa[3]=='F'))
	   {
                        fscanf(f1,"%f",&number);
			settings[6]=number;
 

           }

	   if ((stringa[0]=='N') && (stringa[1]=='E') && (stringa[2]=='L'))
	   {
                        fscanf(f1,"%f",&number);
			settings[7]=number;
 

           }

	   if ((stringa[0]=='M') && (stringa[1]=='U') && (stringa[2]=='L'))
	   {
                        fscanf(f1,"%f",&number);
			settings[8]=number;
 

           }

	   if ((stringa[0]=='C') && (stringa[1]=='H') && (stringa[2]=='O'))
	   {
                        fscanf(f1,"%f",&number);
			settings[9]=number;
 

           }	  	
  

	   if ((stringa[0]=='M') && (stringa[1]=='I') && (stringa[6]=='P'))
	   {
                        fscanf(f1,"%f",&number);
			settings[10]=number;
 

           }

	   if ((stringa[0]=='M') && (stringa[1]=='A') && (stringa[4]=='I') &&(stringa[8]=='P'))
	   {
                        fscanf(f1,"%f",&number);
			settings[11]=number;
 

           }

	   if ((stringa[0]=='T') && (stringa[1]=='Y') && (stringa[4]=='M') &&(stringa[7]=='E'))
	   {
                        fscanf(f1,"%f",&number);
			settings[12]=number;
 

           }

	   if ((stringa[0]=='T') && (stringa[1]=='Y') && (stringa[2]=='P') && (stringa[3]=='E') && (stringa[4]=='S') && (stringa[5]=='I') && (stringa[6]=='M'))
	   {
                        fscanf(f1,"%f",&number);
			settings[13]=number;
 

           }


           if ((stringa[0]=='N') && (stringa[1]=='O') && (stringa[2]=='F') && (stringa[3]=='R') && (stringa[4]=='E') && (stringa[5]=='E'))
	   {

		        fscanf(f1,"%f",&number);
	     		settings[14]=number;
		        fscanf(f1,"%f",&number);
 	     		settings[17]=number;


           }
 
           if ((stringa[0]=='N') && (stringa[1]=='O') && (stringa[2]=='S') && (stringa[3]=='E') && (stringa[4]=='L') && (stringa[5]=='F'))
	       {

		        fscanf(f1,"%f",&number);
	     		settings[15]=number;
  

           }
           if ((stringa[0]=='P') && (stringa[1]=='U') && (stringa[2]=='S') && (stringa[3]=='H') && (stringa[4]=='U') && (stringa[5]=='P'))
	       {

		        fscanf(f1,"%f",&number);
	     		settings[16]=number;
 

           }
           
 


	   if ((stringa[0]=='F') && (stringa[1]=='I') && (stringa[2]=='X'))
 		{

	   while ((stringa[0]!='E'))
           {
           
           fscanf(f1,"%s",stringa);
           if (stringa[0]!='E')
	   {	
	   contatore=0;
	   contatore2=0;	
	   while (stringa[contatore]!=',') contatore++;
	   while (stringa[contatore2]!=')') contatore2++;
	   printf("contatore %d\n",contatore);
	   char cpy5[contatore-1];	
	   for (i=1;i<=contatore;i++) 
	   {	
		 	
		cpy5[i-1]=stringa[i];
	    }

	   int numero5=  atoi(cpy5);
	   printf("numero %d\n",numero5);

	   ii=0;
	   char cpy6[contatore2-contatore-1];	 
	   for (i=contatore+1;i<=contatore2;i++)
	   {	
		cpy6[ii]=stringa[i];
		ii++;	
		}
	   int numero6= atoi(cpy6);
	   printf("numero %d\n",numero6);
           for (k=numero5;k<=numero6;k++)
	   {
		fixed[k]=1;	
	   }

	}

	}

     }


	   if ((stringa[0]=='Z') && (stringa[1]=='E') && (stringa[2]=='R'))
 		{

	   while ((stringa[0]!='E'))
           {
           
           fscanf(f1,"%s",stringa);
           if (stringa[0]!='E')
	   {	
	   contatore=0;
	   contatore2=0;	
	   while (stringa[contatore]!=',') contatore++;
	   while (stringa[contatore2]!=')') contatore2++;
	   printf("contatore %d\n",contatore);
	   char cpy5[contatore-1];	
	   for (i=1;i<=contatore;i++) 
	   {	
		 	
		cpy5[i-1]=stringa[i];
	    }

	   int numero5=  atoi(cpy5);
	   printf("numero %d\n",numero5);

	   ii=0;
	   char cpy6[contatore2-contatore-1];	 
	   for (i=contatore+1;i<=contatore2;i++)
	   {	
		cpy6[ii]=stringa[i];
		ii++;	
		}
	   int numero6= atoi(cpy6);
	   printf("numero %d\n",numero6);
	   fscanf(f1,"%s",stringa);
	   number=atof(stringa);                     
           for (k=numero5;k<=numero6;k++)
	   {
		zeroset[k]=number;	
		printf("ZEROSETTTTTTTTTTTTT %f",zeroset);
	   }

	}

	}

     }


	if ((stringa[0]=='P') && (stringa[1]=='R') && (stringa[2]=='E') && (stringa[3]=='Y'))
	{
	   look='V';
	   printf("IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII");
	   fscanf(f1,"%s",stringa);
	   contatore=0;
	   contatore2=0;
	   while (stringa[contatore]!=',') contatore++;
	   while (stringa[contatore2]!=')') contatore2++;
	   printf("contatore %d\n",contatore);	
	   char cpy[contatore];	
	   for (i=1;i<=contatore;i++) 
	   {	
		 	
		cpy[i-1]=stringa[i];
	    }

	   int numero10=  atoi(cpy);
	   printf("ela peppa !!!!!! numero10 %d\n",numero10);
	   ii=0; 
	   char cpy2[contatore2-1-contatore];	 
	   for (i=contatore+1;i<=contatore2;i++)
	   {	
		cpy2[ii]=stringa[i];
		ii++;	
		}
	   int numero11= atoi(cpy2);
	   printf("numero11 %d\n",numero11);
	   fscanf(f1,"%s",stringa);  //numero di volte essere preso
	   look='V';
	   int numero12=atoi(stringa);    
	   for (i=numero10;i<=numero11;i++)
	   {
		  preypredator[i]=numero12;
		
	   }
	   printf("blammmm");	
	   fscanf(f1,"%s",stringa); //distanza minima to catch
	   double numero13=atof(stringa);    
	   distprey=numero13;
	   
	   	
	}


} 
  //  printf("ciao");
 //  printf("ciao %s",stringa); 
   




fclose(f1);
look='F';
 
fopen("main.aut","r");
   while ((stringa[0]!='E') || (stringa[1]!='N') || (stringa[2]!='D') || (stringa[4]!='Y'))
   {
 	fscanf(f1,"%s",stringa);
	printf("%s",stringa);	    

	if ((stringa[0]=='F') && (stringa[1]=='O') && (stringa[2]=='R'))
	{  
	   look='V';
	   fscanf(f1,"%s",stringa);
	   contatore=0;
	   contatore2=0;
	   while (stringa[contatore]!=',') contatore++;
	   while (stringa[contatore2]!=')') contatore2++;
	   printf("contatore %d\n",contatore);	
	   char cpy[contatore];	
	   for (i=1;i<=contatore;i++) 
	   {	
		 	
		cpy[i-1]=stringa[i];
	    }

	   int numero1=  atoi(cpy);
	   printf("numero1 %d\n",numero1);
	   ii=0; 
	   char cpy2[contatore2-1-contatore];	 
	   for (i=contatore+1;i<=contatore2;i++)
	   {	
		cpy2[ii]=stringa[i];
		ii++;	
		}
	   int numero2= atoi(cpy2);
	   printf("numero2 %d\n",numero2);
	   fscanf(f1,"%s",stringa);
	   look='V';
	   printf("blammmm");	
//**********************************************************************************************
	   if ((stringa[0]=='P') && (stringa[1]=='O') && (stringa[2]=='T'))
	   {	
	   printf("blavvv");	
           while (look=='V')
           {
 
		fscanf(f1,"%s",stringa);
		numero=atoi(stringa);
		printf("potenziale %d",numero);	
		for (i=numero1;i<=numero2;i++)
		{
			contatore3[i]=0;
		        while (typpot[i][contatore3[i]]!=0)
			{
				contatore3[i]++;
                        }
			typpot[i][contatore3[i]]=numero;
		}		
	   
 
           fscanf(f1,"%s",stringa);
	   printf("str %s",stringa);
	   contatore=0;
	   contatore2=0;	
	   while (stringa[contatore]!=',') contatore++;
	   while (stringa[contatore2]!=')') contatore2++;
	   printf("contatore2 %d\n",contatore2);	
	   char cpy3[contatore-1];	 

	   for (i=1;i<=contatore;i++) 
	   {	
		//printf("blo"); 	
		cpy3[i-1]=stringa[i];
	    }

	   int numero3=atoi(cpy3);
	   printf("numero3 %d\n",numero3);
	   ii=0;
	   char cpy4[contatore2-contatore-1];	 
	   for (i=contatore+1;i<=contatore2;i++)
	   {	
		cpy4[ii]=stringa[i];
		ii++;	
		}
	   int numero4= atoi(cpy4);
	   printf("numero4 %d\n",numero4);

		for (i=numero1;i<=numero2;i++)
		{
 		   whoactionbeg[i][contatore3[i]]=numero3;
		   whoactionend[i][contatore3[i]]=numero4;	 


		}		

             	
  			 


//codice.............................
           fscanf(f1,"%s",stringa);

	   contatore=0;
	   contatore2=0;	
	   while (stringa[contatore]!=',') contatore++;
	   while (stringa[contatore2]!=')') contatore2++;
	   printf("contatore %d\n",contatore);
	   char cpy5[contatore-1];	
	   for (i=1;i<=contatore;i++) 
	   {	
		 	
		cpy5[i-1]=stringa[i];
	    }

	   int numero5=  atoi(cpy5);
	   printf("numero5 %d\n",numero5);

	   ii=0;
	   char cpy6[contatore2-contatore-1];	 
	   for (i=contatore+1;i<=contatore2;i++)
	   {	
		cpy6[ii]=stringa[i];
		ii++;	
		}
	   int numero6= atoi(cpy6);
	   printf("numero6 %d\n",numero6);
	for (i=numero1;i<=numero2;i++)
	{
 
	   begintime[i][contatore3[i]]=numero5;
	   endtime[i][contatore3[i]]=numero6;	   
	}

           fscanf(f1,"%s",stringa);
	   printf("blaxx %s",stringa);
	   if ((stringa[0]=='E') && (stringa[5]=='R')) 
	   {
	   	look='F';
               // fscanf(f1,"%s",stringa);
		
	   	
		}
	 //  if (stringa[0]!='E') fscanf(f1,"%s",stringa);
            
	   printf("look %c",look);	
	   	
			
	
//codice.................................
           }
	   }	   	
	   
        //   printf("stringa %s",cpy);
 
 	
	   
		  			
		

	}
	
//********************* to put IDFOR here ***************************//
//*********************************************************************//	
	if ((stringa[0]=='I') && (stringa[1]=='D') && (stringa[2]=='F') && (stringa[5]=='A'))
	{  
 	   fscanf(f1,"%s",stringa);
	   contatore=0;
	   contatore2=0;
	   printf("stringa %s",stringa);
	   while (stringa[contatore]!=',') contatore++;
	   while (stringa[contatore2]!=')') contatore2++;
	   printf("contatore %d\n",contatore);	
	   char cpyb[contatore];	
	   for (i=1;i<=contatore;i++) 
	   {	
		 	
		cpyb[i-1]=stringa[i];
	    }

	   int numero1=  atoi(cpyb);
	   printf("numero1 %d\n",numero1);
	   ii=0; 
	   char cpy2b[contatore2-1-contatore];	 
	   for (i=contatore+1;i<=contatore2;i++)
	   {	
		cpy2b[ii]=stringa[i];
		ii++;	
		}
	   int numero2= atoi(cpy2b);
       printf("numero2 %d\n",numero2);
	   fscanf(f1,"%s",stringa);
	   int numero3 = atoi(stringa);
	   fscanf(f1,"%s",stringa); 
	   double numero6 = atof(stringa);

 	   fscanf(f1,"%s",stringa);
	   contatore=0;
	   contatore2=0;
	   while (stringa[contatore]!=',') contatore++;
	   while (stringa[contatore2]!=')') contatore2++;
	   printf("contatore %d\n",contatore);	
 	   for (i=1;i<=contatore;i++) 
	   {	
		 	
		cpyb[i-1]=stringa[i];
	    }

	   int numero4=  atoi(cpyb);
	   printf("numero1 %d\n",numero1);
	   ii=0; 
	   for (i=contatore+1;i<=contatore2;i++)
	   {	
		cpy2b[ii]=stringa[i];
		ii++;	
		}
	   
	   int numero5=atoi(cpy2b);
	   for (i=numero1;i<=numero2;i++)
	   {
	   for (j=numero4;j<=numero5;j++)
	   {
           printf("modifico %d",i);
           connectactive[i][j]=numero3;
           lengthconnectactive[i][j]=numero6;
           
//compilare connectionactive

       }
       }
	   

} //chiude IDF
 
	   

//**********************************************************************************************

//If***********************************************
//***************************************************

	if ((stringa[0]=='I') && (stringa[1]=='F'))
	{  
	   look='V';
	   fscanf(f1,"%s",stringa);
	   contatore=0;
	   contatore2=0;
	   while (stringa[contatore]!=',') contatore++;
	   while (stringa[contatore2]!=')') contatore2++;
	   printf("contatore %d\n",contatore);	
	   char cpy[contatore];	
	   for (i=1;i<=contatore;i++) 
	   {	
		 	
		cpy[i-1]=stringa[i];
	    }

	   int numero1=  atoi(cpy);
	   printf("numero1 %d\n",numero1);
	   ii=0; 
	   char cpy2[contatore2-1-contatore];	 
	   for (i=contatore+1;i<=contatore2;i++)
	   {	
		cpy2[ii]=stringa[i];
		ii++;	
		}
	   int numero2= atoi(cpy2);
	   printf("numero2 %d\n",numero2);
	   fscanf(f1,"%s",stringa);
	   look='V';
	   printf("blammmm");	
//**********************************************************************************************
	   if ((stringa[0]=='M') && (stringa[1]=='I') && (stringa[2]=='N') && (stringa[3]=='D'))
	   {	
	   printf("blavvv");	
           while (look=='V')
           {
 
		fscanf(f1,"%s",stringa);
		printf("STR %s",stringa);
		number2=atof(stringa);
		printf("potenziale %f",number2);	
		for (i=numero1;i<=numero2;i++)
		{
			contatore4[i]=0;
		        while (distif[i][contatore4[i]]!=0)
			{
				contatore4[i]++;
                        }
          distif[i][contatore4[i]]=number2;
        //  printf("sioioioioioioioioioioioioioioio");
           
          
 		}		
	   
 
           fscanf(f1,"%s",stringa);
	   printf("str %s",stringa);
	   contatore=0;
	   contatore2=0;	
	   while (stringa[contatore]!=',') contatore++;
	   while (stringa[contatore2]!=')') contatore2++;
	   printf("contatore2 %d\n",contatore2);	
	   char cpy3[contatore-1];	 

	   for (i=1;i<=contatore;i++) 
	   {	
		//printf("blo"); 	
		cpy3[i-1]=stringa[i];
	    }

	   int numero3=atoi(cpy3);
	   printf("numero3 %d\n",numero3);
	   ii=0;
	   char cpy4[contatore2-contatore-1];	 
	   for (i=contatore+1;i<=contatore2;i++)
	   {	
		cpy4[ii]=stringa[i];
		ii++;	
		}
	   int numero4= atoi(cpy4);
	   printf("numero4 %d\n",numero4);

		for (i=numero1;i<=numero2;i++)
		{
 		   begintif[i][contatore4[i]]=numero3;
		   endintif[i][contatore4[i]]=numero4;	 


		}		
//codice.............................
           fscanf(f1,"%s",stringa);
	   printf("blaxx %s",stringa);
	   if ((stringa[0]=='E') && (stringa[4]=='F')) 
	   {
	   	look='F';
               // fscanf(f1,"%s",stringa);
		
	   	
		}
	 //  if (stringa[0]!='E') fscanf(f1,"%s",stringa);
            
	   printf("look %c",look);	
	   	
			
	
//codice.................................
           }
	   }	   	
	   
        //   printf("stringa %s",cpy);
 
 	
	   
		  			
		

	}





	}
fclose(f1);
stringa[0]='x';

FILE *f10 = fopen("pos.aut","r");
contatore=0;


while (stringa[0]!='*')
{
	contatore++;
 
for (w=1;w<=settings[0];w++)
{
	fscanf(f10,"%s",stringa);
	x[contatore][w]=atof(stringa);

}
 

}
// parte lettura codice 

//   fclose(f2);
//   fclose(f3);
//   fclose(f4);	

}
