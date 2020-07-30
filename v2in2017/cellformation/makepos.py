import math
import random

f1=open("pos.aut","w")
angle=0
const=0
cont=0
f1.write("0\n")
f1.write("0\n")
for i in range(19):
        x=random.uniform(-1,1)
        y=random.uniform(-1,1)
        f1.write(str(x)+str("\n"))
        f1.write(str(y)+str("\n"))

for j in range(2):
    for i in range(4):
                    
        x=cont*math.cos(angle)
        y=cont*math.sin(angle)
        #z=cont*0.25
        #z=j
        angle+=math.pi/4.0
        f1.write(str(x)+str("\n"))
        f1.write(str(y)+str("\n"))
        #f1.write(str(z)+str("\n"))
        cont+=0.5

cont=0
#f1.write("0\n")
#f1.write("0\n")
#f1.write("0\n")
#f1.write("1\n")
#f1.write("1\n")
#f1.write("1\n")
#f1.write("2\n")
#f1.write("2\n")
#f1.write("2\n")
f1.write("*\n")

f1.close()

    

        
