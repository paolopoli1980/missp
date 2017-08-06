from visual import *
from time import sleep
nex=13
for t in range(nex):
#    gruppi=input('numero di gruppi=')
#    dim=input('inserisci la dimensione:=')
#    frame=input('rate:=')
    raggio=[]
    colore=[]
    
#    for i in range(gruppi):
#    	r=input("Inserisci raggio:=")
#    	c=raw_input("inserisci colore:=")
#    	t=input("inserisci il range del gruppo n."+str(i)+":=")
#    	for j in range(t):
#    		raggio.append(r)
#    		colore.append(c)
	    		
    	
    
    
#    f1=open('pos.aut','r')

    stringa='aaa'
    r=0.5
    if t==0:
        scene = display(title='Visual Missp',x=300, y=200, width=600, height=600,center=(0,0,0), background=(0,1,1))

        path='tutorial/ex1/'
	

        gruppi=2
        dim=3
        frame=400
 	for k in range(20):
        	colore.append('red')
		raggio.append(0.1)
	for k in range(20):
        	colore.append('green')
		raggio.append(0.1)

    if t==1:
        scene = display(title='Visual Missp',x=300, y=200, width=600, height=600,center=(0,0,0), background=(0,1,1))

        path='tutorial/ex2/'
	point=[]
	pointgraf=[]
	
        gruppi=2
        dim=2
        frame=400
  	for k in range(20):
        	colore.append('red')
		raggio.append(0.1)
	for k in range(20):
        	colore.append('yellow')
		raggio.append(0.05)

    if t==2:
        scene = display(title='Visual Missp',x=300, y=200, width=600, height=600,center=(0,0,0), background=(0,1,1))

        path='tutorial/ex4/'

        gruppi=2
        dim=2
        frame=400
 	for k in range(20):
        	colore.append('green')
		raggio.append(0.2)

    if t==3:
        scene = display(title='Visual Missp',x=300, y=200, width=600, height=600,center=(0,0,0), background=(0,1,1))

        path='tutorial/ex5/'

        gruppi=2
        dim=3
        frame=400
 	for k in range(20):
        	colore.append('green')
		raggio.append(0.1)

    if t==4:
        scene = display(title='Visual Missp',x=300, y=200, width=600, height=600,center=(0,0,0), background=(0,1,1))

        path='tutorial/ex6/'

        gruppi=2
        dim=3
        frame=400
 	for k in range(20):
        	colore.append('green')
		raggio.append(0.1)
       	colore.append('red')
	raggio.append(0.1)

    if t==5:
        scene = display(title='Visual Missp',x=300, y=200, width=600, height=600,center=(0,0,0), background=(0,1,1))
 	for k in range(20):
        	colore.append('green')
		raggio.append(0.1)
       	colore.append('green')
	raggio.append(0.1)
       	colore.append('red')
	raggio.append(0.1)
	colore[0]='red'

        path='tutorial/ex7/'

        gruppi=1
        dim=2
        frame=400
    if t==6:
        scene = display(title='Visual Missp',x=300, y=200, width=600, height=600,center=(0,0,0), background=(0,1,1))

        path='tutorial/ex8/'
 	for k in range(20):
        	colore.append('green')
		raggio.append(0.1)
       	colore.append('red')
	raggio.append(0.1)
       	colore.append('red')
	raggio.append(0.1) 
       	colore.append('red')
	raggio.append(0.1) 

        dim=2
        frame=400
    if t==7:
        path='tutorial/ex9/'
        scene = display(title='Visual Missp',x=300, y=200, width=600, height=600,center=(0,0,0), background=(0,1,1))

 
 	for k in range(20):
        	colore.append('green')
		raggio.append(0.1)
       	colore.append('red')
	raggio.append(0.1)
       	colore.append('red')
	raggio.append(0.1) 
       	colore.append('red')
	raggio.append(0.1) 

        dim=2
        frame=400

    if t==8:
        scene = display(title='Visual Missp',x=300, y=200, width=600, height=600,center=(0,0,0), background=(0,1,1))

        path='tutorial/ex10/'
 	for k in range(20):
        	colore.append('green')
		raggio.append(0.1)
 	for k in range(20):
        	colore.append('red')
		raggio.append(0.1)

        gruppi=2
        dim=3
        frame=400

#    if t==9:
#        scene = display(title='Visual Missp',x=300, y=200, width=600, height=600,center=(0,0,0), background=(0,1,1))

