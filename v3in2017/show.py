
gruppi=input('numero di gruppi=')
dim=input('inserisci la dimensione:=')
#frame=input('rate:=')
#frame=int(frame)
raggio=[]
colore=[]
dim=int(dim)
for i in range(int(gruppi)):
        r=input("Inserisci raggio:=")
        c=input("inserisci colore:=")
        t=input("inserisci il range del gruppo n."+str(i)+":=")
        for j in range(int(t)):
                raggio.append(r)
                colore.append(c)
                
        

track=input("Track yes or no (y/n)=")

from vpython import *
from time import sleep
scene = canvas(title='Missp',
     x=0, y=0, width=1366, height=768,
center=vector(0,0,0), background=vector(1,1,1))

f1=open('pos.aut','r')
stringa='aaa'
r=float(0.5)
 


point=[]
pointgraf=[]
contatore=-1
if dim==1:
        while (stringa!='*\n'):
                contatore+=1
                stringa=f1.readline()
                if (stringa!='*\n'):
                        print (stringa)
                        if (colore[contatore]=="red"):
                                point.append(sphere(pos=vec(float(stringa),0,0), radius=float(raggio[contatore]), color=color.red))               
                        if (colore[contatore]=="green"):
                                point.append(sphere(pos=vec(float(stringa),0,0), radius=float(raggio[contatore]), color=color.green))             
                        if (colore[contatore]=="yellow"):
                                point.append(sphere(pos=vec(float(stringa),0,0), radius=float(raggio[contatore]), color=color.yellow))            
                        if (colore[contatore]=="white"):
                                point.append(sphere(pos=vec(float(stringa),0,0), radius=float(raggio[contatore]), color=color.white))             
 


        f1.close()      
        f1=open('posres.aut','r')
        while (stringa!='e\n'):
                cont=0;
                stringa='a'
                while (stringa!='*\n'):
                        rate(500)
                        stringa=f1.readline()
                        if (stringa!='*\n' and stringa!='e\n'):
                                #print stringa
                                point[cont].pos.x=float(stringa)
                                #sleep(0.01)
                        cont=cont+1;    

if dim==2:
        f2=open("vinc.aut","r")
        vx="xx"
        vy="yy"
        while vx!="*\n":
                vx=f2.readline()
                if vx!='*\n':
                        vy=f2.readline()
                        pointgraf.append(sphere(pos=vec(float(vx),float(vy),0), radius=0.05, color=color.black))

        
        ball = sphere(pos=vec(0,0,0), radius=0.01)
        #cr = shapes.circle(radius=1, np=64)
        print (dim)
	
        while (stringa!='*\n'):
                contatore+=1
                stringa=f1.readline()
                stringa2=f1.readline()
		
                if (stringa!='*\n'):
                        #print (stringa)
                        #print (stringa2)
                        if track=='y':
                                if (colore[contatore]=="red"):
                                        point.append(sphere(pos=vec(float(stringa),float(stringa2),float(stringa3)), radius=float(raggio[contatore]), color=color.red,make_trail=True))
                                if (colore[contatore]=="green"):
                                        point.append(sphere(pos=vec(float(stringa),float(stringa2),float(stringa3)), radius=float(raggio[contatore]), color=color.green,make_trail=True))             
                                if (colore[contatore]=="yellow"):
                                        point.append(sphere(pos=vec(float(stringa),float(stringa2),float(stringa3)), radius=float(raggio[contatore]), color=color.yellow,make_trail=True))            
                                if (colore[contatore]=="white"):
                                        point.append(sphere(pos=vec(float(stringa),float(stringa2),float(stringa3)), radius=float(raggio[contatore]), color=color.white,make_trail=True))             
                        else:
                                if (colore[contatore]=="red"):
                                        point.append(sphere(pos=vec(float(stringa),0,0), radius=float(raggio[contatore]), color=color.red,make_trail=False))
                                if (colore[contatore]=="green"):
                                        point.append(sphere(pos=vec(float(stringa),0,0), radius=float(raggio[contatore]), color=color.green,make_trail=False))             
                                if (colore[contatore]=="yellow"):
                                        point.append(sphere(pos=vec(float(stringa),0,0), radius=float(raggio[contatore]), color=color.yellow,make_trail=False))            
                                if (colore[contatore]=="white"):
                                        point.append(sphere(pos=vec(float(stringa),0,0), radius=float(raggio[contatore]), color=color.white,make_trail=False))             
                                

        f1.close()      
        f1=open('posres.aut','r')
        while ((stringa!='e\n') and (stringa2!='e\n')):
                cont=0;
                
                #print cont
                stringa='a'
                stringa2='a'
                while ((stringa!='*\n') and (stringa2!='*\n')):
                        print (cont)
                        rate(500)
                        
                        stringa=f1.readline()
                        if (stringa!='*\n'):
                                stringa2=f1.readline()
                        if (stringa!='*\n' and stringa!='e\n' and stringa2!='*\n' and stringa2!='e\n'):
                                print (stringa)
                                print (stringa2)
                                point[cont].pos.x=float(stringa)
                                point[cont].pos.y=float(stringa2)
                                #sleep(0.05)
                        cont=cont+1;                            
