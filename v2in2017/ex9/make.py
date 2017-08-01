import random
import math
f1=open("pos.aut","w")
k=-4.5 

for i in range(20):
	x=random.uniform(-2+k,-1)
	y=random.uniform(3,5)
	f1.write(str(x)+str("\n"))
	f1.write(str(y)+str("\n"))
f1.write("-3\n")
f1.write("0.5\n")
f1.write("0\n")
f1.write("0.5\n")
f1.write("3\n")
f1.write("0.5\n")

f1.write("*\n")

f1.close()

	
f1=open("vinc.aut","w")
alfa=0

 
 
for i in range(30):
	y=0
	x=(i)/10.0+k
	f1.write(str(x)+str("\n"))
	f1.write(str(y)+str("\n"))
 
for i in range(10):
	y=0+(i+1)/10.0
	x=3+k
	f1.write(str(x)+str("\n"))
	f1.write(str(y)+str("\n"))

for i in range(30):
	y=0
	x=3+(i)/10.0+k
	f1.write(str(x)+str("\n"))
	f1.write(str(y)+str("\n"))

for i in range(10):
	y=0+(i+1)/10.0
	x=6+k
	f1.write(str(x)+str("\n"))
	f1.write(str(y)+str("\n"))

for i in range(60):
	y=0
	x=6+(i)/10.0+k
	f1.write(str(x)+str("\n"))
	f1.write(str(y)+str("\n"))

for i in range(10):
	y=0+(i+1)/10.0
	x=9+k
	f1.write(str(x)+str("\n"))
	f1.write(str(y)+str("\n"))




f1.write("*\n")

f1.close()
	
