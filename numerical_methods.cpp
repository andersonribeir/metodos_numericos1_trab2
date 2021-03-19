#include <iostream>
#include <string>		
#include <cmath>
#include "numerical_methods.hpp"
#include "aux_algorithms.cpp"
using namespace std;

void lu_pivot_parcial(int n, double A[3][3], double b){
    double array_permut[n];
    for(int i = 0; i <= n-1;i++){
        array_permut[i] = i;
    }
    int ite;
    double m;
    for(int k = 0; k <= n-2;k++){
        double pv = select_piv(A,k,ite,n);
        if(pv == 0){
            break;
        }
        if(ite != k){
            permutation(array_permut,A,k,ite);
        }
        for(int i = k; i<= n-1;k++){
            
            m = A[i][k]/A[k][k];
            A[i][k] = m;

            for(int j = k; j<=n-1;j++){
                A[i][j] = A[i][j] - (m*A[k][j]);
            }
        }
    }
    double blin[n];
    double baux[n];
    
    for(int i = 0;i <= n-1;i++){
        ite = array_permut[i];
        blin[i] = baux[ite];

    }
    double y[n];
    subst_sucessive_mod(n,A,blin,y);
    double x[n];
    subst_retroative(n,A,y,x);
        
}