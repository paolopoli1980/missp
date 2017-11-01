import matplotlib.pyplot as plt
import math
class ent():

    def __init__(self,n,nsteps):
      
        self.euclidcomp=[[0 for x in range(nsteps)] for y in range(n)] 
        self.pos=[]    


def filereader(dim,n,nsteps):
    f5=open("posres.aut","r")
    string=""
    for t in range(nsteps):        
       
       
 
        for k in range(n):
            listanum=[]
   
            for d in range(dim):
                string=f5.readline()
 
                if string!="\n" and string!="**\n":
                    n1=float(string[0:len(string)-1])
                    listanum.append(n1)
                
            entsfield[k].pos.append(listanum)  
        if string=='**\n':
            break
 
        if string!='**\n':    
            string=f5.readline()    
 
        
    f5.close()

dim=3
n=60
nsteps=500
entsfield=[]
lista=[]
for i in range(n):
    entsfield.append(ent(n,nsteps))
                     


  
filereader(dim,n,nsteps)
print 
for t in range(nsteps):
    for i in range(n):
        for j in range(n):
            if i!=j:
                dist=0
                for s in range(dim):
                    
                    dist+=(float(entsfield[i].pos[t][s])-float(entsfield[j].pos[t][s]))**2
            else:
                dist=0
            entsfield[i].euclidcomp[j][t]=math.sqrt(dist)    
print entsfield[1].euclidcomp
answer=""
while answer!="exit":
    w=input("n=")
    lista=[]
    fig=plt.figure()
    for j in range(n):
        lista=[]
        for t in range(nsteps):
            lista.append(entsfield[w].euclidcomp[j][t])
            
        plt.plot(lista)
        plt.show()   
                    
 
    
