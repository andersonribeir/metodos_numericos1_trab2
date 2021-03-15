#include <iostream>
#include <string>		
#include <cmath>
#include "aux_algorithms.hpp"
using namespace std;
int n;

double select_piv(double A[3][3], int k, int &ite){

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

void permutation(double p[3],double A[3][3],int k,int &ite){
    double aux = p[k];
    p[k] = p[ite];
    p[ite] = aux;
    for(int j = 0; j<=n-1; j++){
        aux = A[k][j];
        A[k][j] = A[ite][j];
        A[ite][j] = aux;
    } 
}

void subst_sucessive_mod(int n,double A[3][3],double b[3]){
    double x[3];
    for(int i = 0 ; i<= n-1 ; i++){
        double soma = 0;
        for(int j = 0; j<=i-2; j++){
            soma = soma + (A[i][j] * x[j]);
        }
    x[i] = b[i] - soma;    

    }
}