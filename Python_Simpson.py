#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri May 14 20:02:02 2021

@author: juliencalonne
"""

#------------------------------------------------------------------
#I.Saisie des valeurs par l'utilisateur
#------------------------------------------------------------------
#1.Saisie de la valeur de n

n = int(input("Entrer la valeur de n souhaitée (n doit être un entier pair positif): "))
print("Valeur de n :", n)

#2.Saisie des bornes de l'integrale

a= float(input("Entrer la valeur inférieur de votre intégrale que l'on appelera 'a' (un réel): "))
print("a :",a)

b= float(input("Entrer la valeur supérieur de votre intégrale que l'on appelera 'b' (un réel): "))
print("b :",b)


#------------------------------------------------------------------
#II.Calcul des valeurs selon x de la fonction choisie
#------------------------------------------------------------------
h=(b-a)/n #h represente la pas de subdivision de l'intervalle
tab = [0] *1000
for i in range(0,n+1,1): 
    xi=float(a+(i*h))
    tab[i]= 1/(1+xi**2) #On choisit la fonction 1/(1+x^2) qui a pour primitive Arctan(x). Si on veut calculer l'integrale pour une autre fonction il suffit de changer cette ligne de code.

#------------------------------------------------------------------
#III.Calcul des sommes qui seront utilisées dans le calcul de l'intégrale
#------------------------------------------------------------------

#1.Calcul de la somme 1
somme1=0
k = int((n-2)/2) #On utilisera k1 et k2 dans un souci de clarté de la boucle Pour

for i in range (0,k+1,1):
    somme1 = somme1 + tab[2*i+1] #Avec tab[2*i+1] on cherche la valeur de f(x(2*i+1))

print("Valeur de la somme1:", somme1)

#2.Calcul de la somme 2
#k2 = int((n-2)/2)
somme2=0
for i in range (1,k+1,1):
    somme2 = somme2 + tab[2*i] #Avec tab[2*i] on cherche la valeur de f(x(2*i))
    
print("Valeur de la somme2", somme2)

#------------------------------------------------------------------
#IV.Calcul de l'intégrale
#------------------------------------------------------------------
print("h/3 : ",h/3)
print("f(a) : ", tab[0])
print("f(b) : ", tab[n])

integrale = (h/3)*(tab[0]+tab[n]+4*somme1+2*somme2)
print("Le résultat de l'intégrale est :",integrale)



#Valeur estimée réelle de l'integrale :
#0,5404 (integrale normale)
#Méthode de Simpson :
#Avec n=6, a=1 et b=4, on trouve :
#0,5405 a la main avec simpson
#puis la meme chose avec le programme
