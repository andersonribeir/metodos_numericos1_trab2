#include <cmath>
#include <iostream>
using namespace std;

void inline Permute(int n, double **A, double *p, int k, int r)
{
    double aux = p[k];
    p[k] = p[r];
    p[r] = aux;
    for (int j = 0; j < n; j++)
    {
        aux = A[k][j];
        A[k][j] = A[r][j];
        A[r][j] = aux;
    }
}
void inline Pivot(int n, double **A, int k, int &r, double &pv)
{
    pv = fabs(A[k][k]);
    r = k;
    for (int i = k + 1; i < n; i++)
    {
        if (fabs(A[i][k]) > pv)
        {
            pv = (fabs(A[i][k]));
            r = i;
        }
    }
}
void inline SucessiveSubstitution_mod(int n, double **A, double *B, double *X)
{

    for (int i = 0; i < n; i++)
    {
        double soma = 0;
        for (int j = 0; j < i; j++)
        {

            soma += A[i][j] * X[j];
        }
        X[i] = (B[i] - soma);

        std::cout << std::endl;
    }
}

void inline RetroactiveSubstitution(int n, double **A, double *B, double *X)
{
    X[n] = B[n] / A[n][n];
    for (int i = n - 1; i >= 0; --i)
    {
        double soma = 0;
        for (int j = i + 1; j < n; j++)
        {
            soma += A[i][j] * X[j];
        }
        X[i] = (B[i] - soma) / A[i][i];
    }
}

void LU(int n, double **A, double *b, double *x, double *y)
{
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         std::cout << "[" << (float)A[i][j] << "]";
    //         //std::cout << i << j << std::endl;
    //     }
    //     std::cout << std::endl;
    // }
    double p[n];
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
    }
    int r;
    double pv;
    for (int k = 0; k < n - 1; k++)
    {
        Pivot(n, A, k, r, pv);
        if (pv = 0)
        {
            return;
        }
        if (r != k)
        {

            Permute(n, A, p, k, r);
        }

        for (int i = k + 1; i < n; i++)
        {
            double m = ((double)A[i][k] / A[k][k]);
            A[i][k] = m;
            for (int j = k + 1; j < n; j++)
            {
                A[i][j] = A[i][j] - m * A[k][j];
            }
        }
    }
    std::cout << std::endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << "[" << (float)A[i][j] << "]";
            //std::cout << i << j << std::endl;
        }
        std::cout << std::endl;
    }

    double blin[n];

    for (int i = 0; i < n; i++)
    {
        r = p[i];
        blin[i] = b[r];
    }

    SucessiveSubstitution_mod(n, A, blin, y);

    RetroactiveSubstitution(n, A, y, x);
}

void LDP(int n, double **A, double *b, double *x, double *y)
{
    double *l[n];
    for (int i = 0; i < n; i++)
    {
        l[i] = new double[n];
    }
    int i = 0, j = 0, k = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            l[i][j] = A[i][j];
        }
    }

    double p[n];
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
    }
    int r;
    double pv;
    double list_piv[n];



   
    for (int k = 0; k < n - 1; k++)
    {
        Pivot(n, l, k, r, pv);
        
        if (pv = 0)
        {
            return;
        }else{
            list_piv[k]=pv;
        }
        
        if (r != k)
        {

            Permute(n, l, p, k, r);
        }

        for (int i = k + 1; i < n; i++)
        {
            double m = ((double)l[i][k] / l[k][k]);
            l[i][k] = m;
            for (int j = k + 1; j < n; j++)
            {
                l[i][j] = l[i][j] - m * l[k][j];
            }
        }
    }
    double *D[n];
    for (int i = 0; i < n; i++)
    {
        D[i] = new double[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i==j){
                D[i][j]=l[i][j];

            }
            if(i<j){
                l[i][j]=0;
            }
        }
    }


    double *P[n];
    for (int i = 0; i < n; i++)
    {
        P[i] = new double[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i<j){
                double soma=0;
                for(int k=0;k<j-1;k++){
                    soma+=l[i][k]*l[j][k]*D[k][k];
                }
                P[i][j]=(A[i][j]-soma)/D[i][i];
            }else if(i==j){
                P[i][j] = 1;
            }
        }

    }
    
        
       for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << "[" << (float)P[i][j] << "]";
            //std::cout << i << j << std::endl;
        }
        std::cout << std::endl;
        
    }

    float tempU[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            float num = 0;
            for (int k = 0; k < 3; k++)
            {
                num += D[i][k] * P[k][j];
            }

            tempU[i][j] = num;
        }
    }
    for(int teste = 0; teste<n ;teste++){
        for(int testecol = 0; testecol<n; testecol++){
            cout<<"["<<tempU[teste][testecol]<<"]";

        }
           
        cout<<endl;
        
    }

    
 
    
    
}
