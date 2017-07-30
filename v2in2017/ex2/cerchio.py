import math
import random 
f1=open("pos.aut","w")

teta=0
while teta<6.28:
	teta=teta+6.28/20
	x=2*math.cos(teta)
	y=2*math.sin(teta)
 	f1.write(str(x)+str("\n"))
	f1.write(str(y)+str("\n"))
  
for i in range(20):
	x=random.uniform(-0.5,0.5)
	y=random.uniform(-0.5,0.5)
 	f1.write(str(x)+str("\n"))
	f1.write(str(y)+str("\n"))

f1.write("*\n")

f1.close()

	