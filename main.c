//
//  main.c
//  projetNF04
//
//  Created by Julien Calonne on 04/05/2021.
//

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    
    //-------------------------------------------------------//
    //I. Saisie des valeurs par l'utilisateur
    //-------------------------------------------------------//
    
    //1. Saisie de n (nombre de sub-divisions)
    int n;
    printf("Entrer la valeur de n souhaitée (n doit être un entier pair positif): \n");
    scanf("%d", &n);
    printf("Valeur de n : %i", n);
    
    //2. Saisie des bornes de l'integrale
    float a;
    printf("Entrer la valeur inférieur de votre intégrale que l'on appelera 'a' (un réel): \n");
    scanf("%f", &a);
    printf("Valeur de a : %f", a);
    
    float b;
    printf("Entrer la valeur supérieur de votre intégrale que l'on appelera 'b' (un réel): \n");
    scanf("%f", &b);
    
    //-------------------------------------------------------//
    //II. Calcul des valeurs selon x de la fonction choisie
    //-------------------------------------------------------//
    
    float h;
    h=(b-a)/n; //h represente la pas de subdivision de l'intervalle
    
    int i;
    float xi, tab[1000];
    for(i=0;i<=n;i++){
        xi=a+h*i;
        tab[i]=1/(1+(xi*xi)); //On choisit la fonction 1/(1+x^2) qui a pour primitive Arctan(x). Si on veut calculer l'integrale pour une autre fonction il suffit de changer cette ligne de code.
        printf("Valeur de f(x) pour i= : %d, est : %f\n",i,tab[i]);
    }
    
    //-------------------------------------------------------//
    //III. Calcul des sommes qui seront utilisées dans le calcul de l'intégrale
    //-------------------------------------------------------//
    
    //1. Calcul de la somme 1
    float somme1;
    somme1=0;
    int k1;
    k1=(n-2)/2;
    for (i=0;i<=k1;i=i+1){
        somme1 = somme1 + tab[2*i+1]; //Avec tab[2*i+1] on cherche la valeur de f(x(2*i+1))
    }
    printf("Résultat de la somme 1 : %f\n",somme1);
    
    //1. Calcul de la somme 2
    float somme2;
    somme2=0;
    int k2;
    k2=(n-2)/2;
    for (i=1;i<=k2;i=i+1){
        somme2 = somme2 + tab[2*i]; //Avec tab[2*i] on cherche la valeur de f(x(2*i))
    }
    printf("Résultat de la somme 2 : %f\n",somme2);
    
    //-------------------------------------------------------//
    //IV. Calcul de l'intégrale
    //-------------------------------------------------------//
    float integrale;
    integrale = (h/3)*(tab[0] + tab[n] + 4*somme1 + 2*somme2);
    //Avec tous les résultats obtenus on peut calculer l'integrale.
    //tab[0] correspond à f(a) et tab[n] à f(b)
    printf("Le résultat de l'integrale calculée est : %f \n", integrale);
    
    return 0;
}