#        path='tutorial/ex11/'
# 	for k in range(20):
#        	colore.append('green')
#		raggio.append(0.1)
# 	for k in range(20):
#        	colore.append('red')
#		raggio.append(0.1)

#        gruppi=2
#        dim=3
#        frame=400
    if t==10:
        path='tutorial/ex12/'
        scene = display(title='Visual Missp',x=300, y=200, width=600, height=600,center=(0,0,0), background=(0,1,1))

         
 	for k in range(20):
        	colore.append('green')
		raggio.append(0.1)
 	for k in range(20):
        	colore.append('red')
		raggio.append(0.1)
 	for k in range(20):
        	colore.append('yellow')
		raggio.append(0.1)

        gruppi=2
        dim=3
        frame=400
    if t==11:
        scene = display(title='Visual Missp',x=300, y=200, width=600, height=600,center=(0,0,0), background=(0,1,1))

 
        path='tutorial/ex13/'
 
         
 	for k in range(5):
        	colore.append('yellow')
		raggio.append(0.1)
 	for k in range(55):
        	colore.append('red')
		raggio.append(0.1)
 
        gruppi=2
        dim=3
        frame=400
    if t==12:
        path='tutorial/ex14/'
        scene = display(title='Visual Missp',x=300, y=200, width=600, height=600,center=(0,0,0), background=(0,1,1))

        path='tutorial/ex14/'
 	for k in range(20):
        	colore.append('green')
		raggio.append(0.1)
       	colore.append('red')
	raggio.append(0.1)
 
        gruppi=2
        dim=3
        frame=400
        r=[0.1,0.1]
  
         
    f1=open(str(path)+'pos.aut','r')
     
    
    
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
    	f1=open(str(path)+'posres.aut','r')
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
    	f2=open(str(path)+"vinc.aut","r")
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
    	f1=open(str(path)+'posres.aut','r')
    	while ((stringa!='e\n') and (stringa2!='e\n')):
    		cont=0;
		if stringa=='**\n' or stringa2=='**\n':
	                break
    		
    		#print cont
    		stringa='a'
    		stringa2='a'
    		while ((stringa!='*\n') and (stringa2!='*\n')):
    			print cont
    			rate(frame)
    			
    			stringa=f1.readline()
    			if (stringa!='*\n'):
    				stringa2=f1.readline()
    			if stringa=='**\n' or stringa2=='**\n':
    				break

    			if (stringa!='*\n' and stringa!='e\n' and stringa2!='*\n' and stringa2!='e\n'):
    				print stringa
    				print stringa2
    				point[cont].pos.x=float(stringa)
    				point[cont].pos.y=float(stringa2)
    				#sleep(0.05)
    			cont=cont+1;				
    if dim==3:
    	f2=open(str(path)+"vinc.aut","r")

    	print dim
	vx="xx"
	vy="yy"
	vz="zz"
	while vx!="*\n":
		vx=f2.readline()
		if vx!='*\n':
			vy=f2.readline()
			vz=f2.readline()
			pointgraf.append(sphere(pos=(float(vx),float(vy),float(vz)), radius=0.05, color=color.white))

	
	ball = sphere(pos=(0,0,0), radius=0.01)
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
    	f1=open(str(path)+'posres.aut','r')
    	while ((stringa!='e\n') and (stringa2!='e\n') and (stringa3!='e\n')):
    		cont=0;
    		#print cont
		if stringa=='**\n' or stringa2=='**\n' or stringa3=='**\n':
	                break

    		stringa='a'
    		stringa2='a'
    		stringa3='a'

    		while ((stringa!='*\n') and (stringa2!='*\n') and (stringa3!='*\n')):
    			#print cont
    			rate(frame)
    			stringa=f1.readline()
    			if stringa=='**\n':
    				break
    			if stringa=='*\n':
    				print stringa
    				cont=0
    				stringa=f1.readline()
    			if stringa!='*\n':
    				stringa2=f1.readline()
    			if stringa2!='*\n':
    				stringa3=f1.readline()
    			if stringa=='**\n' or stringa2=='**\n' or stringa3=='**\n':
    				break
    
    			#print stringa2
    			if (stringa!='*\n' and stringa!='e\n' and stringa2!='*\n' and stringa2!='e\n' and stringa3!='*\n' and stringa3!='e\n'):
    				print stringa
    				print stringa2
    				print stringa3
    				point[cont].pos.x=float(stringa)
    				point[cont].pos.y=float(stringa2)
    				point[cont].pos.z=float(stringa3)
    				#sleep(0.01)
    			cont=cont+1				
