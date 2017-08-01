import random
import math
f1=open("pos.aut","w")
k=0

for i in range(20):
	x=random.uniform(-2+k,-1)
	y=random.uniform(1,2)
	z=random.uniform(1,2)
	f1.write(str(x)+str("\n"))
	f1.write(str(y)+str("\n"))
	f1.write(str(z)+str("\n"))

x=1
y=1
z=1
f1.write(str(x)+str("\n"))
f1.write(str(y)+str("\n"))
f1.write(str(z)+str("\n"))
	  

f1.write("*\n")

f1.close()

	
f1=open("vinc.aut","w")
for i in range(20):
	x=i*0.1	
	for j in range(20):
		y=j*0.1
		z=0
		f1.write(str(x)+str("\n"))
		f1.write(str(y)+str("\n"))
		f1.write(str(z)+str("\n"))
for i in range(20):
	x=i*0.1	
	for j in range(21):
		y=j*0.1
		z=2
		f1.write(str(x)+str("\n"))
		f1.write(str(y)+str("\n"))
		f1.write(str(z)+str("\n"))
for i in range(20):
	z=i*0.1	
	for j in range(20):
		x=j*0.1
		y=0
		f1.write(str(x)+str("\n"))
		f1.write(str(y)+str("\n"))
		f1.write(str(z)+str("\n"))
for i in range(20):
	z=i*0.1	
	for j in range(20):
		x=j*0.1
		y=2
		f1.write(str(x)+str("\n"))
		f1.write(str(y)+str("\n"))
		f1.write(str(z)+str("\n"))


f1.write("*\n")
f1.close() 