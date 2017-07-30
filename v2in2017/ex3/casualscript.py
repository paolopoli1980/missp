
import random
f1=open('pos.aut','w')

for j in range(5):
	for i in range(5):
	
		x=0.6*i
		y=j*0.6
 		f1.write(str(x)+str('\n'))
		f1.write(str(y)+str('\n'))
 
for j in range(5):
	for i in range(5):
	
		x=0.6*i+3
		y=j*0.6
 		f1.write(str(x)+str('\n'))
		f1.write(str(y)+str('\n'))
 
f1.write("1\n")
f1.write("1\n")
f1.write("3\n")
f1.write("1\n")

f1.write('*\n')


f1.close()