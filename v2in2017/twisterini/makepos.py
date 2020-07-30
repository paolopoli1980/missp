import math
import random

f1=open("pos.aut","w")
angle=0
const=0
x=0
for i in range(2):
	#x=random.uniform(-3,-2)
	#y=random.uniform(-3,-2)
	#z=random.uniform(-3,-2)
	x+=3
	y=0
	#z=0
	f1.write(str(x)+str('\n'))
	f1.write(str(y)+str('\n'))	
	#f1.write(str(z)+str('\n'))

x=1
for i in range(2):
	#x=random.uniform(3,4)
	#y=random.uniform(3,4)
	#z=random.uniform(3,4)
	x+=3
	y=0
	#z=0
	f1.write(str(x)+str('\n'))
	f1.write(str(y)+str('\n'))	
	#f1.write(str(z)+str('\n'))

x=2
for i in range(2):
	#x=random.uniform(3,4)
	#y=random.uniform(3,4)
	#z=random.uniform(3,4)
	x+=3
	y=0
	#z=0
	f1.write(str(x)+str('\n'))
	f1.write(str(y)+str('\n'))	
	#f1.write(str(z)+str('\n'))


#f1.write(str('-1')+str('\n'))
#f1.write(str('-1')+str('\n'))	
#f1.write(str('0')+str('\n'))
#f1.write(str('1')+str('\n'))
#f1.write(str('1')+str('\n'))	
#f1.write(str('0')+str('\n'))

#f1.write(str('0')+str('\n'))	

f1.write("*\n")

f1.close()

    

        
