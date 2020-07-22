import math


f1=open("pos.aut","w")
angle=0
const=0

for j in range(1):
    for i in range(8):
                    
        x=2*math.cos(angle)
        y=2*math.sin(angle)
        z=0
        angle+=math.pi/4
        f1.write(str(x)+str("\n"))
        f1.write(str(y)+str("\n"))
        f1.write(str(z)+str("\n"))
        


for j in range(2):
    for i in range(4):
                    
        x=(2+0.5*i)*(-1)**j
        z=(-1)**j
        y=0
        angle+=math.pi/4
        f1.write(str(x)+str("\n"))
        f1.write(str(y)+str("\n"))
        f1.write(str(z)+str("\n"))

f1.write("0\n")
f1.write("0\n")
f1.write("0\n")


f1.write("*\n")

f1.close()

    

        
