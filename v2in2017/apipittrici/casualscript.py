
import random
f1=open('pos.aut','w')

x=-2.5
y=0
z=0
#x=0
#y=0
f1.write(str(x)+str('\n'))
f1.write(str(y)+str('\n'))
#f1.write(str(z)+str('\n'))

for i in range(10):
	
	x=random.uniform(-3,-2)
	y=random.uniform(-1,1)
	#x=random.uniform(-1,1)
	#y=random.uniform(-1,1)
	z=0
	#x=0
 	#y=0
	#z=0
	f1.write(str(x)+str('\n'))
	f1.write(str(y)+str('\n'))
	#f1.write(str(z)+str('\n'))

x=2.5
y=0
z=0
#x=0
#y=0

f1.write(str(x)+str('\n'))
f1.write(str(y)+str('\n'))
#f1.write(str(z)+str('\n'))

for i in range(10):
	
	x=random.uniform(2,3)
	y=random.uniform(-1,1)
	#x=random.uniform(-1,1)
	#y=random.uniform(-1,1)

	z=0
	#x=0
 	#y=0
	#z=0
	f1.write(str(x)+str('\n'))
	f1.write(str(y)+str('\n'))
	#f1.write(str(z)+str('\n'))
  
#x=0
#y=0
#z=0
#f1.write(str(x)+str('\n'))
#f1.write(str(y)+str('\n'))
#f1.write(str(z)+str('\n'))

#for i in range(10):
	
#	x=random.uniform(-0.5,0.5)
#	y=random.uniform(-0.5,0.5)
#	x=random.uniform(-1,1)
#	y=random.uniform(-1,1)

#	z=0
	#x=0
 	#y=0
	#z=0
#	f1.write(str(x)+str('\n'))
#	f1.write(str(y)+str('\n'))
	#f1.write(str(z)+str('\n'))
   

f1.write('*\n')


f1.close()
