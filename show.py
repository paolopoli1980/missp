from visual import *
from time import sleep

gruppi=input('numero di gruppi=')
dim=input('inserisci la dimensione:=')
frame=input('rate:=')
raggio=[]
colore=[]

for i in range(gruppi):
	r=input("Inserisci raggio:=")
	c=raw_input("inserisci colore:=")
	t=input("inserisci il range del gruppo n."+str(i)+":=")
	for j in range(t):
		raggio.append(r)
		colore.append(c)
		
	


f1=open('pos.aut','r')
stringa='aaa'
r=0.5
 


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
		       		point.append(sphere(pos=(float(stringa),0,0), radius=raggio[contatore], color=color.red))	 	
			if (colore[contatore]=="green"):
		       		point.append(sphere(pos=(float(stringa),0,0), radius=raggio[contatore], color=color.green))	 	
			if (colore[contatore]=="yellow"):
		       		point.append(sphere(pos=(float(stringa),0,0), radius=raggio[contatore], color=color.yellow))	 	
			if (colore[contatore]=="white"):
		       		point.append(sphere(pos=(float(stringa),0,0), radius=raggio[contatore], color=color.white))	 	
 


	f1.close()	
	f1=open('posres.aut','r')
	while (stringa!='e\n'):
		cont=0;
		stringa='a'
		while (stringa!='*\n'):
			rate(frame)
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
			pointgraf.append(sphere(pos=(float(vx),float(vy),0), radius=0.05, color=color.white))

	
	ball = sphere(pos=(0,0,0), radius=0.01)
	#cr = shapes.circle(radius=1, np=64)
	print dim
	while (stringa!='*\n'):
		contatore+=1
		stringa=f1.readline()
		stringa2=f1.readline()

		if (stringa!='*\n'):
			#print (stringa)
			#print (stringa2)
 			if (colore[contatore]=="red"):
		       		point.append(sphere(pos=(float(stringa),0,0), radius=raggio[contatore], color=color.red))	 	
			if (colore[contatore]=="green"):
		       		point.append(sphere(pos=(float(stringa),0,0), radius=raggio[contatore], color=color.green))	 	
			if (colore[contatore]=="yellow"):
		       		point.append(sphere(pos=(float(stringa),0,0), radius=raggio[contatore], color=color.yellow))	 	
			if (colore[contatore]=="white"):
		       		point.append(sphere(pos=(float(stringa),0,0), radius=raggio[contatore], color=color.white))	 	


	f1.close()	
	f1=open('posres.aut','r')
	while ((stringa!='e\n') and (stringa2!='e\n')):
		cont=0;
		
		#print cont
		stringa='a'
		stringa2='a'
		while ((stringa!='*\n') and (stringa2!='*\n')):
			print cont
			rate(frame)
			
			stringa=f1.readline()
			if (stringa!='*\n'):
				stringa2=f1.readline()
			if (stringa!='*\n' and stringa!='e\n' and stringa2!='*\n' and stringa2!='e\n'):
				print stringa
				print stringa2
				point[cont].pos.x=float(stringa)
				point[cont].pos.y=float(stringa2)
				#sleep(0.05)
			cont=cont+1;				
if dim==3:
	print dim
	while (stringa!='*\n'):
		contatore+=1
		stringa=f1.readline()
		stringa2=f1.readline()
		stringa3=f1.readline()
		if (stringa!='*\n'):
			print (stringa)
			print (stringa2)
			print (stringa3)
			if (colore[contatore]=="red"):
		       		point.append(sphere(pos=(float(stringa),0,0), radius=raggio[contatore], color=color.red))	 	
			if (colore[contatore]=="green"):
		       		point.append(sphere(pos=(float(stringa),0,0), radius=raggio[contatore], color=color.green))	 	
			if (colore[contatore]=="yellow"):
		       		point.append(sphere(pos=(float(stringa),0,0), radius=raggio[contatore], color=color.yellow))	 	
			if (colore[contatore]=="white"):
		       		point.append(sphere(pos=(float(stringa),0,0), radius=raggio[contatore], color=color.white))	 	
 

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
			rate(frame)
			stringa=f1.readline()
			if stringa=='*\n':
				print stringa
				cont=0
				stringa=f1.readline()
			if stringa!='*\n':
				stringa2=f1.readline()
			if stringa2!='*\n':
				stringa3=f1.readline()
			#print stringa2
			if (stringa!='*\n' and stringa!='e\n' and stringa2!='*\n' and stringa2!='e\n' and stringa3!='*\n' and stringa3!='e\n'):
				print stringa
				print stringa2
				print stringa3
				point[cont].pos.x=float(stringa)
				point[cont].pos.y=float(stringa2)
				point[cont].pos.z=float(stringa3)
				#sleep(0.01)
			cont=cont+1;				
