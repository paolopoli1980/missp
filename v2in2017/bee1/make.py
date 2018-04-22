import random
import math
f1=open("pos.aut","w")
k=0

for i in range(20):
        x=random.uniform(0,0)
        y=random.uniform(2,3)
        z=0
        f1.write(str(x)+str("\n"))
        f1.write(str(y)+str("\n"))
        f1.write(str(z)+str("\n"))


#f1.write("*\n")

#f1.close()

	
#f1=open("vinc.aut","w")
cont=0
inc=0.25
r=4

while cont<2*math.pi:

	x=r*math.cos(cont)
	y=r*math.sin(cont)
	z=math.cos(4*cont)
	
	cont+=inc
	#z=random.uniform(0,2)
	#z=math.sin(cont)
	print (str(x))
	print (str(y))
	f1.write(str(x)+str("\n"))
	f1.write(str(z)+str("\n"))
	f1.write(str(y)+str("\n"))


  

f1.write("*\n")
f1.close() 
