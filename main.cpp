#include <iostream>
#include "numerical_methods.hpp"
int main(int argc, char **argv)
{
    double *mat[3];
    mat[0] = new double[4]{3, -2, 1};
    mat[1] = new double[4]{1, -3, 4};
    mat[2] = new double[4]{9, 4, -5};

    double D[3] = {8, 6, 11};
    double X[3] = {0, 0, 0};
    double Y[3] = {0, 0, 0};
    LDP(3, mat, D, X, Y);
    int i = 0;
    
    // double *L[3];
    // L[0] = new double[3]{1, 0, 0};
    // L[1] = new double[3]{mat[1][0], 1, 0};
    // L[2] = new double[3]{mat[2][0], mat[2][1], 1};

    // double *D[3];
    // D[0] = new double[3]{D[0],  0, 0};
    // D[1] = new double[3]{0, D[1], 0};
    // D[2] = new double[3]{0, 0, D[2]};
    
    // double *P[3];
    // P[0] = new double[3]{1, 0, 0};
    // P[1] = new double[3]{0, 1, 0};
    // P[2] = new double[3]{0, 0, 1};

    for (double x : Y)
    {
        std::cout << "Y" << ++i << ":" << x << std::endl;
    }
    i = 0;
    for (double x : X)
    {
        std::cout << "X" << ++i << ":" << x << std::endl;
    }
}