import random
import math
f1=open("pos.aut","w")
k=0

for i in range(20):
	x=random.uniform(-2,2)
	y=random.uniform(-2,2)

	f1.write(str(x)+str("\n"))
	f1.write(str(y)+str("\n"))
 
 

f1.write("*\n")

f1.close()

	
f1=open("vinc.aut","w")
cont=0
inc=0.025
r=4
while cont<2*math.pi:
	
	x=r*math.cos(cont)
	y=r*math.sin(cont)
	cont+=inc
	f1.write(str(x)+str("\n"))
	f1.write(str(y)+str("\n"))


  

f1.write("*\n")
f1.close() 