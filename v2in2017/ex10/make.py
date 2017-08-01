import random
import math
f1=open("pos.aut","w")
k=0

for i in range(20):
	x=random.uniform(-3+k,-1)
	y=random.uniform(1,3)
	z=random.uniform(0,0.5)
	f1.write(str(x)+str("\n"))
	f1.write(str(y)+str("\n"))
	f1.write(str(z)+str("\n"))

for i in range(20):
	x=random.uniform(1+k,3)
	y=random.uniform(1,3)
	z=random.uniform(0,0.5)

	f1.write(str(x)+str("\n"))
	f1.write(str(y)+str("\n"))
	f1.write(str(z)+str("\n"))
 

f1.write("*\n")

f1.close()

	
f1=open("vinc.aut","w")
for i in range(30):
	z=i*0.1	
	for j in range(30):
		y=j*0.1
		x=0
		f1.write(str(x)+str("\n"))
		f1.write(str(y)+str("\n"))
		f1.write(str(z)+str("\n"))
for i in range(30):
	y=i*0.1	
	for j in range(60):
		x=j*0.1
		z=0
		f1.write(str(x-3)+str("\n"))
		f1.write(str(y)+str("\n"))
		f1.write(str(z)+str("\n"))
f1.write("*\n")
f1.close() 