#include <iostream>
#include <string>		
#include <cmath>
#include "aux_algorithms.hpp"
using namespace std;
int n;

double select_piv(double A[3][3], int k, int &ite, int n){

double pv = abs(A[k][k]);
int r = k;
for(int i = k; i<= n-1; i++){
    if(abs(A[i][k]>pv)){
        pv = abs(A[i][k]);
        r = i;
   }
}
ite = r;
return pv; 
}

void permutation(double p[],double A[3][3],int k,int &ite){
    double aux = p[k];
    p[k] = p[ite];
    p[ite] = aux;
    for(int j = 0; j<=n-1; j++){
        aux = A[k][j];
        A[k][j] = A[ite][j];
        A[ite][j] = aux;
    } 
}

void subst_sucessive_mod(int n,double A[3][3],double b[],double y[]){
    double x[3];
    for(int i = 0 ; i<= n-1 ; i++){
        double soma = 0;
        for(int j = 0; j<=i-2; j++){
            soma = soma + (A[i][j] * x[j]);
        }
    x[i] = b[i] - soma;    
    }
    for(int i = 0; i<=2; i++){
        y[i] = x[i];
    }
   
}

void subst_retroative(int n,double A[3][3], double b[]){
    double x[n];
    x[n] = b[n] / A[n][n];
    for(int i = n-2; i >=0 ;i--){
        double soma = 0;
        for(int j = 1; j<=n-1;j++){
            soma = soma + (A[i][j] * x[j]);
        }
        x[i] = (b[i] - soma)/A[i][i];
    }
    
}