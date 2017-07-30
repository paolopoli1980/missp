
import random
f1=open('pos.aut','w')

for i in range(20):
	
	x=random.uniform(-1,1)
	y=random.uniform(-1,1)
	z=random.uniform(-1,1)
	f1.write(str(x)+str('\n'))
	f1.write(str(y)+str('\n'))
	f1.write(str(z)+str('\n'))
  
 

f1.write('*\n')


f1.close()