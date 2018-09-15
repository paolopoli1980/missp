import math


f1=open("pos.aut","w")
angle=0
const=0

for j in range(3):
    for i in range(4):
                    
        x=math.cos(angle)+j
        y=math.sin(angle)+j
        z=j
        angle+=math.pi/2
        f1.write(str(x)+str("\n"))
        f1.write(str(y)+str("\n"))
        f1.write(str(z)+str("\n"))
        
f1.write("0\n")
f1.write("0\n")
f1.write("0\n")
f1.write("1\n")
f1.write("1\n")
f1.write("1\n")
f1.write("2\n")
f1.write("2\n")
f1.write("2\n")
f1.write("*\n")

f1.close()

    

        
