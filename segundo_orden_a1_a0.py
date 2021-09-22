# -*- coding: utf-8 -*-
"""
Created on Tue Sep 21 18:42:19 2021

@author: david
"""

#import math 
# Clasificación de sistemas de segundo orden
a1= float(input("Ingresa a1: "))
a0= float(input("Ingresa a0: "))
# Sistema sobreamortiguado
if(a1**2 > 4*a0):
    print("El sistema es sobreamortiguado")
# Sistema críticamente amortiguado
elif(a1**2 == 4*a0):
    print("El sistema es críticamente amortiguado")
#Sistema subamortiguado
else:
    print("El sistema es subamortiguado")    