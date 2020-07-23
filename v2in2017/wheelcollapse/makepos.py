import math


f1=open("pos.aut","w")
angle=0
const=0

for j in range(1):
    for i in range(10):
                    
        x=4*math.cos(angle)
        y=4*math.sin(angle)
        #z=0
        angle+=math.pi/10.0
        f1.write(str(x)+str("\n"))
        f1.write(str(y)+str("\n"))
        #f1.write(str(z)+str("\n"))
        


f1.write("0\n")
f1.write("0\n")

f1.write("*\n")

f1.close()

    

        
