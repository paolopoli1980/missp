# -*- coding: utf-8 -*-
"""
Created on Thu Jul 06 22:11:24 2017

@author: paolo
"""

import random
import os

def buildpotmemfile(l1,l2,p1,p3):
    f2=open("potmem10.aut","w")
      
    for el in pot:
        
        f2.write("POT\n")    
        f2.write(str(el)+"\n")
        value=random.uniform(l1,l2)
        f2.write(str(value)+"\n")
        
        for i in range(dim):
            value=random.uniform(p1,p3)
            f2.write(str(value)+str("\n"))
        f2.write("1000000\n")
    f2.write("*\n")
    f2.close()
            
    pass
def dynamics(n):
    f1.write("DYNAMICS\n")
    for i in range(n):
        f1.write("FOR\n")
        f1.write("("+str(i+1)+","+str(i+1)+")\n")
        f1.write("POT\n")
        f1.write("-"+str(pot[i])+"\n")
        f1.write("("+str(1)+","+str(n)+")\n")
        f1.write("(1,100000)\n")
        f1.write("ENDFOR\n")
    f1.write("ENDDYNAMICS\n")        
        
        
        
def putbody(n,r1,r2,dim):
    f3=open("pos.aut","w")
    for j in range(n):
        for i in range(dim):
            casual=random.uniform(r1,r2)
            f3.write(str(casual)+"\n")
    f3.write("*\n")        
             
        
def build_main_static_part(nel,dim,maxstep,minstep,typesim,typemove,nsteps,chosen):
    global f1
    f1=open("main.aut","w")
    f1.write("SETTING\n")
    f1.write("NEL\n")
    f1.write(str(nel)+"\n");
    f1.write("NSTEPS\n")
    f1.write(str(nsteps)+"\n")
    f1.write("DIM\n")
    f1.write(str(dim)+"\n")
    f1.write("MAXSTEP\n")
    f1.write(str(maxstep)+str("\n"))
    f1.write("MINSTEP\n")
    f1.write(str(minstep)+str("\n"))
    f1.write("TYEPSIM\n")
    f1.write(str(typesim)+str("\n"))
    f1.write("TYPEMOVE\n")
    f1.write("1\n")
    f1.write("PUSHUP\n")
    f1.write("1\n")
    f1.write("CHOSEN\n")
    f1.write(str(chosen)+"\n")
    f1.write("MULTIFILE\n")
    f1.write("1\n")
    f1.write("TYPESTEP\n")
    f1.write("1\n")
    f1.write("MAXPOTAB\n")
    f1.write("5\n")

    f1.write("ENDSETTING\n")

n=40
nsteps=200
maxstep=0.05
minstep=0.02
dim=3
typesim=3
typemove=1
l1=0.5
l2=1.5
p1=0.2
P2=1.8
p3=1.8
chosen=5
r1=-2
r2=2
pot=[i+901 for i in range(n)]

putbody(n,r1,r2,dim)
build_main_static_part(n,dim,maxstep,minstep,typesim,typemove,nsteps,chosen)
buildpotmemfile(l1,l2,p1,p3)
dynamics(n)
f1.close()
 


    