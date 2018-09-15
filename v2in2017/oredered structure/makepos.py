import math
import random

f1=open("pos.aut","w")
angle=0
const=0

for j in range(3):
    for i in range(10):
        casual=random.uniform(-0.15,0.15)            
        x=casual
        casual=random.uniform(-0.15,0.15)            
        y=casual
        if j==1:
            
            x+=2
        if j==2:
            y+=2		
        z=0
        
        f1.write(str(x)+str("\n"))
        f1.write(str(y)+str("\n"))
        f1.write(str(z)+str("\n"))
        
f1.write("0\n")
f1.write("0\n")
f1.write("0\n")
f1.write("2\n")
f1.write("0\n")
f1.write("0\n")
f1.write("0\n")
f1.write("2\n")
f1.write("0\n")
f1.write("*\n")

f1.close()

    

        