if dim==3:
        f2=open("vinc.aut","r")
        vx="xx"
        vy="yy"
        vz="zz"
        while vx!="*\n":
                vx=f2.readline()
                if vx!='*\n':
                        vy=f2.readline()
                        vz=f2.readline()
                        pointgraf.append(sphere(pos=vec(float(vx),float(vy),float(vz)), radius=0.05, color=color.black))

        
        ball = sphere(pos=vec(0,0,0), radius=0.01)


        print (dim)
        while (stringa!='*\n'):
                contatore+=1
                stringa=f1.readline()
                stringa2=f1.readline()
                stringa3=f1.readline()
                if (stringa!='*\n'):
                        print (stringa)
                        print (stringa2)
                        print (stringa3)
                        if track=='y':
                                if (colore[contatore]=="red"):
                                        point.append(sphere(pos=vec(float(stringa),float(stringa2),float(stringa3)), radius=float(raggio[contatore]), color=color.red,make_trail=True))               
                                if (colore[contatore]=="green"):
                                        point.append(sphere(pos=vec(float(stringa),float(stringa2),float(stringa3)), radius=float(raggio[contatore]), color=color.green,make_trail=True))             
                                if (colore[contatore]=="yellow"):
                                        point.append(sphere(pos=vec(float(stringa),float(stringa2),float(stringa3)), radius=float(raggio[contatore]), color=color.yellow,make_trail=True))            
                                if (colore[contatore]=="white"):
                                        point.append(sphere(pos=vec(float(stringa),float(stringa2),float(stringa3)), radius=float(raggio[contatore]), color=color.white,make_trail=True))             
                        else:
                                if (colore[contatore]=="red"):
                                        point.append(sphere(pos=vec(float(stringa),0,0), radius=float(raggio[contatore]), color=color.red,make_trail=False))
                                if (colore[contatore]=="green"):
                                        point.append(sphere(pos=vec(float(stringa),0,0), radius=float(raggio[contatore]), color=color.green,make_trail=False))             
                                if (colore[contatore]=="yellow"):
                                        point.append(sphere(pos=vec(float(stringa),0,0), radius=float(raggio[contatore]), color=color.yellow,make_trail=False))            
                                if (colore[contatore]=="white"):
                                        point.append(sphere(pos=vec(float(stringa),0,0), radius=float(raggio[contatore]), color=color.white,make_trail=False))             
 


        f1.close()      
        f1=open('posres.aut','r')
        while ((stringa!='e\n') and (stringa2!='e\n') and (stringa3!='e\n')):
                cont=0;
                #print cont
                stringa='a'
                stringa2='a'
                stringa3='a'
                while ((stringa!='*\n') and (stringa2!='*\n') and (stringa3!='*\n')):
                        #print cont
                        rate(500)
                        stringa=f1.readline()
                        if stringa=='**\n':
                                exit()
                        if stringa=='*\n':
                                print (stringa)
                                cont=0
                                stringa=f1.readline()
                        if stringa!='*\n':
                                stringa2=f1.readline()
                        if stringa2!='*\n':
                                stringa3=f1.readline()
                        if stringa=='**\n' or stringa=='**\n':
                                exit()

                        #print stringa2
                        if (stringa!='*\n' and stringa!='e\n' and stringa2!='*\n' and stringa2!='e\n' and stringa3!='*\n' and stringa3!='e\n'):
                                print (stringa)
                                print (stringa2)
                                print (stringa3)
                                point[cont].pos.x=float(stringa)
                                point[cont].pos.y=float(stringa2)
                                point[cont].pos.z=float(stringa3)
                                print (point[cont].pos.z)
                                print ("***************")
                                #sleep(0.01)
                        cont=cont+1;                            
 
